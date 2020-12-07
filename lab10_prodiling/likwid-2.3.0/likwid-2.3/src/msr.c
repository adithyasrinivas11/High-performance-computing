/*
 * ===========================================================================
 *
 *      Filename:  msr.c
 *
 *      Description:  Implementation of msr module.
 *                   Provides API to read and write values to the model
 *                   specific registers on x86 processors using the msr
 *                   sys interface of the Linux 2.6 kernel. This module 
 *                   is based on the msr-util tools.
 *
 *      Version:  2.3
 *      Created:  09.02.2012
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Company:  RRZE Erlangen
 *      Project:  likwid
 *      Copyright:  Copyright (c) 2011, Jan Treibig
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License, v2, as
 *      published by the Free Software Foundation
 *     
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *     
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110.
 *
 * ===========================================================================
 */


/* #####   HEADER FILE INCLUDES   ######################################### */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <types.h>
#include <error.h>
#include <cpuid.h>
#include <msr.h>

/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ######################### */
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ###################### */
#ifndef MSR_DIRECT
static int socket_fd = -1;
static char* filepath;
static char * msr_strerror(MsrErrorType met);

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ########### */
static char * msr_strerror(MsrErrorType met)
{
    switch (met) {
        case MSR_ERR_NOERROR:   return "No error";
        case MSR_ERR_UNKNOWN:   return "unknown command";
        case MSR_ERR_RESTREG:   return "access to this MSR is not allowed";
        case MSR_ERR_OPENFAIL:  return "failed to open MSR file";
        case MSR_ERR_RWFAIL:    return "failed to read/write MSR";
        default:                return "UNKNOWN errorcode";
    }
}
#else
static int FD[MAX_NUM_THREADS];
#endif

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ################## */

void
msr_init()
{
#ifdef MSR_DIRECT
    int  fd;
    char* msr_file_name = "/dev/cpu/0/msr";

    fd = open(msr_file_name, O_RDWR);

    if (fd < 0)
    {
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "rdmsr: failed to open '%s': %s!\n",msr_file_name , strerror(errno));
        fprintf(stderr, "       Please check if the msr module is loaded and the device file has correct permissions.\n\n");
        exit(127);
    }

    close(fd);

    /* NOTICE: This assumes consecutive processor Ids! */
    for ( uint32_t i=0; i < cpuid_topology.numHWThreads; i++ )
    {
        char* msr_file_name = (char*) malloc(20 * sizeof(char));
        sprintf(msr_file_name,"/dev/cpu/%d/msr",i);
        FD[i] = open(msr_file_name, O_RDWR);

        if ( FD[i] < 0 )
        {
            ERROR;
        }
    }
#else
    /* Check the function of the daemon here */
    /*    MsrDataRecord msrData;*/
    char *newargv[] = { NULL };
    char *newenv[] = { NULL };
    char *exeprog = TOSTRING(MSRDAEMON);
    struct sockaddr_un address;
    size_t address_length;
    int  ret;
    pid_t pid;
    int timeout = 10;

    pid = fork();

    if (pid == 0)
    { 
        ret = execve (exeprog, newargv, newenv);
        if (ret < 0)
        {
            ERRNO_PRINT;
            fprintf(stderr, "Failed to execute the msr-daemon '%s' (see error above)\n", exeprog);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        ERROR_PLAIN_PRINT(Failed to fork);
    }

    EXIT_IF_ERROR(socket_fd = socket(AF_LOCAL, SOCK_STREAM, 0), socket() failed);

    address.sun_family = AF_LOCAL;
    address_length = sizeof(address);
    snprintf(address.sun_path, sizeof(address.sun_path), "/tmp/likwid-%d", pid);

    filepath = strdup(address.sun_path);
    DEBUG_PRINT(0, "Generated pathname is %s\n", filepath);

    while (timeout > 0)
    {
        int res;
        sleep(1);
        res = connect(socket_fd, (struct sockaddr *) &address, address_length);
        if (res == 0) {
            break;
        }
        timeout--;
        DEBUG_PRINT(1, "%s\n", "Still waiting for socket...");
    }
    if (timeout <= 0)
    {
        ERRNO_PRINT;  /* should hopefully still work, as we make no syscalls in between. */
        fprintf(stderr, "Exiting due to timeout: The socket file at '%s' could not be opened within 10 seconds.\n", filepath);
        fprintf(stderr, "Consult the error message above this to find out why.\n");
        fprintf(stderr, "If the error is 'no such file or directoy', it usually means that likwid-msrD just failed to start.\n");
        exit(EXIT_FAILURE);
    }
    DEBUG_PRINT(0, "%s\n", "Successfully opened socket to daemon.");
#endif /* MSR_DIRECT */
}

void
msr_finalize()
{
#ifdef MSR_DIRECT
    for ( uint32_t i=0; i < cpuid_topology.numHWThreads; i++ )
    {
        close(FD[i]);
    }
#else
    if ( socket_fd != -1 )
    { /* Only if a socket is actually open */
        MsrDataRecord msrData;
        msrData.type = EXIT;
        CHECK_ERROR(write(socket_fd, &msrData, sizeof(MsrDataRecord)),socket write failed);
        CHECK_ERROR(close(socket_fd),socket close failed);
        free(filepath);
    }
#endif /* MSR_DIRECT */
}


uint64_t 
msr_read(const int cpu, uint32_t reg)
{
#ifdef MSR_DIRECT
    uint64_t data;

    if ( pread(FD[cpu], &data, sizeof data, reg) != sizeof data ) 
    {
        ERROR_PRINT("cpu %d reg %x",cpu, reg);
    }

    return data;
#else
    MsrDataRecord msrData;

    msrData.cpu = cpu;
    msrData.reg = reg;
    msrData.data = 0x00;
    msrData.type = MSR_READ;
    CHECK_ERROR(write(socket_fd, &msrData, sizeof(MsrDataRecord)), socket write failed);
    CHECK_ERROR(read(socket_fd, &msrData, sizeof(MsrDataRecord)), socket read failed);
    if (msrData.errorcode != MSR_ERR_NOERROR)
    {
        fprintf(stderr, "Failed to read MSR through msr-daemon: "
                "daemon returned error %d '%s' for cpu %d reg %x\n",
                msrData.errorcode, msr_strerror(msrData.errorcode), cpu, reg);
        exit(EXIT_FAILURE);
    }

    return msrData.data;
#endif /* MSR_DIRECT */
}

void 
msr_write(const int cpu, uint32_t reg, uint64_t data)
{
#ifdef MSR_DIRECT
    if (pwrite(FD[cpu], &data, sizeof data, reg) != sizeof data) 
    {
        ERROR_PRINT("cpu %d reg %x",cpu, reg);
    }
#else
    MsrDataRecord msrData;

    msrData.cpu = cpu;
    msrData.reg = reg;
    msrData.data = data;
    msrData.type = MSR_WRITE;
    CHECK_ERROR(write(socket_fd, &msrData, sizeof(MsrDataRecord)), socket write failed);
    CHECK_ERROR(read(socket_fd, &msrData, sizeof(MsrDataRecord)), socket read failed);
    if (msrData.errorcode != MSR_ERR_NOERROR)
    {
        fprintf(stderr, "Failed to write MSR through msr-daemon: "
                "daemon returned error %d '%s' for cpu %d reg 0x%x\n",
                msrData.errorcode, msr_strerror(msrData.errorcode), cpu, reg);
        exit(EXIT_FAILURE);
    }

    if (msrData.data != 0x00ULL)
    {
        ERROR_PLAIN_PRINT(msr write failed);
    }
#endif /* MSR_DIRECT */
}


