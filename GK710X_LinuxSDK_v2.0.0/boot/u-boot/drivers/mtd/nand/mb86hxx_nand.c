/*
 *  drivers/mtd/mb86h61_nand.c
 *
 *  Copyright (c) 2011 Fujitsu Semiconductor ShangHai
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>

#include <nand.h>
#include <asm/arch/mb86hxx.h>
#include <asm/arch/upi.h>
#include <asm/io.h>
#include <asm/errno.h>


/* UPI Device Config Register Base */
#define MB86H61_UPI0_CONFIG_BASE        (MB86HXX_UPI_BASE + 0x18000000)
#define MB86H61_UPI1_CONFIG_BASE        (MB86HXX_UPI_BASE + 0x18000040)
#define MB86H61_UPI2_CONFIG_BASE        (MB86HXX_UPI_BASE + 0x18000080)

#ifdef CONFIG_MB86H61_NAND_UPI0
	#define MB86H61_NAND_BASE            MB86HXX_UPI_BASE
#endif
#ifdef CONFIG_MB86H61_NAND_UPI1
	#define MB86H61_NAND_BASE           (MB86HXX_UPI_BASE + 0x08000000)
#endif
#ifdef CONFIG_MB86H61_NAND_UPI2
	#define MB86H61_NAND_BASE           (MB86HXX_UPI_BASE + 0x10000000)
#endif

static void __iomem *mb86h61_nand_base;

static struct nand_ecclayout nand_oob_224 = {
	.eccbytes = 48,
		#if 1
	.eccpos = {
				   176, 177, 178, 179, 180, 181, 182, 183,
				   184, 185, 186, 187, 188, 189, 190, 191,
				   192, 193, 194, 195, 196, 197, 198, 199,
				   200, 201, 202, 203, 204, 205, 206, 207,
				   208, 209, 210, 211, 212, 213, 214, 215,
				   216, 217, 218, 219, 220, 221, 222, 223
			   },
	         #endif
		 #if 0
	.eccpos = { 0,1,2,3,4,5,6,7,
			   8,9,10,11,12,13,14,15,
			   16,17,18,19,20,21,22,23,
			   24,25,26,27,28,29,30,31,
			   32,33,34,35,36,37,38,39,
			   40,41,42,43,44,45,46,47
	         	  },
		#endif
	.oobfree = {
			   	{
				   	.offset = 2,
					.length = 174
				}
			   }
};

#ifdef CONFIG_NAND_SPL
static u_char nand_read_byte(struct mtd_info *mtd);
static void nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len);
static void nand_read_buf(struct mtd_info *mtd, u_char *buf, int len);
#endif

/**
 * nand_command - [DEFAULT] Send command to NAND device
 * @mtd:	MTD device structure
 * @command:	the command to be sent
 * @column:	the column address for this command, -1 if none
 * @page_addr:	the page address for this command, -1 if none
 *
 * Send command to NAND device. This function is used for small page
 * devices (256/512 Bytes per page)
 */
static void mb86h61_nand_command(struct mtd_info *mtd, unsigned int command,
			 int column, int page_addr)
{
	register struct nand_chip *chip = mtd->priv;
	int ctrl = NAND_CTRL_CLE | NAND_CTRL_CHANGE;
	/*
	 * Write out the command to the device.
	 */
	if (command == NAND_CMD_SEQIN) {
		int readcmd;

		if (column >= mtd->writesize) {
			/* OOB area */
			column -= mtd->writesize;
			readcmd = NAND_CMD_READOOB;
		} else if (column < 256) {
			/* First 256 bytes --> READ0 */
			readcmd = NAND_CMD_READ0;
		} else {
			column -= 256;
			readcmd = NAND_CMD_READ1;
		}
		chip->cmd_ctrl(mtd, readcmd, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
	}
	chip->cmd_ctrl(mtd, command, ctrl);

	/*
	 * Address cycle, when necessary
	 */
	ctrl = NAND_CTRL_ALE | NAND_CTRL_CHANGE;
	/* Serially input address */
	if (column != -1) {
		/* Adjust columns for 16 bit buswidth */
		if (chip->options & NAND_BUSWIDTH_16)
			column >>= 1;
		chip->cmd_ctrl(mtd, column, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
	}
	if (page_addr != -1) {
		chip->cmd_ctrl(mtd, page_addr, ctrl);
		ctrl &= ~NAND_CTRL_CHANGE;
		chip->cmd_ctrl(mtd, page_addr >> 8, ctrl);
		/* One more address cycle for devices > 32MiB */
		if (chip->chipsize > (32 << 20))
			chip->cmd_ctrl(mtd, page_addr >> 16, ctrl);
	}
	chip->cmd_ctrl(mtd, NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);

	/*
	 * program and erase have their own busy handlers
	 * status and sequential in needs no delay
	 */
	switch (command) {

	case NAND_CMD_PAGEPROG:
	case NAND_CMD_ERASE1:
	case NAND_CMD_ERASE2:
	case NAND_CMD_SEQIN:
	case NAND_CMD_STATUS:
		return;

	case NAND_CMD_RESET:
		if (chip->dev_ready)
			break;
		udelay(chip->chip_delay);
		chip->cmd_ctrl(mtd, NAND_CMD_STATUS,
			       NAND_CTRL_CLE | NAND_CTRL_CHANGE);
		chip->cmd_ctrl(mtd,
			       NAND_CMD_NONE, NAND_NCE | NAND_CTRL_CHANGE);
		while (!(chip->read_byte(mtd) & NAND_STATUS_READY)) ;
		return;

		/* This applies to read commands */
	default:
		/*
		 * If we don't have access to the busy pin, we apply the given
		 * command delay
		 */
		if (!chip->dev_ready) {
			udelay(chip->chip_delay);
			return;
		}
	}
	/* Apply this short delay always to ensure that we do wait tWB in
	 * any case on any machine. */
	ndelay(100);

	nand_wait_ready(mtd);
}
static inline void mb86h61_upi_nand_init(void)
{
#ifdef CONFIG_MB86H61_NAND_UPI0
	unsigned long base = MB86H61_UPI0_CONFIG_BASE;
#endif
#ifdef CONFIG_MB86H61_NAND_UPI1
	unsigned long base = MB86H61_UPI1_CONFIG_BASE;
#endif
#ifdef CONFIG_MB86H61_NAND_UPI2
	unsigned long base = MB86H61_UPI2_CONFIG_BASE;
#endif
	writel(134, MB86HXX_GPIO_BASE+4*6	); /*configure GPIO 6 as CLE*/
	writel(1, MB86HXX_GPIO_BASE+4*66	);     /*configure GPIO 66 as CS */
	writel(1, MB86HXX_GPIO_BASE+4*68     ); /*configure GPIO 68 as CS */

	/* initialize UPI */
	writel(UPI_MODE_PARAM, 		base + 	MB86H61_UPI_MODE_OFFSET);
	writel(UPI_TALS_PARAM, 		base + 	MB86H61_UPI_TALS_OFFSET);
	writel(UPI_TALH_PARAM, 		base + 	MB86H61_UPI_TALH_OFFSET);
	writel(UPI_TRS_PARAM, 		base + 	MB86H61_UPI_TRS_OFFSET);
	writel(UPI_TRDS_PARAM,		base + 	MB86H61_UPI_TRDS_OFFSET);
	writel(UPI_TRDH_PARAM, 		base + 	MB86H61_UPI_TRDH_OFFSET);
	writel(UPI_TRR_PARAM, 		base + 	MB86H61_UPI_TRR_OFFSET);
	writel(UPI_TWS_PARAM, 		base + 	MB86H61_UPI_TWS_OFFSET);
	writel(UPI_TWP_PARAM, 		base + 	MB86H61_UPI_TWP_OFFSET);
	writel(UPI_TWR_PARAM, 		base + 	MB86H61_UPI_TWR_OFFSET);
	writel(UPI_WMMASK_PARAM, 	base + 	MB86H61_UPI_WMMASK_OFFSET);
	writel(UPI_BUFEN_PARAM, 	base + 	MB86H61_UPI_BUFEN_OFFSET);

	writel(UPI_ADDREXT_PARAM, 	MB86H61_UPI_ADDREXT);
	writel(UPI_CSSEL_PARAM, 	MB86H61_UPI_CSSEL);
	writel(UPI_CSMODE_PARAM, 	MB86H61_UPI_CSMODE);

	writel(UPI_WAIT_TIME_PARAM, 	MB86H61_UPI_WAIT_TIME);
	writel(UPI_WAIT_TIME_EN_PARAM, 	MB86H61_UPI_WAIT_TIME_EN);

}

/*	hardware specific access to control-lines
 *
 */
static void mb86h61_hwcontrol(struct mtd_info *mtd, int cmd,unsigned int ctrl)
{
	struct nand_chip *chip = mtd->priv;

	if(ctrl & NAND_CTRL_CHANGE)
	{
		if((ctrl & NAND_CTRL_CLE) == NAND_CTRL_CLE)
			chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_CMD_OFFSET;
		else if((ctrl & NAND_CTRL_ALE) == NAND_CTRL_ALE)
			chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_ADDR_OFFSET;
		else
			chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_DATA_OFFSET;
	}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, chip->IO_ADDR_W);
}

static int mb86h61_nand_device_ready(struct mtd_info *mtd)
{
	unsigned int gpio;
	gpio = *((volatile unsigned int*)(MB86HXX_GPIO_BASE+0x504));
	return (gpio>>8)&0x1;
}

static void mb86h61_select_chip(struct mtd_info *mtd,int chip_nr)
{
	int i;

	if(chip_nr == -1)
	{
		writel(1, MB86HXX_GPIO_BASE+4*66	);   /*CS disable*/
	}
	else
	{
		writel(0, MB86HXX_GPIO_BASE+4*66	);   /*CS enable*/
	}
	for(i=0;i<2000;i++);
}

/*
 * Board-specific NAND initialization. The following members of the
 * argument are board-specific (per include/linux/mtd/nand.h):
 * - IO_ADDR_R?: address to read the 8 I/O lines of the flash device
 * - IO_ADDR_W?: address to write the 8 I/O lines of the flash device
 * - hwcontrol: hardwarespecific function for accesing control-lines
 * - dev_ready: hardwarespecific function for  accesing device ready/busy line
 * - enable_hwecc?: function to enable (reset)  hardware ecc generator. Must
 *   only be provided if a hardware ECC is available
 * - eccmode: mode of ecc, see defines
 * - chip_delay: chip dependent delay for transfering data from array to
 *   read regs (tR)
 * - options: various chip options. They can partly be set to inform
 *   nand_scan about special functionality. See the defines for further
 *   explanation
 * Members with a "?" were not set in the merged testing-NAND branch,
 * so they are not set here either.
 */
int board_nand_init(struct nand_chip *nand)
{
	mb86h61_upi_nand_init();

	mb86h61_nand_base = (void __iomem *)MB86H61_NAND_BASE;

	/* Set address of NAND IO lines */
	nand->IO_ADDR_R = mb86h61_nand_base + MB86H61_NAND_DATA_OFFSET;
	nand->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_DATA_OFFSET;
	nand->cmd_ctrl = mb86h61_hwcontrol;
	nand->select_chip = mb86h61_select_chip;
	nand->dev_ready = NULL;//mb86h61_nand_device_ready;
	nand->cmdfunc =NULL;//mb86h61_nand_command;
	/* 50 us command delay time */
	nand->chip_delay = 50;
	nand->options		= 	NAND_USE_FLASH_BBT;


#ifdef CONFIG_NAND_SPL
	nand->read_byte		= nand_read_byte;
	nand->write_buf		= nand_write_buf;
	nand->read_buf		= nand_read_buf;
#endif

#ifdef CONFIG_SYS_MB86H6XX_NAND_HWECC
	nand->ecc.hwctl		= s3c_nand_enable_hwecc;
	nand->ecc.calculate	= s3c_nand_calculate_ecc;
	nand->ecc.correct	= s3c_nand_correct_data;

	/*
	 * If you get more than 1 NAND-chip with different page-sizes on the
	 * board one day, it will get more complicated...
	 */
	nand->ecc.mode		= NAND_ECC_HW;
	nand->ecc.size		= CONFIG_SYS_NAND_ECCSIZE;
	nand->ecc.bytes		= CONFIG_SYS_NAND_ECCBYTES;
#else
	nand->ecc.mode		= NAND_ECC_SOFT;
#endif /* ! CONFIG_SYS_S3C_NAND_HWECC */
	return 0;
	//nand->badblock_pattern = &largepage_memorybased;
}
#ifdef CONFIG_NAND_SPL
static u_char nand_read_byte(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv;
	return readb(this->IO_ADDR_R);
}

static void nand_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
	int i;
	struct nand_chip *this = mtd->priv;

	for (i = 0; i < len; i++)
		writeb(buf[i], this->IO_ADDR_W);
}

static void nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
	int i;
	struct nand_chip *this = mtd->priv;

	for (i = 0; i < len; i++)
		buf[i] = readb(this->IO_ADDR_R);
}
#endif
static int mb86hxx_nand_device_ready(struct mtd_info *mtdinfo)
{
	unsigned int gpio;
	gpio = *((volatile unsigned int*)(MB86HXX_GPIO_BASE+0x504));
	return (gpio>>8)&0x1;
}
static void mb86hxx_nand_hwcontrol(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
	struct nand_chip *chip = mtd->priv;
	if(ctrl & NAND_CTRL_CHANGE)
	{
	if((ctrl & NAND_CTRL_CLE) == NAND_CTRL_CLE)
		chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_CMD_OFFSET;
	else if((ctrl & NAND_CTRL_ALE) == NAND_CTRL_ALE)
		chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_ADDR_OFFSET;
	else
		chip->IO_ADDR_W = mb86h61_nand_base + MB86H61_NAND_DATA_OFFSET;
}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, chip->IO_ADDR_W);

}

