
    AREA ARM1176START, CODE, READONLY

    EXTERN  __main
    EXTERN  ARM1176_TcmInitialise
    EXTERN  ARM1176_VfpInitialise
    EXTERN  ARM1176_VfpSetFastmode
    EXTERN  ARM1176_MmuInitialise

    EXPORT ARM1176_Start

ARM1176_Start
    MSR      CPSR_c,#0xdf
    BL       ARM1176_TcmInitialise
    BL       ARM1176_VfpInitialise
    BL       ARM1176_VfpSetFastmode
    LDR      R12,=__main
    BL       ARM1176_MmuInitialise
    BX       R12

    EXPORT ARM1176_Halt
ARM1176_Halt
    b ARM1176_Halt

    END
