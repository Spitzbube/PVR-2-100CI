/*!
*****************************************************************************
**
** \file        ./fapi/sys/src/sys_init.h
**
** \brief       System initialization interface.
**
** This file contains the declaration of the system intialization for the
** HDTV decoder(s).
** Dependend on the actual decoder type and board it determines all necessary
** drivers and defines the parameters which must be set.
** The file is targeted on applications to provide them a common approach
** for the HDTV system initialization.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_SYS_INIT_H
    #define FAPI_SYS_INIT_H

    #include <fapi/sys_services.h>

    //***********************************************************************
    //***********************************************************************
    //** Include decoder and board specific settings
    //***********************************************************************
    //***********************************************************************

    #ifdef MB86H60
        #ifdef BOARD_FUJITSU_FPGA
            #include <fapi/sys_init_mb86h60_fpga.h>
        #endif
        #ifdef BOARD_FUJITSU_DEVKIT
            #include <fapi/sys_init_mb86h60_devkit.h>
        #endif
        #ifdef BOARD_CUSTOMER
            #include <fapi/sys_init_customer.h>
        #endif
    #endif

    typedef void (*FAPI_SYS_RegInitFuncT)(void);

    //***********************************************************************
    //***********************************************************************
    //** Include required hardware register blocks
    //***********************************************************************
    //***********************************************************************
    #if FAPI_SYS_INIT_REG_AO == 1
        #include <fapi/reg_ao.h>
    #endif

    #if FAPI_SYS_INIT_REG_BM == 1
        #include <fapi/reg_bm.h>
    #endif

    #if FAPI_SYS_INIT_REG_CLKPWR == 1
        #include <fapi/reg_clkpwr.h>
    #endif

    #if FAPI_SYS_INIT_REG_DMA == 1
        #include <fapi/reg_dma.h>
    #endif

    #if FAPI_SYS_INIT_REG_ETH == 1
        #include <fapi/reg_eth.h>
    #endif

    #if FAPI_SYS_INIT_REG_FPC == 1
        #include <fapi/reg_fpc.h>
    #endif

    #if FAPI_SYS_INIT_REG_GPIO == 1
        #include <fapi/reg_gpio.h>
    #endif

    #if FAPI_SYS_INIT_REG_I2C == 1
        #include <fapi/reg_i2c.h>
    #endif

    #if FAPI_SYS_INIT_REG_ICC == 1
        #include <fapi/reg_icc.h>
    #endif

    #if FAPI_SYS_INIT_REG_IR == 1
        #include <fapi/reg_ir.h>
    #endif

    #if FAPI_SYS_INIT_REG_IRQ_CTRL == 1
        #include <fapi/reg_irq_ctrl.h>
    #endif

    #if FAPI_SYS_INIT_REG_SFLASH == 1
        #include <fapi/reg_sflash.h>
    #endif

    #if FAPI_SYS_INIT_REG_SSP == 1
        #include <fapi/reg_ssp.h>
    #endif

    #if FAPI_SYS_INIT_REG_TSD == 1
        #include <fapi/reg_tsd.h>
    #endif

    #if FAPI_SYS_INIT_REG_UART == 1
        #include <fapi/reg_uart.h>
    #endif

    #if FAPI_SYS_INIT_REG_UPI == 1
        #include <fapi/reg_upi.h>
    #endif

    #if FAPI_SYS_INIT_REG_VE == 1
        #include <fapi/reg_ve.h>
    #endif

    #if FAPI_SYS_INIT_REG_VE_HD == 1
        #include <fapi/reg_ve_hd.h>
    #endif

    #if FAPI_SYS_INIT_REG_VIC == 1
        #include <fapi/reg_vic.h>
    #endif

    #if FAPI_SYS_INIT_REG_VO == 1
        #include <fapi/reg_vo.h>
    #endif

    // to be continued ...

    //***********************************************************************
    //***********************************************************************
    //** Declare the array of hardware register initialization functions
    //***********************************************************************
    //***********************************************************************

    FAPI_SYS_RegInitFuncT FAPI_SYS_RegInitArr[] =
    {
        #if FAPI_SYS_INIT_REG_AO == 1
            FREG_AO_Init,
        #endif

        #if FAPI_SYS_INIT_REG_BM == 1
            FREG_BM_Init,
        #endif

        #if FAPI_SYS_INIT_REG_CLKPWR == 1
            FREG_CLKPWR_Init,
        #endif

        #if FAPI_SYS_INIT_REG_DMA == 1
            FREG_DMA_Init,
        #endif

        #if FAPI_SYS_INIT_REG_ETH == 1
            FREG_ETH_Init,
        #endif

        #if FAPI_SYS_INIT_REG_FPC == 1
            FREG_FPC_Init,
        #endif

        #if FAPI_SYS_INIT_REG_GPIO == 1
            FREG_GPIO_Init,
        #endif

        #if FAPI_SYS_INIT_REG_I2C == 1
            FREG_I2C_Init,
        #endif

        #if FAPI_SYS_INIT_REG_ICC == 1
            FREG_ICC_Init,
        #endif

        #if FAPI_SYS_INIT_REG_IR == 1
            FREG_IR_Init,
        #endif

        #if FAPI_SYS_INIT_REG_IRQ_CTRL == 1
            FREG_IRQ_CTRL_Init,
        #endif

        #if FAPI_SYS_INIT_REG_SFLASH == 1
            FREG_SFLASH_Init,
        #endif

        #if FAPI_SYS_INIT_REG_SSP == 1
            FREG_SSP_Init,
        #endif

        #if FAPI_SYS_INIT_REG_TSD == 1
            FREG_TSD_Init,
        #endif

        #if FAPI_SYS_INIT_REG_UART == 1
            FREG_UART_Init,
        #endif

        #if FAPI_SYS_INIT_REG_UPI == 1
            FREG_UPI_Init,
        #endif

        #if FAPI_SYS_INIT_REG_VE == 1
            FREG_VE_Init,
        #endif

        #if FAPI_SYS_INIT_REG_VE_HD == 1
            FREG_VE_HD_Init,
        #endif

        #if FAPI_SYS_INIT_REG_VIC == 1
            FREG_VIC_Init,
        #endif

        #if FAPI_SYS_INIT_REG_VO == 1
            FREG_VO_Init,
        #endif

        // to be continued ...

        // last entry must be NULL. Don't remove it!!
        (FAPI_SYS_RegInitFuncT)0
    };

    //***********************************************************************
    //***********************************************************************
    //** Include required drivers
    //***********************************************************************
    //***********************************************************************

    #if FAPI_SYS_INIT_GPIO == 1
        #include <fapi/drv_gpio.h>
    #endif

    #if FAPI_SYS_INIT_MMU == 1
        #include <fapi/drv_mmu.h>
    #endif

    #if FAPI_SYS_INIT_ATA == 1
        #include <fapi/drv_ata.h>
    #endif

    #if FAPI_SYS_INIT_AUDEC == 1
        #include <fapi/drv_audec.h>
    #endif

    #if FAPI_SYS_INIT_AUOUT == 1
        #include <fapi/drv_auout.h>
    #endif

    #if FAPI_SYS_INIT_BM == 1
        #include <fapi/drv_bm.h>
    #endif

    #if FAPI_SYS_INIT_CLKPWR == 1
        #include <fapi/drv_clkpwr.h>
    #endif

    #if FAPI_SYS_INIT_DESC == 1
        #include <fapi/drv_desc.h>
    #endif

    #if FAPI_SYS_INIT_DMA == 1
        #include <fapi/drv_dma.h>
    #endif

    #if FAPI_SYS_INIT_ETH == 1
        #include <fapi/drv_eth.h>
    #endif

    #if FAPI_SYS_INIT_FLASH == 1
        #include <fapi/drv_flash.h>
    #endif

    #if FAPI_SYS_INIT_FPC == 1
        #include <fapi/drv_fpc.h>
    #endif

    #if FAPI_SYS_INIT_GPREG == 1
        #include <fapi/drv_gpreg.h>
    #endif

    #if FAPI_SYS_INIT_HDMI == 1
        #include <fapi/drv_hdmi.h>
    #endif

    #if FAPI_SYS_INIT_I2C == 1
        #include <fapi/drv_i2c.h>
    #endif

    #if FAPI_SYS_INIT_ICC == 1
        #include <fapi/drv_icc.h>
    #endif

    #if FAPI_SYS_INIT_INTR == 1
        #include <fapi/drv_intr.h>
    #endif

    #if FAPI_SYS_INIT_IR == 1
        #include <fapi/drv_ir.h>
    #endif

    #if FAPI_SYS_INIT_SSP == 1
        #include <fapi/drv_ssp.h>
    #endif

    #if FAPI_SYS_INIT_SYNC == 1
        #include <fapi/drv_sync.h>
    #endif

    #if FAPI_SYS_INIT_TIMER == 1
        #include <fapi/drv_timer.h>
    #endif

    #if FAPI_SYS_INIT_TSD == 1
        #include <fapi/drv_tsd.h>
    #endif

    #if FAPI_SYS_INIT_TTX == 1
        #include <fapi/drv_ttx.h>
    #endif

    #if FAPI_SYS_INIT_UART == 1
        #include <fapi/drv_uart.h>
    #endif

    #if FAPI_SYS_INIT_UPI == 1
        #include <fapi/drv_upi.h>
    #endif

    #if FAPI_SYS_INIT_USB == 1
        #include <fapi/drv_usb.h>
    #endif

    #if FAPI_SYS_INIT_VIDEC == 1
        #include <fapi/drv_videc.h>
    #endif

    #if FAPI_SYS_INIT_VIENC == 1
        #include <fapi/drv_vienc.h>
    #endif

    #if FAPI_SYS_INIT_VISCALE == 1
        #include <fapi/drv_viscale.h>
    #endif

    #if FAPI_SYS_INIT_BOOT == 1
        #include <fapi/drv_boot.h>
    #endif

    // to be  continued ....

    //***********************************************************************
    //***********************************************************************
    //** Declare the array of all required drivers
    //***********************************************************************
    //***********************************************************************

    FAPI_SYS_DriverT* FAPI_SYS_DriverArr[] =
    {
        #if FAPI_SYS_INIT_MMU == 1
            &FAPI_MMU_Driver,
        #endif

        #if FAPI_SYS_INIT_GPREG == 1
            &FAPI_GPREG_Driver,
        #endif

        #if FAPI_SYS_INIT_INTR == 1
            &FAPI_INTR_Driver,
        #endif

        #if FAPI_SYS_INIT_GPIO == 1
            &FAPI_GPIO_Driver,
        #endif

        #if FAPI_SYS_INIT_UART == 1
            &FAPI_UART_Driver0,
            &FAPI_UART_Driver1,
        #endif

        #if FAPI_SYS_INIT_TIMER == 1
            &FAPI_TIMER_Driver0,
            &FAPI_TIMER_Driver1,
            &FAPI_TIMER_Driver2,
        #endif

        #if FAPI_SYS_INIT_UPI == 1
            &FAPI_UPI_Driver,
        #endif

        #if FAPI_SYS_INIT_CLKPWR == 1
            &FAPI_CLKPWR_Driver,
        #endif

        #if FAPI_SYS_INIT_DESC == 1
            &FAPI_DESC_Driver0,
            &FAPI_DESC_Driver1,
            &FAPI_DESC_Driver2,
            &FAPI_DESC_Driver3,
        #endif

        #if FAPI_SYS_INIT_DMA == 1
            &FAPI_DMA_Driver,
        #endif

        #if FAPI_SYS_INIT_USB == 1
            &FAPI_USB_Driver0,
        #endif

        #if FAPI_SYS_INIT_I2C == 1
            &FAPI_I2C_Driver0,
            &FAPI_I2C_Driver1,
            &FAPI_I2C_Driver2,
        #endif

        #if FAPI_SYS_INIT_ICC == 1
            &FAPI_ICC_Driver0,
            &FAPI_ICC_Driver1,
        #endif

        #if FAPI_SYS_INIT_BM == 1
            &FAPI_BM_Driver0,
            &FAPI_BM_Driver1,
            &FAPI_BM_Driver2,
            &FAPI_BM_Driver3,
        #endif

        #if FAPI_SYS_INIT_SYNC == 1
            &FAPI_SYNC_Driver,
        #endif

        #if FAPI_SYS_INIT_TSD == 1
            &FAPI_TSD_Driver0,
            &FAPI_TSD_Driver1,
            &FAPI_TSD_Driver2,
            &FAPI_TSD_Driver3,
        #endif

        #if FAPI_SYS_INIT_TTX == 1
            &FAPI_TTX_Driver,
        #endif

        #if FAPI_SYS_INIT_ETH == 1
            &FAPI_ETH_Driver,
        #endif

        #if FAPI_SYS_INIT_FLASH == 1
            &FAPI_FLASH_Driver,
        #endif

        #if FAPI_SYS_INIT_BOOT == 1
            &FAPI_BOOT_Driver,
        #endif

        #if FAPI_SYS_INIT_SSP == 1
            &FAPI_SSP_Driver0,
            &FAPI_SSP_Driver1,
        #endif

        #if FAPI_SYS_INIT_VIDEC == 1
            &FAPI_VIDEC_Driver0,
            &FAPI_VIDEC_Driver1,
        #endif

        #if FAPI_SYS_INIT_VISCALE == 1
            &FAPI_VISCALE_Driver0,
        #endif

        #if FAPI_SYS_INIT_VIENC == 1
            &FAPI_VIENC_Driver0,
        #endif

        #if FAPI_SYS_INIT_HDMI == 1
            &FAPI_HDMI_Driver,
        #endif

        #if FAPI_SYS_INIT_IR == 1
            &FAPI_IR_Driver,
        #endif

        #if FAPI_SYS_INIT_FPC == 1
            &FAPI_FPC_Driver,
        #endif

        #if FAPI_SYS_INIT_AUOUT == 1
            &FAPI_AUOUT_Driver,
        #endif

        #if FAPI_SYS_INIT_AUDEC == 1
            &FAPI_AUDEC_Driver,
        #endif

        #if FAPI_SYS_INIT_ATA == 1
            &FAPI_ATA_Driver,
        #endif

        // to be  continued ....

        // last entry must be NULL. Don't remove it!!
        (FAPI_SYS_DriverT*)0
    };

    //***********************************************************************
    //***********************************************************************
    //** Declare central system init function
    //***********************************************************************
    //***********************************************************************

    /*!
    *************************************************************************
    ** \brief Central system initialization.
    **
    ** This \b inline function serves the application as central system
    ** initialization. Dependent on the actual decoder type and board
    ** it first initializes the hardware register layer FREG. Then it
    ** overwrites default driver parameters if necessary.
    ** Finally all required drivers will be registered with the actual
    ** operating environment.
    ** After sucessful return the whole system is ready to use.
    **
    ** \note If an application requires special parameter settings it must
    **       provide the macro \b APP_SET_BOARD_PARAMS before including
    **       sys_init.h.
    **       In addition it can exclude unused drivers by providing a
    **       preprocessor \#define <b>FAPI_SYS_INIT_</b><i>BLOCK</i> 0 for
    **       each unused <i>BLOCK</i> driver just before including
    **       sys_init.h.
    **       Please see also the code example below:
    **
    **           \code
    **           // exclude unused drivers (optional)
    **           #define FAPI_SYS_INIT_IDE 0
    **           ...
    **
    **           // application specific parameter settings (optional)
    **           #define APP_SET_BOARD_PARAMS \
    **                   FAPI_UART_SetBaudrate(115200); \
    **                   FAPI_AUD_SetAbvSize(0x06000);  \
    **                   ...
    **
    **           // include central system initialization
    **           #include <fapi/sys_init.h>
    **
    **           ...
    **
    **           if ( FAPI_SYS_Init() != 0 ) {
    **               // Handle ERROR
    **           }
    **           ...
    **           \endcode
    **
    ** \return
    **          - #FAPI_OK if the drivers were successfully initialized
    **          - (<0) driver specific error code from a related
    **                 FAPI_SYS_DriverT::initDriverFunc
    **
    ** \sa FAPI_SYS_ServicesT::initDriversFunc
    *************************************************************************
    */
    INLINE int32_t FAPI_SYS_Init(void)
    {
        uint32_t index = 0;

        // Initialize the Hardware Register Layer
        while( FAPI_SYS_RegInitArr[index] != 0 )
        {
            (FAPI_SYS_RegInitArr[index++])();
        }

        // Set board specific parameter
        #if defined(FAPI_SYS_SET_BOARD_PARAMS)
            FAPI_SYS_SET_BOARD_PARAMS
        #endif

        // Set application specific parameter
        #if defined(APP_SET_BOARD_PARAMS)
            APP_SET_BOARD_PARAMS
        #endif

        // Register all drivers with operating environment
        return( FAPI_SYS_INIT_DRIVERS( FAPI_SYS_DriverArr ) );
    }
#endif
