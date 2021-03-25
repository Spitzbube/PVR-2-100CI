

#include <fatfs/fatfs.h>



int Data_21f7717c; //21f7717c
FATFS_GetTaskIdCallbackT Data_21f77178; //21f77178
FATFS_GetDateCallbackT Data_21f77170; //21f77170
FATFS_GetTimeCallbackT Data_21f77174; //21f77174


/* 21c9b974 - todo */
int32_t FATFS_Init(FATFS_InitParamsT* paramsPtr)
{
//   printf("FATFS_Init\n");

   if (Data_21f7717c != 0)
   {
      return -3;
   }
   
   if (paramsPtr != 0)
   {
      Data_21f77170 = paramsPtr->getDateFct;
      Data_21f77174 = paramsPtr->getTimeFct;
      Data_21f77178 = paramsPtr->getTaskIdFct;
   }
   
   func_21ca2128();
   
   Data_21f7717c = 1;
   
   return 0;
}




