#ifndef APP_OSD_H_
#define APP_OSD_H_

#include "app_scaler.h"
#include "app_lang.h"


/** Corner identifiers */
#define OSD_CORNER_NONE         0x0000
#define OSD_CORNER_TOP_LEFT     0x0100
#define OSD_CORNER_TOP_RIGHT    0x0200
#define OSD_CORNER_BOT_LEFT     0x0400
#define OSD_CORNER_BOT_RIGHT    0x0800
#define OSD_CORNER_ALL          0x0F00


#define OSD_COL_TITLE_TEXT               13

typedef enum
{
    OSD_COLSCHEME_CURRENT = -1,
    OSD_COLSCHEME_BLUE = 0,
    OSD_COLSCHEME_GREEN,
    OSD_COLSCHEME_RED,
    OSD_COLSCHEME_BLACK,
    OSD_COLSCHEME_NUMS

} OSD_COLSCHEME_E;

typedef enum
{
    OSD_SCHEMECOL_MAIN_BKGR = 0,
#if 0
    OSD_SCHEMECOL_MAIN_BKGR_HIGHL,
    OSD_SCHEMECOL_BLACK_BKGR,
#endif
    OSD_SCHEMECOL_HELP_BKGR = 2, //2
    OSD_SCHEMECOL_TITLE_BKGR = 3, //3
    OSD_SCHEMECOL_FRAME = 4, //4
    OSD_SCHEMECOL_FRAME_SHADOW1 = 5, //5
    OSD_SCHEMECOL_FRAME_SHADOW2 = 6, //6
#if 0
    OSD_SCHEMECOL_SCROLLBAR_INACT,
    OSD_SCHEMECOL_PROGRESSBAR_INACT,
#endif
    OSD_SCHEMECOL_NUMS = 9 //9
} OSD_SCHEMECOL_E;


extern int32_t app_osd_init(void);
extern int32_t app_osd_start(unsigned, int);
extern void app_osd_stop(void);
extern int32_t app_osd_start_layer(void);


#endif /*APP_OSD_H_*/
