#include <common.h>

#define INTR_COUNT                32 //!< max. number of interrupts

#define REG_VIC_ADDRESS                                    0xE0000F00UL
#define REG_VIC_VECT0_ADDR                                 0xE0000100UL
#define REG_VIC_VECT0_PRIORITY                             0xE0000200UL
#define REG_IRQ_CTRL_ARMIRQMASK                            0xCF000300UL
#define REG_IRQ_CTRL_ARMIRQXOR                             0xCF000304UL
#define REG_VIC_INTENABLE                                  0xE0000010UL
#define REG_VIC_INTSELECT                                  0xE000000CUL

static uint32_t REG_VIC_GetAddress( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(REG_VIC_ADDRESS));
    return( value );
}
static void REG_VIC_SetAddress( uint32_t value )
{
    *((volatile uint32_t*)(REG_VIC_ADDRESS)) = value;
}
static uint32_t REG_IRQ_CTRL_GetArmirqmask( void )
{
    register uint32_t value;
    value = *((volatile uint32_t*)(REG_IRQ_CTRL_ARMIRQMASK));
    return( value );
}
static void REG_IRQ_CTRL_SetArmirqxor( uint32_t value )
{
    *((volatile uint32_t*)(REG_IRQ_CTRL_ARMIRQXOR)) = value;
}

static void REG_IRQ_CTRL_SetArmirqmask( uint32_t value )
{
    *((volatile uint32_t*)(REG_IRQ_CTRL_ARMIRQMASK)) = value;
}
static void REG_VIC_SetVectAddr( uint32_t blockIndex, uint32_t value )
{
    *((volatile uint32_t*)(REG_VIC_VECT0_ADDR+(blockIndex*0x4))) = value;
}
static void REG_VIC_SetVectPriority( uint32_t blockIndex, uint32_t value )
{
    *((volatile uint32_t*)(REG_VIC_VECT0_PRIORITY+(blockIndex*0x4))) = value;
}
static void REG_VIC_SetIntenable( uint32_t value )
{
    *((volatile uint32_t*)(REG_VIC_INTENABLE)) = value;
}
static void REG_VIC_SetIntselect( uint32_t value )
{
    *((volatile uint32_t*)(REG_VIC_INTSELECT)) = value;
}


void do_irq(struct pt_regs *pt_regs)
{
	uint32_t (*irqFunc)(void);

	irqFunc = (void *)REG_VIC_GetAddress();

	if (irqFunc)
	{
		irqFunc();
	}
	REG_VIC_SetAddress((uint32_t)NULL);
}

void register_irq(uint32_t irqNo, uint32_t (*irqFunc)(void))
{
	uint32_t armirqmask = 0;

	REG_VIC_SetVectAddr(irqNo, (uint32_t)irqFunc);
	REG_VIC_SetVectPriority(irqNo, 0xf);

	armirqmask = REG_IRQ_CTRL_GetArmirqmask();
	armirqmask |= (1 << irqNo);
	REG_IRQ_CTRL_SetArmirqmask(armirqmask);
}

void unregister_irq(uint32_t irqNo)
{
	uint32_t armirqmask = 0;

	armirqmask = REG_IRQ_CTRL_GetArmirqmask();
	armirqmask &= ~(1 << irqNo);
	REG_IRQ_CTRL_SetArmirqmask(armirqmask);

	REG_VIC_SetVectAddr(irqNo, (uint32_t)NULL);
	REG_VIC_SetVectPriority(irqNo, 0xf);
}

int arch_interrupt_init(void)
{
	int i;

	/* install default interrupt handlers */
	for (i = 0; i < INTR_COUNT; i++)
	{
		REG_VIC_SetVectAddr(i, (uint32_t)NULL);
		REG_VIC_SetVectPriority(i, 0xf);
	}

	REG_IRQ_CTRL_SetArmirqmask(0x00000000UL);
	REG_IRQ_CTRL_SetArmirqxor(0x00000000UL);
	REG_VIC_SetIntenable(0xFFFFFFFFUL);
	REG_VIC_SetIntselect(0x00000000UL);

	return 0;
}


