
    .text
    .section ".ARM1176INIT"
    .align 8


.globl ARM1176_MmuInitialise
ARM1176_MmuInitialise:
    MOV      r11,lr
    MRC      p15,0,r0,c1,c0,0
    BIC      r0,r0,#0x1000
    BIC      r0,r0,#4
    BIC      r0,r0,#1
    MCR      p15,0,r0,c1,c0,0
    MRC      p15,0,r0,c1,c0,0
    MOV      r1,#0x800000
    ORR      r0,r0,r1
    MCR      p15,0,r0,c1,c0,0
    MOV      r0,#0
    MCR      p15,0,r0,c2,c0,2
    LDR      r0,Data_21b106e0
    MCR      p15,0,r0,c2,c0,0
    LDR      r0,Data_21b106e0
    MOV      r1,#0
    MOV      r2,#0
    MOV      r3,#0
    MOV      r4,#0x80000000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4_1
    MOV      r2,#0
    MOV      r3,#0
    MOV      r4,#0x100000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x2000000
    MOV      r3,#0x2000000
    MOV      r4,#0x100000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0xf000000
    MOV      r3,#0xf000000
    MOV      r4,#0x100000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e8
    MOV      r2,#0x20000000
    MOV      r3,#0x20000000
    MOV      r4,#0x4000000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x20000000
    MOV      r3,#0x20000000
    MOV      r4,#0x1b00000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e8
    MOV      r2,#0x40000000
    MOV      r3,#0x40000000
    MOV      r4,#0x4000000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x40000000
    MOV      r3,#0x40000000
    MOV      r4,#0x2000000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x60000000
    MOV      r3,#0x60000000
    MOV      r4,#0x1200000
    BL       func_21b106b4
    LDR      r0,Data_21b106e0
    LDR      r1,Data_21b106e4
    MOV      r2,#0x80000000
    MOV      r3,#0x80000000
    MOV      r4,#0x80000000
    BL       func_21b106b4
    MRC      p15,0,r0,c3,c0,0
    LDR      r0,Data_21b106ec
    MCR      p15,0,r0,c3,c0,0
    MRC      p15,0,r0,c1,c0,0
    ORR      r0,r0,#0x1000
    ORR      r0,r0,#4
    ORR      r0,r0,#1
    ORR      r0,r0,#0x400000
    ORR      r0,r0,#0x100
    BIC      r0,r0,#0x200
    MCR      p15,0,r0,c1,c0,0
    MOV      lr,r11
    BX       lr

func_21b106b4:
/*
    LSR      r2,r2,#20
    LSR      r3,r3,#20
    LSR      r4,r4,#20
*/
    MOV      r2,r2,LSR #20
    MOV      r3,r3,LSR #20
    MOV      r4,r4,LSR #20
    ADD      r4,r4,r3
l_21b106c4:
    ORR      r5,r1,r2,LSL #20
    STR      r5,[r0,r3,LSL #2]
    ADD      r3,r3,#1
    ADD      r2,r2,#1
    CMP      r3,r4
    BNE      l_21b106c4
    BX       lr

Data_21b106e0:
    .long 0x02004000
Data_21b106e4_1:
    .long 0x000011e2
Data_21b106e4:
    .long 0x00000de2
Data_21b106e8:
    .long 0x00000dee
Data_21b106ec:
    .long 0x55555555

