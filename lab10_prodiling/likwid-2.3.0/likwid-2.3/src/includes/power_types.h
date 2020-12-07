/*
 * ===========================================================================
 *
 *      Filename:  power_types.h
 *
 *      Description:  Types file for power module.
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

#ifndef POWER_TYPES_H
#define POWER_TYPES_H

#include <stdint.h>

typedef enum {
    PKG = 0,
    PP0,
    PP1,
    DRAM
} PowerType;

typedef struct {
    int numSteps;
    double* steps;
} TurboBoost;

typedef struct {
    double baseFrequency;
    double minFrequency;
    TurboBoost turbo;
    double powerUnit;
    double energyUnit;
    double timeUnit;
    double tdp;
    double minPower;
    double maxPower;
    double maxTimeWindow;
} PowerInfo;

typedef struct {
    uint32_t before;
    uint32_t after;
} PowerData;


#endif /*POWER_TYPES_H*/
