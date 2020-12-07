/*
 * ===========================================================================
 *
 *      Filename:  strUtil_types.h
 *
 *      Description:  Types file for strUtil module.
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


#ifndef STRUTIL_TYPES_H
#define STRUTIL_TYPES_H

#include  <bstrlib.h>


typedef struct {
    bstring eventName;
    bstring counterName;
} StrUtilEvent;

typedef struct {
    StrUtilEvent* events;
    int numberOfEvents;
} StrUtilEventSet;

typedef struct {
    bstring domain;
    int offset;
    void* ptr;
} Stream;

typedef struct {
    uint32_t numberOfThreads;
    int* processorIds;
    int size;
    Stream* streams;
} Workgroup;


#endif /*STRUTIL_TYPES_H*/
