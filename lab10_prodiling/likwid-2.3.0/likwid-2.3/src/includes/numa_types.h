/*
 * ===========================================================================
 *
 *      Filename:  numa_types.h
 *
 *      Description:  Types file for numa module.
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


#ifndef NUMA_TYPES_H
#define NUMA_TYPES_H


typedef struct {
    int id;
    uint32_t totalMemory;
    uint32_t freeMemory;
    int numberOfProcessors;
    uint32_t*  processors;
} NumaNode;

typedef struct {
    uint32_t numberOfNodes;
    NumaNode* nodes;
} NumaTopology;


#endif /*NUMA_TYPES_H*/
