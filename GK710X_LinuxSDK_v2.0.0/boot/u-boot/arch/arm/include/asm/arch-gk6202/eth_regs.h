/*
 * (C) Copyright 2003
 * David Müller ELSOFT AG Switzerland. d.mueller@elsoft.ch
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/************************************************
 * NAME	    : mb86h60-v3.h
 * Version  : 31.3.2003
 *
 * common stuff for  MB86H60 SoC
 ************************************************/

#ifndef __MB86H60_V3_H__
#define __MB86H60_V3_H__

#include <asm/arch/mb86hxx.h>
/* I/O PORT (see manual chapter 9) */
typedef enum{
	MB86HXX_UART0,
	MB86HXX_UART1,
}MB86HXX_UARTS_NR;

#define FREG_DDRRAMIF_RAMIFSVERSION              0xDD000000UL
#define FREG_DDRRAMIF_RAMIFSDUMMYFF              0xDD000004UL
#define FREG_DDRRAMIF_RAMIFSENABLE               0xDD000008UL
#define FREG_DDRRAMIF_RAMIFSSTATUS               0xDD00000CUL
#define FREG_DDRRAMIF_RAMIFSSDRAMTYPE            0xDD000100UL
#define FREG_DDRRAMIF_RAMIFSACSPEC_1             0xDD000104UL
#define FREG_DDRRAMIF_RAMIFSACSPEC_2             0xDD000108UL
#define FREG_DDRRAMIF_RAMIFSACSPEC_3             0xDD00010CUL
#define FREG_DDRRAMIF_RAMIFSACSPEC_4             0xDD000110UL
#define FREG_DDRRAMIF_RAMIFSACSPEC_5             0xDD000114UL
#define FREG_DDRRAMIF_RAMIFSDATADELAY            0xDD000118UL
#define FREG_DDRRAMIF_RAMIFSODTMODE              0xDD000200UL
#define FREG_DDRRAMIF_RAMIFSODTDELAY1            0xDD000204UL
#define FREG_DDRRAMIF_RAMIFSODTDELAY2            0xDD000208UL
#define FREG_DDRRAMIF_RAMIFSODTDELAY3            0xDD00020CUL
#define FREG_DDRRAMIF_RAMIFSODTDELAY4            0xDD000210UL
#define FREG_DDRRAMIF_RAMIFSPIRLOMODE            0xDD000300UL
#define FREG_DDRRAMIF_RAMIFSPIRLORID             0xDD000304UL
#define FREG_DDRRAMIF_RAMIFSPIRLOWID             0xDD000308UL
#define FREG_DDRRAMIF_RAMIFSMACRORST             0xDD000500UL
#define FREG_DDRRAMIF_RAMIFSDLLSET               0xDD000504UL
#define FREG_DDRRAMIF_RAMIFSOCDSET               0xDD000508UL
#define FREG_DDRRAMIF_RAMIFSOCDRESULT            0xDD00050CUL
#define FREG_DDRRAMIF_RAMIFSODTSET               0xDD000510UL
#define FREG_DDRRAMIF_RAMIFSIOCONTSET            0xDD000514UL
#define FREG_DDRRAMIF_RAMIFSSDRAMCMD             0xDD000600UL
#define FREG_DDRRAMIF_RAMIFSSDRAMDEF             0xDD000604UL
#define FREG_DDRRAMIF_RAMIFSIOLOCK               0xDD000608UL
#define FREG_DDRRAMIF_RAMIFSSDRAMADR             0xDD00060CUL
#define FREG_DDRRAMIF_RAMIFSSDRAMDATAH           0xDD000610UL
#define FREG_DDRRAMIF_RAMIFSSDRAMDATAL           0xDD000614UL
#define FREG_DDRRAMIF_RAMIFSSDRAMMASK            0xDD000618UL
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT0          0xDD00061CUL
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT1          0xDD000620UL
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT2          0xDD000624UL
#define FREG_DDRRAMIF_RAMIFSSDRAMOCDDT3          0xDD000628UL
#define FREG_DDRRAMIF_RAMIFVVERSION              0xDE000000UL
#define FREG_DDRRAMIF_RAMIFVDUMMYFF              0xDE000004UL
#define FREG_DDRRAMIF_RAMIFVENABLE               0xDE000008UL
#define FREG_DDRRAMIF_RAMIFVSTATUS               0xDE00000CUL
#define FREG_DDRRAMIF_RAMIFVCLK                  0xDE000010UL
#define FREG_DDRRAMIF_RAMIFVSDRAMTYPE            0xDE000100UL
#define FREG_DDRRAMIF_RAMIFVACSPEC_2             0xDE000104UL
#define FREG_DDRRAMIF_RAMIFVACSPEC_5             0xDE000110UL
#define FREG_DDRRAMIF_RAMIFVDATADELAY            0xDE000114UL
#define FREG_DDRRAMIF_RAMIFVODTDELAY1            0xDE000204UL
#define FREG_DDRRAMIF_RAMIFVODTDELAY2            0xDE000208UL
#define FREG_DDRRAMIF_RAMIFVODTDELAY3            0xDE00020CUL
#define FREG_DDRRAMIF_RAMIFVODTDELAY4            0xDE000210UL
#define FREG_DDRRAMIF_RAMIFVMACRORST             0xDE000500UL
#define FREG_DDRRAMIF_RAMIFVDLLSET               0xDE000504UL
#define FREG_DDRRAMIF_RAMIFVOCDSET               0xDE000508UL
#define FREG_DDRRAMIF_RAMIFVOCDRESULT            0xDE00050CUL
#define FREG_DDRRAMIF_RAMIFVODTSET               0xDE000510UL
#define FREG_DDRRAMIF_RAMIFVIOCONTSET            0xDE000514UL
#define FREG_DDRRAMIF_RAMIFVSDRAMCMD             0xDE000600UL
#define FREG_DDRRAMIF_RAMIFVSDRAMDEF             0xDE000604UL
#define FREG_DDRRAMIF_RAMIFVIOLOCK               0xDE000608UL
#define FREG_DDRRAMIF_RAMIFVSDRAMADR             0xDE00060CUL
#define FREG_DDRRAMIF_RAMIFVSDRAMDATAH           0xDE000610UL
#define FREG_DDRRAMIF_RAMIFVSDRAMDATAL           0xDE000614UL
#define FREG_DDRRAMIF_RAMIFVSDRAMMASK            0xDE000618UL
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT0          0xDE00061CUL
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT1          0xDE000620UL
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT2          0xDE000624UL
#define FREG_DDRRAMIF_RAMIFVSDRAMOCDDT3          0xDE000628UL
#define FREG_DDRRAMIF_RAMIFVCORESEL              0xDE000700UL
#define FREG_DDRRAMIF_RAMIFVBANKN                0xDE000800UL
#define FREG_DDRRAMIF_RAMIFVYB                   0xDE000858UL
#define FREG_DDRRAMIF_RAMIFVCT                   0xDE00085CUL
#define FREG_DDRRAMIF_RAMIFVCB                   0xDE000860UL
#define FREG_DDRRAMIF_RAMIFVSIZE                 0xDE000864UL
#define FREG_DDRRAMIF_RAMIFVERROR                0xDE000A00UL

/* Timer */ 
#define FREG_IRQ_CTRL_TIMERXENABLE          0xCF000000UL    
#define FREG_IRQ_CTRL_TIMERXCNTPRE          0xCF000004UL    
#define FREG_IRQ_CTRL_TIMERXCNTLOW          0xCF000008UL    
#define FREG_IRQ_CTRL_TIMERXCNTHIGH         0xCF00000CUL    
#define FREG_IRQ_CTRL_TIMERXIRQRESET        0xCF000018UL    
#define FREG_IRQ_CTRL_TIMERXIRQCNTLOW       0xCF00001CUL    
#define FREG_IRQ_CTRL_TIMERXIRQCNTHIGH      0xCF000020UL    
#define FREG_IRQ_CTRL_TIMERXIRQMASK         0xCF000024UL    
#define FREG_IRQ_CTRL_MUTEXX                0xCF000100UL    
#define FREG_IRQ_CTRL_ARCIRQMASK            0xCF000200UL    
#define FREG_IRQ_CTRL_ARCIRQXOR             0xCF000204UL    
#define FREG_IRQ_CTRL_ARCIRQSTATUS          0xCF000208UL    
#define FREG_IRQ_CTRL_ARCSTATUS             0xCF000210UL    
#define FREG_IRQ_CTRL_ARCJMPADDRESS         0xCF000214UL    
#define FREG_IRQ_CTRL_ARMIRQMASK            0xCF000300UL    
#define FREG_IRQ_CTRL_ARMIRQXOR             0xCF000304UL    
#define FREG_IRQ_CTRL_ARMIRQSTATUS          0xCF000308UL    
#define FREG_IRQ_CTRL_ARMSTATUS             0xCF000310UL    
#define FREG_IRQ_CTRL_ARMJMPADDRESS         0xCF000314UL    
#define FREG_IRQ_CTRL_GPX                   0xCF000380UL   

/* GPIO MB86HXX_GPIO_BASE=0xC3000000*/ 
#define FREG_GPIO_DATAOUT     MB86HXX_GPIO_BASE + 0x0
#define FREG_GPIO_DATAIN      MB86HXX_GPIO_BASE + 0x200
#define FREG_GPIO_IRQCFG      MB86HXX_GPIO_BASE + 0x4c0
#define FREG_GPIO_CONFIG      MB86HXX_GPIO_BASE + 0x4c4
#define FREG_GPIO_IRQSTATUS   MB86HXX_GPIO_BASE + 0x400
#define FREG_GPIO_INPUT_31_0  MB86HXX_GPIO_BASE + 0x404
#define FREG_GPIO_INPUT_63_32 MB86HXX_GPIO_BASE + 0x408
#define FREG_GPIO_INPUT_95_64 MB86HXX_GPIO_BASE + 0x40c
#define FREG_GPIO_PWMSETTING  MB86HXX_GPIO_BASE + 0x4ec


/* UART (see manual chapter 27) MB86HXX_UART0_BASE=0xC2000000*/
#define FREG_UART_DR      MB86HXX_UART0_BASE + 0x0 
#define FREG_UART_ECR     MB86HXX_UART0_BASE + 0x4
#define FREG_UART_RSR     MB86HXX_UART0_BASE + 0x4 
#define FREG_UART_FR      MB86HXX_UART0_BASE + 0x18
#define FREG_UART_ILPR    MB86HXX_UART0_BASE + 0x20
#define FREG_UART_IBRD    MB86HXX_UART0_BASE + 0x24
#define FREG_UART_FBRD    MB86HXX_UART0_BASE + 0x28
#define FREG_UART_LCRH    MB86HXX_UART0_BASE + 0x2c
#define FREG_UART_CR      MB86HXX_UART0_BASE + 0x30
#define FREG_UART_IFLS    MB86HXX_UART0_BASE + 0x34
#define FREG_UART_IMSC    MB86HXX_UART0_BASE + 0x38
#define FREG_UART_RIS     MB86HXX_UART0_BASE + 0x3c
#define FREG_UART_MIS     MB86HXX_UART0_BASE + 0x40
#define FREG_UART_ICR     MB86HXX_UART0_BASE + 0x44
#define FREG_UART_MOFFSET 0x0C000000UL 


#define FREG_ETH_MCR                             0xE4000000UL
#define FREG_ETH_MFFR                            0xE4000004UL
#define FREG_ETH_MHTRH                           0xE4000008UL
#define FREG_ETH_MHTRL                           0xE400000CUL
#define FREG_ETH_GAR                             0xE4000010UL
#define FREG_ETH_GDR                             0xE4000014UL
#define FREG_ETH_FCR                             0xE4000018UL
#define FREG_ETH_VTR                             0xE400001CUL
#define FREG_ETH_RWFFR                           0xE4000028UL
#define FREG_ETH_PMTR                            0xE400002CUL
#define FREG_ETH_MAR0H                           0xE4000040UL
#define FREG_ETH_MAR0L                           0xE4000044UL
#define FREG_ETH_MARXH                           0xE4000048UL
#define FREG_ETH_MARXL                           0xE400004CUL
#define FREG_ETH_BMR                             0xE4001000UL
#define FREG_ETH_TPDR                            0xE4001004UL
#define FREG_ETH_RPDR                            0xE4001008UL
#define FREG_ETH_RDLAR                           0xE400100CUL
#define FREG_ETH_TDLAR                           0xE4001010UL
#define FREG_ETH_SR                              0xE4001014UL
#define FREG_ETH_OMR                             0xE4001018UL
#define FREG_ETH_IER                             0xE400101CUL
#define FREG_ETH_MFBOCR                          0xE4001020UL
#define FREG_ETH_CHTBAR                          0xE4001050UL
#define FREG_ETH_CHRBAR                          0xE4001054UL
#define FREG_ETH_FLOWCTLSIG                      0xC30004C8UL


#endif /*__MB86H60_V3_H__*/
