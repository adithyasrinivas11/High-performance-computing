/*
 * ===========================================================================
 *
 *      Filename:  bitUtil.c
 *
 *      Description:  Utility routines manipulating bit arrays.
 *
 *      Version:  2.3
 *      Created:  09.02.2012
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Company:  RRZE Erlangen
 *      Project:  likwid
 *      Copyright:  Copyright (c) 2012, Jan Treibig
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
#include <math.h>

#include <types.h>
#include <power.h>
#include <cpuid.h>

/* #####   EXPORTED VARIABLES   ########################################### */

PowerInfo power_info;
const uint32_t power_regs[4] = {MSR_PKG_ENERGY_STATUS,
                                MSR_PP0_ENERGY_STATUS,
                                MSR_PP1_ENERGY_STATUS,
                                MSR_DRAM_ENERGY_STATUS};

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ########### */



/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ################## */

void
power_init(int cpuId)
{
    uint64_t flags;
    uint32_t tmp;

    /* determine Turbo Mode features */
    double busSpeed;

    if (cpuid_info.turbo)
    {
        flags = msr_read(cpuId, MSR_PLATFORM_INFO);

        if ((cpuid_info.model == SANDYBRIDGE_EP) || (cpuid_info.model == SANDYBRIDGE))
        {
            busSpeed = 100.0;
        }
        else 
        {
            busSpeed = 133.33;
        }

        power_info.baseFrequency = busSpeed * (double) extractBitField(flags,8,8);
        power_info.minFrequency  = busSpeed * (double) extractBitField((flags>>(32)),8,8);

        power_info.turbo.numSteps = cpuid_topology.numCoresPerSocket;
        power_info.turbo.steps = (double*) malloc(power_info.turbo.numSteps * sizeof(double));

        flags = msr_read(cpuId, MSR_TURBO_RATIO_LIMIT);

        for (int i=0; i < power_info.turbo.numSteps; i++)
        {
            if ( i < 4 )
            {
                power_info.turbo.steps[i] = busSpeed * (double) extractBitField(flags,8,i*8);
            }
            else
            {
                power_info.turbo.steps[i] = busSpeed * (double) extractBitField(flags>>(32),8,i*8);
            }
        }
    }
    else
    {
        power_info.turbo.numSteps = 0;
    }

    /* determine RAPL parameters */
    if ((cpuid_info.model == SANDYBRIDGE_EP) || (cpuid_info.model == SANDYBRIDGE))
    {
        flags = msr_read(cpuId, MSR_RAPL_POWER_UNIT);

        power_info.powerUnit = pow(0.5,(double) extractBitField(flags,4,0));
        power_info.energyUnit = pow(0.5,(double) extractBitField(flags,5,8));
        power_info.timeUnit = pow(0.5,(double) extractBitField(flags,4,16));

        flags = msr_read(cpuId, MSR_PKG_POWER_INFO);
        power_info.tdp = (double) extractBitField(flags,15,0) * power_info.powerUnit;
        power_info.minPower =  (double) extractBitField(flags,15,16) * power_info.powerUnit;
        power_info.maxPower = (double) extractBitField(flags,15,32) * power_info.powerUnit;
        power_info.maxTimeWindow = (double) extractBitField(flags,15,48) * power_info.timeUnit;
    }
    else
    {
        power_info.powerUnit = 0.0;
    }
}

double
power_printEnergy(PowerData* data)
{
    return  (double) ((data->after - data->before) * power_info.energyUnit);
}


