
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
	ldr	pc, Data_21b00520
	ldr	pc, Data_21b00524
	ldr	pc, Data_21b00528
	ldr	pc, Data_21b0052c
	ldr	pc, Data_21b00530
	nop
	ldr	pc, Data_21b00538
	ldr	pc, Data_21b0053c

Data_21b00520:	
	.word ARM1176_INTR_ResetHandler
Data_21b00524:
	.word ARM1176_INTR_UndefHandler
Data_21b00528:	
	.word ARM1176_INTR_SwiHandler
Data_21b0052c:
	.word ARM1176_INTR_PrefetchHandler
Data_21b00530:	
	.word ARM1176_INTR_AbortHandler
	.word 0x00000000
Data_21b00538:	
	.word ARM1176_INTR_IrqHandler
Data_21b0053c:	
	.word ARM1176_INTR_FiqHandler

Data_21b00540:
	.word ARM1176_INTR_VectorTable

/*
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
*/

/* V49: 21b005b0 */
ARM1176_INTR_Initialise:
	stmdb	sp!, {r0, r1, r2, r3, r4, lr}

	/* Use new interrupt vector table */
	ldr	r0, Data_21b00540	
	mcr	15, 0, r0, cr12, cr0, 0

/*
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
*/
	ldmia	sp!, {r0, r1, r2, r3, r4, pc}


Data_21b00704:
	.word ARM1176_INTR_FunctionTable

ARM1176_INTR_ResetHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	subs	r0, lr, #4
	ldr	ip, Data_21b00704
	ldr	ip, [ip]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_UndefHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, Data_21b00704
	ldr	ip, [ip,#4]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_SwiHandler:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r1, r0
	mov	r0, lr
	ldr	ip, Data_21b00704
	ldr	ip, [ip,#8]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_PrefetchHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, Data_21b00704
	ldr	ip, [ip,#12]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_AbortHandler:
	sub	lr, lr, #8
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, Data_21b00704
	ldr	ip, [ip,#16]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_IrqHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, Data_21b00704
	ldr	ip, [ip,#24]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

ARM1176_INTR_FiqHandler:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, lr}
	stmdb	sp!, {r0}
	mov	r0, lr
	ldr	r7, Data_21b00704
	ldr	r7, [r7, #28]
	cmp	r7, #0
	blxne	r7
	ldmia	sp!, {r0}
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, pc}^
