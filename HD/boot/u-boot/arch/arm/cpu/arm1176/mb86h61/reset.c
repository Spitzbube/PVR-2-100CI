#include "asm/arch/mb86hxx.h"
#include "asm/arch/clkpwr.h"

#define iowrite32(val, addr) (*(volatile unsigned int *)(addr) = (val))
#define ioread32(addr) (*(volatile unsigned int *)(addr))

void reset_cpu(void)
{
    iowrite32(WATCHDOG_MASK, MB86HXX_CLKPWR_BASE+CLKPWR_WATCHDOG);

	while (1)
		0 /* forever */ ;
}
