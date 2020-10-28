
.global FAMOS_InitInterrupts
.global famosStartContextFirst
.global famosSwitchContextFromInterrupt
.global famosSwitchContextFromEvent
.global famosBreakPoint

/*
.section .ARM1176_INT
*/
.section .ARM1176IVT

famosIntrVectorTable:
	ldr	pc, famosIntrVectorReset
	ldr	pc, famosIntrVectorUndef
	ldr	pc, famosIntrVectorSwi
	ldr	pc, famosIntrVectorPrefetch
	ldr	pc, famosIntrVectorAbort
	nop
	ldr	pc, famosIntrVectorIrq
	ldr	pc, famosIntrVectorFiq

famosIntrVectorReset:
	.word famosIntrHandlerReset
famosIntrVectorUndef:
	.word famosIntrHandlerUndef
famosIntrVectorSwi:
	.word famosIntrHandlerSwi
famosIntrVectorPrefetch:
	.word famosIntrHandlerPrefetch
famosIntrVectorAbort:
	.word famosIntrHandlerAbort
	.word 0x00000000
famosIntrVectorIrq:
	.word famosIntrHandlerIrq
famosIntrVectorFiq:
	.word famosIntrHandlerFiq

famosIntrVectorAddress:
	.word famosIntrVectorTable


famosFarIntrHandlerVic5:
	.word famosIntrHandlerVic5
famosFarIntrHandlerVic6:
	.word famosIntrHandlerVic6
famosFarIntrHandlerVic7:
	.word famosIntrHandlerVic7
famosFarIntrHandlerVic8:
	.word famosIntrHandlerVic8
famosFarIntrHandlerVic9:
	.word famosIntrHandlerVic9
famosFarIntrHandlerVic10:
	.word famosIntrHandlerVic10
famosFarIntrHandlerVic11:
	.word famosIntrHandlerVic11
famosFarIntrHandlerVic12:
	.word famosIntrHandlerVic12
famosFarIntrHandlerVic13:
	.word famosIntrHandlerVic13
famosFarIntrHandlerVic14:
	.word famosIntrHandlerVic14
famosFarIntrHandlerVic15:
	.word famosIntrHandlerVic15
famosFarIntrHandlerVic16:
	.word famosIntrHandlerVic16
famosFarIntrHandlerVic17:
	.word famosIntrHandlerVic17
famosFarIntrHandlerVic18:
	.word famosIntrHandlerVic18
famosFarIntrHandlerVic19:
	.word famosIntrHandlerVic19
famosFarIntrHandlerVic20:
	.word famosIntrHandlerVic20
famosFarIntrHandlerVic21:
	.word famosIntrHandlerVic21
famosFarIntrHandlerVic22:
	.word famosIntrHandlerVic22
famosFarIntrHandlerVic23:
	.word famosIntrHandlerVic23
famosFarIntrHandlerVic24:
	.word famosIntrHandlerVic24
famosFarIntrHandlerVic25:
	.word famosIntrHandlerVic25
famosFarIntrHandlerVic26:
	.word famosIntrHandlerVic26
famosFarIntrHandlerVic27:
	.word famosIntrHandlerVic27
famosFarIntrHandlerVic28:
	.word famosIntrHandlerVic28
famosFarIntrHandlerVic29:
	.word famosIntrHandlerVic29
famosFarIntrHandlerVic30:
	.word famosIntrHandlerVic30
famosFarIntrHandlerVic31:
	.word famosIntrHandlerVic31


/* V49: 21b005b0 */
FAMOS_InitInterrupts:
	stmdb	sp!, {r0, r1, r2, r3, r4, lr}

	/* Use new interrupt vector table */
	ldr	r0, famosIntrVectorAddress
	mcr	15, 0, r0, cr12, cr0, 0

	mov	r0, #5
	ldr	r1, famosFarIntrHandlerVic5
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #6
	ldr	r1, famosFarIntrHandlerVic6
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #7
	ldr	r1, famosFarIntrHandlerVic7
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #8
	ldr	r1, famosFarIntrHandlerVic8
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #9
	ldr	r1, famosFarIntrHandlerVic9
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #10
	ldr	r1, famosFarIntrHandlerVic10
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #11
	ldr	r1, famosFarIntrHandlerVic11
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #12
	ldr	r1, famosFarIntrHandlerVic12
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #13
	ldr	r1, famosFarIntrHandlerVic13
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #14
	ldr	r1, famosFarIntrHandlerVic14
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #15
	ldr	r1, famosFarIntrHandlerVic15
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #16
	ldr	r1, famosFarIntrHandlerVic16
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #17
	ldr	r1, famosFarIntrHandlerVic17
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #18
	ldr	r1, famosFarIntrHandlerVic18
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #19
	ldr	r1, famosFarIntrHandlerVic19
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #20
	ldr	r1, famosFarIntrHandlerVic20
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #21
	ldr	r1, famosFarIntrHandlerVic21
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #22
	ldr	r1, famosFarIntrHandlerVic22
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #23
	ldr	r1, famosFarIntrHandlerVic23
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #24
	ldr	r1, famosFarIntrHandlerVic24
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #25
	ldr	r1, famosFarIntrHandlerVic25
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #26
	ldr	r1, famosFarIntrHandlerVic26
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #27
	ldr	r1, famosFarIntrHandlerVic27
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #28
	ldr	r1, famosFarIntrHandlerVic28
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #29
	ldr	r1, famosFarIntrHandlerVic29
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #30
	ldr	r1, famosFarIntrHandlerVic30
	bl	FREG_VIC_SetVectaddrx

	mov	r0, #31
	ldr	r1, famosFarIntrHandlerVic31
	bl	FREG_VIC_SetVectaddrx

	ldmia	sp!, {r0, r1, r2, r3, r4, pc}


famosFarIntrFunctionTable:
	.word famosIntrFunctionTable

famosIntrHandlerReset:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	subs	r0, lr, #4
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerUndef:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip,#4]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerSwi:
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r1, r0
	mov	r0, lr
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip,#8]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerPrefetch:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip,#12]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerAbort:
	sub	lr, lr, #8
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip,#16]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerIrq:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	r0, lr
	ldr	ip, famosFarIntrFunctionTable
	ldr	ip, [ip,#24]
	cmp	ip, #0
	blxne	ip
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

famosIntrHandlerFiq:
	sub	lr, lr, #4
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, lr}
	stmdb	sp!, {r0}
	mov	r0, lr
	ldr	r7, famosFarIntrFunctionTable
	ldr	r7, [r7, #28]
	cmp	r7, #0
	blxne	r7
	ldmia	sp!, {r0}
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, pc}^


famosFarThreadPtrNew:
	.word famosThreadPtrNew

famosFarThreadPtrAct:
	.word famosThreadPtrAct

famosStartContextFirst:
	ldr	r4, famosFarThreadPtrNew
	ldr	r4, [r4]
	ldr	sp, [r4]
	b	famosRunContextNew

famosSaveContextAct:
	stmdb	sp!, {lr}
	stmdb	sp!, {lr}
	stmdb	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip}
	mrs	r0, CPSR
	stmdb	sp!, {r0}
	ldr	r0, famosFarThreadPtrAct
	ldr	r0, [r0]
	str	sp, [r0]

famosSetContextNew:
	ldr	r1, famosFarThreadPtrNew
	ldr	r2, famosFarThreadPtrAct
	ldr	r0, [r1]
	str	r0, [r2]
	ldr	sp, [r0]

famosRunContextNew:
	ldmia	sp!, {fp}
	ldmia	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl}
	mov	ip, sp
	add	sp, sp, #8
	ldmia	sp!, {lr}
	add	sp, sp, #4
	msr	CPSR_c, #210
	sub	sp, sp, #16
	stmdb	sp!, {r0, r1, r2, r3}
	add	sp, sp, #32
	msr	SPSR_fsxc, fp
	ldmia	ip, {r0, r1, r2, r3}
	stmdb	sp!, {r0, r1, r2, r3}
	sub	sp, sp, #16
	ldmia	sp!, {r0, r1, r2, r3, fp, ip, lr, pc}^

famosSwitchContextFromInterrupt:
	b famosSetContextNew

famosSwitchContextFromEvent:
	b famosSaveContextAct


.macro ARM1176_INTR_IrqHandler,irq,b=0
	stmdb	sp!, {r0}
	stmdb	sp!, {r1, r2, r3}
	mov	r1, sp
	add	sp, sp, #16
	sub	r2, lr, #4
	mrs	r3, SPSR
	msr	CPSR_c, #223
	stmdb	sp!, {r2}
	stmdb	sp!, {lr}
	stmdb	sp!, {r4, r5, r6, r7, r8, r9, sl, fp, ip}
	ldmia	r1!, {r4, r5, r6}
	stmdb	sp!, {r4, r5, r6}
	stmdb	sp!, {r0}
	stmdb	sp!, {r3}

	mov	r0, #\irq
	bl	famos_irq_entry

.if \irq == 5
	bl	famos_timer_func
.endif

	ldr	r0, 5f
	ldr	r0, [r0]
	str	sp, [r0]
	ldr	ip, 2f /* =famos_driver_isr */
	ldr	ip, [ip, #4*\irq]
	cmp	ip, #0
	beq	1f
	msr	CPSR_c, #210
	blx	ip
	msr	CPSR_c, #223
.if \irq != 5
	cmp	r0, #0
	beq	1f
	ldr	r1, 3f /* =famos_driver_bsr */
	ldr	r1, [r1, #4*\irq]
	cmp	r1, #0
	beq	1f
	ldr	ip, 4f /* =famos_bsr_flags */
	ldr	ip, [ip, #4*\irq]
	cmp	ip, #1
	blxeq	r1
	beq	1f
	mov	r2, #\irq
	bl	famos_write_bsr_fifo
.endif
1:
	mov	r0, #\irq
	bl	FREG_VIC_SetAddress

	mov	r0, #\b
	bl	famos_irq_leave

	b	famosRunContextNew
2:
	.word famos_driver_isr
3:
	.word famos_driver_bsr
4:
	.word famos_bsr_flags
5:
	.word famosThreadPtrAct
.endm

famosIntrHandlerVic5:
	ARM1176_INTR_IrqHandler 5,1

famosIntrHandlerVic6:
	ARM1176_INTR_IrqHandler 6

famosIntrHandlerVic7:
	ARM1176_INTR_IrqHandler 7

famosIntrHandlerVic8:
	ARM1176_INTR_IrqHandler 8

famosIntrHandlerVic9:
	ARM1176_INTR_IrqHandler 9

famosIntrHandlerVic10:
	ARM1176_INTR_IrqHandler 10,1

famosIntrHandlerVic11:
	ARM1176_INTR_IrqHandler 11,1

famosIntrHandlerVic12:
	ARM1176_INTR_IrqHandler 12,1

famosIntrHandlerVic13:
	ARM1176_INTR_IrqHandler 13,1

famosIntrHandlerVic14:
	ARM1176_INTR_IrqHandler 14,1

famosIntrHandlerVic15:
	ARM1176_INTR_IrqHandler 15,1

famosIntrHandlerVic16:
	ARM1176_INTR_IrqHandler 16,1

famosIntrHandlerVic17:
	ARM1176_INTR_IrqHandler 17,1

famosIntrHandlerVic18:
	ARM1176_INTR_IrqHandler 18

famosIntrHandlerVic19:
	ARM1176_INTR_IrqHandler 19

famosIntrHandlerVic20:
	ARM1176_INTR_IrqHandler 20,1

famosIntrHandlerVic21:
	ARM1176_INTR_IrqHandler 21,1

famosIntrHandlerVic22:
	ARM1176_INTR_IrqHandler 22,1

famosIntrHandlerVic23:
	ARM1176_INTR_IrqHandler 23

famosIntrHandlerVic24:
	ARM1176_INTR_IrqHandler 24,1

famosIntrHandlerVic25:
	ARM1176_INTR_IrqHandler 25,1

famosIntrHandlerVic26:
	ARM1176_INTR_IrqHandler 26,1

famosIntrHandlerVic27:
	ARM1176_INTR_IrqHandler 27,1

famosIntrHandlerVic28:
	ARM1176_INTR_IrqHandler 28,1

famosIntrHandlerVic29:
	ARM1176_INTR_IrqHandler 29,1

famosIntrHandlerVic30:
	ARM1176_INTR_IrqHandler 30,1

famosIntrHandlerVic31:
	ARM1176_INTR_IrqHandler 31


famosBreakPoint:
	bkpt	0x00ff
	b 	famosBreakPoint


