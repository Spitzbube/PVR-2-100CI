
    EXPORT  ARM1176_INTR_VectorTable
    EXPORT  ARM1176_INTR_Initialise
    EXPORT  ARM1176_INTR_ResetHandler
    EXPORT  ARM1176_INTR_UndefHandler
    EXPORT  ARM1176_INTR_SwiHandler
    EXPORT  ARM1176_INTR_PrefetchHandler
    EXPORT  ARM1176_INTR_AbortHandler
    EXPORT  ARM1176_INTR_FiqHandler
    EXPORT  ARM1176_INTR_IrqHandler
    EXPORT  ARM1176_INTR_IrqHandler_5
    EXPORT  ARM1176_INTR_IrqHandler_6
    EXPORT  ARM1176_INTR_IrqHandler_7
    EXPORT  ARM1176_INTR_IrqHandler_8
    EXPORT  ARM1176_INTR_IrqHandler_9
    EXPORT  ARM1176_INTR_IrqHandler_10
    EXPORT  ARM1176_INTR_IrqHandler_11
    EXPORT  ARM1176_INTR_IrqHandler_12
    EXPORT  ARM1176_INTR_IrqHandler_13
    EXPORT  ARM1176_INTR_IrqHandler_14
    EXPORT  ARM1176_INTR_IrqHandler_15
    EXPORT  ARM1176_INTR_IrqHandler_16
    EXPORT  ARM1176_INTR_IrqHandler_17
    EXPORT  ARM1176_INTR_IrqHandler_18
    EXPORT  ARM1176_INTR_IrqHandler_19
    EXPORT  ARM1176_INTR_IrqHandler_20
    EXPORT  ARM1176_INTR_IrqHandler_21
    EXPORT  ARM1176_INTR_IrqHandler_22
    EXPORT  ARM1176_INTR_IrqHandler_23
    EXPORT  ARM1176_INTR_IrqHandler_24
    EXPORT  ARM1176_INTR_IrqHandler_25
    EXPORT  ARM1176_INTR_IrqHandler_26
    EXPORT  ARM1176_INTR_IrqHandler_27
    EXPORT  ARM1176_INTR_IrqHandler_28
    EXPORT  ARM1176_INTR_IrqHandler_29
    EXPORT  ARM1176_INTR_IrqHandler_30
    EXPORT  ARM1176_INTR_IrqHandler_31
    
    EXTERN  FREG_VIC_SetVectaddrx
    EXTERN  FREG_VIC_SetAddress        

    PRESERVE8 ; required for STMDB/LDM sp!,{r12}
    AREA    ARM1176IVT, CODE, READONLY


ARM1176_INTR_VectorTable
    LDR      pc,Data_ARM1176_INTR_ResetHandler
    LDR      pc,Data_ARM1176_INTR_UndefHandler
    LDR      pc,Data_ARM1176_INTR_SwiHandler
    LDR      pc,Data_ARM1176_INTR_PrefetchHandler
    LDR      pc,Data_ARM1176_INTR_AbortHandler
    NOP      
    LDR      pc,Data_ARM1176_INTR_IrqHandler
    LDR      pc,Data_ARM1176_INTR_FiqHandler

Data_ARM1176_INTR_ResetHandler
    DCD ARM1176_INTR_ResetHandler
Data_ARM1176_INTR_UndefHandler
    DCD ARM1176_INTR_UndefHandler
Data_ARM1176_INTR_SwiHandler
    DCD ARM1176_INTR_SwiHandler
Data_ARM1176_INTR_PrefetchHandler
    DCD ARM1176_INTR_PrefetchHandler
Data_ARM1176_INTR_AbortHandler
    DCD ARM1176_INTR_AbortHandler
Data_21b10774    
    DCD    0
Data_ARM1176_INTR_IrqHandler
    DCD ARM1176_INTR_IrqHandler
Data_ARM1176_INTR_FiqHandler
    DCD ARM1176_INTR_FiqHandler
Data_ARM1176_INTR_FunctionTable
    IMPORT  ARM1176_INTR_FunctionTable
    DCD ARM1176_INTR_FunctionTable
Data_FAPI_INTR_IsrFunctionTable
    IMPORT  FAPI_INTR_IsrFunctionTable    
    DCD FAPI_INTR_IsrFunctionTable
Data_FAPI_INTR_BsrFunctionTable
    IMPORT  FAPI_INTR_BsrFunctionTable
    DCD FAPI_INTR_BsrFunctionTable
Data_FREG_VIC_SetVectaddrx
    DCD FREG_VIC_SetVectaddrx
Data_FREG_VIC_GetVectaddrx
    IMPORT  FREG_VIC_GetVectaddrx
    DCD FREG_VIC_GetVectaddrx
Data_FREG_VIC_SetAddress
    IMPORT  FREG_VIC_SetAddress
    DCD FREG_VIC_SetAddress
Data_FREG_VIC_GetAddress
    IMPORT  FREG_VIC_GetAddress
    DCD FREG_VIC_GetAddress
        

ARM1176_INTR_Initialise
    PUSH     {r0,r1,r12,lr}
    LDR      r0,Data_ARM1176_INTR_VectorTable
    MCR      p15,#0x0,r0,c12,c0,#0

	mov r0, #5
	ldr r1, ARM1176_INTR_IrqHandler_5_1
	bl  FREG_VIC_SetVectaddrx

	mov r0, #6
	ldr r1, ARM1176_INTR_IrqHandler_6_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #7
	ldr r1, ARM1176_INTR_IrqHandler_7_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #8
	ldr r1, ARM1176_INTR_IrqHandler_8_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #9
	ldr r1, ARM1176_INTR_IrqHandler_9_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #10
	ldr r1, ARM1176_INTR_IrqHandler_10_1
	bl  FREG_VIC_SetVectaddrx

	mov r0, #11
	ldr r1, ARM1176_INTR_IrqHandler_11_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #12
	ldr r1, ARM1176_INTR_IrqHandler_12_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #13
	ldr r1, ARM1176_INTR_IrqHandler_13_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #14
	ldr r1, ARM1176_INTR_IrqHandler_14_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #15
	ldr r1, ARM1176_INTR_IrqHandler_15_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #16
	ldr r1, ARM1176_INTR_IrqHandler_16_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #17
	ldr r1, ARM1176_INTR_IrqHandler_17_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #18
	ldr r1, ARM1176_INTR_IrqHandler_18_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #19
	ldr r1, ARM1176_INTR_IrqHandler_19_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #20
	ldr r1, ARM1176_INTR_IrqHandler_20_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #21
	ldr r1, ARM1176_INTR_IrqHandler_21_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #22
	ldr r1, ARM1176_INTR_IrqHandler_22_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #23
	ldr r1, ARM1176_INTR_IrqHandler_23_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #24
	ldr r1, ARM1176_INTR_IrqHandler_24_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #25
	ldr r1, ARM1176_INTR_IrqHandler_25_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #26
	ldr r1, ARM1176_INTR_IrqHandler_26_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #27
	ldr r1, ARM1176_INTR_IrqHandler_27_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #28
	ldr r1, ARM1176_INTR_IrqHandler_28_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #29
	ldr r1, ARM1176_INTR_IrqHandler_29_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #30
	ldr r1, ARM1176_INTR_IrqHandler_30_1
	bl  FREG_VIC_SetVectaddrx
	
	mov r0, #31
	ldr r1, ARM1176_INTR_IrqHandler_31_1
	bl  FREG_VIC_SetVectaddrx

    POP      {r0,r1,r12,pc}

ARM1176_INTR_ResetHandler
    PUSH     {r0-r12,lr}
    SUBS     r0,lr,#4
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#0*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_UndefHandler
    PUSH     {r0-r12,lr}
    MOV      r0,lr
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#1*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_SwiHandler
    PUSH     {r0-r12,lr}
    MOV      r1,r0
    MOV      r0,lr
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#2*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^
    
ARM1176_INTR_PrefetchHandler
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MOV      r0,lr
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#3*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^
    
ARM1176_INTR_AbortHandler
    SUB      lr,lr,#8
    PUSH     {r0-r12,lr}
    MOV      r0,lr
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#4*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^
    
ARM1176_INTR_IrqHandler
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MOV      r0,lr
    LDR      r12,Data_ARM1176_INTR_FunctionTable
    LDR      r12,[r12,#6*4]
    CMP      r12,#0
    BLXNE    r12
    LDM      sp!,{r0-r12,pc}^
    
ARM1176_INTR_FiqHandler
    SUB      lr,lr,#4
    PUSH     {r0-r7,lr}
    STMDB    sp!,{r0}
    MOV      r0,lr
    LDR      r7,Data_ARM1176_INTR_FunctionTable
    LDR      r7,[r7,#7*4]
    CMP      r7,#0
    BLXNE    r7
    LDM      sp!,{r0}
    LDM      sp!,{r0-r7,pc}^

ARM1176_INTR_IrqHandler_5
	SUB      lr,lr,#4
	PUSH     {r0-r12,lr}
	MRS      r12,SPSR
    STMDB    sp!,{r12}
	STMDB    sp!,{r12}
	
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*5]
	CMP      r12,#0
	BEQ      l_21b10a10
	BLX      r12
	CMP      r0,#0
	BEQ      l_21b10a10
	LDR      r12,Data_FAPI_INTR_BsrFunctionTable
	LDR      r12,[r12,#4*5]
	CMP      r12,#0
	BLXNE    r12
l_21b10a10
	LDM      sp!,{r12}
	LDM      sp!,{r12}
	MSR      SPSR_cxsf,r12
	MOV      r0,#5
	BL       FREG_VIC_SetAddress
	LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_6
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*6]
    CMP      r12,#0
    BEQ      l_6
    BLX      r12
    CMP      r0,#0
    BEQ      l_6
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*6]
    CMP      r12,#0
    BLXNE    r12
l_6
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#6
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_7
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*7]
    CMP      r12,#0
    BEQ      l_7
    BLX      r12
    CMP      r0,#0
    BEQ      l_7
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*7]
    CMP      r12,#0
    BLXNE    r12
l_7
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#7
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_8
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*8]
    CMP      r12,#0
    BEQ      l_8
    BLX      r12
    CMP      r0,#0
    BEQ      l_8
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*8]
    CMP      r12,#0
    BLXNE    r12
l_8
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#8
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_9
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*9]
    CMP      r12,#0
    BEQ      l_9
    BLX      r12
    CMP      r0,#0
    BEQ      l_9
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*9]
    CMP      r12,#0
    BLXNE    r12
l_9
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#9
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_10
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*10]
    CMP      r12,#0
    BEQ      l_10
    BLX      r12
    CMP      r0,#0
    BEQ      l_10
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*10]
    CMP      r12,#0
    BLXNE    r12
l_10
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#10
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_11
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*11]
    CMP      r12,#0
    BEQ      l_11
    BLX      r12
    CMP      r0,#0
    BEQ      l_11
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*11]
    CMP      r12,#0
    BLXNE    r12
l_11
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#11
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_12
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*12]
    CMP      r12,#0
    BEQ      l_12
    BLX      r12
    CMP      r0,#0
    BEQ      l_12
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*12]
    CMP      r12,#0
    BLXNE    r12
l_12
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#12
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_13
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*13]
    CMP      r12,#0
    BEQ      l_13
    BLX      r12
    CMP      r0,#0
    BEQ      l_13
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*13]
    CMP      r12,#0
    BLXNE    r12
l_13
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#13
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_14
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*14]
    CMP      r12,#0
    BEQ      l_14
    BLX      r12
    CMP      r0,#0
    BEQ      l_14
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*14]
    CMP      r12,#0
    BLXNE    r12
l_14
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#14
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_15
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*15]
    CMP      r12,#0
    BEQ      l_15
    BLX      r12
    CMP      r0,#0
    BEQ      l_15
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*15]
    CMP      r12,#0
    BLXNE    r12
l_15
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#15
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_16
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*16]
    CMP      r12,#0
    BEQ      l_16
    BLX      r12
    CMP      r0,#0
    BEQ      l_16
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*16]
    CMP      r12,#0
    BLXNE    r12
l_16
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#16
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_17
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*17]
    CMP      r12,#0
    BEQ      l_17
    BLX      r12
    CMP      r0,#0
    BEQ      l_17
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*17]
    CMP      r12,#0
    BLXNE    r12
l_17
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#17
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_18
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*18]
    CMP      r12,#0
    BEQ      l_18
    BLX      r12
    CMP      r0,#0
    BEQ      l_18
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*18]
    CMP      r12,#0
    BLXNE    r12
l_18
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#18
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_19
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*19]
    CMP      r12,#0
    BEQ      l_19
    BLX      r12
    CMP      r0,#0
    BEQ      l_19
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*19]
    CMP      r12,#0
    BLXNE    r12
l_19
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#19
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_20
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*20]
    CMP      r12,#0
    BEQ      l_20
    BLX      r12
    CMP      r0,#0
    BEQ      l_20
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*20]
    CMP      r12,#0
    BLXNE    r12
l_20
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#20
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_21
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*21]
    CMP      r12,#0
    BEQ      l_21
    BLX      r12
    CMP      r0,#0
    BEQ      l_21
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*21]
    CMP      r12,#0
    BLXNE    r12
l_21
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#21
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_22
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*22]
    CMP      r12,#0
    BEQ      l_22
    BLX      r12
    CMP      r0,#0
    BEQ      l_22
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*22]
    CMP      r12,#0
    BLXNE    r12
l_22
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#22
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_23
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*23]
    CMP      r12,#0
    BEQ      l_23
    BLX      r12
    CMP      r0,#0
    BEQ      l_23
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*23]
    CMP      r12,#0
    BLXNE    r12
l_23
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#23
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_24
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*24]
    CMP      r12,#0
    BEQ      l_24
    BLX      r12
    CMP      r0,#0
    BEQ      l_24
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*24]
    CMP      r12,#0
    BLXNE    r12
l_24
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#24
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_25
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*25]
    CMP      r12,#0
    BEQ      l_25
    BLX      r12
    CMP      r0,#0
    BEQ      l_25
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*25]
    CMP      r12,#0
    BLXNE    r12
l_25
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#25
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_26
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*26]
    CMP      r12,#0
    BEQ      l_26
    BLX      r12
    CMP      r0,#0
    BEQ      l_26
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*26]
    CMP      r12,#0
    BLXNE    r12
l_26
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#26
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_27
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*27]
    CMP      r12,#0
    BEQ      l_27
    BLX      r12
    CMP      r0,#0
    BEQ      l_27
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*27]
    CMP      r12,#0
    BLXNE    r12
l_27
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#27
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_28
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*28]
    CMP      r12,#0
    BEQ      l_28
    BLX      r12
    CMP      r0,#0
    BEQ      l_28
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*28]
    CMP      r12,#0
    BLXNE    r12
l_28
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#28
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_29
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*29]
    CMP      r12,#0
    BEQ      l_29
    BLX      r12
    CMP      r0,#0
    BEQ      l_29
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*29]
    CMP      r12,#0
    BLXNE    r12
l_29
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#29
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_30
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*30]
    CMP      r12,#0
    BEQ      l_30
    BLX      r12
    CMP      r0,#0
    BEQ      l_30
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*30]
    CMP      r12,#0
    BLXNE    r12
l_30
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#30
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_31
    SUB      lr,lr,#4
    PUSH     {r0-r12,lr}
    MRS      r12,SPSR
    STMDB    sp!,{r12}
    STMDB    sp!,{r12}    
    LDR      r12,Data_FAPI_INTR_IsrFunctionTable
    LDR      r12,[r12,#4*31]
    CMP      r12,#0
    BEQ      l_31
    BLX      r12
    CMP      r0,#0
    BEQ      l_31
    LDR      r12,Data_FAPI_INTR_BsrFunctionTable
    LDR      r12,[r12,#4*31]
    CMP      r12,#0
    BLXNE    r12
l_31
   LDM      sp!,{r12}
   LDM      sp!,{r12}
    MSR      SPSR_cxsf,r12
    MOV      r0,#31
    BL       FREG_VIC_SetAddress
    LDM      sp!,{r0-r12,pc}^

Data_ARM1176_INTR_VectorTable
    DCD ARM1176_INTR_VectorTable
ARM1176_INTR_IrqHandler_5_1
    DCD ARM1176_INTR_IrqHandler_5
ARM1176_INTR_IrqHandler_6_1
    DCD ARM1176_INTR_IrqHandler_6
ARM1176_INTR_IrqHandler_7_1
    DCD ARM1176_INTR_IrqHandler_7
ARM1176_INTR_IrqHandler_8_1
    DCD ARM1176_INTR_IrqHandler_8
ARM1176_INTR_IrqHandler_9_1
    DCD ARM1176_INTR_IrqHandler_9
ARM1176_INTR_IrqHandler_10_1
    DCD ARM1176_INTR_IrqHandler_10
ARM1176_INTR_IrqHandler_11_1
    DCD ARM1176_INTR_IrqHandler_11
ARM1176_INTR_IrqHandler_12_1
    DCD ARM1176_INTR_IrqHandler_12
ARM1176_INTR_IrqHandler_13_1
    DCD ARM1176_INTR_IrqHandler_13
ARM1176_INTR_IrqHandler_14_1
    DCD ARM1176_INTR_IrqHandler_14
ARM1176_INTR_IrqHandler_15_1
    DCD ARM1176_INTR_IrqHandler_15
ARM1176_INTR_IrqHandler_16_1
    DCD ARM1176_INTR_IrqHandler_16
ARM1176_INTR_IrqHandler_17_1
    DCD ARM1176_INTR_IrqHandler_17
ARM1176_INTR_IrqHandler_18_1
    DCD ARM1176_INTR_IrqHandler_18
ARM1176_INTR_IrqHandler_19_1
    DCD ARM1176_INTR_IrqHandler_19
ARM1176_INTR_IrqHandler_20_1
    DCD ARM1176_INTR_IrqHandler_20
ARM1176_INTR_IrqHandler_21_1
    DCD ARM1176_INTR_IrqHandler_21
ARM1176_INTR_IrqHandler_22_1
    DCD ARM1176_INTR_IrqHandler_22
ARM1176_INTR_IrqHandler_23_1
    DCD ARM1176_INTR_IrqHandler_23
ARM1176_INTR_IrqHandler_24_1
    DCD ARM1176_INTR_IrqHandler_24
ARM1176_INTR_IrqHandler_25_1
    DCD ARM1176_INTR_IrqHandler_25
ARM1176_INTR_IrqHandler_26_1
    DCD ARM1176_INTR_IrqHandler_26
ARM1176_INTR_IrqHandler_27_1
    DCD ARM1176_INTR_IrqHandler_27
ARM1176_INTR_IrqHandler_28_1
    DCD ARM1176_INTR_IrqHandler_28
ARM1176_INTR_IrqHandler_29_1
    DCD ARM1176_INTR_IrqHandler_29
ARM1176_INTR_IrqHandler_30_1
    DCD ARM1176_INTR_IrqHandler_30
ARM1176_INTR_IrqHandler_31_1
    DCD ARM1176_INTR_IrqHandler_31
        
    END