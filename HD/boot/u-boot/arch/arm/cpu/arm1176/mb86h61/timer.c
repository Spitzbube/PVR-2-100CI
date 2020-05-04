/*
 * (C) Copyright 2003
 * Texas Instruments <www.ti.com>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002-2004
 * Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
 *
 * (C) Copyright 2004
 * Philippe Robin, ARM Ltd. <philippe.robin@arm.com>
 *
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/mb86hxx.h>
#include <asm/arch/timer.h>
#include <asm/io.h>

#define TIMER_BASE			MB86HXX_TIMER2_BASE

static ulong timestamp;
static ulong lastdec;

/*
 * Internally time base clock is TIMER_HZ (== MB86HXX_APB_HZ)
 * and prescaled clock should be 1MHz
 * "time" in API is in CONFIG_SYS_HZ
 */
#define TIMER_PRESCALE		(TIMER_HZ/1000000)
									/* clock = 99MHz, PRESCALE < 128 */
#define TIMER_LOAD_VAL		(~0UL)
#define TIMER_NORMALISED	(1000000/CONFIG_SYS_HZ)
static ulong get_timer_masked_new (void);


int timer_init (void)
{
	int read;
#	if 1
	__raw_writel(0, 			  TIMER_BASE + TIMER_ENABLE);
	__raw_writel(TIMER_PRESCALE, TIMER_BASE + TIMER_COUNT_PRE);
	__raw_writel(TIMER_LOAD_VAL, TIMER_BASE + TIMER_COUNT_LOW);
	__raw_writel(0, 			  TIMER_BASE + TIMER_COUNT_HI);

	/* ENDLESS | !IRQ_ENABLE | ENABLE */
	__raw_writel(5, 			TIMER_BASE + TIMER_ENABLE);
#	else 
	read=__raw_readl(TIMER_BASE + TIMER_ENABLE);
	read&=0xfffffffe;
	__raw_writel(read,TIMER_BASE + TIMER_ENABLE);
	__raw_writel(read,TIMER_BASE + TIMER_IRQ_RESET);
	
	__raw_writel(TIMER_PRESCALE-1, 	TIMER_BASE + TIMER_COUNT_PRE);
	__raw_writel(-1, 						TIMER_BASE + TIMER_COUNT_LOW);
	__raw_writel(-1, 						TIMER_BASE + TIMER_COUNT_HI);
	
	read=__raw_readl(TIMER_BASE + TIMER_ENABLE);
	read&=0xfffffffd;
	__raw_writel(read,	TIMER_BASE + TIMER_ENABLE);
	/* ENDLESS | !IRQ_ENABLE | ENABLE */
	__raw_writel(5, 			TIMER_BASE + TIMER_ENABLE);
#	endif		
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
		//tmo /= 1000;		/* finish normalize. */
	}else{				/* else small number, don't kill it prior to HZ multiply */
		tmo = usec * CONFIG_SYS_HZ;
		tmo /= 1000;
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
uint64_t read_timer()
{
	uint32_t first_counter_high32,index = 2;
    uint32_t second_counter_high32;
    uint64_t counter_start;
    uint64_t counter_current;

    counter_start   = 0xFFFFFFFFFFFFFFFFULL;
    first_counter_high32  = *((volatile uint32_t*)(TIMER_BASE + TIMER_COUNT_HI));
    counter_current       = *((volatile uint64_t*)(TIMER_BASE + TIMER_COUNT_LOW));
    second_counter_high32 = *((volatile uint32_t*)(TIMER_BASE + TIMER_COUNT_HI));

    if(second_counter_high32 != first_counter_high32)
    {
        counter_current       = *((volatile uint64_t*)(TIMER_BASE + TIMER_COUNT_LOW));
    }

    counter_current = counter_start - counter_current;
    counter_current =  counter_current / 1;

    return( counter_current );
	
}
void reset_timer_masked (void)
{
	/* reset time */
# if 1
	lastdec = __raw_readl(TIMER_BASE + TIMER_COUNT_LOW);
# else
	lastdec = (ulong)read_timer();
#	endif							/* capure current decrementer value time */
	timestamp = 0;	       /* start "advancing" time stamp from 0 */
}

ulong get_timer_masked (void)
{
	ulong now;		/* current tick value */
# 	if 1
	now = __raw_readl(TIMER_BASE + TIMER_COUNT_LOW);
# 	else
	now = (ulong)read_timer();		/* current tick value */	
#	endif
	if (lastdec >= now) {		/* normal mode (non roll) */
		/* normal mode */
		timestamp += lastdec - now; /* move stamp fordward with absoulte diff ticks */
	} else {			/* we have overflow of the count down timer */
		/* nts = ts + ld + (TLV - now)
		 * ts=old stamp, ld=time that passed before passing through -1
		 * (TLV-now) amount of time after passing though -1
		 * nts = new "advancing time stamp"...it could also roll and cause problems.
		 */
		timestamp += (lastdec + TIMER_LOAD_VAL - now);
	}
	lastdec = now;

#if 1
	return (timestamp/TIMER_NORMALISED);
#else
	return timestamp;
#endif
}


static ulong get_timer_masked_new (void)
{
	ulong now;		/* current tick value */
# 	if 1
	now = __raw_readl(TIMER_BASE + TIMER_COUNT_LOW);
# 	else
	now = (ulong)read_timer();		/* current tick value */	
#	endif
	if (lastdec >= now) {		/* normal mode (non roll) */
		/* normal mode */
		timestamp += lastdec - now; /* move stamp fordward with absoulte diff ticks */
	} else {			/* we have overflow of the count down timer */
		/* nts = ts + ld + (TLV - now)
		 * ts=old stamp, ld=time that passed before passing through -1
		 * (TLV-now) amount of time after passing though -1
		 * nts = new "advancing time stamp"...it could also roll and cause problems.
		 */
		timestamp += (lastdec + TIMER_LOAD_VAL - now);
	}
	lastdec = now;

#if 1
	return (timestamp);
#else
	return timestamp;
#endif
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
		tmo = usec * CONFIG_SYS_HZ;
		tmo /= (1000*1000);
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
