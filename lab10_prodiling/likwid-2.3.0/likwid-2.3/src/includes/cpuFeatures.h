/*
 * ===========================================================================
 *
 *      Filename:  cpuFeatures.h
 *
 *      Description:  Header File of Module cpuFeatures.
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


#ifndef CPUFEATURES_H
#define CPUFEATURES_H

#include <types.h>

extern CpuFeatureFlags cpuFeatureFlags;


extern void cpuFeatures_init(int cpu);
extern void cpuFeatures_print(int cpu);
extern void cpuFeatures_enable(int cpu, CpuFeature type);
extern void cpuFeatures_disable(int cpu, CpuFeature type);

#endif /*CPUFEATURES_H*/
