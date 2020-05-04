/*
 * arch/arm/mach-gk7101/gpio.c
 *
 * History:
 *
 *  2014/09/18 - [Kewell Liu] created file
 *
 * Copyright (C) 2004-2014, Goke, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <common.h>
#include <config.h>
#include <errno.h>
#include <asm/arch-gk7101s/io.h>
#include <asm/arch-gk7101s/gpio.h>


static int init_tag = 0;

static void gk7101_gpio_get_outcfg(u32 gpioid, u32* pvalue)
{
    *pvalue = gk_gpio_readl(GPIO0_OUTPUT_CFG_REG + (gpioid << 2));
}

static void gk7101_gpio_set_outcfg(u32 gpioid, u32 value)
{
    gk_gpio_writel((GPIO0_OUTPUT_CFG_REG + (gpioid << 2)), value);
}

static void gk7101_gpio_get_incfg(u32 value, u32* pgpioid)
{
    *pgpioid = gk_gpio_readl(GPIO0_INPUT_CFG_REG + (value << 2));
}

void gk7101_gpio_set_incfg(u32 value, u32 gpioid)
{
    gk_gpio_writel((GPIO0_INPUT_CFG_REG + (value << 2)), gpioid);
}
static void gk7101_get_pll_ioctl_gpio(u32 gpioid, u32* pvalue)
{
    *pvalue = gk_rct_readl(REG_PLL_IOCTRL_GPIO + (gpioid << 2));
}

static void gk7101_set_pll_ioctl_gpio(u32 gpioid, u32 value)
{
    gk_rct_writel((REG_PLL_IOCTRL_GPIO + (gpioid << 2)), value);
}
static void gk7101_gpio_set_out(u32 gpioid, u32 value)
{
    if (value == GPIO_LOW) {
        gk_gpio_clrbitsl((GPIO0_OUTPUT_CFG_REG + (gpioid << 2)), 1);
    } else {
        gk_gpio_setbitsl((GPIO0_OUTPUT_CFG_REG + (gpioid << 2)), 1);
    }
}

static int gk7101_gpio_func_config(u32 gpioid, u32 gtype)
{
    int             retval = 0;
    unsigned int    inreg = 0, outreg = 0;
	PLL_IOCTRL_GPIO_S ioctl;
    // write only registry
    //gk7101_gpio_get_incfg(gpioid, &inreg);
    //gk7101_gpio_get_outcfg(gpioid, &outreg);

    if((GPIO_GET_FUNC(gtype) > GPIO_FUNC_INOUT) || (gtype == GPIO_TYPE_UNDEFINED))
    {
		if(0 != init_tag)
        	printf("%s: invalid GPIO func %d for GPIO:%d.\n", __func__, gtype, gpioid);
        return -EINVAL;
    }

    if(GPIO_GET_IN_SEL(gtype) >= 2)
    {
        inreg &= (~REG_CONFIG_IN_OUT_SEL);
        inreg |= (GPIO_GET_IN_SEL(gtype) - 2);
    }

    outreg &= (~(REG_OUTCFG_OEN_SELECT | REG_CONFIG_IN_OUT_SEL));
    outreg |= (GPIO_GET_OUT_SEL(gtype) | (GPIO_GET_OEN_SEL(gtype) << 8));

    if(GPIO_GET_OEN_INVERT(gtype))
    {
        outreg |= (GPIO_GET_OEN_INVERT(gtype) << 15);
    }
    outreg |= (GPIO_GET_OUT_INVERT(gtype) << 14);

    if(GPIO_GET_FUNC(gtype) != GPIO_FUNC_OUT)
    {
		if(0 != init_tag)
			printf("%s: Input GPIO:%d.\n", __func__, gpioid);
        // must >=2 can set
		if(GPIO_GET_IN_SEL(gtype) >= 2)
		{
            gk7101_gpio_set_incfg((GPIO_GET_IN_SEL(gtype) - 2), gpioid);
		}
    }

    gk7101_gpio_set_outcfg(gpioid, outreg);

    if(GPIO_GET_IOCTRL(gtype))
    {
        if(gpioid<4)//gpio0-3
        {
            gk7101_get_pll_ioctl_gpio((55-gpioid)/4, (u32 *)&(ioctl.all));
            switch(gpioid%4)
            {
            case 0:
                ioctl.bitc.io2 = GPIO_GET_IOCTRL(gtype);
                break;
            case 1:
                ioctl.bitc.io0 = GPIO_GET_IOCTRL(gtype);
                break;
            case 2:
                ioctl.bitc.io1 = GPIO_GET_IOCTRL(gtype);
                break;
            case 3:
                ioctl.bitc.io3 = GPIO_GET_IOCTRL(gtype);
                break;
            }
            gk7101_set_pll_ioctl_gpio((55-gpioid)/4, ioctl.all);
        }
        else if(gpioid<52)//gpio4-51
        {
            gk7101_get_pll_ioctl_gpio((55-gpioid)/4, (u32 *)&(ioctl.all));
            switch(gpioid%4)
            {
            case 0:
                ioctl.bitc.io1 = GPIO_GET_IOCTRL(gtype);
                break;
            case 1:
                ioctl.bitc.io2 = GPIO_GET_IOCTRL(gtype);
                break;
            case 2:
                ioctl.bitc.io0 = GPIO_GET_IOCTRL(gtype);
                break;
            case 3:
                ioctl.bitc.io3 = GPIO_GET_IOCTRL(gtype);
                break;
            }
            gk7101_set_pll_ioctl_gpio((55-gpioid)/4, ioctl.all);
        }
        else if(gpioid<56)//gpio52-55
        {
            gk7101_get_pll_ioctl_gpio((55-gpioid)/4, (u32 *)&(ioctl.all));
            switch(gpioid%4)
            {
            case 0:
                ioctl.bitc.io1 = GPIO_GET_IOCTRL(gtype);
                break;
            case 1:
                ioctl.bitc.io0 = GPIO_GET_IOCTRL(gtype);
                break;
            case 2:
                ioctl.bitc.io2 = GPIO_GET_IOCTRL(gtype);
                break;
            case 3:
                ioctl.bitc.io3 = GPIO_GET_IOCTRL(gtype);
                break;
            }
            gk7101_set_pll_ioctl_gpio((55-gpioid)/4, ioctl.all);
        }
        else//gpio56-62
        {
            gk7101_get_pll_ioctl_gpio(gpioid/4, (u32 *)&(ioctl.all));
            switch(gpioid%4)
            {
            case 0:
                ioctl.bitc.io0 = GPIO_GET_IOCTRL(gtype);
                break;
            case 1:
                ioctl.bitc.io1 = GPIO_GET_IOCTRL(gtype);
                break;
            case 2:
                ioctl.bitc.io2 = GPIO_GET_IOCTRL(gtype);
                break;
            case 3:
                ioctl.bitc.io3 = GPIO_GET_IOCTRL(gtype);
                break;
            }
            gk7101_set_pll_ioctl_gpio(gpioid/4, ioctl.all);
        }
    }

    return retval;

}

static  void gk7101_gpio_inline_set(u32 offset, int value)
{
    gk7101_gpio_set_out(offset, value);
}

static  int gk7101_gpio_inline_get(u32 offset)
{
    u32 val = 0, gpioid;


    if(offset <= 31)
    {
        val = gk_gpio_readl(GPIO0_BASE + GPIO_DIN_LOW_OFFSET);
        gpioid = offset;
    }
    else
    {
        gpioid = offset - 32;
        val = gk_gpio_readl(GPIO0_BASE + GPIO_DIN_HIGH_OFFSET);
    }

    val = (val >> gpioid) & 0x1;
    return (val ? GPIO_HIGH : GPIO_LOW);

}

void gk7101_gpio_config(int id, u32 func)
{
	if(id > GPIO_TOTAL_NUM){
		if(0 != init_tag)
			printf("%s: Invalid argument\n",  __func__);
		return;
	}

    if(gk7101_gpio_func_config((u32)id, func))
    {
		if(0 != init_tag)
        	printf("%s: failed to configure GPIO %d for func %d.\n", __func__, id, func);
    }
}

void gk7101_gpio_set(int id, int value)
{
	if(id > GPIO_TOTAL_NUM){
		printf("%s: Invalid argument\n",  __func__);
		return;
	}

    gk7101_gpio_inline_set((u32)id, value);
}

int gk7101_gpio_get(int id)
{
	if(id > GPIO_TOTAL_NUM){
		printf("%s: Invalid argument\n",  __func__);
		return 0;
	}

    return gk7101_gpio_inline_get((u32)id);
}

/* ==========================================================================*/
int gk7101_set_gpio_output(struct gk7101_gpio_io_info *pinfo, u32 on)
{
    int                 retval = 0;

    if (pinfo == NULL) {
        printf("%s: pinfo is NULL.\n", __func__);
        retval = -1;
        goto gk7101_set_gpio_output_can_sleep_exit;
    }
    if (pinfo->gpio_id < 0 ) {
        printf("%s: wrong gpio id %d.\n", __func__, pinfo->gpio_id);
        retval = -1;
        goto gk7101_set_gpio_output_can_sleep_exit;
    }

    if (pinfo->gpio_id >= GPIO_TOTAL_NUM)
    {
        printf("%s: try expander gpio id %d.\n",
            __func__, pinfo->gpio_id);
        retval = -1;
        goto gk7101_set_gpio_output_can_sleep_exit;
    }
    else
    {
       if (on) {
			gk7101_gpio_config(pinfo->gpio_id, GPIO_TYPE_OUTPUT_1);
        } else {
			gk7101_gpio_config(pinfo->gpio_id, GPIO_TYPE_OUTPUT_0);
        }
    }
    mdelay(pinfo->active_delay);

gk7101_set_gpio_output_can_sleep_exit:
    return retval;
}

u32 gk7101_get_gpio_input(struct gk7101_gpio_io_info *pinfo)
{
    u32                 gpio_value = 0;

    if (pinfo == NULL) {
        printf("%s: pinfo is NULL.\n", __func__);
        goto gk7101_get_gpio_input_can_sleep_exit;
    }
    if (pinfo->gpio_id < 0 ) {
        printf("%s: wrong gpio id %d.\n", __func__, pinfo->gpio_id);
        goto gk7101_get_gpio_input_can_sleep_exit;
    }

    if (pinfo->gpio_id >= GPIO_TOTAL_NUM) {
        printf("%s: try expander gpio id %d.\n",
            __func__, pinfo->gpio_id);
        goto gk7101_get_gpio_input_can_sleep_exit;
    }else {
        gk7101_gpio_config(pinfo->gpio_id, GPIO_TYPE_INPUT_0);
            mdelay(pinfo->active_delay);
        gpio_value = gk7101_gpio_get(pinfo->gpio_id);
    }

    printf("%s: {gpio[%d], level[%s], delay[%dms]} get[%d].\n",
        __func__, pinfo->gpio_id,
        pinfo->active_level ? "HIGH" : "LOW",
        pinfo->active_delay, gpio_value);

gk7101_get_gpio_input_can_sleep_exit:
    return (gpio_value == pinfo->active_level) ? 1 : 0;
}

int gk7101_set_gpio_reset(struct gk7101_gpio_io_info *pinfo)
{
    int                 retval = 0;

    if (pinfo == NULL) {
        printf("%s: pinfo is NULL.\n", __func__);
        retval = -1;
        goto gk7101_set_gpio_reset_can_sleep_exit;
    }
    if (pinfo->gpio_id < 0 ) {
        printf("%s: wrong gpio id %d.\n", __func__, pinfo->gpio_id);
        retval = -1;
        goto gk7101_set_gpio_reset_can_sleep_exit;
    }

    printf("%s: Reset gpio[%d], level[%s], delay[%dms].\n",
        __func__, pinfo->gpio_id,
        pinfo->active_level ? "HIGH" : "LOW",
        pinfo->active_delay);
    if (pinfo->gpio_id >= GPIO_TOTAL_NUM) {
        printf("%s: try expander gpio id %d.\n",
            __func__, pinfo->gpio_id);
        retval = -1;
        goto gk7101_set_gpio_reset_can_sleep_exit;
    } else {
        gk7101_gpio_config(pinfo->gpio_id, GPIO_TYPE_OUTPUT_0);
        gk7101_gpio_set(pinfo->gpio_id, pinfo->active_level);
        mdelay(pinfo->active_delay);
        gk7101_gpio_set(pinfo->gpio_id, !pinfo->active_level);
        mdelay(pinfo->active_delay);
    }

gk7101_set_gpio_reset_can_sleep_exit:
    return retval;
}

#ifdef CONFIG_PHY_USE_SD_CLK
/*----------------------------------------------------------------------------*/
/* registers                                                                  */
/*----------------------------------------------------------------------------*/

typedef union { /* SDIO_Control01Reg */
    u32 all;
    struct {
        u32 softwareresetall            : 1;
        u32 softwareresetcmdline        : 1;
        u32 softwareresetdatline        : 1;
        u32                             : 5;
        u32 datatimeoutcountervalue     : 4;
        u32                             : 4;
        u32 internalclken               : 1;
        u32 internalclkstable           : 1;
        u32 sdclken                     : 1;
        u32                             : 5;
        u32 sdclkfreselect              : 8;
    } bitc;
} GH_SDIO_CONTROL01REG_S;

typedef union { /* SDIO_Control00Reg */
    u32 all;
    struct {
        u32 ledcontrol                  : 1;
        u32 datatrawidth                : 1;
        u32 sd8bitmode                  : 1;
        u32 hostspeeden                 : 1;
        u32                             : 2;
        u32 carddetecttestlevel         : 1;
        u32 carddetectsigdet            : 1;
        u32 sdbuspower                  : 1;
        u32 sdbusvoltageselect          : 3;
        u32                             : 4;
        u32 stopatblkgapreq             : 1;
        u32 rwaitcontrol                : 1;
        u32 continuereq                 : 1;
        u32 intatblkgap                 : 1;
        u32 driveccsd                   : 1;
        u32 spimode                     : 1;
        u32 booten                      : 1;
        u32 altbooten                   : 1;
        u32 wakeupevetenoncardins       : 1;
        u32 wakeupevetenoncardint       : 1;
        u32 wakeupevetenoncardrem       : 1;
        u32                             : 5;
    } bitc;
} GH_SDIO_CONTROL00REG_S;

void GH_SDIO_set_Control01Reg_SoftwareResetAll(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.softwareresetall = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

void GH_SDIO_set_Control01Reg_SoftwareResetCmdLine(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.softwareresetcmdline = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

void GH_SDIO_set_Control01Reg_SoftwareResetDatLine(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.softwareresetdatline = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

static void sdioSoftReset(void)
{
    GH_SDIO_set_Control01Reg_SoftwareResetAll(1);
    GH_SDIO_set_Control01Reg_SoftwareResetCmdLine(1);
    GH_SDIO_set_Control01Reg_SoftwareResetDatLine(1);
}

void GH_SDIO_set_Control01Reg_SdClkEn(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.sdclken = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

static void sdioClockOnOff(u32 on)
{
    if (on == 0)
    {
        GH_SDIO_set_Control01Reg_SdClkEn(0);
    }
    else
    {
        GH_SDIO_set_Control01Reg_SdClkEn(1);
    }
}

void GH_SDIO_set_Control01Reg_SdclkFreSelect(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.sdclkfreselect = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

void GH_SDIO_set_Control01Reg_InternalClkEn(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_sd_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.internalclken = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

u32  GH_SDIO_get_Control01Reg(void)
{
    u32 value = gk_sd_readl(REG_SDIO_SFRST_CONTROL);

    return value;
}

void GH_SDIO_set_Control00Reg_SdBusVoltageSelect(u8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG);
    d.bitc.sdbusvoltageselect = data;
    gk_sd_writel(REG_SDIO_CONTROL00REG,d.all);
}

u32  GH_SDIO_get_CapReg(void)
{
    u32 value = gk_sd_readl(REG_SDIO_CAPREG);
    return value;
}

void GH_SDIO_set_Control00Reg_SdBusPower(u8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_sd_readl(REG_SDIO_CONTROL00REG);
    d.bitc.sdbuspower = data;
    gk_sd_writel(REG_SDIO_CONTROL00REG,d.all);
}

static void sdioSelectVoltage(void)
{
    u32 caps;
    caps=GH_SDIO_get_CapReg();

    if(caps & 0x1<<24)
    {
        GH_SDIO_set_Control00Reg_SdBusVoltageSelect(0x7);
        GH_SDIO_set_Control00Reg_SdBusPower(1);

    }
    else if(caps & 0x1<<25)
    {
        GH_SDIO_set_Control00Reg_SdBusVoltageSelect(0x6);
        GH_SDIO_set_Control00Reg_SdBusPower(1);
    }
    else if(caps & 0x1<<26)
    {
        GH_SDIO_set_Control00Reg_SdBusVoltageSelect(0x5);
        GH_SDIO_set_Control00Reg_SdBusPower(1);
    }
}

static void sdioSetClockDiv( u8 div)
{

    GH_SDIO_set_Control01Reg_SdclkFreSelect(div);
    GH_SDIO_set_Control01Reg_InternalClkEn(1);

    while(1)
    {
        if((GH_SDIO_get_Control01Reg() & (0x1<<17)))
              break;
    }
    sdioClockOnOff(1);
}

void GH_SDIO_set_Control01Reg_DataTimeoutCounterValue(u8 data)
{
    GH_SDIO_CONTROL01REG_S d;
    d.all = gk_readl(REG_SDIO_SFRST_CONTROL);
    d.bitc.datatimeoutcountervalue = data;
    gk_sd_writel(REG_SDIO_SFRST_CONTROL,d.all);
}

static void sdioSetTimeoutControl(u8 timeout)
{
    GH_SDIO_set_Control01Reg_DataTimeoutCounterValue(timeout);
}

void GH_SDIO_set_Control00Reg_HostSpeedEn(u8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_readl(REG_SDIO_CONTROL00REG);
    d.bitc.hostspeeden = data;
    gk_sd_writel(REG_SDIO_CONTROL00REG,d.all);
}

void GH_SDIO_set_Control00Reg_DataTraWidth(u8 data)
{
    GH_SDIO_CONTROL00REG_S d;
    d.all = gk_readl(REG_SDIO_CONTROL00REG);
    d.bitc.datatrawidth = data;
    gk_sd_writel(REG_SDIO_CONTROL00REG,d.all);
}

static void sdioSetHostctlSpeed(u8 mode)
{
    GH_SDIO_set_Control00Reg_HostSpeedEn(mode);
}

static void sdioSetHostctlWidth(u8 mode)
{
    GH_SDIO_set_Control00Reg_DataTraWidth(mode);
}

void GH_SDIO_set_NorIntStatusReg(u16 data)
{
    gk_sd_writew(REG_SDIO_NOR_INT_STA,data);
}
void GH_SDIO_set_ErrIntStatusReg(u16 data)
{
    gk_sd_writew(REG_SDIO_ERR_INT_STA,data);
}

u16  GH_SDIO_get_NorIntStatusReg(void)
{
    u16 value = gk_sd_readw(REG_SDIO_NOR_INT_STA);

    return value;
}
u16  GH_SDIO_get_ErrIntStatusReg(void)
{
    u16 value = gk_sd_readw(REG_SDIO_ERR_INT_STA);

    return value;
}

void GH_SDIO_set_NorIntStatusEnReg(u16 data)
{
    gk_sd_writew(REG_SDIO_NOR_INT_STA_EN,data);
}
void GH_SDIO_set_ErrIntStatusEnReg(u16 data)
{
    gk_sd_writew(REG_SDIO_ERR_INT_STA_EN,data);
}

void GH_SDIO_set_NorIntSigEnReg(u16 data)
{
    gk_sd_writew(REG_SDIO_NOR_INT_SIG_EN,data);
}
void GH_SDIO_set_ErrIntSigEnReg(u16 data)
{
    gk_sd_writew(REG_SDIO_ERR_INT_SIG_EN,data);
}

#define SDIO_INT_STATUS_EN  (1 | 1<<1 | 1<<3 | 1<<4 |1<<5 | 1<<6 | 1<<7)
#define SDIO_INT_SIG_EN     (1 | 1<<1 | 1<<3 | 1<<4 |1<<5 | 1<<6 | 1<<7)
static void sdioEnableIntStatus(void)
{
    /*clear int*/
    if(GH_SDIO_get_NorIntStatusReg() & (0x1 << 15))
    {
        GH_SDIO_set_ErrIntStatusReg(GH_SDIO_get_ErrIntStatusReg());
        GH_SDIO_set_NorIntStatusReg(GH_SDIO_get_NorIntStatusReg());
    }

    GH_SDIO_set_NorIntStatusEnReg(0x0);
    GH_SDIO_set_NorIntStatusEnReg( SDIO_INT_STATUS_EN);
    GH_SDIO_set_ErrIntStatusEnReg( 0xffff);
}

static void sdioEnableIntSig(void)
{
    GH_SDIO_set_NorIntSigEnReg(0);
    GH_SDIO_set_NorIntSigEnReg( SDIO_INT_SIG_EN);
    GH_SDIO_set_ErrIntSigEnReg( 0xffff);
}

static void GD_SDIO_Rest(void)
{
    sdioSoftReset();
    sdioClockOnOff(0);
    sdioSetClockDiv(0x00);
    sdioSelectVoltage();
    sdioSetTimeoutControl(0xe);
    sdioSetHostctlSpeed(0);
    sdioSetHostctlWidth(1);
    /*clear interrupt status*/
    GH_SDIO_set_NorIntStatusReg(GH_SDIO_get_NorIntStatusReg());
    GH_SDIO_set_ErrIntStatusReg(GH_SDIO_get_ErrIntStatusReg());

    sdioEnableIntStatus();
    sdioEnableIntSig();
    printf("GD_SDIO_Rest\r\n");
}
#endif

typedef struct gpio_cfg
{
    u32 gpio_count;
	gpio_info_t gpio_chip[64];
    u32 extphy_gpio_count;
	gpio_info_t ext_phy_gpio[16];
    u32 intphy_gpio_count;
    gpio_info_t int_phy_gpio[16];

    u32 ir_led_ctl;
    u32 ir_cut1;
    u32 ir_cut2;

    u32 sensor_reset;

    u32 phy_reset;
    u32 phy_speed_led;

    u32 spi0_en0;
    u32 spi1_en0;

    u32 pwm0;
    u32 pwm1;
    u32 pwm2;
    u32 pwm3;

    u32 usb_host;

    u32 sd_detect;
    u32 sd_power;
    u32 sd1_detect;
    u32 sd1_power;

    //board info
    u32 soc_type;
    s8  board_type[32];
    u32 board_version;
    u32 reserve1;

    //extra device info
    u32 ext_phy_clk;
    u32 reserve2;

    // Add by Steven Yu:for pmu
    u32 pmu_ctl;
}gpio_cfg_t;

static gpio_cfg_t gk_all_gpio_cfg;

void gk710xs_save_gpio_cfg_to_usr_memory(u32 usrMemory)
{
    int i;
	int size;
    char *s;
//    int soctype;
    int phy_type;
    const gpio_info_t gpio_chip[] = {SYSTEM_GPIO_XREF_TABLE};
    const gpio_info_t ext_phy_gpio[] = {SYSTEM_GPIO_EXTPHY_TABLE};
	const gpio_info_t int_phy_gpio[] = {SYSTEM_GPIO_INTPHY_TABLE};

    memset((u8 *)&gk_all_gpio_cfg,0,sizeof(gk_all_gpio_cfg));

	size = sizeof(gpio_chip) / sizeof(struct gpio_info);
    gk_all_gpio_cfg.gpio_count = size;
	for(i = 0; i < size; i++)
        memcpy(&gk_all_gpio_cfg.gpio_chip[i],&gpio_chip[i],sizeof(gpio_info_t));

	size = sizeof(ext_phy_gpio) / sizeof(struct gpio_info);
    gk_all_gpio_cfg.extphy_gpio_count = size;
    for(i = 0; i < size; i++)
        memcpy(&gk_all_gpio_cfg.ext_phy_gpio[i],&ext_phy_gpio[i],sizeof(gpio_info_t));

    size = sizeof(int_phy_gpio) / sizeof(struct gpio_info);
    gk_all_gpio_cfg.intphy_gpio_count = size;
    for(i = 0; i < size; i++)
        memcpy(&gk_all_gpio_cfg.int_phy_gpio[i],&int_phy_gpio[i],sizeof(gpio_info_t));

    gk_all_gpio_cfg.ir_led_ctl  = SYSTEM_GPIO_IR_LED_CTRL;
    gk_all_gpio_cfg.ir_cut1     = SYSTEM_GPIO_IR_CUT1;
    gk_all_gpio_cfg.ir_cut2     = SYSTEM_GPIO_IR_CUT2;

    gk_all_gpio_cfg.sensor_reset= SYSTEM_GPIO_SENSOR_RESET;

    gk_all_gpio_cfg.phy_reset   = SYSTEM_GPIO_PHY_RESET;
    gk_all_gpio_cfg.phy_speed_led = SYSTEM_GPIO_PHY_SPEED_LED;

    gk_all_gpio_cfg.spi0_en0    = SYSTEM_GPIO_SPI0_EN0;
    gk_all_gpio_cfg.spi1_en0    = SYSTEM_GPIO_SPI1_EN0;

    gk_all_gpio_cfg.pwm0        = SYSTEM_GPIO_PWM0;
    gk_all_gpio_cfg.pwm1        = SYSTEM_GPIO_PWM1;
    gk_all_gpio_cfg.pwm2        = SYSTEM_GPIO_PWM2;
    gk_all_gpio_cfg.pwm3        = SYSTEM_GPIO_PWM3;

    gk_all_gpio_cfg.usb_host    = SYSTEM_GPIO_USB_HOST;

    gk_all_gpio_cfg.sd_detect   = SYSTEM_GPIO_SD_DETECT;
    gk_all_gpio_cfg.sd_power    = SYSTEM_GPIO_SD_POWER;
#ifdef SYSTEM_GPIO_SD1_DETECT
    gk_all_gpio_cfg.sd1_detect  = SYSTEM_GPIO_SD1_DETECT;
#else
    gk_all_gpio_cfg.sd1_detect  = GPIO_COUNT;
#endif
#ifdef SYSTEM_GPIO_SD1_POWER
    gk_all_gpio_cfg.sd1_power   = SYSTEM_GPIO_SD1_POWER;
#else
    gk_all_gpio_cfg.sd1_power   = GPIO_COUNT;
#endif
//    gk_all_gpio_cfg.pmu_ctl     = SYSTEM_GPIO_PMU_CTL;
    gk_all_gpio_cfg.soc_type    = CONFIG_SOC_TYPE;

    strncpy((char *)gk_all_gpio_cfg.board_type, CONFIG_BOARD_TYPE, sizeof(gk_all_gpio_cfg.board_type));
    gk_all_gpio_cfg.board_version   = CONFIG_BOARD_VARSION_CODE;
    gk_all_gpio_cfg.reserve1        = 0x0;

    //save extra device info
    s = getenv ("phytype");
    phy_type = s ? (int)simple_strtol(s, NULL, 10) : 0;
    switch (phy_type)
    {
        case 2://externel PHY 50MHz
            gk_all_gpio_cfg.ext_phy_clk = 50;
            break;
        case 1://externel PHY 25MHz
            gk_all_gpio_cfg.ext_phy_clk = 25;
            break;
        case 0://internel PHY
            gk_all_gpio_cfg.ext_phy_clk = 0;
            break;
        default: //Use default 25MHz
            gk_all_gpio_cfg.ext_phy_clk = 25;
            break;
    }

    gk_all_gpio_cfg.reserve2        = 0x0;
#if 0
    printf("[GPIO CFG] gpio   count = %d\n",gk_all_gpio_cfg.gpio_count);
    printf("[GPIO CFG] intphy count = %d\n",gk_all_gpio_cfg.intphy_gpio_count);
    printf("[GPIO CFG] extphy count = %d\n",gk_all_gpio_cfg.extphy_gpio_count);
    printf("[GPIO CFG] IR LED CTL    (%d)\n",gk_all_gpio_cfg.ir_led_ctl);
    printf("[GPIO CFG] IR CUT1       (%d)\n",gk_all_gpio_cfg.ir_cut1);
    printf("[GPIO CFG] IR CUT2       (%d)\n",gk_all_gpio_cfg.ir_cut2);
    printf("[GPIO CFG] SENSOR Reset  (%d)\n",gk_all_gpio_cfg.sensor_reset);
    printf("[GPIO CFG] PHY Reset     (%d)\n",gk_all_gpio_cfg.phy_reset);
    printf("[GPIO CFG] PHY Speed Led (%d)\n",gk_all_gpio_cfg.phy_speed_led);
    printf("[GPIO CFG] SPI0 EN       (%d)\n",gk_all_gpio_cfg.spi0_en0);
    printf("[GPIO CFG] SPI1 EN       (%d)\n",gk_all_gpio_cfg.spi1_en0);
    printf("[GPIO CFG] USB HOST      (%d)\n",gk_all_gpio_cfg.sd_detect);
    printf("[GPIO CFG] SD Detect     (%d)\n",gk_all_gpio_cfg.usb_host);
    printf("[GPIO CFG] SD Power      (%d)\n",gk_all_gpio_cfg.sd_power);
#endif

    memcpy((u8*)usrMemory,(u8*)&gk_all_gpio_cfg,sizeof(gk_all_gpio_cfg));
}

void gk710xs_gpio_initialize()
{
	int i;
	int size;
	const gpio_info_t gpio_chip[] = {SYSTEM_GPIO_XREF_TABLE};

	size = sizeof(gpio_chip) / sizeof(struct gpio_info);
	for(i = 0; i < size; i++) {
		if(gpio_chip[i].gpio_type != GPIO_TYPE_UNDEFINED)
			gk7101_gpio_config(gpio_chip[i].gpio_id, gpio_chip[i].gpio_type);
	}

	gk_gpio_writel(REG_GPIO_IN_EN,0x00000001);
#if 0
    gk_rct_writel(REG_PLL_IOCTRL_MISC2,0x00000011);
#endif
	init_tag = 1;

#ifdef CONFIG_PHY_USE_SD_CLK
	GD_SDIO_Rest();
#endif
}

void gk710xs_phy_gpio_initialize()
{
	int i;
	int size;
	int phy_tpye = 0;
	char *s;
	const gpio_info_t ext_phy_gpio[] = {SYSTEM_GPIO_EXTPHY_TABLE};
	const gpio_info_t int_phy_gpio[] = {SYSTEM_GPIO_INTPHY_TABLE};
#if defined(CONFIG_USE_EXT_PHY)
	s = getenv ("phytype");
	phy_tpye = s ? (int)simple_strtol(s, NULL, 10) : CONFIG_USE_EXT_PHY;
#endif
	if(phy_tpye == 1 || phy_tpye == 2){
		size = sizeof(ext_phy_gpio) / sizeof(struct gpio_info);
		for(i = 0; i < size; i++) {
			if(ext_phy_gpio[i].gpio_type != GPIO_TYPE_UNDEFINED)
				gk7101_gpio_config(ext_phy_gpio[i].gpio_id, ext_phy_gpio[i].gpio_type);
		}
	}else{
		size = sizeof(int_phy_gpio) / sizeof(struct gpio_info);
		for(i = 0; i < size; i++) {
			if(int_phy_gpio[i].gpio_type != GPIO_TYPE_UNDEFINED)
				gk7101_gpio_config(int_phy_gpio[i].gpio_id, int_phy_gpio[i].gpio_type);
		}
	}
}
