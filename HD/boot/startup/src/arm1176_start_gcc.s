@See: https://github.com/RT-Thread/rt-thread/blob/master/bsp/gkipc/armv6/start_gcc.s

    .text
    .section ".ARM1176START"
    .code 32


@*******************************************************************************
@** Common cpu modes
@*******************************************************************************

    .equ ARM1176_MODE_USR,   0x10  @ CPSR_c xxx10000
    .equ ARM1176_MODE_FIQ,   0x11  @ CPSR_c xxx10001
    .equ ARM1176_MODE_IRQ,   0x12  @ CPSR_c xxx10010
    .equ ARM1176_MODE_SVC,   0x13  @ CPSR_c xxx10011
    .equ ARM1176_MODE_ABT,   0x17  @ CPSR_c xxx10111
    .equ ARM1176_MODE_UND,   0x1B  @ CPSR_c xxx11011
    .equ ARM1176_MODE_SYS,   0x1F  @ CPSR_c xxx11111
    .equ ARM1176_CPSR_I_BIT, 0x80  @ CPSR_c 100xxxxx
    .equ ARM1176_CPSR_F_BIT, 0x40  @ CPSR_c 010xxxxx
    .equ ARM1176_CPSR_T_BIT, 0x20  @ CPSR_c 001xxxxx



.globl _start
.globl  ARM1176_Start
_start:
ARM1176_Start:
    msr cpsr_c,#(ARM1176_MODE_SYS | ARM1176_CPSR_I_BIT | ARM1176_CPSR_F_BIT)    @disable irq/fiq first
    bl	ARM1176_TcmInitialise
    bl	bss_clear
    bl	ctor_init
    bl	stack_init
    ldr	ip, =main
    bl	ARM1176_MmuInitialise
    mov	r0, #0
    mov	r1, r0
    mov	r2, r0
    mov	fp, r0
    mov	r7, r0
    mov	lr, pc
    bx	ip

    ldr	ip, =exit
    bx	ip

    /* clear .bss */
bss_clear:
    mov     r0,#0                   /* get a zero                       */
    ldr     r1,=__bss_start__         /* bss start                      */
    ldr     r2,=__bss_end__           /* bss end                            */

bss_loop:
    cmp     r1,r2                   /* check if data to clear           */
    strlo   r0,[r1],#4              /* clear 4 bytes                    */
    blo     bss_loop                /* loop until done                  */
    bx	    lr


    /* call C++ constructors of global objects                          */
ctor_init:
    stmfd   sp!,{r0-r2,lr}
    ldr     r0, =__ctors_start__
    ldr     r1, =__ctors_end__

ctor_loop:
    cmp     r0, r1
    beq     ctor_end
    ldr     r2, [r0], #4
    stmfd   sp!, {r0-r1}
    mov     lr, pc
    mov     pc, r2
    ldmfd   sp!, {r0-r1}
    b       ctor_loop

ctor_end:
    ldmfd   sp!,{r0-r2,lr}
    bx	    lr

stack_init:
    ldr     sp, =__stack_start__
    bx      lr

ARM1176_Halt:
    b       ARM1176_Halt

