
.global ARM1176_INTR_Initialise
.global func_21b007f0
.global func_21b00870
.global func_21b00874
.global func_21b01c88

/*
.section .ARM1176_INT
*/
.section .ARM1176IVT

ARM1176_INTR_VectorTable:
	ldr	pc, arm1176_intr_reset_vector
	ldr	pc, arm1176_intr_undef_vector
	ldr	pc, arm1176_intr_swi_vector
	ldr	pc, arm1176_intr_prefetch_vector
	ldr	pc, arm1176_intr_abort_vector
	nop
	ldr	pc, arm1176_intr_irq_vector
	ldr	pc, arm1176_intr_fiq_vector

arm1176_intr_reset_vector:
	.word ARM1176_INTR_ResetHandler
arm1176_intr_undef_vector:
	.word ARM1176_INTR_UndefHandler
arm1176_intr_swi_vector:
	.word ARM1176_INTR_SwiHandler
arm1176_intr_prefetch_vector:
	.word ARM1176_INTR_PrefetchHandler
arm1176_intr_abort_vector:
	.word ARM1176_INTR_AbortHandler
	.word 0x00000000
arm1176_intr_irq_vector:
	.word ARM1176_INTR_IrqHandler
arm1176_intr_fiq_vector:
	.word ARM1176_INTR_FiqHandler

arm1176_intr_vector_table:
	.word ARM1176_INTR_VectorTable


Data_21b00544:	
	.word ARM1176_INTR_IrqHandler_5
Data_21b00548:	
	.word ARM1176_INTR_IrqHandler_6
Data_21b0054c:	
	.word ARM1176_INTR_IrqHandler_7
Data_21b00550:
	.word ARM1176_INTR_IrqHandler_8
Data_21b00554:	
	.word ARM1176_INTR_IrqHandler_9
Data_21b00558:
	.word ARM1176_INTR_IrqHandler_10
Data_21b0055c:	
	.word ARM1176_INTR_IrqHandler_11
Data_21b00560:	
	.word ARM1176_INTR_IrqHandler_12
Data_21b00564:	
	.word ARM1176_INTR_IrqHandler_13
Data_21b00568:	
	.word ARM1176_INTR_IrqHandler_14
Data_21b0056c:	
	.word ARM1176_INTR_IrqHandler_15
Data_21b00570:	
	.word ARM1176_INTR_IrqHandler_16
Data_21b00574:	
	.word ARM1176_INTR_IrqHandler_17
Data_21b00578:	
	.word ARM1176_INTR_IrqHandler_18
Data_21b0057c:	
	.word ARM1176_INTR_IrqHandler_19
Data_21b00580:	
	.word ARM1176_INTR_IrqHandler_20
Data_21b00584:	
	.word ARM1176_INTR_IrqHandler_21
Data_21b00588:	
	.word ARM1176_INTR_IrqHandler_22
Data_21b0058c:	
	.word ARM1176_INTR_IrqHandler_23
Data_21b00590:	
	.word ARM1176_INTR_IrqHandler_24
Data_21b00594:	
	.word ARM1176_INTR_IrqHandler_25
Data_21b00598:	
	.word ARM1176_INTR_IrqHandler_26
Data_21b0059c:	
	.word ARM1176_INTR_IrqHandler_27
Data_21b005a0:	
	.word ARM1176_INTR_IrqHandler_28
Data_21b005a4:	
	.word ARM1176_INTR_IrqHandler_29
Data_21b005a8:	
	.word ARM1176_INTR_IrqHandler_30
Data_21b005ac:	
	.word ARM1176_INTR_IrqHandler_31


/* V49: 21b005b0 */
ARM1176_INTR_Initialise:
	stmdb	sp!, {r0, r1, r2, r3, r4, lr}

	/* Use new interrupt vector table */
	ldr	r0, arm1176_intr_vector_table
	mcr	15, 0, r0, cr12, cr0, 0

	/* IRQ 0...4 are for the ARC */

	mov	r0, #5
	ldr	r1, Data_21b00544
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #6
	ldr	r1, Data_21b00548
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #7
	ldr	r1, Data_21b0054c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #8
	ldr	r1, Data_21b00550
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #9
	ldr	r1, Data_21b00554
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #10
	ldr	r1, Data_21b00558
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #11
	ldr	r1, Data_21b0055c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #12
	ldr	r1, Data_21b00560
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #13
	ldr	r1, Data_21b00564
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #14
	ldr	r1, Data_21b00568
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #15
	ldr	r1, Data_21b0056c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #16
	ldr	r1, Data_21b00570
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #17
	ldr	r1, Data_21b00574
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #18
	ldr	r1, Data_21b00578
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #19
	ldr	r1, Data_21b0057c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #20
	ldr	r1, Data_21b00580
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #21
	ldr	r1, Data_21b00584
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #22
	ldr	r1, Data_21b00588
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #23
	ldr	r1, Data_21b0058c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #24
	ldr	r1, Data_21b00590
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #25
	ldr	r1, Data_21b00594
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #26
	ldr	r1, Data_21b00598
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #27
	ldr	r1, Data_21b0059c
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #28
	ldr	r1, Data_21b005a0
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #29
	ldr	r1, Data_21b005a4
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #30
	ldr	r1, Data_21b005a8
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #31
	ldr	r1, Data_21b005ac
	bl	FREG_VIC_SetVectaddrx

	ldmia	sp!, {r0, r1, r2, r3, r4, pc}


arm1176_intr_function_table:
	.word ARM1176_INTR_FunctionTable
arm1176_isr_function_table:
    .long FAPI_INTR_IsrFunctionTable
arm1176_bsr_function_table:
    .long FAPI_INTR_BsrFunctionTable

ARM1176_INTR_ResetHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	subs	r0, lr, #4
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_UndefHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip,#4]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_SwiHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r1, r0
	mov	r0, lr
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip,#8]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_PrefetchHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip,#12]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_AbortHandler:
	sub	lr, lr, #8
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip,#16]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_IrqHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, arm1176_intr_function_table
	ldr	ip, [ip,#24]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_FiqHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, lr}
	stmdb	sp!, {r0}
	mov	r0, lr
	ldr	r7, arm1176_intr_function_table
	ldr	r7, [r7, #28]
	cmp	r7, #0
	blxne	r7
	ldmia	sp!, {r0}
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, pc}^


ARM1176_INTR_IrqHandler_5:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*5]
    cmp r12,#0
    beq l5
    blx r12
    cmp r0,#0
    beq l5
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*5]
    cmp r12,#0
    blxne r12
l5:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#5
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_6:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*6]
    cmp r12,#0
    beq l6
    blx r12
    cmp r0,#0
    beq l6
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*6]
    cmp r12,#0
    blxne r12
l6:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#6
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_7:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*7]
    cmp r12,#0
    beq l7
    blx r12
    cmp r0,#0
    beq l7
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*7]
    cmp r12,#0
    blxne r12
l7:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#7
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_8:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*8]
    cmp r12,#0
    beq l8
    blx r12
    cmp r0,#0
    beq l8
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*8]
    cmp r12,#0
    blxne r12
l8:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#8
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_9:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*9]
    cmp r12,#0
    beq l9
    blx r12
    cmp r0,#0
    beq l9
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*9]
    cmp r12,#0
    blxne r12
l9:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#9
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_10:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*10]
    cmp r12,#0
    beq l10
    blx r12
    cmp r0,#0
    beq l10
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*10]
    cmp r12,#0
    blxne r12
l10:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#10
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_11:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*11]
    cmp r12,#0
    beq l11
    blx r12
    cmp r0,#0
    beq l11
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*11]
    cmp r12,#0
    blxne r12
l11:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#11
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_12:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*12]
    cmp r12,#0
    beq l12
    blx r12
    cmp r0,#0
    beq l12
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*12]
    cmp r12,#0
    blxne r12
l12:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#12
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_13:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*13]
    cmp r12,#0
    beq l13
    blx r12
    cmp r0,#0
    beq l13
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*13]
    cmp r12,#0
    blxne r12
l13:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#13
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_14:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*14]
    cmp r12,#0
    beq l14
    blx r12
    cmp r0,#0
    beq l14
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*14]
    cmp r12,#0
    blxne r12
l14:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#14
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_15:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*15]
    cmp r12,#0
    beq l15
    blx r12
    cmp r0,#0
    beq l15
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*15]
    cmp r12,#0
    blxne r12
l15:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#15
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_16:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*16]
    cmp r12,#0
    beq l16
    blx r12
    cmp r0,#0
    beq l16
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*16]
    cmp r12,#0
    blxne r12
l16:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#16
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_17:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*17]
    cmp r12,#0
    beq l17
    blx r12
    cmp r0,#0
    beq l17
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*17]
    cmp r12,#0
    blxne r12
l17:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#17
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_18:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*18]
    cmp r12,#0
    beq l18
    blx r12
    cmp r0,#0
    beq l18
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*18]
    cmp r12,#0
    blxne r12
l18:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#18
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_19:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*19]
    cmp r12,#0
    beq l19
    blx r12
    cmp r0,#0
    beq l19
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*19]
    cmp r12,#0
    blxne r12
l19:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#19
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_20:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*20]
    cmp r12,#0
    beq l20
    blx r12
    cmp r0,#0
    beq l20
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*20]
    cmp r12,#0
    blxne r12
l20:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#20
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_21:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*21]
    cmp r12,#0
    beq l21
    blx r12
    cmp r0,#0
    beq l21
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*21]
    cmp r12,#0
    blxne r12
l21:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#21
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_22:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*22]
    cmp r12,#0
    beq l22
    blx r12
    cmp r0,#0
    beq l22
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*22]
    cmp r12,#0
    blxne r12
l22:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#22
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_23:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*23]
    cmp r12,#0
    beq l23
    blx r12
    cmp r0,#0
    beq l23
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*23]
    cmp r12,#0
    blxne r12
l23:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#23
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_24:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*24]
    cmp r12,#0
    beq l24
    blx r12
    cmp r0,#0
    beq l24
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*24]
    cmp r12,#0
    blxne r12
l24:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#24
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_25:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*25]
    cmp r12,#0
    beq l25
    blx r12
    cmp r0,#0
    beq l25
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*25]
    cmp r12,#0
    blxne r12
l25:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#25
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_26:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*26]
    cmp r12,#0
    beq l26
    blx r12
    cmp r0,#0
    beq l26
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*26]
    cmp r12,#0
    blxne r12
l26:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#26
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_27:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*27]
    cmp r12,#0
    beq l27
    blx r12
    cmp r0,#0
    beq l27
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*27]
    cmp r12,#0
    blxne r12
l27:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#27
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_28:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*28]
    cmp r12,#0
    beq l28
    blx r12
    cmp r0,#0
    beq l28
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*28]
    cmp r12,#0
    blxne r12
l28:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#28
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_29:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*29]
    cmp r12,#0
    beq l29
    blx r12
    cmp r0,#0
    beq l29
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*29]
    cmp r12,#0
    blxne r12
l29:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#29
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_30:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*30]
    cmp r12,#0
    beq l30
    blx r12
    cmp r0,#0
    beq l30
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*30]
    cmp r12,#0
    blxne r12
l30:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#30
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

ARM1176_INTR_IrqHandler_31:
	sub	lr, lr, #4
	stmdb	sp!, {r0-r12, lr}
	mrs r12,spsr
	stmdb	sp!, {r12}
	stmdb	sp!, {r12}
	ldr r12,arm1176_isr_function_table
    ldr r12,[r12,#4*31]
    cmp r12,#0
    beq l31
    blx r12
    cmp r0,#0
    beq l31
    ldr r12,arm1176_bsr_function_table
    ldr r12,[r12,#4*31]
    cmp r12,#0
    blxne r12
l31:
    ldmia	sp!,{r12}
    ldmia	sp!,{r12}
    msr spsr_cxsf,r12
    mov r0,#31
    bl 	FREG_VIC_SetAddress
    ldmia	sp!,{r0-r12,pc}^

