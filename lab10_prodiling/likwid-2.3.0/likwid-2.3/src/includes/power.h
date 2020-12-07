/*
 * ===========================================================================
 *
 *      Filename:  power.h
 *
 *      Description:  Header File Power Module. 
 *                    Implements Intel RAPL Interface.
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

#ifndef POWER_H
#define POWER_H

#include <types.h>
#include <registers.h>
#include <bitUtil.h>
#include <msr.h>

extern PowerInfo power_info;
extern  const uint32_t power_regs[4];

extern void power_init(int cpuId);
inline void power_start(PowerData* data, int cpuId, PowerType type);
inline void power_stop(PowerData* data, int cpuId, PowerType type);
inline uint32_t power_read(int cpuId, uint64_t reg);
extern double power_printEnergy(PowerData* data);

inline void
power_start(PowerData* data, int cpuId, PowerType type)
{
    data->before = extractBitField(msr_read(cpuId, power_regs[type]),32,0);
}

inline void
power_stop(PowerData* data, int cpuId, PowerType type)
{
    data->after = extractBitField(msr_read(cpuId, power_regs[type]),32,0);
}

inline uint32_t
power_read(int cpuId, uint64_t reg)
{
    return extractBitField(msr_read(cpuId, reg),32,0);
}


#endif /*POWER_H*/
