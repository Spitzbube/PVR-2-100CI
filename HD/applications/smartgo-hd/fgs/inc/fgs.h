/*!
*****************************************************************************
**
** \file        ./applications/smartgo-hd/fgs/inc/fgs.h
**
** \brief       content description.
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
#ifndef _FGS_H_
#define _FGS_H_

#include "fgs_config.h"
#include "fgs_keys.h"
#include "fapi/sys_services.h"
#include "smartgo_types.h"
#include "sys_api.h"
#if 0
#include "utils.h"
#else
#endif

/*---------------------------------------------------------------------------*/
/* constants and macros                                                      */
/*---------------------------------------------------------------------------*/

#define FGS_ALIGN_HOR_LEFT     0x00 //!< hor. left aligned: x is relative to left pos.
#define FGS_ALIGN_HOR_RIGHT    0x01 //!< hor. right aligned: x is relative to right pos.
#define FGS_ALIGN_HOR_CENTER   0x02 //!< hor. center aligned: x is ignored
#define FGS_ALIGN_VER_TOP      0x00 //!< ver. top aligned: y is relative to top pos.
#define FGS_ALIGN_VER_BOTTOM   0x10 //!< ver. bot. aligned: y is relative to bottom pos.
#define FGS_ALIGN_VER_CENTER   0x20 //!< ver. center aligned: y is ignored

#define FGS_ALIGN_MASK_HOR     0x0F
#define FGS_ALIGN_MASK_VER     0xF0

/* general algorithm for calculating an absolute position */
#define FGS_CalculateAbsPos(pMember, parentAbs, pParentPos, gridX, gridY) \
        do                                                                \
        {                                                                 \
            switch ( (pMember)->pos->alignment & FGS_ALIGN_MASK_HOR )     \
            {                                                             \
                default:                                                  \
                case FGS_ALIGN_HOR_LEFT:                                  \
                    (pMember)->abspos.x = (parentAbs).x +                 \
                                          (pMember)->pos->x;              \
                    break;                                                \
                                                                          \
                case FGS_ALIGN_HOR_RIGHT:                                 \
                    (pMember)->abspos.x = (parentAbs).x +                 \
                                          (pParentPos)->width +           \
                                          (pMember)->pos->x;              \
                    break;                                                \
                                                                          \
                case FGS_ALIGN_HOR_CENTER:                                \
                    (pMember)->abspos.x = (parentAbs).x +                 \
                                          ((pParentPos)->width) / 2 -     \
                                          ((pMember)->pos->width) / 2;    \
                    break;                                                \
            }                                                             \
                                                                          \
            switch ( (pMember)->pos->alignment & FGS_ALIGN_MASK_VER)      \
            {                                                             \
                default:                                                  \
                case FGS_ALIGN_VER_TOP:                                   \
                    (pMember)->abspos.y = (parentAbs).y +                 \
                                          (pMember)->pos->y;              \
                    break;                                                \
                                                                          \
                case FGS_ALIGN_VER_BOTTOM:                                \
                    (pMember)->abspos.y = (parentAbs).y +                 \
                                          (pParentPos)->height +          \
                                          (pMember)->pos->y;              \
                    break;                                                \
                                                                          \
                case FGS_ALIGN_VER_CENTER:                                \
                    (pMember)->abspos.y = (parentAbs).y +                 \
                                          ((pParentPos)->height) / 2 -    \
                                          ((pMember)->pos->height) / 2;   \
                    break;                                                \
            }                                                             \
                                                                          \
            (pMember)->abspos.x &= (~((uint16_t)(gridX - 1)));            \
            (pMember)->abspos.y &= (~((uint16_t)(gridY - 1)));            \
        }                                                                 \
        while ( 0 )


/*---------------------------------------------------------------------------*/
/* types, enums and structures                                               */
/*---------------------------------------------------------------------------*/

typedef fbool_t (*FGS_KEY_CB)       (FAPI_SYS_HandleT data);
typedef fbool_t (*FGS_KEYNUM_CB)    (FAPI_SYS_HandleT data, uint8_t value);

typedef void  (*FGS_FOCUSSET_CB)  (FAPI_SYS_HandleT h, fbool_t hasFocus);
typedef void  (*FGS_GNR_ITEM_CB)  (FAPI_SYS_HandleT h, uint8_t align, uint16_t x, uint16_t y,
                                   uint16_t width, uint16_t height);

typedef fbool_t (*FGS_LINEPARSED_CB)(uint16_t lineIdx, SYS_STRING_S lineStart,
                                   uint16_t lineLength);

typedef enum
{
   FGS_KEYTYPE_PRESSED = 0,
   FGS_KEYTYPE_RELEASED,
   FGS_KEYTYPE_REPEATED, //2

} FGS_KEYTYPE_E;

typedef union
{
    FGS_KEY_CB          btn;
    FGS_KEYNUM_CB       num;
    void*               all;

} FGS_KEY_CB_S;

typedef struct
{
    FGS_KEY_CB_S        cb;
    FAPI_SYS_HandleT    data;
    fbool_t             blockRep;
    fbool_t             suppressGui;

} FGS_APPKEY_HDL_S;

/* ------------------------------------------------------------------------- */

typedef enum
{
    FGS_NONFOCUS = 0,
    FGS_FOCUS,
    FGS_DISABLED,
    FGS_STATE_NUMS

} FGS_ITEMSTATE_E;

typedef enum
{
    FGS_ITEM_TYPE_NONE = 0,     //!< No item.
    FGS_ITEM_TYPE_GENERIC,      //!< Generic item, drawn by user via callback.
    FGS_ITEM_TYPE_STRING,       //!< String item.
    FGS_ITEM_TYPE_ICON,         //!< Icon item (bitmap).
    FGS_ITEM_TYPE_TIME,         //!< Time item (time string).
    FGS_ITEM_TYPE_DATE,         //!< Date item (date string).
    FGS_ITEM_TYPE_IP,           //!< IP item (ip string).
    FGS_ITEM_TYPE_MAC,          //!< MAC item (MAC string).
    FGS_ITEM_TYPE_NUMBER,       //!< Number item (number string).

} FGS_ITEM_TYPE_E;

typedef enum
{
    FGS_FORMAT_TIME_DAYTIME,     //!< Daytime in hours and minutes
    FGS_FORMAT_TIME_PLAYTIME,    //!< Playback or recording time
    FGS_FORMAT_TIME_NEGPLAYTIME, //!< Negative playback time

} FGS_FORMAT_TIME_E;

typedef enum
{
    FGS_FORMAT_DATE_INT_NORM,     //!< yyyy-mm-dd: International format
    FGS_FORMAT_DATE_INT_SHORT,    //!< mm-dd: Internation format without year
    FGS_FORMAT_DATE_EUROPE_NORM,  //!< dd.mm.yyyy: European notation
    FGS_FORMAT_DATE_EUROPE_SHORT, //!< dd.mm.: European notation without year

} FGS_FORMAT_DATE_E;

typedef enum
{
    FGS_FORMAT_NUM_NORM,           //!< No special format
    FGS_FORMAT_NUM_SIGNEDHOURS,    //!< Value represents hours, always signed

} FGS_FORMAT_NUM_E;

typedef enum
{
    FGS_FORMAT_IP_V4,                //!< IP address v4 192.168.100.100
    FGS_FORMAT_IP_V6,                //!< IP address v6

} FGS_FORMAT_IP_E;

typedef enum
{
    FGS_ICONMODE_OVRWRITE = 0,  //!< Draw complete bitmap rectangle.
    FGS_ICONMODE_OVRLAY,        //!< Overlay mode: Leave out bitmap pixels
                                //!< with color defined as background.
    FGS_ICONMODE_OVRLAYPLAIN,   //!< Special overlay mode: Background pixels
                                //!< are replaced by plain color.
} FGS_ICONMODE_E;


typedef union
{
    int32_t             number;
    SYS_TIME_S          time;
    SYS_DATE_S          date;
    SYS_STRING_S        string;
#if 0
    FAPI_ETH_Ip4T       ip;
    FAPI_ETH_MacT       mac;
#endif

} FGS_VAL_S;


typedef struct
{
    int16_t             x; /*0*/                  //!< start X pos in parent item
    int16_t             y; /*2*/                  //!< start Y pos in parent item
    uint16_t            width; /*4*/              //!< item width
    uint16_t            height; /*6*/             //!< item height
    uint8_t             alignment; /*8*/          //!< hor./ver. alignment status (or'ed)
    //12
} FGS_POS_S;

typedef struct
{
    int16_t             x;                   //!< start X position
    int16_t             y;                   //!< start Y position
    //4
} FGS_LOC_S;

typedef struct
{
    uint16_t            x;
    uint16_t            y;
    uint16_t            width;
    uint16_t            height;

} FGS_AREA_S;

typedef struct
{
    FGS_GNR_ITEM_CB     cb;         //!< Callback for drawing generic item.
    FAPI_SYS_HandleT    cbArg;      //!< Optional argument passed with callback.

} FGS_GENERIC_S;

typedef struct
{
    SYS_STRING_S        chr;        //!< Pointer to NULL-terminated character
                                    //!< list.
    uint8_t             font;       //!< Text font to be used.
    uint16_t            lineHeight; //!< Line height in pixels, needed for
                                    //!< multi-line strings; 0: force
                                    //!< single line.
    uint32_t            col;        //!< Text color.

} FGS_STRING_S;

typedef struct
{
    const uint32_t*     addr;       //!< Start address of icon data.
    FGS_ICONMODE_E      drawMode;   //!< Drawing mode.
    uint32_t            bkgrCol;    //!< Bitmap color defined as "background"
                                    //!< for overlay modes.
    uint32_t            altBkgrCol; //!< plain background color for special
                                    //!< overlay mode.

} FGS_ICON_S;

typedef struct
{
    SYS_TIME_S          value;      //!< time value
    FGS_FORMAT_TIME_E   format;     //!< time format
    uint8_t             font;       //!< text font to be used
    uint32_t            col;        //!< text color

} FGS_TIME_S;

typedef struct
{
    SYS_DATE_S          value;      //!< date value
    FGS_FORMAT_DATE_E   format;     //!< date format
    uint8_t             font;       //!< text font to be used
    uint32_t            col;        //!< text color

} FGS_DATE_S;

typedef struct
{
    int32_t             value;         //!< number value
    FGS_FORMAT_NUM_E    format;        //!< number format
    uint8_t             decimalPlaces; //!< number of decimal places (0...),
                                       //!< applies for format FGS_FORMAT_NUM_NORM
                                       //!< only
    SYS_STRING_S        unitStr;       //!< optional unit string appended to number
    uint8_t             font;          //!< text font to be used
    uint32_t            col;           //!< text color

} FGS_NUMBER_S;

#if 0

typedef struct
{
    FAPI_ETH_Ip4T       value;      //!< IP address value
    FGS_FORMAT_IP_E     format;     //!< IP format
    uint8_t             font;       //!< text font to be used
    uint32_t            col;        //!< text color

} FGS_IP_S;

typedef struct
{
    FAPI_ETH_MacT       value;      //!< MAC address value
    uint8_t             font;       //!< text font to be used
    uint32_t            col;        //!< text color

} FGS_MAC_S;

#endif

typedef struct
{
    FGS_ITEM_TYPE_E     type; //0
    uint8_t             align; /*4*/        //!< alignment in target rectangle

    union
    {
        FGS_GENERIC_S   gnr;
        FGS_STRING_S    str; //8
        FGS_ICON_S      icon;
        FGS_TIME_S      time;
        FGS_DATE_S      date;
        FGS_NUMBER_S    number;
#if 0
        FGS_IP_S        ip;
        FGS_MAC_S        mac;
#endif

    } item;

} FGS_ITEM_S;

typedef void  (*FGS_GETITEM_CB)  (FAPI_SYS_HandleT h, int32_t id, uint32_t index,
                                  FGS_ITEMSTATE_E state, FGS_ITEM_S* item);
typedef void  (*FGS_DRAWIF_CLEARAREA_CB)    (const FGS_AREA_S* pArea);

/*!
*******************************************************************************
**
** \brief OSD interface: Print string.
**
** \param x         X-Position in pixels.
** \param y         Y-Position in pixels.
** \param color     Requested color.
** \param font      Requested font.
** \param numBytes  Number of bytes to be processed (-1: entire string).
** \param maxWidth  Maximum available width in pixels.
** \param strWidth  String width in pixels, set to -1 if unknown.
** \param string    String (character set and start address).
** \param softCut   Handling of strings wider than available width
**                  (FTRUE: append string indicating cut, FFALSE: cut without
**                  any indication).
**
** \return Status of the operation
**
******************************************************************************/
typedef int32_t  (*FGS_DRAWIF_PRINTSTR_CB)     (uint16_t x, uint16_t y, uint32_t color, uint8_t font,
                                             int32_t numBytes, uint16_t maxWidth,
                                             int32_t strWidth, SYS_STRING_S string,
                                             fbool_t softCut);

/*!
*******************************************************************************
**
** \brief OSD interface: Get pixel width of requested string.
**
** \param string    String (character set and start address).
** \param numBytes  Number of bytes (-1: entire string).
** \param font      Requested font.
**
** \return String width in pixels.
**
******************************************************************************/
typedef uint32_t   (*FGS_DRAWIF_GETSTRWIDTH_CB) (SYS_STRING_S string, int32_t numBytes,
                                             uint8_t font);
typedef void  (*FGS_DRAWIF_GETFONTPARS_CB)  (uint8_t font, uint8_t* ascent, uint8_t* descent,
                                             int8_t* offsetY);
typedef int32_t  (*FGS_DRAWIF_DRAWBITMAP_CB)   (uint16_t x, uint16_t y,
                                             const FGS_ICON_S* pData);

typedef struct
{
    FGS_DRAWIF_CLEARAREA_CB     clearArea;
    FGS_DRAWIF_PRINTSTR_CB      printStr;
    FGS_DRAWIF_GETSTRWIDTH_CB   getStrWidth;
    FGS_DRAWIF_GETFONTPARS_CB   getFontPars;
    FGS_DRAWIF_DRAWBITMAP_CB    drawBitmap;

} FGS_DRAWIF_S;


typedef void* (*FGS_MEM_GET_CB) (uint32_t size);
typedef void  (*FGS_MEM_RELEASE_CB) (void *p);

typedef struct
{
    FGS_MEM_GET_CB        get;
    FGS_MEM_RELEASE_CB    release;

} FGS_MEM_S;

typedef struct
{
    FGS_POS_S      pos;           //!< root panel dimensions (absolute!)
    uint8_t        gridX; /*12*/        //!< hor. alignment grid size for members (1...),
                                  //!< must be a multiple of 2!
    uint8_t        gridY; /*13*/        //!< ver. alignment grid size for members (1...),
                                  //!< must be a multiple of 2!
    FGS_DRAWIF_S   draw;  /*16*/        //!< general drawing interface
#if 0
    FGS_MEM_S      mem;           //!< general memory interface
#endif

    fbool_t        optimizedHide; //!< Optimized panel hide mechanism, currently
                                  //!< usable for rectangular panel graphics
                                  //!< only.

} FGS_INIT_S;

typedef struct
{
    /* written by parent */
    FGS_LOC_S           abspos;      //!< absolute member position (written by parent)
    fbool_t             posChg;      //!< notifies a change in positioning

    /* written by member */
    FAPI_SYS_HandleT    h;
    FGS_POS_S*          pos;         //!< Member's position and size in parent item.
    int32_t             id; /*16*/         //!< member ID.
    fbool_t             isVisible; /*20*/  //!< Visibility status.
    fbool_t             inFront; /*24*/    //!< Display order, 1: always in front of
                                     //!< other members.

    int32_t         (*setFocus) /*28*/    (FAPI_SYS_HandleT h, fbool_t hasFocus); //28   // mandatory
    int32_t         (*show) /*32*/       (FAPI_SYS_HandleT h, fbool_t force);       // mandatory
    int32_t         (*hide) /*36*/       (FAPI_SYS_HandleT h);                    // mandatory
    int32_t         (*close) /*40*/      (FAPI_SYS_HandleT h);                    // optional
    int32_t         (*refresh) /*44*/    (FAPI_SYS_HandleT h, FGS_POS_S* pArea);  // mandatory

} FGS_MEMBER_S;

extern FGS_DRAWIF_S* fgsDraw; // general drawing interface is globally available

/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

int32_t  FGS_Init               (FGS_INIT_S* pInitParams);
int32_t  FGS_Exit               (void);
int32_t  FGS_AddMember          (FGS_MEMBER_S* pMember, FGS_MEMBER_S** pId);
int32_t  FGS_RemoveMember       (FGS_MEMBER_S* id);
int32_t  FGS_HandleMemberShow   (FGS_MEMBER_S* pMember);
int32_t  FGS_HandleMemberHide   (FGS_MEMBER_S* pMember);

int32_t  FGS_SetFrameDimensions (FGS_POS_S* newPos);
void     FGS_GetFrameDimensions (FGS_POS_S* pos);
int32_t  FGS_SetMemberFocus     (int32_t id);
int32_t  FGS_GetMemberFocusID   (void);
int32_t  FGS_SetMemberPosition  (int32_t id, const FGS_POS_S* pos);

uint16_t FGS_GetLinesFromString (SYS_STRING_S str,
                                 uint16_t lineWidth,
                                 uint8_t font,
                                 FGS_LINEPARSED_CB lineParsed);
int32_t  FGS_DrawItem           (const FGS_ITEM_S* item,
                                 uint16_t x,
                                 uint16_t y,
                                 uint16_t width,
                                 uint16_t height);
void     FGS_GetPosString       (SYS_STRING_S string,
                                 int32_t numBytes,
                                 uint8_t font,
                                 uint8_t align,
                                 uint16_t x,
                                 uint16_t y,
                                 uint16_t width,
                                 uint16_t height,
                                 int32_t stringWidth,
                                 uint16_t* strX,
                                 uint16_t* strY,
                                 uint16_t* strWidth,
                                 uint16_t* strHeight);
void    FGS_GetPosIcon          (const uint32_t* addr,
                                 uint8_t align,
                                 uint16_t x,
                                 uint16_t y,
                                 uint16_t width,
                                 uint16_t height,
                                 uint16_t* iconX,
                                 uint16_t* iconY);

/* key handler interface */
fbool_t FGS_DispatchKey        (FGS_KEY_E key, FGS_KEYTYPE_E type, int8_t numVal);

void  FGS_SetKeyHandler      (FGS_KEY_E key,
                              FGS_KEY_CB callback,
                              FAPI_SYS_HandleT data,
                              fbool_t blockRepeated);
void  FGS_SetNumKeyHandler   (FGS_KEY_E key,
                              FGS_KEYNUM_CB callback,
                              FAPI_SYS_HandleT data,
                              fbool_t blockRepeated);
void  FGS_ClearKeyHandler    (FGS_KEY_E key);
void  FGS_ClearAllHandlers   (void);

void  FGS_SetAppKeyHandler   (FGS_KEY_E key,
                              FGS_KEY_CB callback,
                              FAPI_SYS_HandleT data,
                              fbool_t blockRepeated,
                              fbool_t suppressGui);

void  FGS_SetAppNumKeyHandler(FGS_KEY_E key,
                              FGS_KEYNUM_CB callback,
                              FAPI_SYS_HandleT data,
                              fbool_t blockRepeated,
                              fbool_t suppressGui);

void             FGS_ClearAppKeyHandler (FGS_KEY_E key);
FGS_APPKEY_HDL_S FGS_GetAppKeyHandler   (FGS_KEY_E key);
void             FGS_WriteAppKeyHandler (FGS_KEY_E key,
                                         FGS_APPKEY_HDL_S* hdl);

void             FGS_ClearAllAppKeyHandlers (void);
void             FGS_GetAllAppKeyHandlers   (FGS_APPKEY_HDL_S* pHdl);
void             FGS_WriteAllAppKeyHandlers (FGS_APPKEY_HDL_S* pHdl);

FGS_KEY_E        FGS_GetCurrentKeyCode(void);
int8_t           FGS_GetCurrentKeyVal (void);

FGS_AREA_S       FGS_GetOverlapArea (FGS_LOC_S* abspos1,
                                     uint16_t width1,
                                     uint16_t height1,
                                     FGS_LOC_S* abspos2,
                                     uint16_t width2,
                                     uint16_t height2);

fbool_t            FGS_GetOverlapStatus(FGS_MEMBER_S* pMember,
                                        const FGS_LOC_S* abspos,
                                        uint16_t width,
                                        uint16_t height);
fbool_t            FGS_AreaOccupied (int32_t memberId, FGS_AREA_S* area);

void*              FGS_Malloc(uint32_t size);
void               FGS_Free(void *p);

#ifdef __cplusplus
}
#endif

#endif /* _FGS_H_ */
/******************************************************************************/
/* END OF FILE */
