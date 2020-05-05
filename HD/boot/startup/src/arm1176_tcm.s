
    AREA    ARM1176INIT, CODE, READONLY

    EXPORT  ARM1176_TcmInitialise


svc_stack
    DCD ARM1176_STACK_BOTTOM_SVC_AREA

fiq_stack
    DCD 0x0f001000

irq_stack
    DCD 0x0f002000

abort_stack
    DCD ARM1176_STACK_BOTTOM_ABT_AREA

undefined_stack
    DCD ARM1176_STACK_BOTTOM_UND_AREA

sys_stack
    DCD ARM1176_STACK_BOTTOM_SYS_AREA

usr_stack
    DCD ARM1176_STACK_BOTTOM_SYS_AREA



ARM1176_TcmInitialise
    mov r0, #0  ;/* TCM 0 */
    mcr p15, 0, r0, c9, c2, 0  ;/*Write TCM Selection */

    mov r0, #0x0f000000
    orr r0, r0, #1
    mcr p15, 0, r0, c9, c1, 0  ;/* Write Data TCM Region */

    ldr r0, =0x0f004000
    orr r0, r0, #1
    mcr p15, 0, r0, c9, c1, 1  ;/* Write Instruction TCM Region */

    mov r0, #1  ;/* TCM 1 */
    mcr p15, 0, r0, c9, c2, 0  ;/* Write TCM Selection */

    mov r0, #0x0f000000
    add r0, r0, #0x2000
    orr r0, r0, #1
    mcr p15, 0, r0, c9, c1, 0  ;/* Write Data TCM Region */

    ldr r0, =0x0f004000
    add r0, r0, #0x2000
    orr r0, r0, #1
    mcr p15, 0, r0, c9, c1, 1  ;/* Write Instruction TCM Region */

    mov r1, #0  ;/* TCM 0 */
    mcr p15, 0, r1, c9, c2, 0  ;/* Write TCM Selection */

    mov r0, #0x0f000000
    mov r1, #0x02000000
    str r0, [r1, #132]

    mov r0, #0x4000
    mov r1, #0x02000000
    str r0, [r1, #136]

    ldr r0, =0x0f004000
    mov r1, #0x02000000
    str r0, [r1, #120]

    mov r0, #0x4000
    mov r1, #0x02000000
    str r0, [r1, #124]

    ;/* Setup the stack for each mode */

    ldr r0, undefined_stack
    msr CPSR_c, #0xdb   ;/* Undefined Instruction Mode  */
    mov sp, r0

    ldr r0, abort_stack
    msr CPSR_c, #0xd7   ;/* Abort Mode */
    mov sp, r0

    ldr r0, irq_stack
    msr CPSR_c, #0xd2   ;/* IRQ Mode */
    mov sp, r0

    ldr r0, fiq_stack
    msr CPSR_c, #0xd1   ;/* FIQ Mode */
    mov sp, r0

    ldr r0, svc_stack
    msr CPSR_c, #0xd3   ;/* Supervisor Mode */
    mov sp, r0

    ldr r0, usr_stack
    msr CPSR_c, #0xdf   ;/* User Mode */
    mov sp, r0

    mov r1, #0x02000000
    ldr r0, usr_stack
    str r0, [r1, #180]

    mov r0, #0x800
    str r0, [r1, #184]

    ldr r0, sys_stack
    str r0, [r1, #188]

    mov r0, #0x800
    str r0, [r1, #192]

    ldr r0, svc_stack
    str r0, [r1, #196]

    mov r0, #0x1000
    str r0, [r1, #200]

    ldr r0, undefined_stack
    str r0, [r1, #204]

    mov r0, #0x400
    str r0, [r1, #208]

    ldr r0, abort_stack
    str r0, [r1, #212]

    mov r0, #0x400
    str r0, [r1, #216]

    ldr r0, irq_stack
    str r0, [r1, #220]

    mov r0, #0x1000
    str r0, [r1, #224]

    ldr r0, fiq_stack
    str r0, [r1, #228]

    mov r0, #0x1000
    str r0, [r1, #232]
    bx  lr


    AREA    ARM1176STACKS, BSS

    SPACE   0x400
ARM1176_STACK_BOTTOM_UND_AREA
    SPACE   0x400
ARM1176_STACK_BOTTOM_ABT_AREA
    SPACE   0x1000
ARM1176_STACK_BOTTOM_SVC_AREA
    SPACE   0x800
ARM1176_STACK_BOTTOM_SYS_AREA

    END

