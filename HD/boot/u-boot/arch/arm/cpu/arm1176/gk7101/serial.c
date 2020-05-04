#include <common.h>
#include <watchdog.h>
#include <serial.h>
#include <asm/global_data.h>
#include <linux/compiler.h>
#include <asm/arch/serial.h>

#define CONSOLE_PORT CONFIG_CONS_INDEX
#define NUM_PORTS (sizeof(port)/sizeof(port[0]))
DECLARE_GLOBAL_DATA_PTR;

static void gk7101_putc (int portnum, char c);
static int gk7101_getc (int portnum);
static int gk7101_tstc (int portnum);
unsigned int baudrate = CONFIG_BAUDRATE;

static struct gk7101_regs port[] =
{
    [0] = {
              UART0_RB_REG,
              UART0_TH_REG,
              UART0_DLL_REG,
              UART0_IE_REG,
              UART0_DLH_REG,
              UART0_II_REG,
              UART0_FC_REG,
              UART0_LC_REG,
              UART0_MC_REG,
              UART0_LS_REG,
              UART0_MS_REG,
           },
};

static void uartSetBaudrate(struct gk7101_regs *regs, u32 baudRate)
{
    u32 brdi;

    gk_rct_writel(REG_PLL_SCALER_UART,0x1);

    brdi = UART_BASE_FREQ * 10 / baudRate / 16;
    if (brdi % 10 >= 5)
        brdi = (brdi / 10) + 1;
    else
        brdi = (brdi / 10);

    gk_uart_writel(regs->reg_lc,UART_LC_DLAB);
    gk_uart_writel(regs->reg_dll,brdi & 0xff);
    gk_uart_writel(regs->reg_dlh,(brdi >> 8) & 0xff);
    gk_uart_writel(regs->reg_lc,0);
}

static struct gk7101_regs *gk7101_get_regs(int portnum)
{
    struct gk7101_regs * regs = &port[portnum];
	return regs;
}


int serial_init(void)
{
	struct gk7101_regs *regs = gk7101_get_regs(CONSOLE_PORT);
	unsigned int lcr;
    unsigned int ier;
    unsigned int fcr;

    gk_uart_writel(REG_INTERRUPT_IDENTITY,0x00);

    uartSetBaudrate(regs, baudrate);
    lcr = UART_LC_CLS_8_BITS | UART_LC_STOP_1BIT | UART_LC_ODD_PARITY;
    gk_uart_writel(regs->reg_lc,lcr);
    gk_uart_writel(regs->reg_mc,DEFAULT_UART_MCR);
    ier = DEFAULT_UART_IER;
    gk_uart_writel(regs->reg_ie,ier | UART_IE_PTIME);
    fcr = DEFAULT_UART_FCR;
    gk_uart_writel(regs->reg_fc,fcr | UART_FC_XMITR | UART_FC_RCVRR);
    gk_uart_writel(regs->reg_ie,ier);

	return 0;
}

void serial_putc(const char c)
{
	if (c == '\n')
		gk7101_putc (CONSOLE_PORT, '\r');

	gk7101_putc (CONSOLE_PORT, c);
}

void serial_puts (const char *s)
{
	while (*s) {
		serial_putc (*s++);
	}
}

int serial_getc(void)
{
	return gk7101_getc (CONSOLE_PORT);
}

int serial_tstc(void)
{
	return gk7101_tstc (CONSOLE_PORT);
}

void serial_setbrg(void)
{
	struct gk7101_regs *regs = gk7101_get_regs(CONSOLE_PORT);

	baudrate = gd->baudrate;

	while (!gk_uart_readl(regs->reg_ls));

	serial_init();
}

static void gk7101_putc (int portnum, char c)
{
	struct gk7101_regs *regs = gk7101_get_regs(portnum);

    /*use readl/writel for output speed*/
	while (!(readl(regs->reg_ls-0x30000000) & UART_LS_TEMT));
    writel(c, regs->reg_th-0x30000004);
}

static int gk7101_getc (int portnum)
{
	struct gk7101_regs *regs = gk7101_get_regs(portnum);
	unsigned int data;

	while (!(gk_uart_readl(regs->reg_ls) & UART_LS_DR));

	data = gk_uart_readl(regs->reg_rb);

	return (int) data;
}

static int gk7101_tstc (int portnum)
{
	struct gk7101_regs *regs = gk7101_get_regs(portnum);
	return (gk_uart_readl(regs->reg_ls) & UART_LS_DR);
}

