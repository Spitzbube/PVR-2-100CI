/******************************************************************************
**
** \file      gm_debug.c
**
** \brief     Debug support module.
**
**            Copyright:   2012 - 2013 (C) GoKe Microelectronics ShangHai Branch
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** \version
**
******************************************************************************/
/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
#include "gtypes.h"
#include "gm_debug.h"


/******************************************************************************

Name:        GM_DEBUG_Init

Description: This function initializes the debug module.

Parameters:  1) pointer init parameter structure

Returns:     GD_OK
             GD_ERR_ALREADY_INITIALIZED
             GD_ERR_DEVICE_BUSY
             GD_ERR_OUT_OF_MEMORY

******************************************************************************/
GERR GM_DEBUG_Init(GM_DEBUG_INIT_PARAMS_S *paramsP)
{
  
}


/******************************************************************************

Name:        GM_Printf

Description: hook function for printf from C-Lib.

Parameters:  see printf

Returns:     see printf

******************************************************************************/

int GM_Printf(const char *__format, ...)
{
    printf(__format);
}

void  GM_PrintfSeperator1(void)
{
    GM_Printf("-------------------------------------------------\n");
}

void  GM_PrintfSeperator2(void)
{
    GM_Printf("*************************************************\n");
}

/******************************************************************************

Name:        GM_Scanf

Description: hook function for scanf from C-Lib.

Parameters:  see printf

Returns:     see printf

******************************************************************************/
int GM_Scanf(const char *__format, ...)
{
   
}

/******************************************************************************

Name:        GM_ScanStr

Description: Scans only strings and does not need the Metaware lib.
             Max string length is defined by UTIL_MAX_STR_LEN-1
             Note: Backspace is supported to delete entries from Terminal

Parameters:  pointer to a char buffer

Returns:     none

******************************************************************************/
void GM_ScanStr(char *pDest)
{
   
}


/******************************************************************************

Name:        GM_LimScanStr

Description: Almost same as GM_ScanStr but length limitation can be set.
             Scans only strings and does not need the Metaware lib.
             Max string length is defined by length-1
             Note: Backspace is supported to delete entries from Terminal

Parameters:  pointer to a char buffer
             max. length of string

Returns:     none

******************************************************************************/
void GM_LimScanStr(char *pDest, U32 length)
{
    
}

/******************************************************************************

Name:        GM_ScanNum

Description: Can be used to read in numbers.
             Scans only numbers and does not need the Metaware lib.
             Max size is U32
             Note: Backspace is supported to delete entries from Terminal

Parameters:  pointer to a format descriptor, can be either %x, %d or %i
             number that was read as abs()

Returns:     +1 or -1 depending on format and sign

******************************************************************************/
int GM_ScanNum (const char *Format , U32 *pValue)
{
   
}


/******************************************************************************

Name:        GM_DEBUG_SetOutputDevice

Description: This function initializes the debug module.

Parameters:  1) mode is or'ed combination of GM_DEBUG_OSD, GM_DEBUG_TTY, GM_DEBUG_MEM
             or only GM_DEBUG_DISABLE to set output device to write to.

Returns:     GD_OK
             GD_ERR_BAD_PARAMETER
             GD_ERR_DEVICE_BUSY
             GD_ERR_OUT_OF_MEMORY

******************************************************************************/
GERR GM_DEBUG_SetOutputDevice(U8 mode)
{
    
}

/******************************************************************************

Name:        GM_DEBUG_GetOutputDevice

Description: Returns the current setting for the output device used by write
             function.

Parameters:  None

Returns:     or'ed combination of GM_DEBUG_OSD, GM_DEBUG_TTY, GM_DEBUG_MEM
             or only GM_DEBUG_DISABLE

******************************************************************************/
U8 GM_DEBUG_GetOutputDevice(void)
{
}


/******************************************************************************

Name:        GM_DEBUG_ReadChar()

Description: Reads a character from the input buffer.

Parameters:  None

Returns:     Returns the character.

******************************************************************************/
U8 GM_DEBUG_ReadChar(void)
{

}


/******************************************************************************

Name:        GM_DEBUG_CheckRxBuffer()

Description: Returns status of receive buffer.

Parameters:  None

Returns:     Returns GTRUE if the recive buffer is not empty.

******************************************************************************/
GBOOL GM_DEBUG_CheckRxBuffer(void)
{
  
}


void GM_PrintChar(char cx)
{

}

int GM_ReceiveChar(void)
{
  
}

void GM_PrStrStr(const char *str1P, char *str2P)
{
}

void GM_PrHex(int data, int len)
{

}

void GM_PrCStrHex2(const char *strP, U32 data)
{

}

void GM_PrCStrHex4(const  char *strP, S16 data)
{

}

void GM_PrCStrHex8(const  char *strP, U32 data)
{

}



/******************************************************************************
  Some utility functions

  purpose of this function is to come along without any C-lib function. This
  os necessary when only the simple debug functions are used.

******************************************************************************/

/*---------------------------------------------------------------------------*/
/* Binary to Hex.ASCII Conversion                                            */
/*---------------------------------------------------------------------------*/
static void Bin32ToHex(U32 bin, char *strnP, U32 len)
{
    U32 nib;
    U32 k;

    for (k=0; k<len; k++)
    {
        nib = bin & 0x0000000F;
        strnP[(len-1)-k] = nib > 9 ? ('A'-10)+nib  : '0'+nib;
        bin = bin >> 4;
    }
    strnP[len] = '\0';
}

/******************************************************************************

Name:        GM_PrInt

Description: converts an int to a string and prints it.

Parameters:  data: the value to print

Returns:     None

******************************************************************************/
void GM_PrInt(int data)
{
  
}

/******************************************************************************

Name:        GM_PrU32

Description: converts a U32 to a string and prints it.

Parameters:  data: the value to print

Returns:     None

******************************************************************************/
void GM_PrU32(U32 data)
{
   
}


