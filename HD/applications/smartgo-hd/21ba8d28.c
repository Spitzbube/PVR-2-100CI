

#define DEBUG 0

#include <fapi/sys_services.h>
#include "sys.h"
#include "stringop.h"
#include "21ba8d28.h"



typedef struct
{
   signed short wData_0; //0
   signed short wData_2; //2
   unsigned short wData_4; //4
   unsigned short wData_6; //6
   char bData_8; //8
   //12
} Struct_5FA0E4_Inner2;

struct OsdView
{
   signed short wData_0; //0
   signed short wData_2; //2
   int Data_4; //4
   void* window; //8
   Struct_5FA0E4_Inner2* Data_12; //12
   int id; //16
   int Data_20; //20
   int Data_24; //24
   int (*SetHandler)(void* a, int b); //28
   int (*Data_32)(void* a, int b); //32
   int (*Data_36)(void* a); //36
   int (*Destroy)(void* a); //40
   void (*Data_44)(void); //44
   //48
};


typedef struct
{
   union
   {
      int (*Data_0_1)(void* a); //0
      int (*Data_0_2)(void* a, char b); //0
   } u_0; //0
   void* Data_4; //4
   int Data_8; //8
   union
   {
      int (*Data_12_1)(void* a); //0
      int (*Data_12_2)(void* a, char b); //0
   } u_12; //0
   void* Data_16; //16
   int Data_20; //20
   int Data_24; //24
   //28
} Struct_5FA0E4_Inner3;

struct Struct_21f02f98
{
   struct Struct_21ba8d28 Data_0; //0
   uint8_t numViews; //40
   struct OsdView views[16]; //int fill_45[16 * 48/4]; //44
   int activeView; //812
   struct OsdView* arData_804[16]; //int fill_816[16]; //816
   struct Struct_21ba1a6c Data_880; //880
   int Data_900; //900
   int Data_904[31]; //904
   uint8_t bData_1028; //1028
   void* Data_1032; //1032
   Struct_5FA0E4_Inner3 keyHandler[67]; //1036
   uint32_t Data_2156; //2912
   uint32_t Data_2160; //2916
   int8_t bData_2164; //2920
   int fill_2924[65]; //2924
   //3184
};


typedef struct
{
   char hour; //0
   char min; //1
   char sec; //2
   //3   
} Time;

typedef struct
{
   unsigned short year; //0
   char mon; //2
   char day; //3
   unsigned weekday; //4
   //8
} Date;

typedef struct
{
   char* str; //8
   char font; //12
   char bData_13; //13
   int color; //16
   //20
} OsdTextItem;

typedef struct
{
   void* buffer; //8
   int Data_12; //12
   int Data_16; //16
   int Data_20; //20
} OsdBitmapItem;

typedef struct
{
   Time time; //10
   int format; //12
   char font; //16
   int color; //20   
} OsdTimeItem;

typedef struct
{
   Date date; //8
   int Data_16; //16
   char font; //20
   int color; //24   
} OsdDateItem;

typedef struct
{
   int value; //8
   int Data_12; //12
   char bData_16; //16
   char* strUnit; //20
   char font; //24
   int color; //28
} Struct_371cd8_Inner5;

struct OsdItem
{
   int Data_0; //0
   char align; //4
   union
   {
      OsdTextItem text; //8
      OsdBitmapItem bitmap; //8
      OsdTimeItem time; //8
      OsdDateItem date; //8
      Struct_371cd8_Inner5 s5; //8
   } u; //8
   //32
}; // Struct_371cd8;


extern struct Struct_21ba8d28_Funcs* fgsDraw; //21f02f9c
extern struct Struct_21f02f98* fgsInst; //21f02f98


#if 0

/* v3.8: 36fcec */
/* 21ba8d28 - complete */
int32_t FGS_Init(struct Struct_21ba8d28* a)
{   
   int32_t res;
   
   if (a == 0)
   {
      return -10000001;
   }
   
   fgsInst = SYS_MemoryAllocate(sizeof(struct Struct_21f02f98));
   
   if (fgsInst == 0)
   {
      return -10002002;
   }
   
   memset(fgsInst, 0, sizeof(struct Struct_21f02f98));
   
   fgsInst->Data_0 = *a;
   fgsInst->numViews = 0;
   fgsInst->activeView = -1;
   fgsInst->Data_2156 = 0;
   fgsInst->Data_2160 = 0;
   fgsInst->bData_2164 = -1;

   fgsDraw = &fgsInst->Data_0.funcs;

   if (fgsInst->Data_0.bData_12 == 0)
   {
      fgsInst->Data_0.bData_12 = 1;
   }
   
   if (fgsInst->Data_0.bData_13 == 0)
   {
      fgsInst->Data_0.bData_13 = 1;
   }
   
   res = func_21ba1a6c(&fgsInst->Data_880, 128, 0);
   if (res != 0)
   {
      return res;
   }
   
   fgsInst->bData_1028 = 2;
   fgsInst->Data_1032 = &fgsInst->Data_900;
   
   return 0;
}

#endif

/* 371cd8 - todo */
int func_375240(struct OsdItem* r17, 
                unsigned short x0, unsigned short y0, 
                unsigned short width, unsigned short height)
{
   unsigned short r13;
   unsigned short fp2;
   unsigned short fp4;
   char fp68[64]; 
   int r23 = 0;
   int color = 0;
   char font = 0;
   char r24 = 0;
   char* str = 0;
   int r16 = 0;
   int r15 = 0;
   unsigned r18 = 0;
   
   struct Struct_21ba1a6c sp48;
   
   if (r17 == 0) 
   {
      return -10000001;
   }
   
   STR_Clear(&sp48); //->stringop.c
   
   memset(&fgsInst->Data_900, 0, 32*4);
   
   switch (r17->Data_0)
   {
      case 1:
         //21ba8940
         color = r17->u.text.color;
         font = r17->u.text.font;
         str = r17->u.text.str;
         if ((r17->u.text.bData_13 > 0) &&
            (height >= (unsigned short)(r17->u.text.bData_13*2)))
         {
            r24 = r17->u.text.bData_13;
            r15 = 1;
         }
         //371dcc
         r16 = 1;
         //->3721c0
         break;
         
      case 2:
         //371dd4
         if ((r17->u.bitmap.buffer != 0) && 1) 
//            (Data_5FA0E0->DrawBitmap != 0))
         {
            // Get the bitmap position based on alignment
            func_371c00(r17->u.bitmap.buffer, r17->align,
               x0, y0, width, height, &fp2, &fp4);
               
            // Draw the bitmap
//            (Data_5FA0E0->DrawBitmap)(fp2, fp4, &r17->u.bitmap);
         } 
         //->3721c0
         break;
         
      case 3:
         //371e50
         switch (r17->u.time.format)
         {
            case 0:
            default:
               //371e6c
               sprintf(fp68, "%02i:%02d", 
                       r17->u.time.time.hour, 
                       r17->u.time.time.min); 
               break;
               
            case 1:
               //371e8c
               sprintf(fp68, "%02i:%02d:%02d", 
                       r17->u.time.time.hour, 
                       r17->u.time.time.min, 
                       r17->u.time.time.sec); 
               break;
               
            case 2:
               //371eb4
               sprintf(fp68, "- %02i:%02d:%02d", 
                       r17->u.time.time.hour, 
                       r17->u.time.time.min, 
                       r17->u.time.time.sec); 
               break;               
         } 
         //371ed8
         color = r17->u.time.color;
         font = r17->u.time.font;
         str = fp68;
         r16 = 1;
         //->3721c0
         break;
         
      case 4:
         //371eec
         switch (r17->u.date.Data_16)
         {
            case 0:
            default:
               //371f10
               sprintf(fp68, "%02i-%02i-%04i",
                  r17->u.date.date.day,
                  r17->u.date.date.mon,
                  r17->u.date.date.year);                  
               break;

            case 1:
               //371f38
               sprintf(fp68, "%02i-%02i",
                  r17->u.date.date.day,
                  r17->u.date.date.mon);                  
               break;

            case 2:
               //371f5c
               sprintf(fp68, "%02i.%02i.%04i",
                  r17->u.date.date.day,
                  r17->u.date.date.mon,
                  r17->u.date.date.year);                  
               break;

            case 3:
               //371f84
               sprintf(fp68, "%02i.%02i",
                  r17->u.date.date.day,
                  r17->u.date.date.mon);                  
               break;
         }
         //371fa4
         color = r17->u.date.color;
         font = r17->u.date.font;
         str = fp68;
         r16 = 1;
         //->3721c0         
         break;
      
      case 5:
         //371fb8
         switch (r17->u.s5.Data_12)
         {
            case 0:
            default:
               //371fcc
               sprintf(fp68, "%li", r17->u.s5.value);
               r18 = strlen(fp68);
               if (r17->u.s5.bData_16 > 0)
               {
                  if (r18 <= r17->u.s5.bData_16)
                  {
                     r18 = 0;
                     fp68[r18] = '0';
                     r18++;
                     fp68[r18] = '.';
                     r18++;
                     
                     switch (r17->u.s5.bData_16)
                     { 
                        case 1:
                           //372050
                           sprintf(&fp68[r18], "%.1li", r17->u.s5.value);
                           break;

                        case 2:
                           //372068
                           sprintf(&fp68[r18], "%.2li", r17->u.s5.value);
                           break;

                        case 3:
                           //372080
                           sprintf(&fp68[r18], "%.3li", r17->u.s5.value);
                           break;
                           
                        default:
                           //372098
                           sprintf(&fp68[r18], "%.4li", r17->u.s5.value);
                           break;
                     }
                     //3720ac 
                     r18 += r17->u.s5.bData_16;
                     //->372170
                  } 
                  else
                  {
                     //3720b8
                     for (r13 = r18 - 1; r13 >= (r18 - r17->u.s5.bData_16); r13--)
                     {
                        fp68[r13 + 1] = fp68[r13];
                     } 
                     //3720e8           
                     fp68[r13 + 1] = '.';
                     r18++;          
                  } 
               } 
               //->372170
               break;
               
            case 1:
               //3720fc
               if (r17->u.s5.value > 0)
               {
                  sprintf(fp68, "+ %02li:00", r17->u.s5.value);
               } 
               else if (r17->u.s5.value < 0)
               {
                  sprintf(fp68, "- %02li:00", -r17->u.s5.value);
               } 
               else
               {
                  sprintf(fp68, "00:00");
               } 
               //372164
               r18 = strlen(fp68);
               break;
         }
         //372170 
         if (r17->u.s5.strUnit != 0)
         {
            SYS_StrNCpy(&fp68[r18], " ", 64 - r18);
            r18++;
            SYS_StrNCpy(&fp68[r18], r17->u.s5.strUnit, 64 - r18);
         } 
         //3721a8
         color = r17->u.s5.color;
         font = r17->u.s5.font;
         str = fp68;
         r16 = 1;
         break;
         
      default:
         //3721bc
         r23 = 1;
         break;
   } 
   //3721c0
   if ((r16 != 0) && (str != 0) && (str[0] != 0) && 1)
//      (Data_5FA0E0->i != 0))
   {
      if (r15 == 0)
      {                  
         func_3724e4(str, font, r17->align, color, 
            x0, y0, width, height);
      }
      else
      {
         func_3725cc(str, font, r17->align, color, r24,
            x0, y0, width, height);
      }        
   } 
   //37225c
   return r23;   
}

#if 0

/* 373808 - todo */
int osd_view_remove/*FGS_RemoveMember*/(struct OsdView* a)
{
   signed short i;
   struct OsdView* r14;

   if ((a == 0) ||
      (fgsInst->numViews <= 0))
   {
      return -10000001;
   }

   if ((fgsInst->activeView >= 0) &&
      (&fgsInst->views[fgsInst->activeView] == a))
   {
      r14 = &fgsInst->views[fgsInst->activeView];

      (r14->SetHandler)(r14->window, 0);

      fgsInst->activeView = -1;
   }

   memset(a, 0, sizeof(struct OsdView));

   for (i = 0; i < fgsInst->numViews; i++)
   {
      if (fgsInst->arData_804[i] == a)
      {
         break;
      }
   }

   while (i < (fgsInst->numViews - 1))
   {
      fgsInst->arData_804[i] =
         fgsInst->arData_804[i + 1];
      i++;
   }

   fgsInst->numViews--;

   return 0;
}

#endif

/* 21ba654c - complete */
int32_t osd_view_handle_key(uint32_t a, uint32_t b, int8_t c)
{
   FAPI_SYS_PRINT_DEBUG("osd_view_handle_key: a=%d, b=%d, c=%d\n", a, b, c);

   Struct_5FA0E4_Inner3* r14 = 0;
   int32_t r0 = 0;

   if ((a >= 67) || (a == 0) ||
      (c > 9))
   {
      return 0;
   }

   fgsInst->Data_2156 = a;
   fgsInst->Data_2160 = b;
   fgsInst->bData_2164 = c;

   r14 = &fgsInst->keyHandler[a];

   if ((r14->Data_24 == 0) && (r14->u_0.Data_0_1 != 0))
   {
      if (((r14->Data_8 == 1) && (b != 2)) ||
         (r14->Data_8 == 0))
      {
         if (c < 0)
         {
            r0 = (r14->u_0.Data_0_1)(r14->Data_4);
         }
         else
         {
            r0 = (r14->u_0.Data_0_2)(r14->Data_4, c);
         }
      }
      else
      {
         r0 = 1;
      }
   }

   if ((r0 == 0) && (r14->u_12.Data_12_1 != 0))
   {
      if (((r14->Data_20 == 1) && (b != 2)) ||
         (r14->Data_20 == 0))
      {
         if (c < 0)
         {
            r0 = (r14->u_12.Data_12_1)(r14->Data_16);
         }
         else
         {
            r0 = (r14->u_12.Data_12_2)(r14->Data_16, c);
         }
      }
      else
      {
         r0 = 1;
      }
   }

   fgsInst->Data_2156 = 0;
   fgsInst->Data_2160 = 0;
   fgsInst->bData_2164 = -1;

   return r0;
}


/* 21ba6694 - complete */
/* v3.8: 3746e4 - complete */
void func_21ba6694(int a, int (*b)(void* a), void* c, int d)
{
   fgsInst->keyHandler[a].u_0.Data_0_1 = b;
   fgsInst->keyHandler[a].Data_4 = c;
   fgsInst->keyHandler[a].Data_8 = d;
}


/* 21ba66c0 - complete */
/* v3.8: 374764 - complete */
void func_21ba66c0(int a, int (*b)(void* a, char b), void* c, int d)
{
   fgsInst->keyHandler[a].u_0.Data_0_2 = b;
   fgsInst->keyHandler[a].Data_4 = c;
   fgsInst->keyHandler[a].Data_8 = d;
}


/* 21ba66ec - complete */
/* v3.8: 3747e4 */
void func_21ba66ec(int a)
{
   fgsInst->keyHandler[a].u_0.Data_0_1 = 0;
}


/* 21ba6710 - complete */
/* v3.8: 374828 - complete */
void func_21ba6710(void)
{
   uint32_t i;

   for (i = 0; i < 67; i++)
   {
      fgsInst->keyHandler[i].u_0.Data_0_1 = 0;
   }
}


/* 21ba6744 - complete */
/* v3.8: 374880 - complete */
void func_21ba6744(int a,
                  int (*b)(void* a),
                  void* c, int d, int e)
{
   fgsInst->keyHandler[a].u_12.Data_12_1 = b;
   fgsInst->keyHandler[a].Data_16 = c;
   fgsInst->keyHandler[a].Data_20 = d;
   fgsInst->keyHandler[a].Data_24 = e;
}


/* 21ba6778 - complete */
/* v3.8: 3713b8 - complete */
void func_21ba6778(int a,
                  int (*b)(void* a, char b),
                  void* c, int d, int e)
{
   fgsInst->keyHandler[a].u_12.Data_12_2 = b;
   fgsInst->keyHandler[a].Data_16 = c;
   fgsInst->keyHandler[a].Data_20 = d;
   fgsInst->keyHandler[a].Data_24 = e;
}


/* 21ba6810 - complete */
/* v3.8: 374a80 - complete */
void func_21ba6810(int a)
{
   fgsInst->keyHandler[a].u_12.Data_12_1 = 0;
   fgsInst->keyHandler[a].Data_24 = 0;
}


/* 21ba6838 - complete */
/* v3.8: 374ae4 - complete */
void func_21ba6838(void)
{
   uint32_t i;

   for (i = 0; i < 67; i++)
   {
      fgsInst->keyHandler[i].u_12.Data_12_1 = 0;
      fgsInst->keyHandler[i].Data_24 = 0;
   }
}




