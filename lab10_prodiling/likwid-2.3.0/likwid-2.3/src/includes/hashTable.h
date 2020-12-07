/*
 * ===========================================================================
 *
 *      Filename:  hashtable.h
 *
 *      Description:  Header File hashtable Module. 
 *                    Wrapper for HAshTable data structure holding thread
 *                    specific region information.
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
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <bstrlib.h>
#include <types.h>

extern void hashTable_init();
extern int hashTable_get(bstring regionTag, LikwidThreadResults** result);
extern void hashTable_finalize(int* numberOfThreads, int* numberOfRegions, LikwidResults** results);


#endif /*CPUID_H*/
