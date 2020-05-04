/*
 * Memory Setup stuff - taken from blob memsetup.S
 *
 * Copyright (C) 1999 2000 2001 Erik Mouw (J.A.K.Mouw@its.tudelft.nl) and
 *		       Jan-Derk Bakker (J.D.Bakker@its.tudelft.nl)
 *
 * Modified for the Samsung SMDK2410 by
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2008
 * Guennadi Liakhovetki, DENX Software Engineering, <lg@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <config.h>

	.globl lowlevel_init
lowlevel_init:

	msr cpsr_c, #0xd3 			@ #PSR_F_BIT | PSR_I_BIT | SVC_MODE
										@ ensure svc mode
                        		@ and irqs disabled

	mrc p15, 0, r0, c1, c0, 0	@ read control reg
	bic r0, r0, #0x1				@ Clear MMU bit
	mcr p15, 0, r0, c1, c0, 0	@ write control reg

	mov	pc, lr



#ifdef CONFIG_ENABLE_MMU

        /* form a first-level section entry */
.macro FL_SECTION_ENTRY base,tex,ap,d,c,b
	.word (\base << 20) |(\tex<<12) |(\ap << 10) | \
           (\d << 5) | (0<<4) | (\c << 3) | (\b << 2) | (1<<1)
.endm

.section .mmudata, "a"
	.align 14
	.globl mmu_table
mmu_table:
/*set the the internal ROM to non-cachable/non-bufferable*/
	.set __base, 0
	.rept 0x1
	FL_SECTION_ENTRY __base, 1,0, 15, 0, 0
	.set __base, __base + 1
	.endr
/*access is not allowed.*/
	.rept 0x20- 0x1
	.word 0x00000000
	.endr
/*set the the internal RAM to non-cachable/non-bufferable*/
	.set __base, 0x20
	.rept 0x1
	FL_SECTION_ENTRY __base, 0,2, 15, 0, 0
	.set __base, __base + 1
	.endr
/*access is not allowed. */
	.rept 0xf0 - 0x21
	.word 0x00000000
	.endr
/*set the the internal TCM buffers to non-cachable/non-bufferable*/
	.set __base, 0xf0
	.rept 0x1
	FL_SECTION_ENTRY __base, 0,2, 15, 0, 0
	.set __base, __base + 1
	.endr
/* access is not allowed. */
	.rept 0x200 - 0xf1
	.word 0x00000000
	.endr
#ifndef  CONFIG_SINGLE_DDR_SYSTEM
/*set 1~63M in DDR1 memory to be cachable/non-bufferable*/
	.set __base, 0x200
	.rept 0x3f
	FL_SECTION_ENTRY __base, 0,3, 15, 1,0
	.set __base, __base + 1
	.endr
/*set 64M~64M in DDR1 memory to be non-cachable/non-bufferable*/
	.set __base, 0x23f
	.rept 0x1
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr
/*set 65M~128M in DDR1 memory to be cachable/non-bufferable*/
	.set __base, 0x240
	.rept 0x40
	FL_SECTION_ENTRY __base, 0,3, 15, 1,0
	.set __base, __base + 1
	.endr
#else
/* access is not allowed. */
	.rept 0x280 - 0x200
	.word 0x00000000
	.endr
#endif
/* access is not allowed. */
	.rept 0x300 - 0x280
	.word 0x00000000
	.endr
/*set the the internal RAM2RAM memory to non-cachable/non-bufferable*/
	.set __base, 0x300
	.rept 0x100
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr
#ifndef  CONFIG_SINGLE_DDR_SYSTEM
/*set 128M of DDR2 to be non-cachable/non-bufferable*/
	.set __base, 0x400
	.rept 0x80
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr
#else
/*set 1~63M in DDR2 memory to be cachable/non-bufferable*/
	.set __base, 0x400
	.rept 0x3f
	FL_SECTION_ENTRY __base, 0,3, 15, 1,0
	.set __base, __base + 1
	.endr
/*set 64M~64M in DDR2 memory to be non-cachable/non-bufferable*/
	.set __base, 0x43f
	.rept 0x1
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr
/*set 65M~128M in DDR2 memory to be cachable/non-bufferable*/
	.set __base, 0x440
	.rept 0x40
	FL_SECTION_ENTRY __base, 0,3, 15, 1,0
	.set __base, __base + 1
	.endr
#endif
/* access is not allowed. */
	.rept 0x600 - 0x480
	.word 0x00000000
	.endr
/*set the the internal video decoder memory to non-cachable/non-bufferable*/
	.set __base, 0x600
	.rept 0x12
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr
/* access is not allowed. */
	.rept 0x800 - 0x612
	.word 0x00000000
	.endr
/*set the the peripheral space to non-cachable/non-bufferable*/
	.set __base, 0x800
	.rept 0x800
	FL_SECTION_ENTRY __base, 0,3, 15, 0,0
	.set __base, __base + 1
	.endr

#endif

