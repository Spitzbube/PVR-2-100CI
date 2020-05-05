
    EXPORT  ARM1176_VfpSetFastmode
    EXPORT  ARM1176_VfpInitialise

    AREA    ARM1176INIT, CODE, READONLY

ARM1176_VfpSetFastmode
    MOV      r0,#0x3000000
    VMSR     FPSCR,r0
    BX       lr

ARM1176_VfpInitialise
    MRC      p15,#0x0,r1,c1,c0,#2
    ORR      r1,r1,#0xf00000
    MCR      p15,#0x0,r1,c1,c0,#2
    MOV      r1,#0
    MCR      p15,#0x0,r1,c7,c5,#4
    MOV      r0,#0x40000000
    VMSR     FPEXC,r0
    BX       lr

    END


