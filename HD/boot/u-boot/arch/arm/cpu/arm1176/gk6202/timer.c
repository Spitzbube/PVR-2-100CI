/*
 * arch\arm\cpu\arm1176\gk6202\timer.c
 *
 * Copyright: 2012 - 2013 (C) GoKe Microelectronics LIMITED
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

#define REG_ARC_TIMERPRESCALER     0xD700010C 
#define REG_ARC_TIMERCONFIG         0xD7000100
#define REG_ARC_TIMERVALUE			  0xD7000104


static ulong timestamp;
static ulong lastdec;

#define TIMER_LOAD_VAL		0xFFFFFF
#define TIMER_NORMALISED	(1000/CONFIG_SYS_HZ)
static ulong get_timer_masked_new (void);
ulong read_timer();

int timer_init (void)
{
	*(volatile unsigned int *)0x300030 = 0x12340001;
	/* 1 milliseconds */
	__raw_writel(200000-1, REG_ARC_TIMERPRESCALER);
	/* reset */
	__raw_writel(0x00000043, REG_ARC_TIMERCONFIG);
	/*let it run*/
	__raw_writel(0x00000003, REG_ARC_TIMERCONFIG);
	
	
	/* init the timestamp and lastdec value */
	reset_timer_masked();

	return 0;
}


/*
 * timer without interrupts
 */

void reset_timer (void)
{
	reset_timer_masked ();
	return;
}

ulong get_timer (ulong base)
{
	return get_timer_masked () - base;
}

void set_timer (ulong t)
{
	timestamp = t;
}

void __udelay (unsigned long usec)
{
	ulong tmo, tmp;

	if(usec >= 1000){		/* if "big" number, spread normalization to seconds */
		tmo = usec / 1000;	/* start to normalize for usec to ticks per sec */
		tmo *= CONFIG_SYS_HZ;		/* find number of "ticks" to wait to achieve target */
		tmo /= 1000;		/* finish normalize. */
	}else{				/* else small number, don't kill it prior to HZ multiply */
		tmo = 1;
	}

	tmp = get_timer_masked_new ();		/* get current timestamp */
	if( (tmo + tmp + 1) < tmp )	/* if setting this fordward will roll time stamp */
		reset_timer_masked ();	/* reset "advancing" timestamp to 0, set lastdec value */
	else
		tmo += tmp;		/* else, set advancing stamp wake up time */

	while (get_timer_masked_new () < tmo)/* loop till event */
		/*NOP*/;
}


/* nothing really to do with interrupts, just starts up a counter. */
/* return usec timestamp*/
ulong read_timer()
{

    ulong counter_current;

	counter_current = __raw_readl(REG_ARC_TIMERVALUE);
    return( counter_current );

}

void reset_timer_masked (void)
{
	/* reset time */
	lastdec = __raw_readl(REG_ARC_TIMERVALUE);
							/* capure current decrementer value time */
	timestamp = 0;	       /* start "advancing" time stamp from 0 */
}

ulong get_timer_masked (void)
{
	ulong now;		/* current tick value */

	now = __raw_readl(REG_ARC_TIMERVALUE);

	if (lastdec <= now) {		/* normal mode (non roll) */
		/* normal mode */
		timestamp += now - lastdec ; /* move stamp fordward with absoulte diff ticks */
	} else {			/* we have overflow of the count down timer */
		/* nts = ts + ld + (TLV - now)
		 * ts=old stamp, ld=time that passed before passing through -1
		 * (TLV-now) amount of time after passing though -1
		 * nts = new "advancing time stamp"...it could also roll and cause problems.
		 */
		timestamp += (TIMER_LOAD_VAL - lastdec + now);
	}
	lastdec = now;

	return (timestamp/TIMER_NORMALISED);
}


static ulong get_timer_masked_new (void)
{
	ulong now;		/* current tick value */

	now = __raw_readl(REG_ARC_TIMERVALUE);

	if (lastdec <= now) {		/* normal mode (non roll) */
		/* normal mode */
		timestamp += now - lastdec ; /* move stamp fordward with absoulte diff ticks */
	} else {			/* we have overflow of the count down timer */
		/* nts = ts + ld + (TLV - now)
		 * ts=old stamp, ld=time that passed before passing through -1
		 * (TLV-now) amount of time after passing though -1
		 * nts = new "advancing time stamp"...it could also roll and cause problems.
		 */
		timestamp += (TIMER_LOAD_VAL - lastdec +  now);
	}
	lastdec = now;

	return (timestamp);
}



/* waits specified delay value and resets timestamp */
void udelay_masked (unsigned long usec)
{
	ulong tmo;
	ulong endtime;
	signed long diff;

	if (usec >= 1000) {		/* if "big" number, spread normalization to seconds */
		tmo = usec / 1000;	/* start to normalize for usec to ticks per sec */
		tmo *= CONFIG_SYS_HZ;		/* find number of "ticks" to wait to achieve target */
		tmo /= 1000;		/* finish normalize. */
	} else {			/* else small number, don't kill it prior to HZ multiply */
		tmo = 1;
	}

	endtime = get_timer_masked () + tmo;

	do {
		ulong now = get_timer_masked ();
		diff = endtime - now;
	} while (diff >= 0);
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
	return get_timer(0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk (void)
{
	ulong tbclk;

	tbclk = CONFIG_SYS_HZ;
	return tbclk;
}
