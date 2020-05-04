/*
 * arch\arm\cpu\arm1176\gk7101\timer.c
 *
 * Copyright: 2013 - 2014 (C) GoKe Microelectronics LIMITED
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/timer.h>
#include <asm/arch/gk7101_reg.h>
#include <asm/arch/io.h>

#define APB_CLK                                             (69000000)    //69MHz
#define HAL_NEW_MAP

static void timer_enable(unchar tmr_id, unchar enable)
{
    ulong val;

    val = gk_timer_readl(REG_TIMER_CONTROL);

    if (tmr_id == 0)
    {
        val &= ~0x444;
        if (enable)
        {
            val |= 0x400;
        }
    }
    else if (tmr_id == 1)
    {
        val &= ~0x222;
        if (enable)
        {
            val |= 0x200;
        }
    }
    else if (tmr_id == 3)
    {
        val &= ~0x111;
        if (enable)
        {
            val |= 0x100;
        }
    }
    else
    {
        printf("error timer id\n");
    }

    gk_timer_writel(REG_TIMER_CONTROL, val);

}

int timer_init(void)
{
    gk_timer_writel(REG_TIMER_CNTNSTS, APB_CLK * 10);
    gk_timer_writel(REG_TIMER_RELOADN, APB_CLK * 10);

    timer_enable(0, 1);
    return 0;
}

static ulong time_stamp(void)
{
    ulong Reloadn, CntnSts, temp = 0;
    CntnSts = gk_timer_readl(REG_TIMER_CNTNSTS);

    Reloadn = APB_CLK * 10;
    if(Reloadn != 0)
    {
        temp = (Reloadn - CntnSts)  / (Reloadn / 10000000);
    }
    return (temp);
}

void __udelay(ulong usecs)
{
    ulong     start_time = 0;
    ulong     end_time = 0;
    ulong     max_usecs = 10000000;
    unchar    last_overflow_flag = 0;
    uint      overflow_cnt = 0;
    int       time_difference  = 0;
    int       cumul_time = 0;
    
    start_time = time_stamp();
    do
    {
        end_time = time_stamp();
        time_difference = (ulong)(end_time - start_time);
        /* check overflow */
        if (start_time > end_time)
        {
            time_difference += max_usecs;
            if (last_overflow_flag == 0)
            {
                last_overflow_flag = 1;
            }
        }
        else
        {
            if (last_overflow_flag == 1)
            {
                overflow_cnt++;
                last_overflow_flag = 0;
            }
        }
        /* Caculate accumulate time */
        cumul_time = time_difference + overflow_cnt * max_usecs;
    }while(cumul_time < usecs);

    return;
}

ulong get_tbclk (void)
{
    ulong tbclk;

    tbclk = CONFIG_SYS_HZ;
    return tbclk;
}

ulong get_timer (ulong base)
{
    ulong now;
    now = time_stamp();
    return (now - base);
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
    return get_timer(0);
}


