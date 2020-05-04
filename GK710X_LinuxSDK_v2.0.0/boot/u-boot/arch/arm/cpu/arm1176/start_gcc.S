@*******************************************************************************
@*******************************************************************************
@**
@** \file        start.s
@**
@** \brief       Simple boot loader for MB86H60 linux (or fmboot)
@**              ARM secific part
@**
@** This program implements a simple boot loader which can load a binary
@** file from flash ROM and kick the application. It also have an useful
@** commands.
@**
@** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
@**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
@**              OMMISSIONS.
@**
@** (C) Copyright 2008-2010 by Fujitsu Microelectronics Limited
@** (C) Copyright 2010-2011 by Fujitsu Semiconductor Limited
@**
@*******************************************************************************
@*******************************************************************************

    .text
    .section ".ARM1176IVT"
    .align 8
    @ linker hint: file preserves 8-byte aligned stack

@*******************************************************************************
@*     5. Calling the kernel image */
@*        - Quiesce all DMA devices
@*        - CPU register settings
@*          r0 = 0,
@*          r1 = machine type number
@*          r2 = physical address of tagged list
@*        - CPU mode to SYS
@*        - MMU disabled
@*        - I-cache enabled or disabled
@*        - D-cache disabled
@*    
@*     r4, r5, r6 will be destroyed.
@*******************************************************************************
	
    .global ARM1176_set_and_go
    .global ARM1176_set_and_go
    .type ARM1176_set_and_go,%function
    .func ARM1176_set_and_go

ARM1176_set_and_go:
    mrc    p15, 0, r4, c1, c0, 0
    bic    r4, r4, #0x0		       @ MMU disabled
    bic    r4, r4, #0x2                @ D-$ disabled
    bic    r4, r4, #0x9                @ I-$ disabled
    mcr    p15, 0, r4, c1, c0, 0
    nop
    nop
    msr    cpsr_c, #0x0000001f         @ SYS mode
    mov    r0,r0
    mov    r1,r1
    mov    r2,r2
    blx    r3
    nop
    nop
    nop
    nop

    .size ARM1176_set_and_go, . - ARM1176_set_and_go
    .endfunc

@*******************************************************************************
@** End of file
@*******************************************************************************
