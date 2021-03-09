/*
*****************************************************************************
**
** \file        ./fapi/drv/videc/src/drv_videc_priv.h
**
** \brief       Video Decoder Iprivate header file.
**
** This file contains the declaration of the Video decoder interrupt handler.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef FAPI_VIDEC_PRIV_H
    #define FAPI_VIDEC_PRIV_H

#include <fapi/drv_videc.h>
#ifndef __LINUX__
#include <fapi/drv_mmu.h>
#endif


//*****************************************************************************
//*****************************************************************************
//** Defines
//*****************************************************************************
//*****************************************************************************
//!********************* DEBUG TRACE ******************************************
//#define FAPI_VIDEC_DEBUG                                                    1
//!********************* PTS REGISTERS LOCATION *******************************
//!..................... TSD01 ................................................
#define FAPI_VIDEC_TSD01_PTSLOCATION_0           FIO_ADDRESS(TSD01, 0xC8000140)
#define FAPI_VIDEC_TSD01_PTSLOCATION_1           FIO_ADDRESS(TSD01, 0xC800014C)
#define FAPI_VIDEC_TSD01_PTSLOCATION_2           FIO_ADDRESS(TSD01, 0xC8000158)
#define FAPI_VIDEC_TSD01_PTSLOCATION_3           FIO_ADDRESS(TSD01, 0xC8000164)
//!..................... TSD23 ................................................
#define FAPI_VIDEC_TSD23_PTSLOCATION_0           FIO_ADDRESS(TSD23, 0xC8800140)
#define FAPI_VIDEC_TSD23_PTSLOCATION_1           FIO_ADDRESS(TSD23, 0xC880014C)
#define FAPI_VIDEC_TSD23_PTSLOCATION_2           FIO_ADDRESS(TSD23, 0xC8800158)
#define FAPI_VIDEC_TSD23_PTSLOCATION_3           FIO_ADDRESS(TSD23, 0xC8800164)
//!********** VCPB INFO TABLE *************************************************
#define VCPB_INFO_TABLE_MAX_ENTRY_NUM                                        96
#define VCPB_INFO_TABLE_ENTRY_SIZE                                           96
//!********** VCPB DEC REQ IDX FIFO *******************************************
#define VCPB_DEC_REQ_IDX_FIFO_MAX_NUM                                        96
#define VCPB_DEC_REQ_IDX_FIFO_START_ADDR_OFFSET                      0x00048000
//!********** VCPB FREE IDX FIFO **********************************************
#define VCPB_FREE_IDX_FIFO_MAX_NUM                                           96
#define VCPB_FREE_IDX_FIFO_START_ADDR_OFFSET                         0x00048200
//!********** VDPB INFO TABLE *************************************************
#define VDPB_INFO_TABLE_MAX_ENTRY_NUM                                        48
#define VDPB_INFO_TABLE_ENTRY_SIZE                                           96
//!********** VDPB DEC DONE IDX FIFO ******************************************
#define VDPB_DEC_DONE_IDX_FIFO_MAX_NUM                                       48
#define VDPB_DEC_DONE_IDX_FIFO_START_ADDR_OFFSET                     0x00048400
//!********** VDPB FREE IDX FIFO **********************************************
#define VDPB_FREE_IDX_FIFO_MAX_NUM                                           48
#define VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET                         0x00048500
//!********** OUTCOME OF DECODE TABLE *****************************************
#define OOD_INFO_TABLE_MAX_ENTRY_NUM                                         64
#define OOD_INFO_TABLE_ENTRY_SIZE                                          1280
//!********** OOD FIFO ********************************************************
#define OOD_FIFO_MAX_NUM                       (8*OOD_INFO_TABLE_MAX_ENTRY_NUM)
//!********** AUD FIFO ********************************************************
#define AUD_FIFO_MAX_NUM                      (8*VCPB_INFO_TABLE_MAX_ENTRY_NUM)
//!********** FRAME FIFO ******************************************************
#define FRAME_FIFO_MAX_NUM                        VDPB_INFO_TABLE_MAX_ENTRY_NUM
//!********** PCPU INFORMATION ************************************************
#define PCPU_INFO_OFFSET                                             0x00048700
//!********** MESSAGES & COMMANDS *********************************************
#define PCPU_MESSAGE_VCPB_FREE_FIFO_UPDATE                           0x00002000
#define PCPU_MESSAGE_VDPB_INFO_UPDATE                                0x00001000
#define PCPU_MESSAGE_BOOT_DONE                                       0x00000800
#define PCPU_MESSAGE_DECODE_END                                      0x00000400
#define PCPU_MESSAGE_RESET_READY                                     0x00000200
#define PCPU_MESSAGE_DEC_START                                       0x00000100
#define MAINCPU_MESSAGE_VCPB_INFO_UPDATE                             0x20000000
#define MAINCPU_MESSAGE_VDPB_FREE_UPDATE                             0x10000000
#define MAINCPU_CMD_DECODE_END                                       0x04000000
#define MAINCPU_CMD_RESET_READY                                      0x02000000
#define MAINCPU_CMD_DECODE_START                                     0x01000000
//!********** BSR SWITCH ******************************************************
#define FAPI_VIDEC_BSR_OFF                                           0x00000000
//!********** HW STATES *******************************************************
#define FAPI_VIDEC_HW_RESET_ON                                       0x00030000
#define FAPI_VIDEC_HW_RESET_OFF                                      0x00000000
#define FAPI_VIDEC_HW_CLOCK_ENABLE                                   0x001F0000
#define FAPI_VIDEC_HW_CLOCK_DISABLE                                  0x00000000
#define FAPI_VIDEC_HW_INTERRUPT_ENABLE_ALL                           0xFFFFFFFF
#define FAPI_VIDEC_HW_INTERRUPT_DISABLE_ALL                          0x00000000
//!********** VIDEO CHUNKS SIZE ***********************************************
#if 0 /* FML FAPex (#509) */
#define AXIWRP_SEQ_AREA_SIZE                                         0x00100000
#else
#define AXIWRP_SEQ_AREA_SIZE                                         0
#endif
#define AXIWRP_CC_AREA_SIZE                                          0x00480000
#define AXIWRP_MV_AREA_SIZE                                          0x00080000
#define AXIWRP_DV_AREA_SIZE                                          0x002A8000
#define VIDEO_STREAM_AREA_SIZE                                       0x00B00000
#define DEC_START_PARAMETERS_SIZE                                    0x00000100
#define PCPU_WORK_AREA_SIZE                                          0x00100000
#define OUTCOME_OF_DECODE_AREA_SIZE                (OOD_INFO_TABLE_ENTRY_SIZE \
                                                 *OOD_INFO_TABLE_MAX_ENTRY_NUM)
#define VCPB_INFO_TABLE_AREA_SIZE              (VCPB_INFO_TABLE_MAX_ENTRY_NUM \
                                                   *VCPB_INFO_TABLE_ENTRY_SIZE)
#define VDPB_INFO_TABLE_AREA_SIZE              (VDPB_INFO_TABLE_MAX_ENTRY_NUM \
                                                   *VDPB_INFO_TABLE_ENTRY_SIZE)
//!********** VIDEC ***********************************************************
#define FAPI_VIDEC_MAX_NUM_HANDLES_VIDEC_0                                    1
#define FAPI_VIDEC_MAX_NUM_DECODERS                                           \
                                           (FAPI_VIDEC_MAX_NUM_HANDLES_VIDEC_0)
//! "Videc" in hex = 0x5669646563000000
#define FAPI_VIDEC_ID                                     0x5669646563000000ULL
//!********** TIMEOUTS FOR SEMAPHORES *****************************************
#define FAPI_VIDEC_ISR_BOOT_TIMEOUT                                        5000
#define FAPI_VIDEC_ISR_START_TIMEOUT                                       1000
#define FAPI_VIDEC_ISR_STOP_TIMEOUT                                        1000
#define FAPI_VIDEC_ISR_RESET_TIMEOUT                                       1000
#define FAPI_VIDEC_ISR_ENABLE_TIMEOUT                                     20000
#define FAPI_VIDEC_ISR_GETVESPARAMS_TIMEOUT                               10000
//!********** VIDEC 0 *********************************************************
#define FAPI_VIDEC_START_ADDRESS_0                                   0x60000000
#define SDRAM_S_START_ADDR_0                                         0x20000000
#define SDRAM_V_START_ADDR_0                                         0x40000000
#define SDRAM_S_SIZE_0                                               0x04000000
#define SDRAM_V_SIZE_0                                               0x04000000
//!********** ERROR CONCEALMENTS **********************************************
#define FAPI_VIDEC_ERROR_CONCEALMENT_Y_VAL                           0x00000010
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cb_VAL                          0x00000080
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cr_VAL                          0x00000080
#define FAPI_VIDEC_ERROR_CONCEALMENT_Y_OFFSET                        0x010E2220
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cb_OFFSET                       0x010E2224
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cr_OFFSET                       0x010E2228
#define FAPI_VIDEC_ERROR_CONCEALMENT_Y_ADDR_0                                 \
           (FAPI_VIDEC_START_ADDRESS_0 + FAPI_VIDEC_ERROR_CONCEALMENT_Y_OFFSET)
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cb_ADDR_0                                \
          (FAPI_VIDEC_START_ADDRESS_0 + FAPI_VIDEC_ERROR_CONCEALMENT_Cb_OFFSET)
#define FAPI_VIDEC_ERROR_CONCEALMENT_Cr_ADDR_0                                \
          (FAPI_VIDEC_START_ADDRESS_0 + FAPI_VIDEC_ERROR_CONCEALMENT_Cr_OFFSET)
//!********** VIDEO FIRMWARE INFORMATION **************************************
#define PCPU_INFO_START_ADDR_0                                                \
                                (FAPI_VIDEC_START_ADDRESS_0 + PCPU_INFO_OFFSET)
//!********** VIDEO FIFOS *****************************************************
#define VCPB_DEC_REQ_IDX_FIFO_START_ADDR_0                                    \
         (FAPI_VIDEC_START_ADDRESS_0 + VCPB_DEC_REQ_IDX_FIFO_START_ADDR_OFFSET)
#define VCPB_DEC_REQ_IDX_FIFO_WRITE_POS_ADDR_0                                \
        (FAPI_VIDEC_START_ADDRESS_0 + VCPB_DEC_REQ_IDX_FIFO_START_ADDR_OFFSET \
                                        + (VCPB_DEC_REQ_IDX_FIFO_MAX_NUM << 2))
#define VCPB_DEC_REQ_IDX_FIFO_READ_POS_ADDR_0                                 \
        (FAPI_VIDEC_START_ADDRESS_0 + VCPB_DEC_REQ_IDX_FIFO_START_ADDR_OFFSET \
                                    + (VCPB_DEC_REQ_IDX_FIFO_MAX_NUM << 2) + 4)
//!********** VIDEO FIFOS *****************************************************
#define VCPB_FREE_IDX_FIFO_START_ADDR_0                                       \
            (FAPI_VIDEC_START_ADDRESS_0 + VCPB_FREE_IDX_FIFO_START_ADDR_OFFSET)
#define VCPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0                                   \
           (FAPI_VIDEC_START_ADDRESS_0 + VCPB_FREE_IDX_FIFO_START_ADDR_OFFSET \
                                           + (VCPB_FREE_IDX_FIFO_MAX_NUM << 2))
#define VCPB_FREE_IDX_FIFO_READ_POS_ADDR_0                                    \
           (FAPI_VIDEC_START_ADDRESS_0 + VCPB_FREE_IDX_FIFO_START_ADDR_OFFSET \
                                       + (VCPB_FREE_IDX_FIFO_MAX_NUM << 2) + 4)
//!********** VIDEO FIFOS *****************************************************
#define VDPB_DEC_DONE_IDX_FIFO_START_ADDR_0                                   \
        (FAPI_VIDEC_START_ADDRESS_0 + VDPB_DEC_DONE_IDX_FIFO_START_ADDR_OFFSET)
#define VDPB_DEC_DONE_IDX_FIFO_WRITE_POS_ADDR_0                               \
       (FAPI_VIDEC_START_ADDRESS_0 + VDPB_DEC_DONE_IDX_FIFO_START_ADDR_OFFSET \
                                       + (VDPB_DEC_DONE_IDX_FIFO_MAX_NUM << 2))
#define VDPB_DEC_DONE_IDX_FIFO_READ_POS_ADDR_0                                \
       (FAPI_VIDEC_START_ADDRESS_0 + VDPB_DEC_DONE_IDX_FIFO_START_ADDR_OFFSET \
                                   + (VDPB_DEC_DONE_IDX_FIFO_MAX_NUM << 2) + 4)
//!********** VIDEO FIFOS *****************************************************
#define VDPB_FREE_IDX_FIFO_START_ADDR_0                                       \
            (FAPI_VIDEC_START_ADDRESS_0 + VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET)
#define VDPB_FREE_IDX_FIFO_WRITE_POS_ADDR_0                                   \
           (FAPI_VIDEC_START_ADDRESS_0 + VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET \
                                           + (VDPB_FREE_IDX_FIFO_MAX_NUM << 2))
#define VDPB_FREE_IDX_FIFO_READ_POS_ADDR_0                                    \
           (FAPI_VIDEC_START_ADDRESS_0 + VDPB_FREE_IDX_FIFO_START_ADDR_OFFSET \
                                       + (VDPB_FREE_IDX_FIFO_MAX_NUM << 2) + 4)
//!********** FIELD TYPE ******************************************************
#define FAPI_VIDEC_TOP_FIELD                                         0x00000000
#define FAPI_VIDEC_BOT_FIELD                                         0x00000001
//!********** DISPLAY ORDER INFOS *********************************************
#define FAPI_VIDEC_DOI_UNKNOWN                                       0x00000000
#define FAPI_VIDEC_DOI_STREAM_FLUSH_MARKER                           0x00000001
#define FAPI_VIDEC_DOI_TOP_FIELD_ONLY                                0x00000002
#define FAPI_VIDEC_DOI_BOT_FIELD_ONLY                                0x00000003
#define FAPI_VIDEC_DOI_INTERLACE_FRAME_TOP_BOT                       0x00000004
#define FAPI_VIDEC_DOI_INTERLACE_FRAME_BOT_TOP                       0x00000005
#define FAPI_VIDEC_DOI_PROGRESSIVE_FRAME                             0x00000006
#define FAPI_VIDEC_DOI_INTERLACE_FRAME_TOP_BOT_TOP                   0x00000008
#define FAPI_VIDEC_DOI_INTERLACE_FRAME_BOT_TOP_BOT                   0x00000009
#define FAPI_VIDEC_DOI_PROGRESSIVE_FRAME_FRAME_DOUBLING              0x0000000A
#define FAPI_VIDEC_DOI_PROGRESSIVE_FRAME_FRAME_TRIPPLING             0x0000000B
//*****************************************************************************
//*****************************************************************************
//** Ennumerated types
//*****************************************************************************
//*****************************************************************************
/*
*******************************************************************************
** \brief Internal state of a decoded frame.
*******************************************************************************
*/
typedef enum {
    //! Unknown state of a frame.
    FAPI_VIDEC_UNKNOWN_FRAME_STATE = (int32_t)-1,
    //! Frame is generated out of decoding process.
    FAPI_VIDEC_FRAME_DECODED = 0,
    //! Repeat the current frame.
    FAPI_VIDEC_FRAME_REPEAT = 1,
    //! Start displaying the frame.
    FAPI_VIDEC_FRAME_DISPLAY_START = 2,
    //! Start to display the top field Only.
    FAPI_VIDEC_FRAME_DISPLAY_ONLY_TOP_FIELD_ON_DISPLAY = 3,
    //! Start to display the bot field Only.
    FAPI_VIDEC_FRAME_DISPLAY_ONLY_BOT_FIELD_ON_DISPLAY = 4,
    //! Start to display the top field first of a frame.
    FAPI_VIDEC_FRAME_DISPLAY_FIRST_TOP_FIELD_ON_DISPLAY = 5,
    //! Start to display the bot field first of a frame.
    FAPI_VIDEC_FRAME_DISPLAY_FIRST_BOT_FIELD_ON_DISPLAY = 6,
    //! Start to display only the top field of a frame.
    FAPI_VIDEC_FRAME_DISPLAY_TOP_FIELD_ON_DISPLAY = 7,
    //! Start to display only the bot field of a frame.
    FAPI_VIDEC_FRAME_DISPLAY_BOT_FIELD_ON_DISPLAY = 8,
    //! Start to display only the frame in frame normal mode or display frame for one field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_0_VSYNC = 9,
    //! Start to display only the frame in frame normal mode or display frame for one field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_1_VSYNC = 10,
    //! Start to display only the frame fpr 2 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_2_VSYNC = 11,
    //! Start to display only the frame fpr 3 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_3_VSYNC = 12,
    //! Start to display only the frame fpr 4 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_4_VSYNC = 13,
    //! Start to display only the frame fpr 5 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_5_VSYNC = 14,
    //! Start to display only the frame fpr 6 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_6_VSYNC = 15,
    //! Start to display only the frame fpr 7 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_7_VSYNC = 16,
    //! Start to display only the frame fpr 8 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_8_VSYNC = 17,
    //! Start to display only the frame fpr 9 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_9_VSYNC = 18,
    //! Start to display only the frame fpr 10 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_10_VSYNC = 19,
    //! Start to display only the frame fpr 11 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_11_VSYNC = 20,
    //! Start to display only the frame fpr 12 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_12_VSYNC = 21,
    //! Start to display only the frame fpr 13 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_13_VSYNC = 22,
    //! Start to display only the frame fpr 14 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_14_VSYNC = 23,
    //! Start to display only the frame fpr 15 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_15_VSYNC = 24,
    //! Start to display only the frame fpr 16 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_16_VSYNC = 25,
    //! Start to display only the frame fpr 17 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_17_VSYNC = 26,
    //! Start to display only the frame fpr 18 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_18_VSYNC = 27,
    //! Start to display only the frame fpr 19 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_19_VSYNC = 28,
    //! Start to display only the frame fpr 20 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_20_VSYNC = 29,
    //! Start to display only the frame fpr 21 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_21_VSYNC = 30,
    //! Start to display only the frame fpr 22 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_22_VSYNC = 31,
    //! Start to display only the frame fpr 23 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_23_VSYNC = 32,
    //! Start to display only the frame fpr 24 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_24_VSYNC = 33,
    //! Start to display only the frame fpr 25 field only.
    FAPI_VIDEC_FRAME_DISPLAY_FRAME_25_VSYNC = 34,
    //! Flush marker.
    FAPI_VIDEC_FRAME_FLUSH_MARKER = 253,
    //! Start to display the frame for indefinate V syncs.
    FAPI_VIDEC_FRAME_DISPLAY_PAUSE = 254,
    //! Stop displaying the frame.
    FAPI_VIDEC_FRAME_DISPLAY_END = 255,
    //! The respective frame memory is freed.
    FAPI_VIDEC_FRAME_FREED = 256
}FAPI_VIDEC_DecodedFrameStateEnumT;
/*
*******************************************************************************
** \brief Internal state to check if the Firmware in flash matches the FAPI version.
*******************************************************************************
*/
typedef enum {
    //! Unknown state of of the version matching process.
    FAPI_VIDEC_UNKNOWN_VERSION_MATCH_STATE = (int32_t)-1,
    //! Video firmware not supported by the current FAPI version.
    FAPI_VIDEC_VERSION_MATCH_FAILURE,
    //! Video firmware matches the current FAPI version.
    FAPI_VIDEC_VERSION_MATCH_SUCCESS
}FAPI_VIDEC_VersionStateEnumT;
/*
*******************************************************************************
** \brief Defines if video decoder´s internal state of skip and repeat.
*******************************************************************************
*/
typedef enum {
  /* Specifies an unknown skip or repeat video decoder*/
  FAPI_VIDEC_UNKNOWN_SKIP_REPEAT_STATE = (int32_t)-1,
  /* Normal playback*/
  FAPI_VIDEC_NO_SKIP_NO_REPEAT,
  /* Next picture will be skipped*/
  FAPI_VIDEC_SKIP_NEXT_FRAME,
  /* Current picture will be repeated */
  FAPI_VIDEC_REPEAT_CURR_FRAME
} FAPI_VIDEC_SkipRepeatStateEnumT;
/*
****************************************************************************
** \brief Video Scaler Modes enumerated type
****************************************************************************
*/
typedef enum {
    /* Specifies an unknown interlace or progressive display of VE HD*/
    FAPI_VIDEC_UNKNOWN_DISPLAY_MODE = 0,
    /* Specifies an 1920x1080x2397P display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x2397P = 1,
    /* Specifies an 1920x1080x24P display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x24P = 2,
    /* Specifies an 1920x1080x25P display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x25P = 3,
    /* Specifies an 1920x1080x2997P display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x2997P = 4,
    /* Specifies an 1920x1080x30P display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x30P = 5,
    /* Specifies an 1920x1080x50I interlace display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x50I = 6,
    /* Specifies an 1920x1080x5994I interlace display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x5994I = 7,
    /* Specifies an 1920x1080x60I interlace display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1920x1080x60I = 8,
    /* Specifies an 1280x720x2397P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x2397P = 9,
    /* Specifies an 1280x720x24P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x24P = 10,
    /* Specifies an 1280x720x25P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x25P = 11,
    /* Specifies an 1280x720x2997P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x2997P = 12,
    /* Specifies an 1280x720x30P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x30P = 13,
    /* Specifies an 1280x720x50P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x50P = 14,
    /* Specifies an 1280x720x5994P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x5994P = 15,
    /* Specifies an 1280x720x60P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_1280x720x60P = 16,
    /* Specifies an 720x576x50I interlace display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_720x576x50I = 17,
    /* Specifies an 720x576x50P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_720x576x50P = 18,
    /* Specifies an 720x480x5994I interlace display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_720x480x5994I = 19,
    /* Specifies an 720x480x5994P progressive display of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_720x480x5994P = 20,
    /* Specifies an 640x480x50P LCD display mode of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_LCD_640x480x50P_LQ080V3DG01 = 21,
    /* Specifies an 1024x768x50P LCD display mode of VE HD*/
    FAPI_VIDEC_DISPLAY_MODE_LCD_1024x768x50P_SVA150XG10TB = 22,
} FAPI_VIDEC_DisplayModeEnumT;
/*
****************************************************************************
** \brief Video decoder´s single MPEG I frame states
****************************************************************************
*/
typedef enum {
    /* Specifies normal decoding mode.*/
    FAPI_VIDEC_NON_MPEG_IFRAME_STATE = 0,
    /* Specifies MPEG I frame decoding mode.*/
    FAPI_VIDEC_MPEG_IFRAME_STATE, //1
    /* Specifies that single MPEG I Frame is loaded in ves buffer*/
    FAPI_VIDEC_MPEG_IFRAME_LOADED_IN_ES, //2
    /* Specifies that single MPEG I Frame is decoded and is available in DDR2*/
    FAPI_VIDEC_MPEG_IFRAME_DECODED, //3
    /* Specifies that single MPEG I Frame on Display*/
    FAPI_VIDEC_MPEG_IFRAME_ON_DISPLAY //4
} FAPI_VIDEC_MpegIFrameStateEnumT;
/*
****************************************************************************
** \brief Video decoder´s synchronize state
****************************************************************************
*/
typedef enum {
    /* Specifies an unknown state of synchronization*/
    FAPI_VIDEC_UNKNOWN_SYNC_STATE = (int32_t)-1,
    /* Specifies an unsynchronized playback*/
    FAPI_VIDEC_UNSYNCHRONIZED_STATE,
    /* Specifies an snychronizing state of video decoder by repeating*/
    FAPI_VIDEC_SYNCHRONIZING_BY_REPEATING,
    /* Specifies an synchronizing state of video decoder by skipping*/
    FAPI_VIDEC_SYNCHRONIZING_BY_SKIPPING,
    /* Specifies an repeating current frame because of underflow*/
    FAPI_VIDEC_UNDERFLOW_REPEAT_STATE,
    /* Specifies an synchronized playback state of video decoder*/
    FAPI_VIDEC_SYNCHRONIZED_STATE
} FAPI_VIDEC_SynchronizationStateEnumT;
/*
****************************************************************************
** \brief Field freeze states
****************************************************************************
*/
typedef enum {
    /* Specifies a non field freeze state*/
    FAPI_VIDEC_NO_FIELD_FREEZE_STATE = 0,
    /* Specifies a freezing of Top field only*/
    FAPI_VIDEC_TOP_FIELD_FREEZE_STATE, //1
    /* Specifies a freezing of Bottom field only */
    FAPI_VIDEC_BOT_FIELD_FREEZE_STATE //2
} FAPI_VIDEC_FieldFreezeStateEnumT;
/*
****************************************************************************
** \brief States of each AUD.
****************************************************************************
*/
typedef enum {
    /* Specifies a free state of the AUD, maybe after reset or after being released by VD*/
    FAPI_VIDEC_AUD_STATE_FREE = 0,
    /* Specifies a state where it is filled by extracting it out of Stream*/
    FAPI_VIDEC_AUD_STATE_EXTRACTED_FROM_STREAM,
    /* Specifies a state where it is loaded into Video decoder but not yet released */
    FAPI_VIDEC_AUD_STATE_LOADED_IN_VD
} FAPI_VIDEC_SingleCodedAudStateT;
/*
****************************************************************************
** \brief States of setting decoder playback mode.
****************************************************************************
*/
typedef enum {
    /* Specifies that the request to set playback mode has been served.*/
    FAPI_VIDEC_DECODER_PLAYBACK_ENVIRONMENT_SET = 0,
    /* Specifies a request to change the decoder playback mode*/
    FAPI_VIDEC_REQUEST_TO_SET_DECODER_PLAYBACK_ENVIRONMENT = 1
} FAPI_VIDEC_PlaybackEnvironmentChangeRequestEnumT;
/*
****************************************************************************
** \brief States of setting decoder playback mode.
****************************************************************************
*/
typedef enum {
    /* Specifies that the request to set playback mode has been served.*/
    FAPI_VIDEC_DECODER_PLAYBACK_MODE_SET = 0,
    /* Specifies a request to change the decoder playback mode*/
    FAPI_VIDEC_REQUEST_TO_SET_DECODER_PLAYBACK_MODE = 1
} FAPI_VIDEC_PlaybackModeChangeRequestEnumT;

//*****************************************************************************
//*****************************************************************************
//** Data types
//*****************************************************************************
//*****************************************************************************
/*
*******************************************************************************
** \brief Structure Updated after entropy decoding.
** It is in sync to VCPB process.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         serialNum; //0 49508

    FAPI_VIDEC_AspectRatioEnumT                      decodedPicAspectRatio; //4
    uint32_t                                         decodedWidth; //8 49516
    uint32_t                                         decodedHeight; //12 49520
    FAPI_VIDEC_InterlaceProggStateT                  codedInterlaceProggState; //16

    uint32_t                                         afdUserDataActiveFormatFlag; //20 49528
    uint32_t                                         currAfd; //24 49532

    uint32_t                                         ccUserDataProcessCcDataFlag; //28 49536
    uint32_t                                         ccUserDataCcCount; //32 49540
    uint32_t                                         ccUserDataCcValid[32]; //36
    uint32_t                                         ccUserDataCcType[32]; //164
    uint32_t                                         ccUserDataCcData1[32]; //292
    uint32_t                                         ccUserDataCcData2[32]; //420

    uint32_t                                         barUserDataTopBarFlag; //548 50056
    uint32_t                                         barUserDataEndOfTopBar; //552
    uint32_t                                         barUserDataBotBarFlag; //556
    uint32_t                                         barUserDataStartOfBotBar; //560
    uint32_t                                         barUserDataLeftBarFlag; //564
    uint32_t                                         barUserDataEndOfLeftBar; //568
    uint32_t                                         barUserDataRightBarFlag; //572
    uint32_t                                         barUserDataStartOfRightBar; //576 50084

    uint32_t                                         MPEG2HorizontalSizeValue; //580
    uint32_t                                         MPEG2VerticalSizeValue; //584
    uint32_t                                         MPEG2AspectRatioInformation; //588
    uint32_t                                         MPEG2FrameRateCode; //592
    uint32_t                                         MPEG2BitrateValue; //596
    uint32_t                                         MPEG2VbvBufferSizeValue; //600
    uint32_t                                         MPEG2ProgressiveSequence; //604
    uint32_t                                         MPEG2ChromaFormat; //608
    uint32_t                                         MPEG2HorizontalSizeExtention; //612
    uint32_t                                         MPEG2VerticalSizeExtention; //616
    uint32_t                                         MPEG2BitrateExtention; //620
    uint32_t                                         MPEG2VbvBufferSizeExtention; //624
    uint32_t                                         MPEG2DisplayHorizontalSize; //628
    uint32_t                                         MPEG2DisplayVerticalSize; //632
    uint32_t                                         MPEG2ClosedGop; //636
    uint32_t                                         MPEG2BrokenLink; //640
    uint32_t                                         MPEG2TemporalReference; //644
    uint32_t                                         MPEG2PictureCodingType; //648
    uint32_t                                         MPEG2VbvDelay; //652
    uint32_t                                         MPEG2PictureStructure; //656
    uint32_t                                         MPEG2TopFieldFirst; //660
    uint32_t                                         MPEG2RepeatFirstField; //664
    uint32_t                                         MPEG2ProgressiveFrame; //668
    uint32_t                                         MPEG2CompositeDisplayFlag; //672
    uint32_t                                         MPEG2FieldSequence; //676
    uint32_t                                         MPEG2ColourDescription; //680
    uint32_t                                         MPEG2ColourPrimaries; //684
    uint32_t                                         MPEG2TransferCharacteristics; //688
    uint32_t                                         MPEG2MatrixCoefficient; //692
    uint32_t                                         MPEG2NumberOfFrameCenterOffsets; //696
    uint32_t                                         MPEG2FrameCenterHorizontalOffset0; //700
    uint32_t                                         MPEG2FrameCenterVerticalOffset0; //704
    uint32_t                                         MPEG2FrameCenterHorizontalOffset1; //708
    uint32_t                                         MPEG2FrameCenterVerticalOffset1; //712
    uint32_t                                         MPEG2FrameCenterHorizontalOffset2; //716
    uint32_t                                         MPEG2FrameCenterVerticalOffset2; //720
    uint32_t                                         MPEGDecError; //724
    uint32_t                                         MPEGDecInfo; //728

    uint32_t                                         H264VclHrdBpPresentFlag; //732
    uint32_t                                         H264NalHrdBpPresentFlag; //736
    uint32_t                                         H264BufferingPeriodSeiPresentFlag; //740
    uint32_t                                         H264SequenceParameterSetId; //744 50252
    uint32_t                                         H264NalInitialCpbRemovalDelay; //748
    uint32_t                                         H264NalInitialCpbRemovalDelayOffset; //752
    uint32_t                                         H264VclInitialCpbRemovalDelay; //756
    uint32_t                                         H264VclInitialCpbRemovalDelayOffset; //760
    uint32_t                                         H264ClockTs2PresentFlag; //764
    uint32_t                                         H264ClockTs1PresentFlag; //768
    uint32_t                                         H264ClockTs0PresentFlag; //772
    uint32_t                                         H264PicStructurePresentFlag; //776
    uint32_t                                         H264CpbDpbDelaysPresentFlag; //780
    uint32_t                                         H264PicTimingSeiPresentFlag; //784
    uint32_t                                         H264CpbRemovalDelay; //788
    uint32_t                                         H264DpbOutputDelay; //792
    uint32_t                                         H264PicStructure; //796
    uint32_t                                         H264ClkTimestampFlag0; //800
    uint32_t                                         H264CtType0; //804
    uint32_t                                         H264NuitFieldBasedFlag0; //808
    uint32_t                                         H264CountingType0; //812
    uint32_t                                         H264FullTimestampFlag0; //816
    uint32_t                                         H264DiscontinuityFlag0; //820
    uint32_t                                         H264CntDroppedFlag0; //824
    uint32_t                                         H264NFrames0; //828
    uint32_t                                         H264SecondsFlag0; //832
    uint32_t                                         H264SecondsValue0; //836
    uint32_t                                         H264MinutesFlag0; //840
    uint32_t                                         H264MinutesValue0; //844
    uint32_t                                         H264HoursFlag0; //848
    uint32_t                                         H264HoursValue0; //852
    uint32_t                                         H264TimeOffset0; //856
    uint32_t                                         H264ClkTimestampFlag1; //860
    uint32_t                                         H264CtType1; //864
    uint32_t                                         H264NuitFieldBasedFlag1; //868
    uint32_t                                         H264CountingType1; //872
    uint32_t                                         H264FullTimestampFlag1; //876
    uint32_t                                         H264DiscontinuityFlag1; //880 50388
    uint32_t                                         H264CntDroppedFlag1; //884
    uint32_t                                         H264NFrames1; //888
    uint32_t                                         H264SecondsFlag1; //892
    uint32_t                                         H264SecondsValue1; //896
    uint32_t                                         H264MinutesFlag1; //900
    uint32_t                                         H264MinutesValue1; //904
    uint32_t                                         H264HoursFlag1; //908
    uint32_t                                         H264HoursValue1; //912
    uint32_t                                         H264TimeOffset1; //916
    uint32_t                                         H264ClkTimestampFlag2; //920
    uint32_t                                         H264CtType2; //924
    uint32_t                                         H264NuitFieldBasedFlag2; //928
    uint32_t                                         H264CountingType2; //932
    uint32_t                                         H264FullTimestampFlag2; //936
    uint32_t                                         H264DiscontinuityFlag2; //940
    uint32_t                                         H264CntDroppedFlag2; //944
    uint32_t                                         H264NFrames2; //948
    uint32_t                                         H264SecondsFlag2; //952
    uint32_t                                         H264SecondsValue2; //956
    uint32_t                                         H264MinutesFlag2; //960
    uint32_t                                         H264MinutesValue2; //964
    uint32_t                                         H264HoursFlag2; //968
    uint32_t                                         H264HoursValue2; //972
    uint32_t                                         H264TimeOffset2; //976
    uint32_t                                         H264PanScanSeiPresentFlag; //980
    uint32_t                                         H264PanScanRectangleId; //984
    uint32_t                                         H264PanScanRectCancelFlag; //988 50496
    uint32_t                                         H264PanScanCntMinus1; //992
    uint32_t                                         H264PanScanLeftOffset0; //996
    uint32_t                                         H264PanScanRightOffset0; //1000
    uint32_t                                         H264PanScanTopOffset0; //1004
    uint32_t                                         H264PanScanBotOffset0; //1008
    uint32_t                                         H264PanScanLeftOffset1; //1012
    uint32_t                                         H264PanScanRightOffset1; //1016
    uint32_t                                         H264PanScanTopOffset1; //1020
    uint32_t                                         H264PanScanBotOffset1; //1024
    uint32_t                                         H264PanScanLeftOffset2; //1028 50536
    uint32_t                                         H264PanScanRightOffset2; //1032
    uint32_t                                         H264PanScanTopOffset2; //1036
    uint32_t                                         H264PanScanBotOffset2; //1040
    uint32_t                                         H264PanScanRectRepetitionPeriod; //1044
    uint32_t                                         H264RecoveryPointSeiPresentFlag; //1048
    uint32_t                                         H264RecoveryFrameCount; //1052
    uint32_t                                         H264ExactMatchFlag; //1056
    uint32_t                                         H264BrokenLinkFlag; //1060
    uint32_t                                         H264ChangingSliceGroupIdc; //1064
    uint32_t                                         H264PrimaryPicType; //1068
    uint32_t                                         H264NalRefIdc; //1072
    uint32_t                                         H264NalUnitType; //1076
    uint32_t                                         H264MaxDpbSize; //1080
    uint32_t                                         H264PicWidthInMbsMinus1; //1084
    uint32_t                                         H264FrameHeightInMbs; //1088
    uint32_t                                         H264Log2MaxFrameNumMinus4; //1092 50600
    uint32_t                                         H264FrameMbsOnlyFlag; //1096
    uint32_t                                         H264MbAdaptiveFrameFieldFlag; //1100
    uint32_t                                         H264ProfileIdc; //1104
    uint32_t                                         H264LevelIdc; //1108
    uint32_t                                         H264FrameCropTopOffset; //1112
    uint32_t                                         H264FrameCropBotOffset; //1116
    uint32_t                                         H264FrameCropLeftOffset; //1120
    uint32_t                                         H264FrameCropRightOffset; //1124
    uint32_t                                         H264PicParameterSetId; //1128
    uint32_t                                         H264SeqParameterSetId; //1132
    uint32_t                                         H264ChromaQpIndexOffset; //1136
    uint32_t                                         H264SecondChromaQpIndexOffset; //1140
    uint32_t                                         H264Transform8x8ModeFlag; //1144
    uint32_t                                         H264FrameNum; //1148 50656
    uint32_t                                         H264IdrPicId; //1152
    uint32_t                                         H264TopFieldOrderCount; //1156
    uint32_t                                         H264BotFieldOrderCount; //1160
    uint32_t                                         H264ChromaFormatIdc; //1164
    uint32_t                                         H264FieldPicFlag; //1168
    uint32_t                                         H264BotFieldFlag; //1172
    uint32_t                                         H264EndOfSequenceRbsp; //1176
    uint32_t                                         H264EndOfStreamRbsp; //1180
    uint32_t                                         H264BitRate; //1184
    uint32_t                                         H264AspectRatioInfoPresentFlag; //1188
    uint32_t                                         H264AspectRatioIdc; //1192
    uint32_t                                         H264SarWidth; //1196
    uint32_t                                         H264SarHeight; //1200
    uint32_t                                         H264VideoSignalTypePresentFlag; //1204
    uint32_t                                         H264TimingfInfoPresentFlag; //1208
    uint32_t                                         H264ColourDescriptionPresentFlag; //1212
    uint32_t                                         H264ChromaLocInfoPresentFlag; //1216
    uint32_t                                         H264VideoFullRangeFlag; //1220
    uint32_t                                         H264VideoFormat; //1224
    uint32_t                                         H264NumUnitsInTick; //1228
    uint32_t                                         H264TimeScale; //1232
    uint32_t                                         H264FixedFrameRateFlag; //1236
    uint32_t                                         H264ColourPrimaries; //1240
    uint32_t                                         H264TransferCharacteristics; //1244
    uint32_t                                         H264MatrixCoefficient; //1248
    uint32_t                                         H264ChromaSampleLocTypeTopField; //1252
    uint32_t                                         H264ChromaSampleLocTypeBotField; //1256 50764
    uint32_t                                         H264DecError; //1260
    uint32_t                                         H264DecInfo; //1264
    //1268
} FAPI_VIDEC_SingleOutcomeOfDecodeT;
/*
*******************************************************************************
** \brief Structure for outcome of decode process
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_SingleOutcomeOfDecodeT                table[OOD_FIFO_MAX_NUM]; //49508
    int32_t                                          wPtr; //698724
    int32_t                                          rPtrMemory; //698728
} FAPI_VIDEC_OutcomeOfDecodeDataT;
/*
*******************************************************************************
** \brief Structure Shared by BM & Videc drivers.
*******************************************************************************
*/
typedef struct{
#if 0
    uint32_t                                         picType;
    uint32_t                                         serialNum;
    uint32_t                                         decMode;
    uint32_t                                         streamFlushMarker;
    uint32_t                                         pesHeaderAuFlag;
    uint32_t                                         codedPicPtr;
    uint32_t                                         codedPicSize;
    uint32_t                                         ptsValidFlag;
    uint32_t                                         dtsValidFlag;
#else
    int Data_0; //0
    int Data_4; //4
    int Data_8; //8
    int Data_12; //12
    int Data_16; //16
    int Data_20; //0
    int Data_24; //4
    int codedPicPtr; //28
    int codedPicSize; //32
    int Data_36; //16
    int Data_40; //40
#endif
    uint64_t                                         pts; //44
    uint64_t                                         dts; //52
    FAPI_VIDEC_SingleCodedAudStateT                  state; //60
    //64
} FAPI_VIDEC_SingleCodedFrameDataT;
/*
*******************************************************************************
** \brief Structure Shared by Viscale , BM & Videc drivers
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_SingleCodedFrameDataT                 codedPic[AUD_FIFO_MAX_NUM]; //252
    int32_t                                          wPtr; //49404
    int32_t                                          rPtr;
    int32_t                                          fPtr; //49412
    int32_t                                          fillLevel; //49416
    int32_t                                          fillLevelLimit; //49420

    //Mpeg
    uint32_t                                         entryPointFound; //49424
    uint32_t                                         seqStartFound; //49428
    uint32_t                                         seqStartPtr;

    //State of AUDs
    uint32_t                                         audStateVar;
    uint32_t                                         lastFoundPtr;

    //Average bit rate
    uint64_t                                         monitorStartTimeABR;
    uint64_t                                         totalCodedStreamSizeABR;

    //Current bit rate
    uint32_t                                         audCountCBR;
    uint64_t                                         monitorStartTimeCBR;
    uint64_t                                         totalCodedStreamSizeCBR;
} FAPI_VIDEC_AudDataT;
/*
*******************************************************************************
** \brief Structure for one frame of the display process.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         serialNum; //0 698744
    uint32_t                                         displayFrameBank; //4 698748
    uint32_t                                         displayWidth; //8 698752
    uint32_t                                         displayHeight; //12 698756
    uint32_t                                         decodedWidth; //16 698760
    uint32_t                                         decodedHeight; //20 698764
    uint32_t                                         displayOrderInfo; //24 698768
    uint32_t                                         topFieldSerialNo; //28 698772
    uint32_t                                         botFieldSerialNo; //32 698776
    uint32_t                                         ptsValidFlag; //36 698780
    uint32_t                                         dtsValidFlag; //40 698784
    uint32_t                                         pts; //44 698788
    uint32_t                                         dts; //48 698792
    FAPI_VIDEC_DecodedFrameStateEnumT                state; //52 698796
    uint32_t                                         topDecError; //56 698800
    uint32_t                                         botDecError; //60 698804
    uint32_t                                         vdpbDispCount; //64 698808
    FAPI_VIDEC_AspectRatioEnumT                      decodedPicAspectRatio; //68 698812
    FAPI_VIDEC_AspectRatioEnumT                      activePicAspectRatioL0; //72 698816
    FAPI_VIDEC_AspectRatioEnumT                      activePicAspectRatioL1; //76 698820
    uint32_t                                         afdUserDataActiveFormatFlag; //80 698824
    uint32_t                                         currAfd; //84 698828
    FAPI_VIDEC_InterlaceProggStateT                  codedInterlaceProggState; //88 698832
    FAPI_VIDEC_InterlaceProggStateT                  readoutInterlaceProggState; //92 698836
    uint32_t                                         barUserDataTopBarFlag; //96 698840
    uint32_t                                         barUserDataEndOfTopBar; //100 698844
    uint32_t                                         barUserDataBotBarFlag; //104 698848
    uint32_t                                         barUserDataStartOfBotBar; //108 698852
    uint32_t                                         barUserDataLeftBarFlag; //112 698856
    uint32_t                                         barUserDataEndOfLeftBar; //116 698860
    uint32_t                                         barUserDataRightBarFlag; //120 698864
    uint32_t                                         barUserDataStartOfRightBar; //124 698868
    int Data_128; //128
    //132
} FAPI_VIDEC_SingleDecodedFrameDataT;
/*
*******************************************************************************
** \brief Structure for fifo of frames for the display process.
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_SingleDecodedFrameDataT               decodedPic[FRAME_FIFO_MAX_NUM]; //698744
    int32_t                                          wPtr; //705080
    int32_t                                          rPtr; //705084
    int32_t                                          fillLevel; //705088
    int32_t                                          fillLevelLimit; //705092
} FAPI_VIDEC_FrameDataT;
/*
*******************************************************************************
** \brief Structure for scaling and cropping current frame.
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_AspectRatioEnumT                      aspectRatio; //0
    FAPI_VIDEC_AspectRatioEnumT                      activeAspectRatioL0; //4
    FAPI_VIDEC_AspectRatioEnumT                      activeAspectRatioL1; //8
    uint32_t                                         frameField; //12
    uint32_t                                         fieldInversion; //16
    uint32_t                                         x0; //20
    uint32_t                                         y0; //24
    uint32_t                                         displayWidth; //28
    uint32_t                                         displayHeight; //32
    uint32_t                                         decodedWidth; //36
    uint32_t                                         decodedHeight; //40
    uint32_t                                         topFieldSerialNo; //44
    uint32_t                                         botFieldSerialNo; //48
    uint32_t                                         currAfd; //52
    FAPI_VIDEC_InterlaceProggStateT                  codedInterlaceProggState; //56
    FAPI_VIDEC_InterlaceProggStateT                  readoutInterlaceProggState; //60
    FAPI_VIDEC_MpegIFrameStateEnumT                  mpegIFrameState; //64
    uint32_t                                         frameIdx; //68
    //72
} FAPI_VIDEC_FrameCropDataT;
/*
*******************************************************************************
** \brief Structure for pvr related handling.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         setPtsToStc; //0
    uint32_t                                         ptsDrift; //4
    uint64_t                                         pts; //8
} FAPI_VIDEC_PvrDataT;
/*
*******************************************************************************
** \brief decoder playback environment settings state machine.
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_PlaybackEnvironmentChangeRequestEnumT playbackEnvironmentChangeReqState; //0
    FAPI_VIDEC_PlaybackEnvironmentEnumT              currPlaybackEnvironment; //4
    FAPI_VIDEC_PlaybackEnvironmentEnumT              targetPlaybackEnvironment; //8
} FAPI_VIDEC_PlaybackEnvironmentChangeRequestDataT;
/*
*******************************************************************************
** \brief decoder playback mode settings state machine.
*******************************************************************************
*/
typedef struct{
    FAPI_VIDEC_PlaybackModeChangeRequestEnumT        playbackModeChangeReqState; //0
    FAPI_VIDEC_PlaybackModeEnumT                     currPlaybackMode; //4
    FAPI_VIDEC_PlaybackModeEnumT                     targetPlaybackMode; //8
} FAPI_VIDEC_PlaybackModeChangeRequestDataT;
/*
*******************************************************************************
** \parameter change detection unit.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         paramChangeTrigger;
    FAPI_VIDEC_FrameInfoStateT                       nextFrameInfo;
    FAPI_VIDEC_FrameInfoStateT                       lastFrameInfo;
} FAPI_VIDEC_ParamChangeTriggerDataT;
/*
*******************************************************************************
** \brief Channel Information of BM and TSD Units.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         blockIndex;
    uint32_t                                         channelId;
} FAPI_VIDEC_ChannelDataT;
/*
*******************************************************************************
** \brief es buffer Info.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         size; //0
    uint32_t                                         criticalThreshold; //4
    uint32_t                                         optimalThreshold; //8
    uint32_t                                         fillLevel; //12
    uint32_t                                         availableSpace; //16
} FAPI_VIDEC_EsBufferDataT;
/*
*******************************************************************************
** \brief dummy video decoder segment.
*******************************************************************************
*/
typedef struct {
    uint32_t                                         sizeMBytes;
    uint32_t                                         memoryMode;
    uint32_t                                         functionMode;
    uint32_t                                         strategyMode;
    uint32_t                                         alignmentBits;
} FAPI_VIDEC_HeapParamsT;
/*
*******************************************************************************
** \brief decoder memory segments.
*******************************************************************************
*/
typedef struct{
    uint32_t                                         inUse; //0
    uint32_t                                         memoryInfoAvailable; //4
    int32_t                                          error; //8

    uint32_t                                         ramifsStartAddress; //12
    uint32_t                                         axiWrapperStartAddress; //16
    uint32_t                                         axiSeqAreaStartAddress; //20
    uint32_t                                         axiSeqAreaSize; //24
    uint32_t                                         axiCcAreaStartAddress; //28
    uint32_t                                         axiCcAreaSize; //32
    uint32_t                                         axiMvAreaStartAddress; //36
    uint32_t                                         axiMvAreaSize; //40
    uint32_t                                         axiDvAreaStartAddress; //44
    uint32_t                                         axiDvAreaSize; //48
    uint32_t                                         videoStreamAreaStartAddress; //52
    uint32_t                                         videoStreamAreaSize; //56
    uint32_t                                         vcpbInfoTableStartAddress; //60
    uint32_t                                         vcpbInfoTableSize; //64
    uint32_t                                         vdpbInfoTableStartAddress; //68
    uint32_t                                         vdpbInfoTableSize; //72
    uint32_t                                         pcpuWorkAreaStartAddress; //76
    uint32_t                                         pcpuWorkAreaSize; //80
    uint32_t                                         decStartParamsStartAddress; //84
    uint32_t                                         decStartParamsSize; //88
    uint32_t                                         oodInfoTableStartAddress; //92
    uint32_t                                         oodInfoTableSize; //96
} FAPI_VIDEC_MemoryInfoDataT;
/*
*******************************************************************************
** \brief decoder memory segments.
*******************************************************************************
*/
typedef struct{
    // Preinit & preopen definations
    uint32_t                                         piDone; //0
    int32_t                                          piError; //4
    FAPI_VIDEC_DecoderNumberEnumT                    piMemoryForDecoderNumber; //8
    uint32_t                                         piMemoryAllocationType; //12

#ifndef __LINUX__
    FAPI_MMU_HeapParamsT                             segmentParams; //16
#else
    FAPI_VIDEC_HeapParamsT                           segmentParams;
#endif

    // Preopen & postinit definations
    FAPI_SYS_HandleT                                 segmentHandle; //36
    FAPI_VIDEC_MemoryInfoDataT                       virtualMemoryInfo; //40
    FAPI_VIDEC_MemoryInfoDataT                       physicalMemoryInfo;
} FAPI_VIDEC_VideoDecoderMemoryDataT;
/*
*******************************************************************************
** \brief Trace for Isr.
*******************************************************************************
*/
typedef struct {
    char_t                                           buff0[1024];
    uint32_t                                         buff1[1024];
    uint32_t                                         buff2[1024];
    uint32_t                                         buff3[1024];
    uint32_t                                         wPtr;
    uint32_t                                         rPtr;
}FAPI_VIDEC_TraceT;
/*
*******************************************************************************
** \brief The Data Structure containing the feilds for operating a Video
** Decoder. The feilds are updated by Video driver as well as the HW from
** ISR command/response message.
*******************************************************************************
*/
typedef struct {
    uint32_t                                         inUse; //0

    //Time intervals between last and current units.
//    uint64_t                                         ;
//    uint64_t                                         currAudDetectTimeMsec;
//    uint64_t                                         ;
//    uint64_t                                         currVdpbDecTimeMsec;
    uint64_t currIsrTimeUsec; //4
    uint64_t Data_12; //12
    uint64_t currVcpbDecTimeMsec; //20
    uint64_t Data_28; //28

    uint64_t Data_36; //36
    uint64_t Data_44; //44
    uint64_t Data_52; //52
    uint64_t Data_60; //60

    uint32_t isrMask; //68
    uint32_t isrStatus; //72
    uint32_t isrSerialIdx; //76
    uint32_t isrCurrField; //80
    uint32_t isrNextField; //84
    
    //System Memory allocation
    FAPI_VIDEC_MemoryInfoDataT* virtualMemoryInfoPtr; //88
    FAPI_VIDEC_MemoryInfoDataT* physicalMemoryInfoPtr; //92

    //System static variables
    FAPI_VIDEC_ChannelDataT  channelInfo; //96
    FAPI_VIDEC_DecoderNumberEnumT decoderNumber; //104
    FAPI_VIDEC_DecoderEnumT decoderType; //108
    FAPI_VIDEC_DecoderFrameBankSizeEnumT decodeFrameBankSizeType; //112
    FAPI_VIDEC_AfdStateEnumT decoderAfdState; //116
    Enum_120 Data_120; //120
    uint32_t Data_124; //124
    uint32_t Data_128; //128

    FAPI_VIDEC_EsBufferDataT bufferInfo; //132

    FAPI_VIDEC_PlaybackEnvironmentEnumT decoderPlaybackEnvironment; //152
    FAPI_VIDEC_PlaybackModeEnumT decoderPlaybackMode; //156
    FAPI_VIDEC_DisplayModeEnumT decoderDisplayMode; //160

    FAPI_VIDEC_BootStateEnumT bootState; //164
    FAPI_VIDEC_HardResetStatesEnumT resetState; //168
    FAPI_VIDEC_StartStopStatesEnumT startStopState; //172
    FAPI_VIDEC_EnableStatesEnumT enableDisableState; //176
    int Data_180; //180
    FAPI_VIDEC_HealthStateEnumT healthState; //184
    FAPI_VIDEC_MpegIFrameStateEnumT mpegIFrameState; //188
    int Data_192; //192
    uint32_t Data_196; //196
    Enum_200 Data_200; //200
    /*FAPI_VIDEC_AfdStateEnumT*/uint32_t Data_204; //204
    
    //Stream Statistics as determined by getVesParams process
    FAPI_VIDEC_VESParamsT vesInfo; //208
    
    //AUD pic variables  of the current aud entry
    FAPI_VIDEC_AudDataT audInfo; //252
    uint64_t audLastPts; //49480
    uint32_t audIdx; //49488
    
    //Codec pic variables of the current vcpb entry
    uint32_t vcpbAddress; //49492
    int32_t vcpbLength; //49496
    uint32_t vcpbLoadIdx; //49500
    uint32_t vcpbIdx; //49504

    //Entropy decoded pic variables  of the current entropy decoded aud entry
    FAPI_VIDEC_OutcomeOfDecodeDataT oodInfo; //49508
    uint32_t oodSerialNum; //698732
    uint32_t oodEntropyDecodedAudIdx; //698736
    uint32_t oodIdx; //698740

    //Fifo of the decoder vdpb units
    FAPI_VIDEC_FrameDataT frameInfo; //698744

    //Decoded pic variables of the current decoded pic,
    //Idx is a normal serial counter, SerialNum is mirror of the
    //respective field in the info tables.
    int32_t vdpbDecodedFramesAvailable; //705096
    uint32_t vdpbSerialNum; //705100
    uint32_t Data_705104; //vdpbVclDecodedAudIdx; //705104
    uint32_t vdpbIdx; //705108

    //Last known good display picture variables for error recovery.
    FAPI_VIDEC_FrameCropDataT lkgFrameCrop; //705112

    //Playback environment change request related stuff.
    FAPI_VIDEC_PlaybackEnvironmentChangeRequestDataT pecrInfo; //705184
    //Playback mode change request related stuff.
    FAPI_VIDEC_PlaybackModeChangeRequestDataT        pmcrInfo; //705196
    
    //Pvr related stuff.
    FAPI_VIDEC_PvrDataT                pvrInfo; //705208
    
    //parameter change trigger
    FAPI_VIDEC_ParamChangeTriggerDataT pctInfo; //705224

    //Timestamps of last frame.
    uint64_t Data_705268; //705268
    uint64_t Data_705276; //705276
    uint64_t Data_705284; //705284

    //Current display picture variables of the current display pic.
    FAPI_VIDEC_FieldFreezeStateEnumT   frameFieldState; //705292
    uint32_t                           frameStartDisplay; //705296
    FAPI_VIDEC_DecodedFrameStateEnumT  frameState; //705300
    uint32_t                           frameBank; //705304
    FAPI_VIDEC_FrameCropDataT          frameCrop; //705308
    uint32_t                           frameDisplayOrderInfo; //705380
    uint32_t                           frameTopFieldNo; //705384
    uint32_t                           frameBotFieldNo; //705388
    uint32_t                           frameSerialNum; //705392
    uint32_t                           frameIdx; //705396
    uint32_t                           frameDecError; //705400
    
    uint32_t Data_705404; //705404
    
    //Switch for invoking autoscaling.
    uint32_t                           invokeAutoScalers; //705408
    
    //Fields for reporting info after entropy decoding.
    FAPI_VIDEC_EntropyDecInfoCallbackT entropyDecInfoCbk; //705412
    FAPI_VIDEC_EntropyDecInfoStateT entropyDecInfoData; //705416
    void* entropyOptData; //706120
    
    //Fields for reporting info after video decoding.
    FAPI_VIDEC_VideoDecInfoCallbackT videoDecInfoCbk; //706124
    FAPI_VIDEC_VideoDecInfoStateT    videoDecInfoData; //706128
    void*                            videoOptData; //706192

    //Fields for initiating auto scaling functionality on HD scaler.
    FAPI_VIDEC_AutoScaleCallbackT hdAutoScaleCbk; //706196
    FAPI_SYS_HandleT              hdScalerHandle; //706200
                                         
    //Fields for initiating auto scaling functionality on SD scaler.
    FAPI_VIDEC_AutoScaleCallbackT sdAutoScaleCbk; //706204
    FAPI_SYS_HandleT              sdScalerHandle; //706208
    
    //Fields for reporting if the stream is decodable or not.
    FAPI_VIDEC_FrameDecodedCallbackT frameDecodedCbk; //706212
    void*                            frameDecodedOptData; //706216

    FAPI_VIDEC_FrameAvailableCallbackT frameAvailableCbk; //706220
    void*                              frameAvailableOptData; //706224

    FAPI_VIDEC_FrameAvailableCallbackT vesOverflowCbk; //706228
    void*                              vesOverflowOptData; //706232

    //Fields for reporting if the picture parameter has changed.
    FAPI_VIDEC_ParamChangeCallbackT paramChangeCbk; //706236
    void*                           paramChangeOptData; //706240
    
#if 0
    //Time intervals between last and current units.
    uint64_t                                         currIsrTimeUsec;
    uint64_t                                         currAudDetectTimeMsec;
    uint64_t                                         currVcpbDecTimeMsec;
    uint64_t                                         currVdpbDecTimeMsec;

    //Time since last (Tsl) decoded unit.
    uint64_t                                         isrExeTimeUsec;
    uint64_t                                         isrTslAudMsec;
    uint64_t                                         isrTslVcpbMsec;
    uint64_t                                         isrTslVdpbMsec;

    //Interrupt variables
    uint32_t                                         isrMask;
    uint32_t                                         isrStatus;
    uint32_t                                         isrSerialIdx;
    uint32_t                                         isrCurrField;
    uint32_t                                         isrNextField;

    //System Memory allocation
    FAPI_VIDEC_MemoryInfoDataT*                      virtualMemoryInfoPtr;
    FAPI_VIDEC_MemoryInfoDataT*                      physicalMemoryInfoPtr; //92

    //System static variables
    FAPI_VIDEC_ChannelDataT                          channelInfo; //96
    FAPI_VIDEC_DecoderNumberEnumT                    decoderNumber; //104
    FAPI_VIDEC_DecoderEnumT                          decoderType; //108
    FAPI_VIDEC_DecoderFrameBankSizeEnumT             decodeFrameBankSizeType; //112
    FAPI_VIDEC_AfdStateEnumT                         decoderAfdState; //116
    uint32_t Data_124; //124

    //System dynamic variables.
    FAPI_VIDEC_EsBufferDataT                         bufferInfo; //120
    FAPI_VIDEC_PlaybackEnvironmentEnumT              decoderPlaybackEnvironment; //140
    FAPI_VIDEC_PlaybackModeEnumT                     decoderPlaybackMode; //144
    FAPI_VIDEC_DisplayModeEnumT                      decoderDisplayMode; //148

    //State variables.
    FAPI_VIDEC_BootStateEnumT                        bootState; //152
    FAPI_VIDEC_HardResetStatesEnumT                  resetState; //156
    FAPI_VIDEC_StartStopStatesEnumT                  startStopState; //160
    FAPI_VIDEC_EnableStatesEnumT                     enableDisableState; //164
    FAPI_VIDEC_SkipRepeatStateEnumT                  skipRepeatState;
    FAPI_VIDEC_HealthStateEnumT                      healthState;
    FAPI_VIDEC_MpegIFrameStateEnumT                  mpegIFrameState;
    FAPI_VIDEC_SynchronizationStateEnumT             syncState;

    //Stream`s current Afd
    uint32_t                                         currAfd;

    //Stream Statistics as determined by getVesParams process
    FAPI_VIDEC_VESParamsT                            vesInfo;

    //AUD pic variables  of the current aud entry
    FAPI_VIDEC_AudDataT                              audInfo;
    uint64_t                                         audLastPts;
    uint32_t                                         audIdx;

    //Codec pic variables of the current vcpb entry
    uint32_t                                         vcpbAddress;
    int32_t                                          vcpbLength;
    uint32_t                                         vcpbLoadIdx;
    uint32_t                                         vcpbIdx;

    //Entropy decoded pic variables  of the current entropy decoded aud entry
    FAPI_VIDEC_OutcomeOfDecodeDataT                  oodInfo;
    uint32_t                                         oodSerialNum;
    uint32_t                                         oodEntropyDecodedAudIdx;
    uint32_t                                         oodIdx;

    //Fifo of the decoder vdpb units
    FAPI_VIDEC_FrameDataT                            frameInfo;

    //Decoded pic variables of the current decoded pic,
    //Idx is a normal serial counter, SerialNum is mirror of the
    //respective field in the info tables.
    int32_t                                          vdpbDecodedFramesAvailable;
    uint32_t                                         vdpbSerialNum;
    uint32_t                                         vdpbVclDecodedAudIdx;
    uint32_t                                         vdpbIdx;

    //Last known good display picture variables for error recovery.
    FAPI_VIDEC_FrameCropDataT                        lkgFrameCrop;

    //Playback environment change request related stuff.
    FAPI_VIDEC_PlaybackEnvironmentChangeRequestDataT pecrInfo;
    //Playback mode change request related stuff.
    FAPI_VIDEC_PlaybackModeChangeRequestDataT        pmcrInfo;
    //Pvr related stuff.
    FAPI_VIDEC_PvrDataT                              pvrInfo;
    //parameter change triggerr
    FAPI_VIDEC_ParamChangeTriggerDataT               pctInfo;

    //Timestamps of last frame.
    int64_t                                          frameLastStc;
    int64_t                                          frameLastPts;

    //Current display dicture variables of the current display pic.
    FAPI_VIDEC_FieldFreezeStateEnumT                 frameFieldState;
    uint32_t                                         frameStartDisplay;
    FAPI_VIDEC_DecodedFrameStateEnumT                frameState;
    uint32_t                                         frameBank;
    FAPI_VIDEC_FrameCropDataT                        frameCrop;
    uint32_t                                         frameDisplayOrderInfo;
    uint32_t                                         frameTopFieldNo;
    uint32_t                                         frameBotFieldNo;
    uint32_t                                         frameSerialNum;
    uint32_t                                         frameIdx;
    uint32_t                                         frameDecError;

    //Frame Free variables of the current frame being freed.
    uint32_t                                         frameFreeIdx;

    //Switch for invoking autoscaling.
    uint32_t                                         invokeAutoScalers;

    //Fields for reporting info after entropy decoding.
    FAPI_VIDEC_EntropyDecInfoCallbackT               entropyDecInfoCbk;
    FAPI_VIDEC_EntropyDecInfoStateT                  entropyDecInfoData;
    void*                                            entropyOptData;

    //Feilds for reporting info after video decoding.
    FAPI_VIDEC_VideoDecInfoCallbackT                 videoDecInfoCbk;
    FAPI_VIDEC_VideoDecInfoStateT                    videoDecInfoData;
    void*                                            videoOptData;

    //Fields for initiating auto scaling functionality on HD scaler.
    FAPI_VIDEC_AutoScaleCallbackT                    hdAutoScaleCbk;
    FAPI_SYS_HandleT                                 hdScalerHandle;

    //Fields for initiating auto scaling functionality on SD scaler.
    FAPI_VIDEC_AutoScaleCallbackT                    sdAutoScaleCbk;
    FAPI_SYS_HandleT                                 sdScalerHandle;

    //Fields for reporting if the stream is decodable or not.
    FAPI_VIDEC_FrameDecodedCallbackT                 frameDecodedCbk;
    void*                                            frameDecodedOptData;

    //Fields for reporting if the stream is decodable or not.
    FAPI_VIDEC_FrameAvailableCallbackT               frameAvailableCbk;
    void*                                            frameAvailableOptData;

    //Fields for reporting if the stream is decodable or not.
    FAPI_VIDEC_FrameAvailableCallbackT               vesOverflowCbk;
    void*                                            vesOverflowOptData;

    //Fields for reporting if the picture parameter has changed.
    FAPI_VIDEC_ParamChangeCallbackT                  paramChangeCbk;
    void*                                            paramChangeOptData;

#ifdef FAPI_VIDEC_DEBUG
    //Trace buffer.
    FAPI_VIDEC_TraceT                                trc;
#endif

#endif

} FAPI_VIDEC_VideoDecoderIsrDataT;
/*
*******************************************************************************
** \brief The Handle Data Structure containing the feilds for opening a Video
** Decoder. It has fields for Video decoder signature and decoder type.
** Additionally Video decoder open parameters are also required.
** \sa FAPI_VIDEC_VideoDecoderHandleT
*******************************************************************************
*/
typedef struct {
    uint32_t                                         inUse; //0
    char_t                                           coreName[32]; //4
    uint64_t                                         coreID; //36
    uint32_t                                         baseAddress; //44
    uint32_t                                         decoderBufferSize; //48
    FAPI_VIDEC_DecoderFrameBankSizeEnumT             vBankType; //52
    uint32_t                                         coreSel; //56
    uint32_t                                         bankSize; //60
    uint32_t                                         bankNum; //64
    uint32_t                                         bankNumForBumping; //68
    FAPI_VIDEC_OpenParamsT                           opParams; //72
    FAPI_VIDEC_MemoryInfoDataT*                      virtualMemoryInfoPtr; //104
    FAPI_VIDEC_MemoryInfoDataT*                      physicalMemoryInfoPtr; //108
    FAPI_VIDEC_VideoDecoderIsrDataT*                 isrDataPtr; //112
    FAPI_VIDEC_VersionStateEnumT                     firmwareVersionMatch; //116
    uint32_t                                         firmwareVersionInFlash; //120
    uint32_t                                         firmwareVersionSupported; //124
    FAPI_VIDEC_DisplayModeEnumT                      decoderDisplayMode; //128
    FAPI_VIDEC_PesParserEnumT                        associatedPesParser; //132
    uint32_t                                         ptsLocation; //136

    int32_t (*Start)(FAPI_SYS_HandleT handle); //140
    int32_t (*Stop) (FAPI_SYS_HandleT handle); //144
    int32_t (*ShutDown)(void); //148
    int32_t (*Reset)(FAPI_SYS_HandleT handle, FAPI_VIDEC_ResetEnumT resetType); //152
    int32_t (*EnableDisable)(FAPI_SYS_HandleT handle,
                              FAPI_VIDEC_EnableDisableStateEnumT enableSwitch); //156
    int32_t (*SetPlaybackMode)(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_PlaybackModeEnumT mode); //160
    int32_t (*SetPlaybackEnvironment)(FAPI_SYS_HandleT handle,
                                     FAPI_VIDEC_PlaybackEnvironmentEnumT mode); //164
    int32_t (*GetVesParams)(FAPI_SYS_HandleT handle,
                            FAPI_VIDEC_VESParamsT* vesParamsPtr,
                                                         uint32_t suspendType); //168
    int32_t (*GetVesBufferPosition)(FAPI_SYS_HandleT handle,
                                                          uint32_t* bufferPtr); //172
    int32_t (*GetVesBufferSize)(FAPI_SYS_HandleT handle, uint32_t* bufferSize); //176
    int32_t (*GetVesFillLevel)(FAPI_SYS_HandleT handle, uint32_t* fillLevel); //180
    int32_t (*GetVesAvailableSpace)(FAPI_SYS_HandleT handle,
                                                     uint32_t* availableSpace); //184
    int32_t (*GetState)(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_GetStateT* getStatePtr); //188
    int32_t (*GetHealth)(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_HealthStateEnumT* health); //192
    int32_t (*GetDecodingLatency)(FAPI_SYS_HandleT handle,
                                               int64_t* decoderLatencyInTicks); //196
    void    (*AudCallback)(uint32_t audNum, uint32_t audSearchPattern,
                                   uint32_t foundPtr, FAPI_SYS_HandleT handle); //200
    int32_t (*Recover)(FAPI_SYS_HandleT handle); //204
    int32_t (*DecodeSingleMpegIFrame)(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes); //208
    int32_t (*DisplaySingleMpegIFrame)(FAPI_SYS_HandleT handle); //212
    int32_t (*DecodeSequenceOfMpegIFrame)(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes); //216
    int32_t (*DisplaySequenceOfMpegIFrame)(FAPI_SYS_HandleT handle); //220
    int32_t (*SetEntropyDecInfoCallback)(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_EntropyDecInfoCallbackT entropyDecInfoCallbackFunction,
                                                         void* entropyOptData); //224
    int32_t (*SetVideoDecInfoCallback)(FAPI_SYS_HandleT handle,
                 FAPI_VIDEC_VideoDecInfoCallbackT videoDecInfoCallbackFunction,
                                                           void* videoOptData); //228
    int32_t (*SetAutoScaleCallback)(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_AutoScaleCallbackT autoScaleCallbackFunction,
                                                           void* scalerHandle); //232
    int32_t (*SetDecoderToHdEncoder)(FAPI_SYS_HandleT handle,
                                               FAPI_SYS_HandleT viencHdHandle); //236
    int32_t (*SetPesParserToDecoder)(FAPI_SYS_HandleT handle,
                                       FAPI_VIDEC_PesParserEnumT pesParserNum); //240
    int32_t (*SetFrameDecodedCallback)(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_FrameDecodedCallbackT
                                                  frameDecodedCallbackFunction,
                                                    void* frameDecodedOptData); //244
    int32_t (*SetFrameAvailableCallback)(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_FrameAvailableCallbackT
                                                frameAvailableCallbackFunction,
                                                  void* frameAvailableOptData); //248
    int32_t (*SetVesOverflowCallback)(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_VesOverflowCallbackT
                                                vesOverflowCallbackFunction,
                                                     void* vesOverflowOptData); //252
    int32_t (*SetMpegIFrameMode)(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_MpegIFrameModeEnumT mode); //256
    int32_t (*SetChannelId)(FAPI_SYS_HandleT handle, uint32_t blockIndex,
                                                           uint32_t channelId); //260
    int32_t (*SetParamChangeCallback)(FAPI_SYS_HandleT handle,
                   FAPI_VIDEC_ParamChangeCallbackT paramChangeCallbackFunction,
                                                     void* paramChangeOptData); //264
    int32_t (*SetAfdState)(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_AfdStateEnumT afdState); //268
    int32_t (*Func_272)(FAPI_SYS_HandleT handle, int32_t a); //272
    //276
} FAPI_VIDEC_VideoDecoderHandleT;
//*****************************************************************************
//*****************************************************************************
//** Global Data & API
//*****************************************************************************
//*****************************************************************************
int32_t fapi_videc_0initialize(FAPI_VIDEC_VideoDecoderHandleT* handlePtr);
extern FAPI_VIDEC_VideoDecoderIsrDataT videcIsrData[FAPI_VIDEC_MAX_NUM_DECODERS];
extern uint32_t fvm0d[1024];
extern uint32_t fvm1d[30*1024];
extern uint32_t fvm2d[1024];
extern uint32_t fvm0la;
extern uint32_t fvm1la;
extern uint32_t fvm2la;
extern uint32_t fvm0sz;
extern uint32_t fvm1sz;
extern uint32_t fvm2sz;
extern uint32_t fvh0d[1024];
extern uint32_t fvh1d[30*1024];
extern uint32_t fvh2d[1024];
extern uint32_t fvh0la;
extern uint32_t fvh1la;
extern uint32_t fvh2la;
extern uint32_t fvh0sz;
extern uint32_t fvh1sz;
extern uint32_t fvh2sz;
extern uint32_t videcSupportedFirmwareVersions[5];
void videc_lock(void);
void videc_unlock(void);
//*****************************************************************************
//*****************************************************************************
//** Local Data & API
//*****************************************************************************
//*****************************************************************************
uint32_t checkHandle(FAPI_VIDEC_VideoDecoderHandleT* handlePtr);
int32_t fapi_videc_0start(FAPI_SYS_HandleT handle);
int32_t fapi_videc_0stop(FAPI_SYS_HandleT handle);
int32_t fapi_videc_0shutdown(void);
int32_t fapi_videc_0reset(FAPI_SYS_HandleT handle,
                                              FAPI_VIDEC_ResetEnumT resetType);
int32_t fapi_videc_0enabledisable(FAPI_SYS_HandleT handle,
                              FAPI_VIDEC_EnableDisableStateEnumT enableSwitch);
int32_t fapi_videc_0setplaybackmode(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_PlaybackModeEnumT mode);
int32_t fapi_videc_0setplaybackenvironment(FAPI_SYS_HandleT handle,
                                     FAPI_VIDEC_PlaybackEnvironmentEnumT mode);
int32_t fapi_videc_0getvesparams(FAPI_SYS_HandleT handle,
                    FAPI_VIDEC_VESParamsT* vesParamsPtr, uint32_t suspendType);
int32_t fapi_videc_0getvesbufferposition
                                (FAPI_SYS_HandleT handle, uint32_t* bufferPtr);
int32_t fapi_videc_0getvesbuffersize
                               (FAPI_SYS_HandleT handle, uint32_t* bufferSize);
int32_t fapi_videc_0getvesfilllevel
                                (FAPI_SYS_HandleT handle, uint32_t* fillLevel);
int32_t fapi_videc_0getvesavailablespace
                           (FAPI_SYS_HandleT handle, uint32_t* availableSpace);
int32_t fapi_videc_0getstate(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_GetStateT* getStatePtr);
int32_t fapi_videc_0gethealth(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_HealthStateEnumT* health);
int32_t fapi_videc_0getdecodinglatency(FAPI_SYS_HandleT handle,
                                               int64_t* decoderLatencyInTicks);
void    fapi_videc_0audcallback(uint32_t audNum, uint32_t audSearchPattern,
                                   uint32_t foundPtr, FAPI_SYS_HandleT handle);
int32_t fapi_videc_0recover(FAPI_SYS_HandleT handle);
int32_t fapi_videc_0decodesinglempegiframe(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes);
int32_t fapi_videc_0displaysinglempegiframe(FAPI_SYS_HandleT handle);
int32_t fapi_videc_0decodesequenceofmpegiframe(FAPI_SYS_HandleT handle,
                                      uint32_t* dataPtr, uint32_t sizeInBytes);
int32_t fapi_videc_0displaysequenceofmpegiframe(FAPI_SYS_HandleT handle);
int32_t fapi_videc_0setentropydecinfocallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_EntropyDecInfoCallbackT entropyDecInfoCallbackFunction,
                                                         void* entropyOptData);
int32_t fapi_videc_0setvideodecinfocallback(FAPI_SYS_HandleT handle,
                 FAPI_VIDEC_VideoDecInfoCallbackT videoDecInfoCallbackFunction,
                                                           void* videoOptData);
int32_t fapi_videc_0setautoscalecallback(FAPI_SYS_HandleT handle,
                       FAPI_VIDEC_AutoScaleCallbackT autoScaleCallbackFunction,
                                                           void* scalerHandle);
int32_t fapi_videc_0setdecodertohdencoder(FAPI_SYS_HandleT handle,
                                               FAPI_SYS_HandleT viencHdHandle);
int32_t fapi_videc_0setpesparsertodecoder(FAPI_SYS_HandleT handle,
                                       FAPI_VIDEC_PesParserEnumT pesParserNum);
int32_t fapi_videc_0setframedecodedcallback(FAPI_SYS_HandleT handle,
                 FAPI_VIDEC_FrameDecodedCallbackT frameDecodedCallbackFunction,
                                                    void* frameDecodedOptData);
int32_t fapi_videc_0setframeavailablecallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_FrameAvailableCallbackT frameAvailableCallbackFunction,
                                                  void* frameAvailableOptData);
int32_t fapi_videc_0setvesoverflowcallback(FAPI_SYS_HandleT handle,
             FAPI_VIDEC_VesOverflowCallbackT vesOverflowCallbackFunction,
                                                     void* vesOverflowOptData);
int32_t fapi_videc_0setmpegiframemode(FAPI_SYS_HandleT handle,
                                          FAPI_VIDEC_MpegIFrameModeEnumT mode);
int32_t fapi_videc_0setchannelid(FAPI_SYS_HandleT handle, uint32_t blockIndex,
                                                           uint32_t channelId);
int32_t fapi_videc_0setparamchangecallback(FAPI_SYS_HandleT handle,
                   FAPI_VIDEC_ParamChangeCallbackT paramChangeCallbackFunction,
                                                     void* paramChangeOptData);
int32_t fapi_videc_0setafdstate(FAPI_SYS_HandleT handle,
                                            FAPI_VIDEC_AfdStateEnumT afdState);
int32_t func_21c47c6c(FAPI_SYS_HandleT handle, int32_t a);
void func_21c47ad8(void);
//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif


    #ifdef __cplusplus
    }
    #endif
#endif
