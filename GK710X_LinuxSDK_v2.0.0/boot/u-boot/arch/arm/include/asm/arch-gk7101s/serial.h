/******************************************************************************
**
** \file      serial_gk7101.h
**
** \brief     DEMO test application.
**
**            (C) Goke Microelectronics China 2002 - 2007
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
******************************************************************************/

#ifndef _SERIAL_GK7101S_H_
#define _SERIAL_GK7101S_H_

//*****************************************************************************
//*****************************************************************************
//** Defines and Macros
//*****************************************************************************
//*****************************************************************************

#define     GK7101S_APB_FREQ     48000000
#define     UART_BASE_FREQ     (GK7101S_APB_FREQ / 2)    //unit:Hz 27MHz

/****************************************************/
/* Capabilities based on chip revision              */
/****************************************************/
#define UART_INSTANCES          1

#include <asm/arch/gk7101_reg.h>
#include <asm/arch/io.h>

#define GK7101S_PA_UART0         (REG_UART0_BASE)
#define UART0_PA_ADDR           (GK7101S_PA_UART0)


/****************************************************/
/* Controller registers definitions                 */
/****************************************************/

#define UART0_REG(x)            (GK7101S_PA_UART0 + (x))



#define UART_IE_OFFSET          0x00
#define UART_DLH_OFFSET         0x00
#define UART_RB_OFFSET          0x04
#define UART_TH_OFFSET          0x04
#define UART_DLL_OFFSET         0x04
#define UART_II_OFFSET          0x08
#define UART_FC_OFFSET          0x08
#define UART_MC_OFFSET          0x0C
#define UART_MS_OFFSET          0x10
#define UART_LS_OFFSET          0x14
#define UART_LC_OFFSET          0x18

/* UART[x]_IE_REG */
#define UART_IE_PTIME           0x80
#define UART_IE_ETOI            0x20
#define UART_IE_EBDI            0x10
#define UART_IE_EDSSI           0x08
#define UART_IE_ELSI            0x04
#define UART_IE_ETBEI           0x02
#define UART_IE_ERBFI           0x01

/* UART[x]_II_REG */
#define UART_II_MODEM_STATUS_CHANGED    0x00
#define UART_II_NO_INT_PENDING          0x01
#define UART_II_THR_EMPTY               0x02
#define UART_II_RCV_DATA_AVAIL          0x04
#define UART_II_RCV_STATUS              0x06
#define UART_II_CHAR_TIMEOUT            0x0c

/* UART[x]_FC_REG */
#define UART_FC_RX_ONECHAR              0x00
#define UART_FC_RX_QUARTER_FULL         0x40
#define UART_FC_RX_HALF_FULL            0x80
#define UART_FC_RX_2_TO_FULL            0xc0
#define UART_FC_TX_EMPTY                0x00
#define UART_FC_TX_2_IN_FIFO            0x10
#define UART_FC_TX_QUATER_IN_FIFO       0x20
#define UART_FC_TX_HALF_IN_FIFO         0x30
#define UART_FC_XMITR                   0x04
#define UART_FC_RCVRR                   0x02
#define UART_FC_FIFOE                   0x01

/* UART[x]_LC_REG */
#define UART_LC_BRK             0x80
#define UART_LC_EVEN_PARITY     0x40
#define UART_LC_ODD_PARITY      0x00
#define UART_LC_STICKY_PARITY   0x20
#define UART_LC_DLAB            0x10
#define UART_LC_STOP_2BIT       0x08
#define UART_LC_STOP_1BIT       0x00
#define UART_LC_PEN             0x04
#define UART_LC_CLS_8_BITS      0x03
#define UART_LC_CLS_7_BITS      0x02
#define UART_LC_CLS_6_BITS              0x01
#define UART_LC_CLS_5_BITS              0x00


/* UART[x]_MC_REG */
#define UART_MC_LB              0x40
#define UART_MC_AFCE            0x20
#define UART_MC_SIRE            0x10
#define UART_MC_RTS             0x08
#define UART_MC_DTR             0x04
#define UART_MC_OUT2            0x02
#define UART_MC_OUT1            0x01

/* UART[x]_LS_REG */
#define UART_LS_FERR                    0x80

#define UART_LS_TEMT                    0x40
#define UART_LS_BI              0x20
#define UART_LS_FE              0x10
#define UART_LS_THRE            0x08
#define UART_LS_DR              0x04
#define UART_LS_PE              0x02
#define UART_LS_OE              0x01

/* UART[x]_MS_REG */
#define UART_MS_DCD             0x80
#define UART_MS_DCTS            0x40
#define UART_MS_CTS             0x20
#define UART_MS_DDCD            0x10
#define UART_MS_DSR             0x08
#define UART_MS_DDSR            0x04
#define UART_MS_TERI            0x02
#define UART_MS_RI              0x01

#define UART0_RB_REG            UART0_REG(UART_RB_OFFSET)
#define UART0_TH_REG            UART0_REG(UART_TH_OFFSET)
#define UART0_DLL_REG           UART0_REG(UART_DLL_OFFSET)
#define UART0_IE_REG            UART0_REG(UART_IE_OFFSET)
#define UART0_DLH_REG           UART0_REG(UART_DLH_OFFSET)
#define UART0_II_REG            UART0_REG(UART_II_OFFSET)
#define UART0_FC_REG            UART0_REG(UART_FC_OFFSET)
#define UART0_LC_REG            UART0_REG(UART_LC_OFFSET)
#define UART0_MC_REG            UART0_REG(UART_MC_OFFSET)
#define UART0_LS_REG            UART0_REG(UART_LS_OFFSET)
#define UART0_MS_REG            UART0_REG(UART_MS_OFFSET)


/* Other defs for UART */
#define RECV_BUF_SIZ            1500
#define SEND_BUF_SIZ            1500

/* ==========================================================================*/
#define UART_FIFO_SIZE          (16)

#define DEFAULT_UART_MCR        (0)
#define DEFAULT_UART_IER        (UART_IE_ELSI | UART_IE_ERBFI)
#define DEFAULT_UART_FCR        (UART_FC_FIFOE | UART_FC_RX_2_TO_FULL | UART_FC_TX_EMPTY)

struct gk7101_regs
{
    u32 reg_rb;
    u32 reg_th;
    u32 reg_dll;
    u32 reg_ie;
    u32 reg_dlh;
    u32 reg_ii;
    u32 reg_fc;
    u32 reg_lc;
    u32 reg_mc;
    u32 reg_ls;
    u32 reg_ms;
};

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif /* _GD_UART_H_ */
