/*
 * ===========================================================================
 *
 *      Filename:  asciiBoxes.h
 *
 *      Description:  Module to draw nested ascii art boxes.
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

#ifndef ASCIIBOXES_H
#define ASCIIBOXES_H
#include <types.h>
#include <bstrlib.h>

extern BoxContainer* asciiBoxes_allocateContainer(int numLines,int numColumns);
extern void asciiBoxes_addBox(BoxContainer* container, int line, int column, bstring label);
extern void asciiBoxes_addJoinedBox(BoxContainer* container, int line, int startColumn, int endColumn, bstring label);
extern void asciiBoxes_print(BoxContainer* container);

#endif /*ASCIIBOXES_H*/
