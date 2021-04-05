/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/app_ref/inc/app_scaler.h
**
** \brief       Menu scaler interface.
**
** Detail description. [\ref app_smartgo_app_ref_scaler]
**
**              The Menu scaler interface defines the default sizes of the
**              menu OSD layer for all video output modes. In this file are also
**              the value and picture identifier defined.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
** (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
**
*****************************************************************************
*/
#ifndef _APP_SCALER_H_
#define _APP_SCALER_H_

#if 0

#include <draw/draw.h>
/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/
/*!
 * \brief Defines the horizontal start Position of the Menu OSD layer. This is
 *        used for all video output modes.
 */
#define OSD_X_START                0
/*!
 * \brief Defines the vertical start Position of the Menu OSD layer. This is
 *        used for all video output modes.
 */
#define OSD_Y_START                0

/*!
 * \brief Defines the horizontal size of the Menu OSD layer. This is used for
 *        PAL/NTSC/SECAM video output mode.
 */
#define OSD_X_LEN               VIDEOSZ_X_720
/*!
 * \brief Defines the horizontal size of the Menu OSD layer. This is used for
 *        720P video output mode.
 */
#define OSD_X_LEN_1280          VIDEOSZ_X_1280
/*!
 * \brief Defines the horizontal size of the Menu OSD layer. This is used for
 *        1080I video output mode.
 */
#define OSD_X_LEN_1920          VIDEOSZ_X_1920

/*!
 * \brief Defines the vertical size of the Menu OSD layer. This is used for
 *        NTSC video output mode.
 */
#define OSD_Y_LEN_NTSC          VIDEOSZ_Y_NTSC
/*!
 * \brief Defines the vertical size of the Menu OSD layer. This is used for
 *        PAL/SECAM video output mode.
 */
#define OSD_Y_LEN_PAL           VIDEOSZ_Y_PAL
/*!
 * \brief Defines the vertical size of the Menu OSD layer. This is used for
 *        720P video output mode.
 */
#define OSD_Y_LEN_720           VIDEOSZ_Y_720
/*!
 * \brief Defines the vertical size of the Menu OSD layer. This is used for
 *        1080I video output mode.
 */
#define OSD_Y_LEN_1080          VIDEOSZ_Y_1080

/*!
 * \brief Defines the maximum supported value width for all scaleable values and
 *        picture sizes. If a scaled value exeeds this size it will be cropped
 *        to #OSD_MAX_WIDTH.
 */
#define OSD_MAX_WIDTH           VIDEOSZ_X_1920
/*!
 * \brief Defines the maximum supported value height for all scaleable values
 *        and picture sizes. If a scaled value exeeds this size it will be
 *        cropped to #OSD_MAX_HEIGHT.
 */
#define OSD_MAX_HEIGHT          VIDEOSZ_Y_1080

/*!
 * \brief This defines the reference widht used to design the menu.
 */
#define OSD_REF_WIDTH           1920
/*!
 * \brief This defines the reference height used to design the menu.
 */
#define OSD_REF_HEIGHT          1080

#endif

/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/
typedef enum
{
#if 0
    SCALER_VAL_NONE = -1,
#endif
    OSD_POS_X = 0,
    OSD_POS_Y = 1, //1
#if 0
    OSD_WIDTH,
    OSD_HEIGHT,

    PROHIBITED_WIDTH,
    PROHIBITED_HEIGHT,
    PROHIBITED_PAD_X,
    PROHIBITED_PAD_Y,
#endif

    TITLE_TB_PADDING = 8, //8
    TITLE_LINE_HEIGHT = 9, //9

    MAIN_TOP_PADDING = 10, //10
    MAIN_BOT_PADDING = 11, //11
    MAIN_LEFT_PADDING = 12, //12
#if 0
    MAIN_CENTER_PADDING,
#endif
    MAIN_RIGHT_PADDING = 14, //14
    MAIN_WIDTH = 15, //15
    MAIN_HOR_OFFSET = 16, //16
    MAIN_VER_OFFSET = 17, //17
#if 0
    MAIN_PAD_X,
    MAIN_PAD_Y,
    MAIN_ICON_WIDTH,
    MAIN_ICON_HEIGHT,
#endif
    MAIN_TEXT_PAD_X = 22, //2

    HELP_LR_PADDING = 23, //23
    HELP_TB_PADDING = 24, //24
    HELP_LINE_HEIGHT = 25, //25
#if 0
    HELP_LINE_WIDTH,
#endif
    HELP_LINE_PADDING = 27, //27
    HELP_BOT_XOFF = 28, //28

    LIST_LINE_HEIGHT = 29, //29
    LIST_LINE_PADDING = 30, //30

    SCROLLBAR_WIDTH = 31, //31
#if 0
    SCROLLBAR_PADDING,

    PROGRESSBAR_WIDTH,
    PROGRESSBAR_HEIGHT,

    UPDATE_PROGRESSBAR_HEIGHT,
    UPDATE_PROGRESSBAR_PAD,
#endif

    STACKED_FRAME_DIST = 37, //37
    OUTER_FRAME_WIDTH = 38, //38
    OUTER_FRAME_PADDING = 39, //39
    OUTER_FRAME_ALL = 40, //40
    INNER_FRAME_WIDTH = 41, //41
    SUB_LIST_WIDTH,

#if 0
    EDIT_REC_WIDTH,
    EDIT_REC_SYMBOL_WIDTH,

    EDIT_STRING_WIDTH,
    EDIT_STRING_HEIGHT,

    VOLUMEBAR_WIDTH,

    PLAYLIST_COL0_WIDTH,
    PLAYLIST_COL1_WIDTH,
    PLAYLIST_COL2_WIDTH,
    PLAYLIST_COL3_WIDTH,
    PLAYLIST_COL4_WIDTH,
    PLAYLIST_COL5_WIDTH,
    PLAYLIST_WIDTH,

    TIMERPROG_WIDTH,
    TIMERPROG_COL0_WIDTH,
    TIMERPROG_COL1_WIDTH,
    TIMERPROG_COL2_WIDTH,
    TIMERPROG_COL3_WIDTH,
    TIMERPROG_COL4_WIDTH,
    TIMERPROG_COL5_WIDTH,
    TIMERPROG_COL6_WIDTH,
    TIMERPROG_COL7_WIDTH,
    TIMERPROG_COL8_WIDTH,

    CONFDIALOG_WIDTH,
    CONFDIALOG_COL_WIDTH,

    SERVLIST_WIDTH,
    SERVLIST_WIDTH_HELPKEY_LEFT,
    SERVLIST_WIDTH_HELPKEY_RIGHT,

    SCANNING_WIDTH,
    VIEWER_WIDTH,
    JPEG_WIDTH,
    JPEG_POS_Y,

    MP3_WIDTH,
    MP3_INFO_PADDING,

    INFO_WIDTH,
    INFO_TIME_WIDTH,
    INFO_NUM_WIDTH,
    INFO_LISTID_WIDTH,
    INFO_AUDIO_WIDTH,
    INFO_RECICON_WIDTH,
    INFO_REC_WIDTH,
    INFO_PLAYICON_WIDTH,
    INFO_PLAY_WIDTH,
    INFO_LOCKEDICON_WIDTH,
    INFO_AGEICON_WIDTH,
    INFO_AGE_WIDTH,
    INFO_STIME_WIDTH,
    INFO_PROG_WIDTH,
    INFO_PROGBAR_PAD,

    EPG_SCHED_WIDTH,
    EPG_SCHED_TIME_WIDTH,
    EPG_SCHED_NUM_WIDTH,
    EPG_SCHED_DATE_WIDTH,
    EPG_SCHED_DAY_WIDTH,
    EPG_SCHED_TODAY_WIDTH,

    EPG_EXT_WIDTH,
    EPG_EXT_TIME_WIDTH,
    EPG_EXT_SEPARATOR_WIDTH,
    EPG_EXT_DATE_WIDTH,
    EPG_EXT_DAY_WIDTH,
    EPG_EXT_NUM_WIDTH,

    EPG_GRID_PIX_PER_UNIT,
    EPG_GRID_TIMELINE_WIDTH,
    EPG_GRID_COLUMN_WIDTH,
    EPG_GRID_COLUMN_PAD,
    EPG_GRID_REC_COLUMN_WIDTH,
    EPG_GRID_HELPKEY_WIDTH_SHORT,
    EPG_GRID_HELPKEY_WIDTH_LONG,

    CHANLIST_WIDTH,

    PINDIALOG_WIDTH,
    PINDIALOG_DIGITWIDTH,
    PINDIALOG_DIGITPAD,

    STRINF_WIDTH,
    STRINF_COL1_WIDTH,
    STRINF_COL2_WIDTH,

    DEBUG_WIDTH,
    DEBUG_COL_WIDTH,

    SATINSTYPE_PIC_HEIGHT,
    SATINSTYPE_PIC_WIDTH,
    SATINSTYPE_PREAMBEL_WIDTH,

    MMI_DIGIT_WIDTH,
    MMI_DIGIT_PAD,

    MOSAIC_FRAME_WIDTH,
    MOSAIC_OSD_POS_X,
    MOSAIC_OSD_POS_Y,
    MOSAIC_OSD_WIDTH,
    MOSAIC_OSD_HEIGHT,

    MOSAIC_POS_X,
    MOSAIC_2_4_POS_Y,
    MOSAIC_6_9_POS_Y,
    MOSAIC_13_POS_Y,
    MOSAIC_PAD_X,
    MOSAIC_PAD_Y,

    MOSAIC_2_4_WIDTH,
    MOSAIC_2_4_HEIGHT,
    MOSAIC_6_9_WIDTH,
    MOSAIC_6_9_HEIGHT,
    MOSAIC_13_WIDTH,
    MOSAIC_13_HEIGHT,

    PIP_POS_X,
    PIP_SIZE_X_MIN,
    PIP_SIZE_X_MAX,
    PIP_STEP_X,
    PIP_POS_Y,

    MEDIA_INFO_WIDTH,
    MEDIA_INFO_SHUFFLE_WIDTH,
    MEDIA_INFO_PIC_ZOOM_WIDTH,
    MEDIA_INFO_PIC_ROT_WIDTH,
    MEDIA_INFO_PIC_RES_WIDTH,
    MEDIA_INFO_PIC_SLIDE_WIDTH,
    MEDIA_INFO_MUSIC_TIME_WIDTH,
    MEDIA_INFO_MUSIC_PROG_WIDTH,
    MEDIA_SMALLINFO_WIDTH,

    /* general used sizes, positions and width */
    TIME_BOX_WIDTH,

    SCALER_VAL_ID_NUMS, //149
#endif

} SCALER_VAL_ID_E;


typedef enum
{
    ICON_NONE    = -1,
    ICON_CRYPTED = 0,
    ICON_TTXT,
    ICON_HD,
    #ifdef APPL_SUBTT_ENABLED
        ICON_SUBT,
    #endif /* #if APPL_SUBTT_ENABLED */
    ICON_USR,
    ICON_TV,
    ICON_RADIO,
    ICON_16_9,
    ICON_LOCKED,
    ICON_PROHIBITED,
    ICON_BTNREDSMALL,
    ICON_BTNGREENSMALL,
    ICON_BTNYELLOWSMALL,
    ICON_BTNBLUESMALL,

    #if (defined APPL_FESAT_ENABLED) && (defined USE_SATINST_GFX)

    PICTURE_ONE_SAT_MOTLNB,
    PICTURE_ONE_SAT_MULTLNB,
    PICTURE_ONE_SAT_SGLLNB,
    PICTURE_TWO_SAT_MOTLNB,
    PICTURE_TWO_SAT_MULTLNB,
    PICTURE_TWO_SAT_SGLLNB,

    #endif /* (defined APPL_FESAT_ENABLED) && (defined USE_SATINST_GFX) */

    #ifdef APPL_FILEOP_ENABLED

    ICON_HARDDISKSMALL,
    ICON_USBSMALL,
    ICON_FILESMALL,
    ICON_FOLDERSMALL,
    ICON_MUSICSMALL,
    ICON_MOVIESMALL,
    ICON_PICTURESMALL,

    #ifdef APPL_FILEUPDATE_ENABLED
    ICON_UPDATESMALL,
    #endif /* APPL_FILEUPDATE_ENABLED */

    #endif /* APPL_FILEOP_ENABLED */

    #ifdef APPL_MP3_ENABLED
    ICON_SHUFFLE,
    #endif /* APPL_MP3_ENABLED */

    SCALER_PIC_ID_NUMS

} SCALER_PIC_ID_E;


typedef enum
{
// TODO: to be renamed?
    TITLE_FONT = 0,
    MAIN_FONT, //1
    HELP_FONT, //2
    SYMBOL_FONT, //3
    SYMBOL_TITLE, //4

    SCALER_FONT_NUMS, //5

} SCALER_FONT_E;


typedef enum
{
    SCALER_TYPE_WIDTH = 0,
    SCALER_TYPE_HEIGHT, //1
    SCALER_TYPE_X_POS, //2
    SCALER_TYPE_Y_POS, //3

    SCALER_TYPE_NUMS,

} SCALER_VAL_TYPE_E;


typedef struct
{

    /*!
     * \brief Value Identifier symbol.
     */
    SCALER_VAL_ID_E     id; //0

    /*!
     * \brief Minimum of this value.
     */
    uint32_t            min; //4

    /*!
     * \brief Maximum of this value.
     */
    uint32_t            max; //8

    /*!
     * \brief The typical size of this value. This size refers to the default
     *        Menu size defined by #OSD_REF_WIDTH and #OSD_REF_HEIGHT.
     */
    uint32_t            org; //12

    /*!
     * \brief The current value. This calculated internaly base on the transform
     *        matrix set with SCALER_SetTransformMatrix().
     */
    uint32_t            curr; //16

    /*!
     *  \brief The type defines how this value is scaled. There are four
     *         possibilities.
     *         - #SCALER_TYPE_WIDTH
     *         - #SCALER_TYPE_HEIGHT
     *         - #SCALER_TYPE_X_POS
     *         - #SCALER_TYPE_Y_POS
     */
    SCALER_VAL_TYPE_E   type; //20
    //24
} SCALER_VAL_S;


typedef struct
{

    /*!
     * \brief Picture Identifier symbol.
     */
    SCALER_PIC_ID_E     id; //0

    /*!
     * \brief Pointer to RAW Data.
     */
    const uint32_t*     ptr; //4
    //8
} SCALER_PICFILE_S;


typedef struct
{
    uint32_t sxNum; //0
    uint32_t sxDenom; //4
    uint32_t syNum; //8
    uint32_t syDenom; //12
    int32_t  txNum; //16
    int32_t  txDenom; //20
    int32_t  tyNum; //24
    int32_t  tyDenom; //28
    //32
} SCALER_TRANSFORM_S;


typedef struct
{
    SCALER_TRANSFORM_S       transform; //0
    SCALER_VAL_S*            valPtr; //32
    const SCALER_PICFILE_S*  picPtr; //36
    uint32_t                 menuLayer; //40
    uint32_t                 defaultFontSize; //44
    uint32_t                 fonts[SCALER_FONT_NUMS]; //48
    //68
} SCALER_INIT_PARAMS_S;


/*!
*******************************************************************************
**
** \brief  Reads out the current scaled Value for given value id. The scaling
**         factor is set with SCALER_SetTransformMatrix().
**
** \param  id   Value Id.
**
** \return The current scaled value.
**
** \sa
**          - SCALER_VAL_ID_E
******************************************************************************/

extern SCALER_VAL_S* scalerValPtr; //21f024c0

#define SCALER_GetCurrVal(a) scalerValPtr[(a)].curr


/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

      int32_t        SCALER_Init                (SCALER_INIT_PARAMS_S* pParams);
      int32_t        SCALER_Exit                (void);
#if 0
      int32_t        SCALER_GetTransformMatrix  (SCALER_TRANSFORM_S* transform);
      int32_t        SCALER_SetTransformMatrix  (SCALER_TRANSFORM_S* transform);
#endif
      int32_t        SCALER_GetFont             (SCALER_FONT_E font);
      int32_t        SCALER_GetFontSize         (SCALER_FONT_E id);
#if 0
const DRAW_PicItemT* SCALER_GetPic              (SCALER_PIC_ID_E id);
#endif

#ifdef __cplusplus
}
#endif


#endif /* _APP_SCALER_H_ */
/******************************************************************************/
/* END OF FILE */
