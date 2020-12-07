/*
 * ===========================================================================
 *
 *      Filename:  msr.h
 *
 *      Description:  Header File msr Module. 
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


#ifndef MSR_H
#define MSR_H

#include <types.h>

extern void msr_init();
extern void msr_finalize();
extern uint64_t msr_read(int cpu, uint32_t reg);
extern void msr_write(int cpu, uint32_t reg, uint64_t data);

#endif /*MSR_H*/
