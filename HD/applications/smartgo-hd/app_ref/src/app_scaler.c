
#define DEBUG 0

#include <string.h>
#include <fapi/sys_services.h>
#include "osdhandler/osdhandler.h"
#include "fontserver/fontserver.h"
#include "fontserver/fontserver_engine_ft.h"
#include "draw/draw.h"
#include "sys.h"
#include "app_scaler.h"
#include "app_main.h"


typedef struct
{
   SCALER_TRANSFORM_S transform; //0
   unsigned numVal; //32
   uint32_t numPic; //36
   uint32_t menuLayer; //40
#if 0
   int Data_44; //44
   int Data_48; //48
   int Data_52; //52
   int Data_56; //56
   int Data_60; //60
#else
   int font[SCALER_FONT_NUMS];
#endif
   unsigned defaultFontSize; //64
   char fontSize[5]; //68
   SCALER_VAL_S val[149/*SCALER_VAL_ID_NUMS*/]; //76
   DRAW_PicT pic[24]; //3652
   //5092
} SCALER_DATA_S;

SCALER_DATA_S* scalerDat; //21f024bc
SCALER_VAL_S* scalerValPtr; //21f024c0


/* 21b3dd10 - complete */
int32_t SCALER_GetFont(SCALER_FONT_E id)
{
//   FAPI_SYS_PRINT_MSG("func_21b3dd10\n");
   
   SCALER_DATA_S* inst = scalerDat;

   if( inst == NULL )
   {
      return 0;
   }
   else
   {
      return (int32_t)inst->font[id];
   }
}


/* 21b3dd34 - complete */
int32_t SCALER_GetFontSize(SCALER_FONT_E id)
{
   uint32_t res = 0;

   FAPI_SYS_PRINT_DEBUG(4, "SCALER_GetFontSize\n");

   if (scalerDat != 0)
   {
      res = scalerDat->fontSize[id];
   }

   FAPI_SYS_PRINT_DEBUG(3, "SCALER_GetFontSize: res=%d\n", res);

   return res;
}


/* 21b3dd94 - complete */
int32_t calcWidth(SCALER_VAL_S* a)
{   
   uint32_t newValue;
      
   if (scalerDat == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   newValue = ((scalerDat->transform.sxDenom >> 1) +
         (scalerDat->transform.sxNum * a->org)) /
      scalerDat->transform.sxDenom;
   
   a->curr = (newValue < a->min)? a->min:
      (newValue > a->max)? a->max: newValue;
   
   return 0;
}


/* 21b3de00 - complete */
int32_t calcHeight(SCALER_VAL_S* a)
{
   uint32_t newValue;
   
   if (scalerDat == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   newValue = ((scalerDat->transform.syDenom >> 1) +
         (scalerDat->transform.syNum * a->org)) /
      scalerDat->transform.syDenom;
   
   a->curr = (newValue < a->min)? a->min:
      (newValue > a->max)? a->max: newValue;
   
   return 0;
}


/* 21b3de6c - complete */
int32_t calcXPos(SCALER_VAL_S* a)
{
   uint32_t newValue;
   
   if (scalerDat == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   newValue = ((scalerDat->transform.sxDenom >> 1) +
         (scalerDat->transform.sxNum * a->org)) /
      scalerDat->transform.sxDenom;
   
   a->curr = (newValue < a->min)? a->min:
      (newValue > a->max)? a->max: newValue;
   
   return 0;
}


/* 21b3ded8 - complete */
int32_t calcYPos(SCALER_VAL_S* a)
{
   uint32_t newValue;
   
   if (scalerDat == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   newValue = ((scalerDat->transform.syDenom >> 1) +
         (scalerDat->transform.syNum * a->org)) /
      scalerDat->transform.syDenom;
   
   a->curr = (newValue < a->min)? a->min:
      (newValue > a->max)? a->max: newValue;
   
   return 0;
}


/* 21b3e22c - complete */
int32_t calcFontSize(void)
{
   int32_t res = 0;
   FONTSERVER_InformationT fontserverInfo; //sp
   SCALER_VAL_S sp80;
   SCALER_DATA_S* sl = scalerDat;
   char r4;

   if (sl == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   memset(&fontserverInfo, 0, sizeof(FONTSERVER_InformationT));
   memset(&sp80, 0, sizeof(SCALER_VAL_S));

   FONTSERVER_SetFont(appDat->fontserverHandle, 0);

   FONTSERVER_SetSize(appDat->fontserverHandle, SCALER_GetFontSize(0));

   res = FONTSERVER_GetFontInfo(appDat->fontserverHandle, &fontserverInfo);
   if (res == 0)
   {
      if (fontserverInfo.fontFormat == FONTSERVER_FORMAT_TTF)
      {
         r4 = (sl->defaultFontSize * sl->transform.syNum) / sl->transform.syDenom;

         sp80.id = 0;
         sp80.min = 2;
         sp80.org = 4;
         sp80.max = 4;
         sp80.type = 1;

         calcHeight(&sp80);

         sl->fontSize[0] = r4 + sp80.curr;
         sl->fontSize[1] = r4;
         sl->fontSize[2] = r4;
         sl->fontSize[3] = r4;
         sl->fontSize[4] = r4 + sp80.curr;
      }
   }

   return res;
}


/* 21b3e050 - complete */
int32_t resizePicAll(void)
{
   int32_t res = 0;
   uint32_t i;
   SCALER_VAL_S width;
   SCALER_VAL_S height;

   SCALER_DATA_S* sl = scalerDat;

   if (sl == 0)
   {
      return -10000004; //0xff67697c;
   }

   memset(&width, 0, sizeof(SCALER_VAL_S));
   memset(&height, 0, sizeof(SCALER_VAL_S));

   for (i = 0; i < sl->numPic; i++)
   {
      width.org = sl->pic[i].orgPic.fbmHeaderPtr->width;
      width.min = width.org / 2;
      width.max = width.org * 2;
      width.type = 0;
      width.id = 21;

      height.org = sl->pic[i].orgPic.fbmHeaderPtr->height;
      height.min = height.org / 2;
      height.max = height.org * 2;
      height.type = 1;

      res = calcWidth(&width);

      if (res != 0)
      {
         FAPI_SYS_PRINT_MSG("[SCALER] calcWidth() failed %ld\n", res);

         break; //return res;
      }

      res = calcHeight(&height);

      if (res != 0)
      {
         FAPI_SYS_PRINT_MSG("[SCALER] calcHeight() failed %ld\n", res);

         break; //return res;
      }

      DRAW_FreeFbm(&sl->pic[i].convPic);

      memset(&sl->pic[i].convPic, 0, sizeof(DRAW_PicItemT));

      sl->pic[i].orgPic.clutEndIdx = 215;
      sl->pic[i].orgPic.clutId = 2;

      res = DRAW_ScalePicture_1(&sl->pic[i].orgPic,
            &sl->pic[i].convPic, width.curr, height.curr);

      if (res != 0)
      {
         FAPI_SYS_PRINT_MSG("[SCALER] DRAW_ScalePicture() failed %ld\n", res);
      }
   }

   return res;
}


/* 21b3e540 - complete */
int32_t SCALER_Init(SCALER_INIT_PARAMS_S* a)
{
//   printf("21b3e540\n");
   
   uint32_t sp;
   uint32_t id;
   int currId;
   int32_t res = 0;
   DRAW_PictureFileTypeT type; //sp4
   
   if (scalerDat != 0)
   {
      return 0;
   }
   
   if ((a == 0) || (a->valPtr == 0))
   {
      return -10000001; //0xff67697f; 
   }
   
   for (; ;)
   {
       scalerDat = SYS_MemoryAllocate(sizeof(SCALER_DATA_S));

       if (scalerDat == 0)
       {
          //->21b3e8b8
          res = -10000002; //0xff67697e;
          break; //->21b3e7e8
       }

      //21b3e59c
      memset(scalerDat, 0, sizeof(SCALER_DATA_S));

      scalerDat->transform = a->transform;
      scalerDat->menuLayer = a->menuLayer;

      for (sp = 0; sp < 149; sp++)
      {
          currId = a->valPtr[sp].id;

         if (currId == -1)
         {
            break;
         }

         scalerDat->val[currId] = *(a->valPtr + sp);

         switch (scalerDat->val[currId].type)
         {
         case SCALER_TYPE_WIDTH: //0:
            //21b3e83c
            res = calcWidth(scalerDat->val + currId);
            //->21b3e648
            break;

         case SCALER_TYPE_HEIGHT: //1:
            //21b3e638
            res = calcHeight(scalerDat->val + currId);
            //21b3e648
            break;

         case SCALER_TYPE_X_POS: //2:
            //21b3e828
            res = calcXPos(scalerDat->val + currId);
            //->21b3e648
            break;

         case SCALER_TYPE_Y_POS: //3:
            //21b3e814
            res = calcYPos(scalerDat->val + currId);
            //->21b3e648
            break;

         default:
            res = 0;
            break;
         }
         //21b3e648
         if (res != 0)
         {
            //->21b3e668
            break;
         }
         //21b3e650
      } //for (sp = 0; sp < 149; sp++)
      //21b3e668
      scalerDat->numVal = sp;
      scalerDat->defaultFontSize = a->defaultFontSize;
      scalerDat->font[TITLE_FONT] = a->fonts[TITLE_FONT];
      scalerDat->font[MAIN_FONT] = a->fonts[MAIN_FONT];
      scalerDat->font[HELP_FONT] = a->fonts[HELP_FONT];
      scalerDat->font[SYMBOL_FONT] = a->fonts[SYMBOL_FONT];
      scalerDat->font[SYMBOL_TITLE] = a->fonts[SYMBOL_TITLE];

      res = calcFontSize();

      if (res != 0)
      {
          break;
      }

     //21b3e6b0
     if (a->picPtr != 0)
     {
         //21b3e6bc -> 21b3e758
         for (id = 0; id < 24; id++)
         {
            //21b3e76c
            currId = a->picPtr[id].id;

            if (currId == -1)
            {
               break;
            }

            res = DRAW_DetectFile(&type, a->picPtr[id].ptr);

            if (res != 0)
            {
               //->21b3e8ec
               FAPI_SYS_PRINT_MSG("[SCALER] Can't detect file type [id %i]", id);
               //->21b3e7e0
               break;
            }
            //21b3e780
            switch (type)
            {
            case DRAW_PIC_FILE_TYPE_BMP: //1
               //21b3e884
               res = DRAW_ReadFile_BMP(a->picPtr[id].ptr,
                     &scalerDat->pic[id].orgPic);
               //->21b3e7bc
               break;

            case DRAW_PIC_FILE_TYPE_FBM: //2
               //21b3e78c
               res = DRAW_ReadFile_FBM(a->picPtr[id].ptr,
                     &scalerDat->pic[id].orgPic);
               //21b3e7bc
               break;

            case DRAW_PIC_FILE_TYPE_DAT: //3
               //21b3e850
               res = DRAW_ReadFile_DAT(a->picPtr[id].ptr,
                     &scalerDat->pic[id].orgPic);
               //->21b3e7bc
               break;

            default:
               //21b3e6d4
               FAPI_SYS_PRINT_MSG("[SCALER] Can't read unknown file type [id %i]", id);
               //21b3e700
               break;
            }
            //21b3e7bc
            if (res != 0)
            {
               //21b3e7c4
               FAPI_SYS_PRINT_MSG("[SCALER] Can't read file type [id %i]", id);
               //21b3e7e0
               break;
            }
            //->21b3e700
            scalerDat->pic[id].id = id;
            scalerDat->pic[id].orgPic.id = id;
            scalerDat->pic[id].orgPic.clutPtr = 0;
            scalerDat->pic[id].orgPic.clutId = scalerDat->menuLayer;
            scalerDat->pic[id].orgPic.clutStartIdx = 0;
            scalerDat->pic[id].orgPic.clutEndIdx = 255;
            scalerDat->pic[id].orgPic.globalAlpha = 0x100;
         } //for (id = 0; id < 24; id++)
         //21b3e8c0 / 21b3e7e0
         scalerDat->numPic = id;
          //21b3e7e8
           if (res != 0)
           {
               break;
           }

           //21b3e8c8
           res = resizePicAll();

           if (res != 0)
           {
               break;
           }

          //21b3e8d4
          scalerValPtr = scalerDat->val;
       }

       break;
   }

   if (res != 0)
   {
      //21b3e7e8
      if (scalerDat != 0)
      {
         //21b3e7f4
         SYS_MemoryFree(scalerDat);
         
         scalerDat = 0;
      }
      //21b3e804
      scalerValPtr = 0;
   }

   return res;
}


/* 21b3e468 - complete */
int32_t SCALER_Exit(void)
{
   uint32_t i;
   DRAW_PicItemT* picItem;
   SCALER_DATA_S* r8 = scalerDat;
      
   FAPI_SYS_PRINT_DEBUG(4, "SCALER_Exit\n");
   
   if (r8 == 0)
   {
      return -10000004; //0xff67697c;
   }
   
   for (i = 0; i < r8->numPic; i++)
   {
      picItem = &r8->pic[i].orgPic;
      
      DRAW_FreeFbm(picItem);
      
      memset(picItem, 0, sizeof(DRAW_PicItemT));
      
      picItem = &r8->pic[i].convPic;
      
      DRAW_FreeFbm(picItem);
      
      memset(picItem, 0, sizeof(DRAW_PicItemT));
   }

   SYS_MemoryFree(scalerDat);
   
   scalerDat = 0;
   scalerValPtr = 0;

   return 0;
}


