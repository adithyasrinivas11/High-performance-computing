/*
 * ===========================================================================
 *
 *      Filename:  allocator.c
 *
 *      Description:  Implementation of allocator module.
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
#include <string.h>

#include <error.h>
#include <types.h>
#include <allocator.h>
#include <affinity.h>

/* #####   EXPORTED VARIABLES   ########################################### */


/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ######################### */



/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ###################### */

static int numberOfAllocatedVectors = 0;
static void** allocations;


/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ########### */


/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ################## */

void
allocator_init(int numVectors)
{
    allocations = (void**) malloc(numVectors * sizeof(void*));
}


void
allocator_finalize()
{
    int i;

    for (i=0; i<numberOfAllocatedVectors; i++)
    {
        free(allocations[i]);
    }
}

void
allocator_allocateVector(
        void** ptr,
        int alignment,
        int size,
        int offset,
        DataType type,
        bstring domainString)
{
    int bytesize = 0;
    const AffinityDomain* domain;

    switch ( type )
    {
        case SINGLE:
            bytesize = (size+offset) * sizeof(float);
            break;

        case DOUBLE:
            bytesize = (size+offset) * sizeof(double);
            break;
    }

    CHECK_ERROR(posix_memalign(ptr, alignment, bytesize), posix_memalign failed);

    allocations[numberOfAllocatedVectors] = *ptr;
    numberOfAllocatedVectors++;
    domain = affinity_getDomain(domainString);
    affinity_pinProcess(domain->processorList[0]);

    printf("Allocate: Process running on core %d - Vector length %d Offset %d\n",
            affinity_processGetProcessorId(),
            size,
            offset);

    switch ( type )
    {
        case SINGLE:
            {
                float* sptr = (float*) *ptr;
                sptr += offset;

                for ( int i=0; i < size; i++ )
                {
                    sptr[i] = 0.0;
                }
                *ptr = (void*) sptr;

            }
            break;

        case DOUBLE:
            {
                double* dptr = (double*) *ptr;
                dptr += offset;

                for ( int i=0; i < size; i++ )
                {
                    dptr[i] = 0.0;
                }
                *ptr = (void*) dptr;
            }
            break;
    }
}

