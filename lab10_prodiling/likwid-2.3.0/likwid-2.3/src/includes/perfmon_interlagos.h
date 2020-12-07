/*
 * ===========================================================================
 *
 *      Filename:  perfmon_interlagos.h
 *
 *      Description:  AMD Interlagos specific subroutines
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
#include <stdlib.h>
#include <stdio.h>

#include <bstrlib.h>
#include <types.h>
#include <registers.h>
#include <numa.h>
#include <perfmon_interlagos_events.h>
#include <perfmon_interlagos_groups.h>

#define NUM_COUNTERS_INTERLAGOS 10

static int perfmon_numCountersInterlagos = NUM_COUNTERS_INTERLAGOS;
static int perfmon_numGroupsInterlagos = NUM_GROUPS_INTERLAGOS;
static int perfmon_numArchEventsInterlagos = NUM_ARCH_EVENTS_INTERLAGOS;

static volatile int _init = 0;

static PerfmonCounterMap interlagos_counter_map[NUM_COUNTERS_INTERLAGOS] = {
    {"PMC0",PMC0},
    {"PMC1",PMC1},
    {"PMC2",PMC2},
    {"PMC3",PMC3},
    {"PMC4",PMC4},
    {"PMC5",PMC5},
    {"UPMC0",PMC6},
    {"UPMC1",PMC7},
    {"UPMC2",PMC8},
    {"UPMC3",PMC9}
};

void perfmon_init_interlagos(PerfmonThread *thread)
{
    uint64_t flags = 0x0ULL;
    int cpu_id = thread->processorId;
//    int socketId;

    if (! _init) {
        _init =1;
        for( int i=0; i < MAX_NUM_NODES; i++ ) socket_lock[i] = 0;

        for ( uint32_t i = 0; i < numa_info.numberOfNodes; i++ )
        {
            for ( int j = 0; j < numa_info.nodes[i].numberOfProcessors; j++ )
            {
                processor_lookup[numa_info.nodes[i].processors[j]] = i;
            }
        }
    }

    /* Core counters */
    thread->counters[PMC0].configRegister = MSR_AMD15_PERFEVTSEL0;
    thread->counters[PMC0].counterRegister = MSR_AMD15_PMC0;
    thread->counters[PMC0].type = PMC;
    thread->counters[PMC1].configRegister = MSR_AMD15_PERFEVTSEL1;
    thread->counters[PMC1].counterRegister = MSR_AMD15_PMC1;
    thread->counters[PMC1].type = PMC;
    thread->counters[PMC2].configRegister = MSR_AMD15_PERFEVTSEL2;
    thread->counters[PMC2].counterRegister = MSR_AMD15_PMC2;
    thread->counters[PMC2].type = PMC;
    thread->counters[PMC3].configRegister = MSR_AMD15_PERFEVTSEL3;
    thread->counters[PMC3].counterRegister = MSR_AMD15_PMC3;
    thread->counters[PMC3].type = PMC;
    thread->counters[PMC4].configRegister = MSR_AMD15_PERFEVTSEL4;
    thread->counters[PMC4].counterRegister = MSR_AMD15_PMC4;
    thread->counters[PMC4].type = PMC;
    thread->counters[PMC5].configRegister = MSR_AMD15_PERFEVTSEL5;
    thread->counters[PMC5].counterRegister = MSR_AMD15_PMC5;
    thread->counters[PMC5].type = PMC;

    /* Northbridge counters */
    thread->counters[PMC6].configRegister = MSR_AMD15_NB_PERFEVTSEL0;
    thread->counters[PMC6].counterRegister = MSR_AMD15_NB_PMC0;
    thread->counters[PMC6].type = UNCORE;
    thread->counters[PMC7].configRegister = MSR_AMD15_NB_PERFEVTSEL1;
    thread->counters[PMC7].counterRegister = MSR_AMD15_NB_PMC1;
    thread->counters[PMC7].type = UNCORE;
    thread->counters[PMC8].configRegister = MSR_AMD15_NB_PERFEVTSEL2;
    thread->counters[PMC8].counterRegister = MSR_AMD15_NB_PMC2;
    thread->counters[PMC8].type = UNCORE;
    thread->counters[PMC9].configRegister = MSR_AMD15_NB_PERFEVTSEL3;
    thread->counters[PMC9].counterRegister = MSR_AMD15_NB_PMC3;
    thread->counters[PMC9].type = UNCORE;

    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL0, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL1, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL2, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL3, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL4, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_PERFEVTSEL5, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_NB_PERFEVTSEL0, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_NB_PERFEVTSEL1, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_NB_PERFEVTSEL2, 0x0ULL);
    msr_write(cpu_id, MSR_AMD15_NB_PERFEVTSEL3, 0x0ULL);

    flags |= (1<<16);  /* user mode flag */

    msr_write(cpu_id, MSR_AMD_PERFEVTSEL0, flags);
    msr_write(cpu_id, MSR_AMD_PERFEVTSEL1, flags);
    msr_write(cpu_id, MSR_AMD_PERFEVTSEL2, flags);
    msr_write(cpu_id, MSR_AMD_PERFEVTSEL3, flags);
}


void
perfmon_setupCounterThread_interlagos(int thread_id,
        PerfmonEvent* event,
        PerfmonCounterIndex index)
{
    uint64_t flags;
    uint64_t reg = perfmon_threadData[thread_id].counters[index].configRegister;
    int cpu_id = perfmon_threadData[thread_id].processorId;
    perfmon_threadData[thread_id].counters[index].init = TRUE;

    flags = msr_read(cpu_id,reg);
    flags &= ~(0xFFFFU); 

	/* AMD uses a 12 bit Event mask: [35:32][7:0] */
	flags |= ((uint64_t)(event->eventId>>8)<<32) + (event->umask<<8) + (event->eventId & ~(0xF00U));

    if (perfmon_verbose)
    {
        printf("[%d] perfmon_setup_counter: Write Register 0x%llX , Flags: 0x%llX \n",
               cpu_id,
               LLU_CAST reg,
               LLU_CAST flags);
    }
    msr_write(cpu_id, reg , flags);
}


void
perfmon_startCountersThread_interlagos(int thread_id)
{
    int i;
    int haveLock = 0;
    uint64_t flags;
    int cpu_id = perfmon_threadData[thread_id].processorId;

    if (!socket_lock[processor_lookup[cpu_id]])
    {
        socket_lock[processor_lookup[cpu_id]] = 1;
        haveLock = 1;
    }

    for ( i=0; i<NUM_COUNTERS_INTERLAGOS; i++ ) 
    {
        if (perfmon_threadData[thread_id].counters[i].init == TRUE) 
        {
            if (perfmon_threadData[thread_id].counters[i].type == PMC)
            {
                msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].counterRegister , 0x0ULL);
                flags = msr_read(cpu_id,perfmon_threadData[thread_id].counters[i].configRegister);
                flags |= (1<<22);  /* enable flag */

                if (perfmon_verbose) 
                {
                    printf("perfmon_start_counters: Write Register 0x%llX , Flags: 0x%llX \n",
                            LLU_CAST perfmon_threadData[thread_id].counters[i].configRegister,
                            LLU_CAST flags);
                }

                msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].configRegister , flags);

            }
            else if (perfmon_threadData[thread_id].counters[i].type == UNCORE)
            {
                if(haveLock)
                {
                    msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].counterRegister , 0x0ULL);
                    flags = msr_read(cpu_id,perfmon_threadData[thread_id].counters[i].configRegister);
                    flags |= (1<<22);  /* enable flag */

                    if (perfmon_verbose) 
                    {
                        printf("perfmon_start_counters: Write Register 0x%llX , Flags: 0x%llX \n",
                                LLU_CAST perfmon_threadData[thread_id].counters[i].configRegister,
                                LLU_CAST flags);
                    }

                    msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].configRegister , flags);
                }
            }
        }
    }
}

void 
perfmon_stopCountersThread_interlagos(int thread_id)
{
    int i;
    uint64_t flags;
    int haveLock = 0;
    int cpu_id = perfmon_threadData[thread_id].processorId;

    if (!socket_lock[processor_lookup[cpu_id]])
    {
        socket_lock[processor_lookup[cpu_id]] = 1;
        haveLock = 1;
    }

    for ( i=0; i<NUM_COUNTERS_INTERLAGOS; i++ ) 
    {
        if (perfmon_threadData[thread_id].counters[i].init == TRUE) 
        {
 //           if (perfmon_threadData[thread_id].counters[i].type == PMC)
 //           {
                flags = msr_read(cpu_id,perfmon_threadData[thread_id].counters[i].configRegister);
                flags &= ~(1<<22);  /* clear enable flag */
                msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].configRegister , flags);
                if (perfmon_verbose)
                {
                    printf("perfmon_stop_counters: Write Register 0x%llX , Flags: 0x%llX \n",
                            LLU_CAST perfmon_threadData[thread_id].counters[i].configRegister,
                            LLU_CAST flags);
                }
                perfmon_threadData[thread_id].counters[i].counterData =
                    msr_read(cpu_id, perfmon_threadData[thread_id].counters[i].counterRegister);

  //          }
   //         else if (perfmon_threadData[thread_id].counters[i].type == UNCORE)
    //        {
     //           if(haveLock)
      //          {
       //             flags = msr_read(cpu_id,perfmon_threadData[thread_id].counters[i].configRegister);
        //            flags &= ~(1<<22);  /* clear enable flag */
        //            msr_write(cpu_id, perfmon_threadData[thread_id].counters[i].configRegister , flags);
        //            if (perfmon_verbose)
        //            {
        //                printf("perfmon_stop_counters: Write Register 0x%llX , Flags: 0x%llX \n",
        //                        LLU_CAST perfmon_threadData[thread_id].counters[i].configRegister,
        //                        LLU_CAST flags);
        //            }
        //            perfmon_threadData[thread_id].counters[i].counterData =
        //                msr_read(cpu_id, perfmon_threadData[thread_id].counters[i].counterRegister);
//
//                }
//            }
        }
    }
}


void 
perfmon_readCountersThread_interlagos(int thread_id)
{
    int i;
    int cpu_id = perfmon_threadData[thread_id].processorId;

    for (i=0;i<NUM_COUNTERS_INTERLAGOS;i++) 
    {
        if (perfmon_threadData[thread_id].counters[i].init == TRUE) 
        {
            perfmon_threadData[thread_id].counters[i].counterData =
                msr_read(cpu_id, perfmon_threadData[thread_id].counters[i].counterRegister);
        }
    }
}


