/*
 * ===========================================================================
 *
 *      Filename:  bitUtil.h
 *
 *      Description:  Header File bitUtil Module. 
 *                    Helper routines for dealing with bit manipulations
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

#ifndef BITUTIL_H
#define BITUTIL_H

#include <types.h>

extern uint32_t extractBitField(uint32_t inField, uint32_t width, uint32_t offset);
extern uint32_t getBitFieldWidth(uint32_t number);

#endif /*BITUTIL_H*/
