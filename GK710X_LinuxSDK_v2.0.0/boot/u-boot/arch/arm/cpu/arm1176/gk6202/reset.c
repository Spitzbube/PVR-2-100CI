#include <common.h>
#include <asm/arch/gk6202.h>

#define iowrite32(val, addr) (*(volatile unsigned int *)(addr) = (val))
#define ioread32(addr) (*(volatile unsigned int *)(addr))
#define set_bit(val, addr) iowrite32(ioread32(addr)|(val),addr)
#define clear_bit(val, addr) iowrite32(ioread32(addr)& ~(val),addr)

void reset_cpu(ulong addr)
{
	clear_bit(1 << 4, GK6202_PWM_SYS_BASE);
	udelay(10);
	set_bit(1 << 4, GK6202_PWM_SYS_BASE);	/* rising edge, reset system */

	while (1)
	/* forever */ ;
}
