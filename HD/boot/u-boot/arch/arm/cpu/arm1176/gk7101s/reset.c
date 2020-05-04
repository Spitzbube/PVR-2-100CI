#include <asm/arch/gk7101_reg.h>
#include <asm/arch/io.h>

void reset_cpu(void)
{
    gk_wdt_writel(REG_WDT_RELOAD, 0xFF);
    gk_wdt_writel(REG_WDT_RESTART, 0x4755);
    gk_wdt_writel(REG_WDT_CTRL, 0x5);

	while(1) {
		;
	}
}
