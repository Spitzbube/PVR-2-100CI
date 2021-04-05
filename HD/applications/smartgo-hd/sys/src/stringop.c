

#include <fapi/sys_services.h>
#include "sys.h"
#include "app_main.h"
#include "stringop.h"



typedef uint32_t  (*SYS_STR_INTCPY) (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes);

typedef struct
{
    /* NOTE: array is addressed as follows: [srcFormat][dstFormat] */
    SYS_STR_INTCPY  conv[SYS_CHARSET_NUMS][SYS_CHARSET_NUMS];

    SYS_STRBUF_S    lineBuf; //1296
    SYS_STRING_S    asciiStr; //1316

    SYS_CHARSET     defaultSiCharSet; //1324
    //1328
} SYS_STR_DATA_S;

static SYS_STR_DATA_S* strDat = NULL; //21f02e40
#define STR_UD                      0   /* Indicates "undefined" in internal
                                           character lookup tables. */

SYS_CHAR table_8859_unicode[] =
{
/*
  Idx  ------------------------------------ ISO/IEC 8859 ------------------------------------------------------------
       - 01 -  - 02 -  - 03 -  - 04 -  - 05 -  - 06 -  - 07 -  - 08 -  - 09 -  - 10 -  - 11 -  - 13 -  - 14 -  - 15 - */
/*A0*/ 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0, 0x00A0,
/*A1*/ 0x00A1, 0x0104, 0x0126, 0x0104, 0x0401, STR_UD, 0x2018, STR_UD, 0x00A1, 0x0104, 0x0E01, 0x201D, 0x1E02, 0x00A1,
/*A2*/ 0x00A2, 0x02D8, 0x02D8, 0x0138, 0x0402, STR_UD, 0x2019, 0x00A2, 0x00A2, 0x0112, 0x0E02, 0x00A2, 0x1E03, 0x00A2,
/*A3*/ 0x00A3, 0x0141, 0x00A3, 0x0156, 0x0403, STR_UD, 0x00A3, 0x00A3, 0x00A3, 0x0122, 0x0E03, 0x00A3, 0x00A3, 0x00A3,
/*A4*/ 0x00A4, 0x00A4, 0x00A4, 0x00A4, 0x0404, 0x00A4, 0x20AC, 0x00A4, 0x00A4, 0x012A, 0x0E04, 0x00A4, 0x010A, 0x20AC,
/*A5*/ 0x00A5, 0x013D, STR_UD, 0x0128, 0x0405, STR_UD, 0x20AF, 0x00A5, 0x00A5, 0x0128, 0x0E05, 0x201E, 0x010B, 0x00A5,
/*A6*/ 0x00A6, 0x015A, 0x0124, 0x013B, 0x0406, STR_UD, 0x00A6, 0x00A6, 0x00A6, 0x0136, 0x0E06, 0x00A6, 0x1E0A, 0x0160,
/*A7*/ 0x00A7, 0x00A7, 0x00A7, 0x00A7, 0x0407, STR_UD, 0x00A7, 0x00A7, 0x00A7, 0x00A7, 0x0E07, 0x00A7, 0x00A7, 0x00A7,
/*A8*/ 0x00A8, 0x00A8, 0x00A8, 0x00A8, 0x0408, STR_UD, 0x00A8, 0x00A8, 0x00A8, 0x013B, 0x0E08, 0x00D8, 0x1E80, 0x0161,
/*A9*/ 0x00A9, 0x0160, 0x0130, 0x0160, 0x0409, STR_UD, 0x00A9, 0x00A9, 0x00A9, 0x0110, 0x0E09, 0x00A9, 0x00A9, 0x00A9,
/*AA*/ 0x00AA, 0x015E, 0x015E, 0x0112, 0x040A, STR_UD, 0x037A, 0x00D7, 0x00AA, 0x0160, 0x0E0A, 0x0156, 0x1E82, 0x00AA,
/*AB*/ 0x00AB, 0x0164, 0x011E, 0x0122, 0x040B, STR_UD, 0x00AB, 0x00AB, 0x00AB, 0x0166, 0x0E0B, 0x00AB, 0x1E0B, 0x00AB,
/*AC*/ 0x00AC, 0x0179, 0x0134, 0x0166, 0x040C, 0x060C, 0x00AC, 0x00AC, 0x00AC, 0x017D, 0x0E0C, 0x00AC, 0x1EF2, 0x00AC,
/*AD*/ 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x00AD, 0x0E0D, 0x00AD, 0x00AD, 0x00AD,
/*AE*/ 0x00AE, 0x017D, STR_UD, 0x017D, 0x040E, STR_UD, STR_UD, 0x00AE, 0x00AE, 0x016A, 0x0E0E, 0x00AE, 0x00AE, 0x00AE,
/*AF*/ 0x00AF, 0x017B, 0x017B, 0x00AF, 0x040F, STR_UD, 0x2015, 0x00AF, 0x00AF, 0x014A, 0x0E0F, 0x00C6, 0x0178, 0x00AF,
/*B0*/ 0x00B0, 0x00B0, 0x00B0, 0x00B0, 0x0410, STR_UD, 0x00B0, 0x00B0, 0x00B0, 0x00B0, 0x0E10, 0x00B0, 0x1E1E, 0x00B0,
/*B1*/ 0x00B1, 0x0105, 0x0127, 0x0105, 0x0411, STR_UD, 0x00B1, 0x00B1, 0x00B1, 0x0105, 0x0E11, 0x00B1, 0x1E1F, 0x00B1,
/*B2*/ 0x00B2, 0x02DB, 0x00B2, 0x02DB, 0x0412, STR_UD, 0x00B2, 0x00B2, 0x00B2, 0x0113, 0x0E12, 0x00B2, 0x0120, 0x00B2,
/*B3*/ 0x00B3, 0x0142, 0x00B3, 0x0157, 0x0413, STR_UD, 0x00B3, 0x00B3, 0x00B3, 0x0123, 0x0E13, 0x00B3, 0x0121, 0x00B3,
/*B4*/ 0x00B4, 0x00B4, 0x00B4, 0x00B4, 0x0414, STR_UD, 0x0384, 0x00B4, 0x00B4, 0x012B, 0x0E14, 0x201C, 0x1E40, 0x017D,
/*B5*/ 0x00B5, 0x013E, 0x00B5, 0x0129, 0x0415, STR_UD, 0x0385, 0x00B5, 0x00B5, 0x0129, 0x0E15, 0x00B5, 0x1E41, 0x00B5,
/*B6*/ 0x00B6, 0x015B, 0x0125, 0x013C, 0x0416, STR_UD, 0x0386, 0x00B6, 0x00B6, 0x0137, 0x0E16, 0x00B6, 0x00B6, 0x00B6,
/*B7*/ 0x00B7, 0x02C7, 0x00B7, 0x02C7, 0x0417, STR_UD, 0x00B7, 0x00B7, 0x00B7, 0x00B7, 0x0E17, 0x00B7, 0x1E56, 0x00B7,
/*B8*/ 0x00B8, 0x00B8, 0x00B8, 0x00B8, 0x0418, STR_UD, 0x0388, 0x00B8, 0x00B8, 0x013C, 0x0E18, 0x00F8, 0x1E81, 0x017E,
/*B9*/ 0x00B9, 0x0161, 0x0131, 0x0161, 0x0419, STR_UD, 0x0389, 0x00B9, 0x00B9, 0x0111, 0x0E19, 0x00B9, 0x1E57, 0x00B9,
/*BA*/ 0x00BA, 0x015F, 0x015F, 0x0113, 0x041A, STR_UD, 0x038A, 0x00F7, 0x00BA, 0x0161, 0x0E1A, 0x0157, 0x1E83, 0x00BA,
/*BB*/ 0x00BB, 0x0165, 0x011F, 0x0123, 0x041B, 0x061B, 0x00BB, 0x00BB, 0x00BB, 0x0167, 0x0E1B, 0x00BB, 0x1E60, 0x00BB,
/*BC*/ 0x00BC, 0x017A, 0x0135, 0x0167, 0x041C, STR_UD, 0x038C, 0x00BC, 0x00BC, 0x017E, 0x0E1C, 0x00BC, 0x1EF3, 0x0152,
/*BD*/ 0x00BD, 0x02DD, 0x00BD, 0x014A, 0x041D, STR_UD, 0x00BD, 0x00BD, 0x00BD, 0x2015, 0x0E1D, 0x00BD, 0x1E84, 0x0153,
/*BE*/ 0x00BE, 0x017E, STR_UD, 0x017E, 0x041E, STR_UD, 0x038E, 0x00BE, 0x00BE, 0x016B, 0x0E1E, 0x00BE, 0x1E85, 0x0178,
/*BF*/ 0x00BF, 0x017C, 0x017C, 0x014B, 0x041F, 0x061F, 0x038F, STR_UD, 0x00BF, 0x014B, 0x0E1F, 0x00E6, 0x1E61, 0x00BF,
/*C0*/ 0x00C0, 0x0154, 0x00C0, 0x0100, 0x0420, STR_UD, 0x0390, STR_UD, 0x00C0, 0x0100, 0x0E20, 0x0104, 0x00C0, 0x00C0,
/*C1*/ 0x00C1, 0x00C1, 0x00C1, 0x00C1, 0x0421, 0x0621, 0x0391, STR_UD, 0x00C1, 0x00C1, 0x0E21, 0x012E, 0x00C1, 0x00C1,
/*C2*/ 0x00C2, 0x00C2, 0x00C2, 0x00C2, 0x0422, 0x0622, 0x0392, STR_UD, 0x00C2, 0x00C2, 0x0E22, 0x0100, 0x00C2, 0x00C2,
/*C3*/ 0x00C3, 0x0102, STR_UD, 0x00C3, 0x0423, 0x0623, 0x0393, STR_UD, 0x00C3, 0x00C3, 0x0E23, 0x0106, 0x00C3, 0x00C3,
/*C4*/ 0x00C4, 0x00C4, 0x00C4, 0x00C4, 0x0424, 0x0624, 0x0394, STR_UD, 0x00C4, 0x00C4, 0x0E24, 0x00C4, 0x00C4, 0x00C4,
/*C5*/ 0x00C5, 0x0139, 0x010A, 0x00C5, 0x0425, 0x0625, 0x0395, STR_UD, 0x00C5, 0x00C5, 0x0E25, 0x00C5, 0x00C5, 0x00C5,
/*C6*/ 0x00C6, 0x0106, 0x0108, 0x00C6, 0x0426, 0x0626, 0x0396, STR_UD, 0x00C6, 0x00C6, 0x0E26, 0x0118, 0x00C6, 0x00C6,
/*C7*/ 0x00C7, 0x00C7, 0x00C7, 0x012E, 0x0427, 0x0627, 0x0397, STR_UD, 0x00C7, 0x012E, 0x0E27, 0x0112, 0x00C7, 0x00C7,
/*C8*/ 0x00C8, 0x010C, 0x00C8, 0x010C, 0x0428, 0x0628, 0x0398, STR_UD, 0x00C8, 0x010C, 0x0E28, 0x010C, 0x00C8, 0x00C8,
/*C9*/ 0x00C9, 0x00C9, 0x00C9, 0x00C9, 0x0429, 0x0629, 0x0399, STR_UD, 0x00C9, 0x00C9, 0x0E29, 0x00C9, 0x00C9, 0x00C9,
/*CA*/ 0x00CA, 0x0118, 0x00CA, 0x0118, 0x042A, 0x062A, 0x039A, STR_UD, 0x00CA, 0x0118, 0x0E2A, 0x0179, 0x00CA, 0x00CA,
/*CB*/ 0x00CB, 0x00CB, 0x00CB, 0x00CB, 0x042B, 0x062B, 0x039B, STR_UD, 0x00CB, 0x00CB, 0x0E2B, 0x0116, 0x00CB, 0x00CB,
/*CC*/ 0x00CC, 0x011A, 0x00CC, 0x0116, 0x042C, 0x062C, 0x039C, STR_UD, 0x00CC, 0x0116, 0x0E2C, 0x0122, 0x00CC, 0x00CC,
/*CD*/ 0x00CD, 0x00CD, 0x00CD, 0x00CD, 0x042D, 0x062D, 0x039D, STR_UD, 0x00CD, 0x00CD, 0x0E2D, 0x0136, 0x00CD, 0x00CD,
/*CE*/ 0x00CE, 0x00CE, 0x00CE, 0x00CE, 0x042E, 0x062E, 0x039E, STR_UD, 0x00CE, 0x00CE, 0x0E2E, 0x012A, 0x00CE, 0x00CE,
/*CF*/ 0x00CF, 0x010E, 0x00CF, 0x012A, 0x042F, 0x062F, 0x039F, STR_UD, 0x00CF, 0x00CF, 0x0E2F, 0x013B, 0x00CF, 0x00CF,
/*D0*/ 0x00D0, 0x0110, STR_UD, 0x0110, 0x0430, 0x0630, 0x03A0, STR_UD, 0x011E, 0x00D0, 0x0E30, 0x0160, 0x0174, 0x00D0,
/*D1*/ 0x00D1, 0x0143, 0x00D1, 0x0145, 0x0431, 0x0631, 0x03A1, STR_UD, 0x00D1, 0x0145, 0x0E31, 0x0143, 0x00D1, 0x00D1,
/*D2*/ 0x00D2, 0x0147, 0x00D2, 0x014C, 0x0432, 0x0632, STR_UD, STR_UD, 0x00D2, 0x014C, 0x0E32, 0x0145, 0x00D2, 0x00D2,
/*D3*/ 0x00D3, 0x00D3, 0x00D3, 0x0136, 0x0433, 0x0633, 0x03A3, STR_UD, 0x00D3, 0x00D3, 0x0E33, 0x00D3, 0x00D3, 0x00D3,
/*D4*/ 0x00D4, 0x00D4, 0x00D4, 0x00D4, 0x0434, 0x0634, 0x03A4, STR_UD, 0x00D4, 0x00D4, 0x0E34, 0x014C, 0x00D4, 0x00D4,
/*D5*/ 0x00D5, 0x0150, 0x0120, 0x00D5, 0x0435, 0x0635, 0x03A5, STR_UD, 0x00D5, 0x00D5, 0x0E35, 0x00D5, 0x00D5, 0x00D5,
/*D6*/ 0x00D6, 0x00D6, 0x00D6, 0x00D6, 0x0436, 0x0636, 0x03A6, STR_UD, 0x00D6, 0x00D6, 0x0E36, 0x00D6, 0x00D6, 0x00D6,
/*D7*/ 0x00D7, 0x00D7, 0x00D7, 0x00D7, 0x0437, 0x0637, 0x03A7, STR_UD, 0x00D7, 0x0168, 0x0E37, 0x00D7, 0x1E6A, 0x00D7,
/*D8*/ 0x00D8, 0x0158, 0x011C, 0x00D8, 0x0438, 0x0638, 0x03A8, STR_UD, 0x00D8, 0x00D8, 0x0E38, 0x0172, 0x00D8, 0x00D8,
/*D9*/ 0x00D9, 0x016E, 0x00D9, 0x0172, 0x0439, 0x0639, 0x03A9, STR_UD, 0x00D9, 0x0172, 0x0E39, 0x0141, 0x00D9, 0x00D9,
/*DA*/ 0x00DA, 0x00DA, 0x00DA, 0x00DA, 0x043A, 0x063A, 0x03AA, STR_UD, 0x00DA, 0x00DA, 0x0E3A, 0x015A, 0x00DA, 0x00DA,
/*DB*/ 0x00DB, 0x0170, 0x00DB, 0x00DB, 0x043B, STR_UD, 0x03AB, STR_UD, 0x00DB, 0x00DB, STR_UD, 0x016A, 0x00DB, 0x00DB,
/*DC*/ 0x00DC, 0x00DC, 0x00DC, 0x00DC, 0x043C, STR_UD, 0x03AC, STR_UD, 0x00DC, 0x00DC, STR_UD, 0x00DC, 0x00DC, 0x00DC,
/*DD*/ 0x00DD, 0x00DD, 0x016C, 0x0168, 0x043D, STR_UD, 0x03AD, STR_UD, 0x0130, 0x00DD, STR_UD, 0x017B, 0x00DD, 0x00DD,
/*DE*/ 0x00DE, 0x0162, 0x015C, 0x016A, 0x043E, STR_UD, 0x03AE, STR_UD, 0x015E, 0x00DE, STR_UD, 0x017D, 0x0176, 0x00DE,
/*DF*/ 0x00DF, 0x00DF, 0x00DF, 0x00DF, 0x043F, STR_UD, 0x03AF, 0x2017, 0x00DF, 0x00DF, 0x0E3F, 0x00DF, 0x00DF, 0x00DF,
/*E0*/ 0x00E0, 0x0155, 0x00E0, 0x0101, 0x0440, 0x0640, 0x03B0, 0x05D0, 0x00E0, 0x0101, 0x0E40, 0x0105, 0x00E0, 0x00E0,
/*E1*/ 0x00E1, 0x00E1, 0x00E1, 0x00E1, 0x0441, 0x0641, 0x03B1, 0x05D1, 0x00E1, 0x00E1, 0x0E41, 0x012F, 0x00E1, 0x00E1,
/*E2*/ 0x00E2, 0x00E2, 0x00E2, 0x00E2, 0x0442, 0x0642, 0x03B2, 0x05D2, 0x00E2, 0x00E2, 0x0E42, 0x0101, 0x00E2, 0x00E2,
/*E3*/ 0x00E3, 0x0103, STR_UD, 0x00E3, 0x0443, 0x0643, 0x03B3, 0x05D3, 0x00E3, 0x00E3, 0x0E43, 0x0107, 0x00E3, 0x00E3,
/*E4*/ 0x00E4, 0x00E4, 0x00E4, 0x00E4, 0x0444, 0x0644, 0x03B4, 0x05D4, 0x00E4, 0x00E4, 0x0E44, 0x00E4, 0x00E4, 0x00E4,
/*E5*/ 0x00E5, 0x013A, 0x010B, 0x00E5, 0x0445, 0x0645, 0x03B5, 0x05D5, 0x00E5, 0x00E5, 0x0E45, 0x00E5, 0x00E5, 0x00E5,
/*E6*/ 0x00E6, 0x0107, 0x0109, 0x00E6, 0x0446, 0x0646, 0x03B6, 0x05D6, 0x00E6, 0x00E6, 0x0E46, 0x0119, 0x00E6, 0x00E6,
/*E7*/ 0x00E7, 0x00E7, 0x00E7, 0x012F, 0x0447, 0x0647, 0x03B7, 0x05D7, 0x00E7, 0x012F, 0x0E47, 0x0113, 0x00E7, 0x00E7,
/*E8*/ 0x00E8, 0x010D, 0x00E8, 0x010D, 0x0448, 0x0648, 0x03B8, 0x05D8, 0x00E8, 0x010D, 0x0E48, 0x010D, 0x00E8, 0x00E8,
/*E9*/ 0x00E9, 0x00E9, 0x00E9, 0x00E9, 0x0449, 0x0649, 0x03B9, 0x05D9, 0x00E9, 0x00E9, 0x0E49, 0x00E9, 0x00E9, 0x00E9,
/*EA*/ 0x00EA, 0x0119, 0x00EA, 0x0119, 0x044A, 0x064A, 0x03BA, 0x05DA, 0x00EA, 0x0119, 0x0E4A, 0x017A, 0x00EA, 0x00EA,
/*EB*/ 0x00EB, 0x00EB, 0x00EB, 0x00EB, 0x044B, 0x064B, 0x03BB, 0x05DB, 0x00EB, 0x00EB, 0x0E4B, 0x0117, 0x00EB, 0x00EB,
/*EC*/ 0x00EC, 0x011B, 0x00EC, 0x0117, 0x044C, 0x064C, 0x03BC, 0x05DC, 0x00EC, 0x0117, 0x0E4C, 0x0123, 0x00EC, 0x00EC,
/*ED*/ 0x00ED, 0x00ED, 0x00ED, 0x00ED, 0x044D, 0x064D, 0x03BD, 0x05DD, 0x00ED, 0x00ED, 0x0E4D, 0x0137, 0x00ED, 0x00ED,
/*EE*/ 0x00EE, 0x00EE, 0x00EE, 0x00EE, 0x044E, 0x064E, 0x03BE, 0x05DE, 0x00EE, 0x00EE, 0x0E4E, 0x012B, 0x00EE, 0x00EE,
/*EF*/ 0x00EF, 0x010F, 0x00EF, 0x012B, 0x044F, 0x064F, 0x03BF, 0x05DF, 0x00EF, 0x00EF, 0x0E4F, 0x013C, 0x00EF, 0x00EF,
/*F0*/ 0x00F0, 0x0111, STR_UD, 0x0111, 0x2116, 0x0650, 0x03C0, 0x05E0, 0x011F, 0x00F0, 0x0E50, 0x0161, 0x0175, 0x00F0,
/*F1*/ 0x00F1, 0x0144, 0x00F1, 0x0146, 0x0451, 0x0651, 0x03C1, 0x05E1, 0x00F1, 0x0146, 0x0E51, 0x0144, 0x00F1, 0x00F1,
/*F2*/ 0x00F2, 0x0148, 0x00F2, 0x014D, 0x0452, 0x0652, 0x03C2, 0x05E2, 0x00F2, 0x014D, 0x0E52, 0x0146, 0x00F2, 0x00F2,
/*F3*/ 0x00F3, 0x00F3, 0x00F3, 0x0137, 0x0453, STR_UD, 0x03C3, 0x05E3, 0x00F3, 0x00F3, 0x0E53, 0x00F3, 0x00F3, 0x00F3,
/*F4*/ 0x00F4, 0x00F4, 0x00F4, 0x00F4, 0x0454, STR_UD, 0x03C4, 0x05E4, 0x00F4, 0x00F4, 0x0E54, 0x014D, 0x00F4, 0x00F4,
/*F5*/ 0x00F5, 0x0151, 0x0121, 0x00F5, 0x0455, STR_UD, 0x03C5, 0x05E5, 0x00F5, 0x00F5, 0x0E55, 0x00F5, 0x00F5, 0x00F5,
/*F6*/ 0x00F6, 0x00F6, 0x00F6, 0x00F6, 0x0456, STR_UD, 0x03C6, 0x05E6, 0x00F6, 0x00F6, 0x0E56, 0x00F6, 0x00F6, 0x00F6,
/*F7*/ 0x00F7, 0x00F7, 0x00F7, 0x00F7, 0x0457, STR_UD, 0x03C7, 0x05E7, 0x00F7, 0x0169, 0x0E57, 0x00F7, 0x1E6B, 0x00F7,
/*F8*/ 0x00F8, 0x0159, 0x011D, 0x00F8, 0x0458, STR_UD, 0x03C8, 0x05E8, 0x00F8, 0x00F8, 0x0E58, 0x0173, 0x00F8, 0x00F8,
/*F9*/ 0x00F9, 0x016F, 0x00F9, 0x0173, 0x0459, STR_UD, 0x03C9, 0x05E9, 0x00F9, 0x0173, 0x0E59, 0x0142, 0x00F9, 0x00F9,
/*FA*/ 0x00FA, 0x00FA, 0x00FA, 0x00FA, 0x045A, STR_UD, 0x03CA, 0x05EA, 0x00FA, 0x00FA, 0x0E5A, 0x015B, 0x00FA, 0x00FA,
/*FB*/ 0x00FB, 0x0171, 0x00FB, 0x00FB, 0x045B, STR_UD, 0x03CB, STR_UD, 0x00FB, 0x00FB, 0x0E5B, 0x016B, 0x00FB, 0x00FB,
/*FC*/ 0x00FC, 0x00FC, 0x00FC, 0x00FC, 0x045C, STR_UD, 0x03CC, STR_UD, 0x00FC, 0x00FC, STR_UD, 0x00FC, 0x00FC, 0x00FC,
/*FD*/ 0x00FD, 0x00FD, 0x016D, 0x0169, 0x00A7, STR_UD, 0x03CD, 0x200E, 0x0131, 0x00FD, STR_UD, 0x017C, 0x00FD, 0x00FD,
/*FE*/ 0x00FE, 0x0163, 0x015D, 0x016B, 0x045E, STR_UD, 0x03CE, 0x200F, 0x015F, 0x00FE, STR_UD, 0x017E, 0x0177, 0x00FE,
/*FF*/ 0x00FF, 0x02D9, 0x02D9, 0x02D9, 0x045F, STR_UD, STR_UD, STR_UD, 0x00FF, 0x0138, STR_UD, 0x2019, 0x00FF, 0x00FF
};

#define STR_PRINTABLE_START         0x20    //!< Start of printable characters.

#ifdef STR_UNICODE_BIGENDIAN /* big endian format */

    #define STR_UNICODE_RDCHAR(a)    ((((SYS_CHAR)(a)[0]) << 8) | (a)[1])

    #define STR_UNICODE_WRCHAR(a, d) do {                       \
                                         (a)[0] = (d) >> 8;     \
                                         (a)[1] = (d) & 0x00FF; \
                                     } while (0);               \

#else /* little endian format */

    #define STR_UNICODE_RDCHAR(a)    ((a)[0] | (((SYS_CHAR)(a)[1]) << 8))

    #define STR_UNICODE_WRCHAR(a, d) do {                       \
                                    /*lint -save -e572 -e702*/  \
                                         (a)[0] = (d) & 0x00FF; \
                                         (a)[1] = (d) >> 8;     \
                                    /*lint -restore */          \
                                     } while (0);               \

#endif /* STR_UNICODE_BIGENDIAN */


#define STR_UTF8_1BYTE_IS(a)   (((a)[0] & 0x80) == 0x00)

#define STR_UTF8_2BYTE_IS(a)  ((((a)[0] & 0xE0) == 0xC0) && \
                               (((a)[1] & 0xC0) == 0x80))

#define STR_UTF8_3BYTE_IS(a)  ((((a)[0] & 0xF0) == 0xE0) && \
                               (((a)[1] & 0xC0) == 0x80) && \
                               (((a)[2] & 0xC0) == 0x80))

#define STR_UTF8_1BYTE_GET(a) ((a)[0] & 0x7F)

#define STR_UTF8_2BYTE_GET(a) ((((SYS_CHAR)((a)[0] & 0x1F)) << 6) | \
                                           ((a)[1] & 0x3F))

#define STR_UTF8_3BYTE_GET(a) ((((SYS_CHAR)((a)[0] & 0x0F)) << 12) | \
                               (((SYS_CHAR)((a)[1] & 0x3F)) <<  6) | \
                                           ((a)[2] & 0x3F))


#define STR_8859_UPPERSTART         0xA0    //!< Start of supplementary chars.
#define STR_8859_UPPERBYTES         0x60    //!< Number of supplementary chars.
#define STR_8559_CHARSET_NUMS       (SYS_CHARSET_ISO8859_15 -   \
                                     SYS_CHARSET_ISO8859_1 + 1)
                                            //!< Number of ISO-8859 char sets.

/*FSTATIC*/ uint32_t STR_CharGetTab0 (const char_t* pStr,
                                     SYS_CHAR* pChr);

typedef struct
{
    char_t      followByte;
    SYS_CHAR    unicodeChar;

} STR_TAB0_MAP_S;

STR_TAB0_MAP_S table_tab0_c1[] =  { { 0x20, 0x0060 },
                                    { 0x41, 0x00C0 },
                                    { 0x45, 0x00C8 },
                                    { 0x49, 0x00CC },
                                    { 0x4F, 0x00D2 },
                                    { 0x55, 0x00D9 },
                                    { 0x61, 0x00E0 },
                                    { 0x65, 0x00E8 },
                                    { 0x69, 0x00EC },
                                    { 0x6F, 0x00F2 },
                                    { 0x75, 0x00F9 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c2[] =  { { 0x20, 0x00B4 },
                                    { 0x41, 0x00C1 },
                                    { 0x43, 0x0106 },
                                    { 0x45, 0x00C9 },
                                    { 0x49, 0x00CD },
                                    { 0x4C, 0x0139 },
                                    { 0x4E, 0x0143 },
                                    { 0x4F, 0x00D3 },
                                    { 0x52, 0x0154 },
                                    { 0x53, 0x015A },
                                    { 0x55, 0x00DA },
                                    { 0x59, 0x00DD },
                                    { 0x5A, 0x0179 },
                                    { 0x61, 0x00E1 },
                                    { 0x63, 0x0107 },
                                    { 0x65, 0x00E9 },
                                    { 0x69, 0x00ED },
                                    { 0x6C, 0x013A },
                                    { 0x6E, 0x0144 },
                                    { 0x6F, 0x00F3 },
                                    { 0x72, 0x0155 },
                                    { 0x73, 0x015B },
                                    { 0x75, 0x00FA },
                                    { 0x79, 0x00FD },
                                    { 0x7A, 0x017A },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c3[] =  { { 0x20, 0x02C6 },
                                    { 0x41, 0x00C2 },
                                    { 0x43, 0x0108 },
                                    { 0x45, 0x00CA },
                                    { 0x47, 0x011C },
                                    { 0x48, 0x0124 },
                                    { 0x49, 0x00CE },
                                    { 0x4A, 0x0134 },
                                    { 0x4F, 0x00D4 },
                                    { 0x53, 0x015C },
                                    { 0x55, 0x00DB },
                                    { 0x57, 0x0174 },
                                    { 0x59, 0x0176 },
                                    { 0x61, 0x00E2 },
                                    { 0x63, 0x0109 },
                                    { 0x65, 0x00EA },
                                    { 0x67, 0x011D },
                                    { 0x68, 0x0125 },
                                    { 0x69, 0x00EE },
                                    { 0x6A, 0x0135 },
                                    { 0x6F, 0x00F4 },
                                    { 0x73, 0x015D },
                                    { 0x75, 0x00FB },
                                    { 0x77, 0x0175 },
                                    { 0x79, 0x0177 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c4[] =  { { 0x20, 0x02DC },
                                    { 0x41, 0x00C3 },
                                    { 0x49, 0x0128 },
                                    { 0x4E, 0x00D1 },
                                    { 0x4F, 0x00D5 },
                                    { 0x55, 0x0168 },
                                    { 0x61, 0x00E3 },
                                    { 0x69, 0x0129 },
                                    { 0x6E, 0x00F1 },
                                    { 0x6F, 0x00F5 },
                                    { 0x75, 0x0169 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c5[] =  { { 0x20, 0x00AF },
                                    { 0x41, 0x0100 },
                                    { 0x45, 0x0112 },
                                    { 0x49, 0x012A },
                                    { 0x4F, 0x014C },
                                    { 0x55, 0x016A },
                                    { 0x61, 0x0101 },
                                    { 0x65, 0x0113 },
                                    { 0x69, 0x012B },
                                    { 0x6F, 0x014D },
                                    { 0x75, 0x016B },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c6[] =  { { 0x20, 0x02D8 },
                                    { 0x41, 0x0102 },
                                    { 0x47, 0x011E },
                                    { 0x55, 0x016C },
                                    { 0x61, 0x0103 },
                                    { 0x67, 0x011F },
                                    { 0x75, 0x016D },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c7[] =  { { 0x20, 0x02D9 },
                                    { 0x43, 0x010A },
                                    { 0x45, 0x0116 },
                                    { 0x47, 0x0120 },
                                    { 0x49, 0x0130 },
                                    { 0x5A, 0x017B },
                                    { 0x63, 0x010B },
                                    { 0x65, 0x0117 },
                                    { 0x67, 0x0121 },
                                    { 0x69, 0x0131 },
                                    { 0x7A, 0x017C },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_c8[] =  { { 0x20, 0x00A8 },
                                    { 0x41, 0x00C4 },
                                    { 0x45, 0x00CB },
                                    { 0x49, 0x00CF },
                                    { 0x4F, 0x00D6 },
                                    { 0x55, 0x00DC },
                                    { 0x59, 0x0178 },
                                    { 0x61, 0x00E4 },
                                    { 0x65, 0x00EB },
                                    { 0x69, 0x00EF },
                                    { 0x6F, 0x00F6 },
                                    { 0x75, 0x00FC },
                                    { 0x79, 0x00FF },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_ca[] =  { { 0x20, 0x00B0 },
                                    { 0x41, 0x00C5 },
                                    { 0x55, 0x016E },
                                    { 0x61, 0x00E5 },
                                    { 0x75, 0x016F },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_cb[] =  { { 0x20, 0x00B8 },
                                    { 0x43, 0x00C7 },
                                    { 0x47, 0x0122 },
                                    { 0x4B, 0x0136 },
                                    { 0x4C, 0x013B },
                                    { 0x4E, 0x0145 },
                                    { 0x52, 0x0156 },
                                    { 0x53, 0x015E },
                                    { 0x54, 0x0162 },
                                    { 0x63, 0x00E7 },
                                    { 0x67, 0x0123 },
                                    { 0x6B, 0x0137 },
                                    { 0x6C, 0x013C },
                                    { 0x6E, 0x0146 },
                                    { 0x72, 0x0157 },
                                    { 0x73, 0x015F },
                                    { 0x74, 0x0163 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_cd[] =  { { 0x20, 0x02DD },
                                    { 0x4F, 0x0150 },
                                    { 0x55, 0x0170 },
                                    { 0x6F, 0x0151 },
                                    { 0x75, 0x0171 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_ce[] =  { { 0x20, 0x02DB },
                                    { 0x41, 0x0104 },
                                    { 0x45, 0x0118 },
                                    { 0x49, 0x012E },
                                    { 0x55, 0x0172 },
                                    { 0x61, 0x0105 },
                                    { 0x65, 0x0119 },
                                    { 0x69, 0x012F },
                                    { 0x75, 0x0173 },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S table_tab0_cf[] =  { { 0x20, 0x02C7 },
                                    { 0x43, 0x010C },
                                    { 0x44, 0x010E },
                                    { 0x45, 0x011A },
                                    { 0x4C, 0x013D },
                                    { 0x4E, 0x0147 },
                                    { 0x52, 0x0158 },
                                    { 0x53, 0x0160 },
                                    { 0x54, 0x0164 },
                                    { 0x5A, 0x017D },
                                    { 0x63, 0x010D },
                                    { 0x64, 0x010F },
                                    { 0x65, 0x011B },
                                    { 0x6C, 0x013E },
                                    { 0x6E, 0x0148 },
                                    { 0x72, 0x0159 },
                                    { 0x73, 0x0161 },
                                    { 0x74, 0x0165 },
                                    { 0x7A, 0x017E },
                                    { 0x00, 0x0000 } };

STR_TAB0_MAP_S* table_tab0_twobyte[] =    { table_tab0_c1,
                                            table_tab0_c2,
                                            table_tab0_c3,
                                            table_tab0_c4,
                                            table_tab0_c5,
                                            table_tab0_c6,
                                            table_tab0_c7,
                                            table_tab0_c8,
                                            NULL,
                                            table_tab0_ca,
                                            table_tab0_cb,
                                            NULL,
                                            table_tab0_cd,
                                            table_tab0_ce,
                                            table_tab0_cf};


/*FSTATIC*/static inline fbool_t STR_IsPrintableChar_8Bit(char_t currChar)
{
    if ( currChar >= STR_PRINTABLE_START )
    {
        return FTRUE;
    }
#if 0
    if ( ( SYS_GetAppProfile() == SYS_APP_PROFILE_UKDTT_T2 ) ||
         ( SYS_GetAppProfile() == SYS_APP_PROFILE_AUSTRALIA_FREEVIEW) )
    {
        if( currChar == 0x0A )
        {
            return FTRUE;
        }
    }
#endif
    return FFALSE;
}


/*FSTATIC*/static inline fbool_t STR_IsPrintableChar_16Bit(SYS_CHAR currChar)
{
    if ( currChar >= STR_PRINTABLE_START )
    {
        return FTRUE;
    }

#if 0
    if ( ( SYS_GetAppProfile() == SYS_APP_PROFILE_UKDTT_T2 ) ||
         ( SYS_GetAppProfile() == SYS_APP_PROFILE_AUSTRALIA_FREEVIEW) )
    {
        if( currChar == 0x0A )
        {
            return FTRUE;
        }
    }
#endif

    return FFALSE;
}


/* 21b9ffe8 - complete */
FSTATIC uint32_t STR_INT_8859_Plain (SYS_CHARSET srcCs, const char_t* srcBuf,
                                     SYS_CHARSET dstCs, char_t* dstBuf,
                                     uint32_t maxBytes, uint32_t numBytes)
{
    char_t* pDst = dstBuf;

    if ( maxBytes >= 1 )
    {
        while ( ((*srcBuf)  != 0)  &&
                (maxBytes    > 1)  &&
                (numBytes--  > 0) )
        {
            if ( STR_IsPrintableChar_8Bit(*srcBuf) )
            {
                *pDst++ = *srcBuf;
                maxBytes--;
            }
            srcBuf++;
        }
        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba0068 - complete */
FSTATIC uint32_t STR_INT_8859_8859 (SYS_CHARSET srcCs, const char_t* srcBuf,
                                    SYS_CHARSET dstCs, char_t* dstBuf,
                                    uint32_t maxBytes, uint32_t numBytes)
{
    char_t* pDst = dstBuf;

    if ( maxBytes >= 1 )
    {
        while ( ((*srcBuf)  != 0) &&
                (maxBytes   >  1) &&
                (numBytes-- >  0) )
        {
            if ( STR_IsPrintableChar_8Bit(*srcBuf) )
            {
                if ( (uint8_t)(*srcBuf) < STR_8859_UPPERSTART )
                {
                    /* low 7 bits + control codes are common among 8-bit
                       character sets. */
                    *pDst++ = *srcBuf;
                    maxBytes--;
                }

                /* NOTE: Characters 0xA0 - 0xFF cannot be mapped among 8-bit
                         character sets. Thus they will be discarded during
                         this conversion! */
            }
            srcBuf++;
        }
        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba05b8 - complete */
FSTATIC uint32_t STR_INT_16Bit_Plain (SYS_CHARSET srcCs, const char_t* srcBuf,
                                 SYS_CHARSET dstCs, char_t* dstBuf,
                                 uint32_t maxBytes, uint32_t numBytes)
{
    char_t*       pDst = dstBuf;
    SYS_CHAR    currChar;

    if ( maxBytes >= 2 )
    {
        while ( (maxBytes >= 4) &&
                (numBytes >= 2) )
        {
            currChar = STR_UNICODE_RDCHAR(srcBuf);

            if ( currChar == 0 )
            {
                /* source string end */
                break;
            }
            else if ( STR_IsPrintableChar_16Bit( currChar ) )
            {
                /* not necessary to use STR_UNICODE_WRCHAR here. No conversion
                   takes place. */
                *pDst++ = srcBuf[0];
                *pDst++ = srcBuf[1];

                maxBytes -= 2;
            }

            srcBuf   += 2;
            numBytes -= 2;
        }

        /* terminate destination string */
        STR_UNICODE_WRCHAR(pDst, 0);
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba0208 - complete */
FSTATIC uint32_t STR_INT_Utf8_Plain (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t* pDst = dstBuf;

    if ( maxBytes >= 1 )
    {
        while ( ((*srcBuf) != 0)  &&
                (numBytes   > 0) )
        {
            if ( STR_UTF8_1BYTE_IS(srcBuf) )
            {
                /* single-byte code */

                if ( maxBytes < 2 ) break; /* includes termination */

                if ( STR_IsPrintableChar_8Bit(srcBuf[0]) )
                {
                    *pDst++ = *srcBuf;
                    maxBytes--;
                }

                srcBuf++;
                numBytes--;
            }
            else if ( STR_UTF8_2BYTE_IS(srcBuf) && (numBytes > 1) )
            {
                /* two-byte code */

                if ( maxBytes < 3 ) break; /* includes termination */

                *pDst++ = *srcBuf++;
                *pDst++ = *srcBuf++;

                maxBytes -= 2;
                numBytes -= 2;
            }
            else if ( STR_UTF8_3BYTE_IS(srcBuf) && (numBytes > 2) )
            {
                /* three-byte code */

                if ( maxBytes < 4 ) break; /* includes termination */

                *pDst++ = *srcBuf++;
                *pDst++ = *srcBuf++;
                *pDst++ = *srcBuf++;

                maxBytes -= 3;
                numBytes -= 3;
            }
            else
            {
                FAPI_SYS_PRINT_DEBUG(4,"[SYS] UTF-8: invalid encoding!\n");
                break;
            }
        }

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba0820 - complete */
FSTATIC uint32_t STR_INT_16Bit_Tab0 (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t*       pDst = dstBuf;
    SYS_CHAR    currChar;

    if ( maxBytes >= 1 )
    {
        while ( (maxBytes >= 2) &&
                (numBytes >= 2) )
        {
            currChar = STR_UNICODE_RDCHAR(srcBuf);

            if ( currChar == 0 )
            {
                /* source string end */
                break;
            }
            else if ( STR_IsPrintableChar_16Bit( currChar ) )
            {
                /* to do: map characters for table 0 (0xA0-0xFF) */
                /* to do: handle 2-byte characters of table 0 */
                /* reverse matrix needed: unicode -> 6937 */

                *pDst++ = currChar & 0x00FF;

                maxBytes--;
            }

            srcBuf   += 2;
            numBytes -= 2;
        }

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba0350 - complete */
FSTATIC uint32_t STR_INT_Utf8_8859 (SYS_CHARSET srcCs, const char_t* srcBuf,
                               SYS_CHARSET dstCs, char_t* dstBuf,
                               uint32_t maxBytes, uint32_t numBytes)
{
    char_t*    pDst = dstBuf;
    SYS_CHAR currChar;

    if ( maxBytes >= 1 )
    {
        while ( ((*srcBuf) != 0)  &&
                (maxBytes  >= 2)  &&
                (numBytes  >  0) )
        {
            if ( STR_UTF8_1BYTE_IS(srcBuf) )
            {
                /* single-byte code */
                currChar = STR_UTF8_1BYTE_GET(srcBuf);

                srcBuf++;
                numBytes--;
            }
            else if ( STR_UTF8_2BYTE_IS(srcBuf) && (numBytes > 1) )
            {
                /* two-byte code */
                currChar = STR_UTF8_2BYTE_GET(srcBuf);

                srcBuf   += 2;
                numBytes -= 2;
            }
            else if ( STR_UTF8_3BYTE_IS(srcBuf) && (numBytes > 2) )
            {
                /* three-byte code */
                currChar = STR_UTF8_3BYTE_GET(srcBuf);

                srcBuf   += 3;
                numBytes -= 3;
            }
            else
            {
                FAPI_SYS_PRINT_DEBUG(4,"[SYS] UTF-8: invalid encoding!\n");
                break;
            }

            if ( STR_IsPrintableChar_16Bit( currChar ) )
            {
                if ( currChar < STR_8859_UPPERSTART )
                {
                    *pDst++ = (currChar & 0xFF);
                    maxBytes--;
                }
                else if ( (currChar <
                          (STR_8859_UPPERSTART + STR_8859_UPPERBYTES)) &&
                          (dstCs == SYS_CHARSET_ISO8859_1) )
                {
                    *pDst++ = (currChar & 0xFF);
                    maxBytes--;
                }

                /* NOTE: Unicode characters >= 0x100 for ISO 8859-1 or
                         >= 0xA0 for other ISO 8859 character sets are
                         discarded in this current implementation. */
                /* to do: map unicode characters onto ISO-8859-x upper bytes! */
            }
        }

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba00f0 - complete */
FSTATIC uint32_t STR_INT_8859_16Bit (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t*       pDst = dstBuf;
    SYS_CHAR    currChar;

    if ( maxBytes >= 2 )
    {
        while ( ((*srcBuf) != 0) && (maxBytes >= 4) && (numBytes-- > 0) )
        {
            if ( STR_IsPrintableChar_8Bit(*srcBuf) )
            {
                if ( (uint8_t)(*srcBuf) < STR_8859_UPPERSTART )
                {
                    /* low 7 bits + control codes are common among 8-bit
                       character sets and are mapped directly to unicode. */
                    currChar = *srcBuf;
                }
                else
                {
                    currChar = table_8859_unicode[
                                   (((*srcBuf) - STR_8859_UPPERSTART) *
                                   STR_8559_CHARSET_NUMS) +
                                   (srcCs - SYS_CHARSET_ISO8859_1)];
                }
                if ( currChar != STR_UD )
                {
                    STR_UNICODE_WRCHAR(pDst, currChar);
                    pDst += 2;
                }
                maxBytes -= 2;
            }
            srcBuf++;
        }
        /* terminate destination string */
        STR_UNICODE_WRCHAR(pDst, 0);
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba0490 - complete */
FSTATIC uint32_t STR_INT_Utf8_16Bit (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t*    pDst = dstBuf;
    SYS_CHAR currChar;

//    FAPI_SYS_PRINT_MSG("STR_INT_Utf8_16Bit\n");

    if ( maxBytes >= 2 )
    {
        while ( ((*srcBuf) != 0)  &&
                (maxBytes  >= 4)  &&
                (numBytes  >  0) )
        {
            if ( STR_UTF8_1BYTE_IS(srcBuf) )
            {
                /* single-byte code */
                currChar = STR_UTF8_1BYTE_GET(srcBuf);

                srcBuf++;
                numBytes--;
            }
            else if ( STR_UTF8_2BYTE_IS(srcBuf) && (numBytes > 1) )
            {
                /* two-byte code */
                currChar = STR_UTF8_2BYTE_GET(srcBuf);

#if 0
                if( ( SYS_GetAppProfile() == SYS_APP_PROFILE_UKDTT_T2 ) ||
                    ( SYS_GetAppProfile() == SYS_APP_PROFILE_AUSTRALIA_FREEVIEW ) )
                {
                    switch( currChar )
                    {
                        case 0x00A4: currChar = 0x20AC; break; // euro currency sign
                        default: break;
                    }
                }
#endif
                srcBuf   += 2;
                numBytes -= 2;
            }
            else if ( STR_UTF8_3BYTE_IS(srcBuf) && (numBytes > 2) )
            {
                /* three-byte code */
                currChar = STR_UTF8_3BYTE_GET(srcBuf);

                srcBuf   += 3;
                numBytes -= 3;
            }
            else
            {
                FAPI_SYS_PRINT_DEBUG(4,"[SYS] UTF-8: invalid encoding!\n");
                break;
            }

            if ( STR_IsPrintableChar_16Bit( currChar ) )
            {
                STR_UNICODE_WRCHAR(pDst, currChar);

                pDst     += 2;
                maxBytes -= 2;
            }
        }

        /* terminate destination string */
        STR_UNICODE_WRCHAR(pDst, 0);
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba08a8 - complete */
FSTATIC uint32_t  STR_INT_Tab0_16Bit (SYS_CHARSET srcCs, const char_t* srcBuf,
                                 SYS_CHARSET dstCs, char_t* dstBuf,
                                 uint32_t maxBytes, uint32_t numBytes)
{
    char_t*     pDst = dstBuf;
    SYS_CHAR    currChar;
    uint32_t    bytesPerChar;

    if ( maxBytes >= 2 )
    {
        while ( ((*srcBuf) != 0)    &&
                (maxBytes  >= 4)    &&
                (numBytes  >  0) )
        {
            if ( STR_IsPrintableChar_8Bit(*srcBuf) )
            {
                bytesPerChar = STR_CharGetTab0 (srcBuf, &currChar);

                if ( (bytesPerChar == 0) ||
                     (bytesPerChar > numBytes) )
                {
                    break;
                }

                if ( currChar != STR_UD )
                {
                    STR_UNICODE_WRCHAR(pDst, currChar);

                    pDst     += 2;
                    maxBytes -= 2;
                }
            }
            else
            {
                bytesPerChar = 1;
            }

            srcBuf   += bytesPerChar;
            numBytes -= bytesPerChar;
        }

        /* terminate destination string */
        STR_UNICODE_WRCHAR(pDst, 0);
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba01c0 - complete */
FSTATIC uint32_t STR_INT_8859_Utf8 (SYS_CHARSET srcCs, const char_t* srcBuf,
                               SYS_CHARSET dstCs, char_t* dstBuf,
                               uint32_t maxBytes, uint32_t numBytes)
{
    char_t* pDst = dstBuf;

#if 0
    FAPI_SYS_PRINT_DEBUG(1,"STR_INT_8859_Utf8 (%i -> %i): not implemented! \n",
               srcCs, dstCs);
#else
    FAPI_SYS_PRINT_MSG("STR_INT_8859_Utf8 (%i -> %i): not implemented! \n",
               srcCs, dstCs);
#endif

    if ( maxBytes >= 1 )
    {
        /* to do: implement it! */

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba066c - complete */
FSTATIC uint32_t STR_INT_16Bit_8859 (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t*       pDst = dstBuf;
    SYS_CHAR    currChar;

    if ( maxBytes >= 1 )
    {
        while ( (maxBytes >= 2) &&
                (numBytes >= 2) )
        {
            currChar = STR_UNICODE_RDCHAR(srcBuf);

            if ( currChar == 0 )
            {
                /* source string end */
                break;
            }
            else if ( STR_IsPrintableChar_16Bit( currChar ) )
            {
                /* to do: map each character >= 0xA0 individually for each
                          ISO 8859 table. */

                *pDst++ = currChar & 0x00FF;

                maxBytes--;
            }

            srcBuf   += 2;
            numBytes -= 2;
        }

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba06f4 - complete */
FSTATIC uint32_t STR_INT_16Bit_Utf8 (SYS_CHARSET srcCs, const char_t* srcBuf,
                                SYS_CHARSET dstCs, char_t* dstBuf,
                                uint32_t maxBytes, uint32_t numBytes)
{
    char_t*       pDst = dstBuf;
    SYS_CHAR    currChar;

    if ( maxBytes >= 1 )
    {
        while ( numBytes >= 2 )
        {
            currChar = STR_UNICODE_RDCHAR(srcBuf);

            if ( currChar == 0 )
            {
                /* source string end */
                break;
            }
            else if ( currChar <= 0x007F ) /* single-byte code */
            {
                if ( maxBytes < 2 ) break; /* includes termination */

                *dstBuf++ = currChar;

                maxBytes--;
            }
            else if ( currChar <= 0x07FF ) /* two-byte code */
            {
                if ( maxBytes < 3 ) break; /* includes termination */

                *dstBuf++ = ((currChar & 0x07C0) >> 6) | 0xC0;
                *dstBuf++ =  (currChar & 0x003F)       | 0x80;

                maxBytes -= 2;
            }
            else /* three-byte code */
            {
                if ( maxBytes < 4 ) break; /* includes termination */

                *dstBuf++ = ((currChar & 0xF000) >> 12) | 0xE0;
                *dstBuf++ = ((currChar & 0x0FC0) >>  6) | 0x80;
                *dstBuf++ =  (currChar & 0x003F)        | 0x80;

                maxBytes -= 3;
            }

            srcBuf   += 2;
            numBytes -= 2;
        }

        *pDst = 0; /* terminate destination string */
    }

    return (uint32_t)(pDst - dstBuf);
}


/* 21ba1adc - complete */
int32_t STR_Init(struct appData* a)
{
    uint32_t cntSrc;
   uint32_t cntDst;

   if (strDat != 0)
   {
      FAPI_SYS_PRINT_MSG("ASSERTION FAILED at %s, l.%i\n",
            "sys/src/stringop.c", 558);
      rtos_halt(-1);
   }
   
   strDat = SYS_MemoryAllocate(sizeof(SYS_STR_DATA_S));
   if (strDat == NULL)
   {
      //21ba1b34
      return -2;
   }
   
   memset(strDat, 0, sizeof(SYS_STR_DATA_S));
   
   if (a->altDefaultSiCharSet != SYS_CHARSET_UNDEFINED) //0)
   {
      strDat->defaultSiCharSet = a->altDefaultSiCharSet;
   }
   else
   {
      strDat->defaultSiCharSet = SYS_CHARSET_TABLE0; //1;
   }
   
   if (0 != STR_BufOpen(&strDat->lineBuf, a->Data_28, 0))
   {
      //->21ba1b34
      return -2;
   }
   
   strDat->/*Data_1320*/asciiStr.chr = SYS_MemoryAllocate(a->Data_32);
   if (strDat->/*Data_1320*/asciiStr.chr == 0)
   {
      //->21ba1b34
      return -2;
   }
   
   strDat->/*bData_1316*/asciiStr.cs = 2;

   for (cntSrc = SYS_CHARSET_TABLE0/*0*/; cntSrc <= SYS_CHARSET_ISO8859_15/*16*/; cntSrc++)
   {
      for (cntDst = SYS_CHARSET_TABLE0/*0*/; cntDst <= SYS_CHARSET_ISO8859_15/*16*/; cntDst++)
      {
         strDat->conv[cntSrc][cntDst] = STR_INT_8859_8859;
      }
   }

   strDat->conv[SYS_CHARSET_TABLE0/*1*/    ][SYS_CHARSET_TABLE0/*1*/    ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_1 ][SYS_CHARSET_ISO8859_1 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_2 ][SYS_CHARSET_ISO8859_2 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_3 ][SYS_CHARSET_ISO8859_3 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_4 ][SYS_CHARSET_ISO8859_4 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_5 ][SYS_CHARSET_ISO8859_5 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_6 ][SYS_CHARSET_ISO8859_6 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_7 ][SYS_CHARSET_ISO8859_7 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_8 ][SYS_CHARSET_ISO8859_8 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_9 ][SYS_CHARSET_ISO8859_9 ] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_10][SYS_CHARSET_ISO8859_10] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_11][SYS_CHARSET_ISO8859_11] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_13][SYS_CHARSET_ISO8859_13] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_14][SYS_CHARSET_ISO8859_14] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO8859_15][SYS_CHARSET_ISO8859_15] = STR_INT_8859_Plain;
   strDat->conv[SYS_CHARSET_ISO_10646/*16*/ ][SYS_CHARSET_ISO_10646/*16*/ ] = STR_INT_16Bit_Plain;
   strDat->conv[SYS_CHARSET_UTF8/*17*/      ][SYS_CHARSET_UTF8      ] = STR_INT_Utf8_Plain;

   /* ----- conversion from 16 bit unicode -------------------------------- */

   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_TABLE0    ] = STR_INT_16Bit_Tab0;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_1 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_2 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_3 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_4 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_5 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_6 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_7 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_8 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_9 ] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_10] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_11] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_13] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_14] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_ISO8859_15] = STR_INT_16Bit_8859;
   strDat->conv[SYS_CHARSET_ISO_10646 ][SYS_CHARSET_UTF8      ] = STR_INT_16Bit_Utf8;

   /* ----- conversion from UTF-8 ----------------------------------------- */

   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_TABLE0    ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_1 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_2 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_3 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_4 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_5 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_6 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_7 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_8 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_9 ] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_10] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_11] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_13] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_14] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8      ][SYS_CHARSET_ISO8859_15] = STR_INT_Utf8_8859;
   strDat->conv[SYS_CHARSET_UTF8/*17*/][SYS_CHARSET_ISO_10646/*16*/] = STR_INT_Utf8_16Bit;

   /* ----- conversion to 16 bit unicode ---------------------------------- */

   strDat->conv[SYS_CHARSET_TABLE0    ][SYS_CHARSET_ISO_10646 ] = STR_INT_Tab0_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_1 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_2 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_3 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_4 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_5 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_6 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_7 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_8 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_9 ][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_10][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_11][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_13][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_14][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;
   strDat->conv[SYS_CHARSET_ISO8859_15][SYS_CHARSET_ISO_10646 ] = STR_INT_8859_16Bit;

   /* ----- conversion to UTF-8 ------------------------------------------- */

   strDat->conv[SYS_CHARSET_TABLE0    ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_1 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_2 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_3 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_4 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_5 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_6 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_7 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_8 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_9 ][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_10][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_11][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_13][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_14][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;
   strDat->conv[SYS_CHARSET_ISO8859_15][SYS_CHARSET_UTF8      ] = STR_INT_8859_Utf8;

   return 0;
}


/* 21ba1a6c - complete */
int32_t STR_BufOpen(SYS_STRBUF_S* a, int size, void* data)
{   
   if ((a == 0) || (size == 0))
   {
      return -10000001;
   }
   
   if (data != 0)
   {
      a->buf = data;
      a->memAllocated = 0;
   }
   else
   {
      a->buf = SYS_MemoryAllocate(size);
      if (a->buf == 0)
      {
         return -2;
      }
      
      a->memAllocated = 1;
   }

   a->bufSize = size;
   
   STR_BufClear(a);

   return 0;
}


/* 21ba1a18 - complete */
int32_t STR_BufClose(struct Struct_21ba1a6c* a)
{
   if (a == 0)
   {
      return -10000001;
   }
   
   if ((a->memAllocated != 0) && (a->buf != 0))
   {
      SYS_MemoryFree(a->buf);
      
      a->buf = 0;
      a->memAllocated = 0;
   }
   
   a->bufSize = 0;
   
   STR_Clear(a);
   
   return 0;
}


/* 21b9fd40 - complete */
uint32_t STR_CharGet (SYS_STRING_S string, uint32_t byteOffset, SYS_CHAR* chr)
{
    const char_t* pStr     = string.chr + byteOffset;
    uint32_t      strBytes = 0;
    SYS_CHAR      currChar = 0;

    switch ( string.cs )
    {
        default:
        case SYS_CHARSET_UNDEFINED:
            /* invalid format */
            break;

        case SYS_CHARSET_TABLE0:
            strBytes = STR_CharGetTab0 (pStr, &currChar);
            break;

        case SYS_CHARSET_ISO8859_1:
        case SYS_CHARSET_ISO8859_2:
        case SYS_CHARSET_ISO8859_3:
        case SYS_CHARSET_ISO8859_4:
        case SYS_CHARSET_ISO8859_5:
        case SYS_CHARSET_ISO8859_6:
        case SYS_CHARSET_ISO8859_7:
        case SYS_CHARSET_ISO8859_8:
        case SYS_CHARSET_ISO8859_9:
        case SYS_CHARSET_ISO8859_10:
        case SYS_CHARSET_ISO8859_11:
        case SYS_CHARSET_ISO8859_13:
        case SYS_CHARSET_ISO8859_14:
        case SYS_CHARSET_ISO8859_15:

            if ( (*pStr) != 0 )
            {
                if ( (uint8_t)(*pStr) < STR_8859_UPPERSTART )
                {
                    /* low 7 bits + control codes are common among 8-bit
                       character sets and are mapped directly to unicode. */
                    currChar = *pStr;
                }
                else
                {
                    currChar = table_8859_unicode[
                                   (((*pStr) - STR_8859_UPPERSTART) *
                                   STR_8559_CHARSET_NUMS) +
                                   (string.cs - SYS_CHARSET_ISO8859_1)];

                }

                strBytes = 1;
            }
            break;

        case SYS_CHARSET_ISO_10646:

            if ( (pStr[0] != 0) ||
                 (pStr[1] != 0) )
            {
                strBytes = 2;
                currChar = STR_UNICODE_RDCHAR(pStr);
            }
            break;

        case SYS_CHARSET_UTF8:

            if ( (*pStr) != 0 )
            {
                if ( STR_UTF8_1BYTE_IS(pStr) )
                {
                    strBytes = 1; /* single-byte code */
                    currChar = STR_UTF8_1BYTE_GET(pStr);
                }
                else if ( STR_UTF8_2BYTE_IS(pStr) )
                {
                    strBytes = 2; /* two-byte code */
                    currChar = STR_UTF8_2BYTE_GET(pStr);
                }
                else if ( STR_UTF8_3BYTE_IS(pStr) )
                {
                    strBytes = 3; /* three-byte code */
                    currChar = STR_UTF8_3BYTE_GET(pStr);
                }
                else
                {
                    FAPI_SYS_PRINT_DEBUG(4,"[SYS] UTF-8: invalid encoding!\n");
                    break;
                }
            }
            break;
    }

    if ( chr != NULL )
    {
        if ( strBytes == 0 )    *chr = 0;
        else                    *chr = currChar;
    }

    return strBytes;
}


/* 21b9f244 - todo */
fbool_t STR_IsEmpty (SYS_STRING_S string)
{
    fbool_t empty = FTRUE;

    if ( string.chr != NULL )
    {
        switch ( string.cs )
        {
            default:
            case SYS_CHARSET_UNDEFINED:
                break;

            case SYS_CHARSET_TABLE0:
            case SYS_CHARSET_ISO8859_1:
            case SYS_CHARSET_ISO8859_2:
            case SYS_CHARSET_ISO8859_3:
            case SYS_CHARSET_ISO8859_4:
            case SYS_CHARSET_ISO8859_5:
            case SYS_CHARSET_ISO8859_6:
            case SYS_CHARSET_ISO8859_7:
            case SYS_CHARSET_ISO8859_8:
            case SYS_CHARSET_ISO8859_9:
            case SYS_CHARSET_ISO8859_10:
            case SYS_CHARSET_ISO8859_11:
            case SYS_CHARSET_ISO8859_13:
            case SYS_CHARSET_ISO8859_14:
            case SYS_CHARSET_ISO8859_15:
            case SYS_CHARSET_UTF8:
                if ( string.chr[0] != 0 )
                {
                    empty = FFALSE;
                }
                break;

            case SYS_CHARSET_ISO_10646:
                if ( (string.chr[0] != 0) ||
                     (string.chr[1] != 0) )
                {
                    empty = FFALSE;
                }
                break;
        }
    }

    return empty;
}


/* 21b9f76c - complete */
int32_t STR_BufClear(struct Struct_21ba1a6c* a)
{
   if (a == 0)
   {
      a = &strDat->lineBuf;
   }

   STR_Clear(a);

   STR_Terminate(a->buf, a->bufSize);

   return 0;
}


/* 21b9f480 - complete */
uint32_t STR_GetLineEnd (SYS_STRING_S string)
{
    const char_t* pStr = string.chr;

    if ( string.chr != NULL )
    {
        switch ( string.cs )
        {
            default:
            case SYS_CHARSET_UNDEFINED:
                /* invalid format */
                break;

            case SYS_CHARSET_TABLE0:
            case SYS_CHARSET_ISO8859_1:
            case SYS_CHARSET_ISO8859_2:
            case SYS_CHARSET_ISO8859_3:
            case SYS_CHARSET_ISO8859_4:
            case SYS_CHARSET_ISO8859_5:
            case SYS_CHARSET_ISO8859_6:
            case SYS_CHARSET_ISO8859_7:
            case SYS_CHARSET_ISO8859_8:
            case SYS_CHARSET_ISO8859_9:
            case SYS_CHARSET_ISO8859_10:
            case SYS_CHARSET_ISO8859_11:
            case SYS_CHARSET_ISO8859_13:
            case SYS_CHARSET_ISO8859_14:
            case SYS_CHARSET_ISO8859_15:
                while ( ((*pStr) != 0x00) &&
                        ((*pStr) != STR_CHAR_LINEBREAK) )
                {
                    pStr++;
                }
                break;

            case SYS_CHARSET_ISO_10646:

                while ( (!((pStr[0] == 0) && (pStr[1] == 0))) &&
                        (!((pStr[0] == 0) && (pStr[1] == STR_CHAR_LINEBREAK))) )
                {
                    pStr += 2;
                }
                break;

            case SYS_CHARSET_UTF8:
                while ( pStr[0] != 0 )
                {
                    if ( STR_UTF8_1BYTE_IS(pStr) )
                    {
                        if ( pStr[0] == STR_CHAR_LINEBREAK )
                        {
                            break;
                        }

                        pStr++; /* single-byte code */
                    }
                    else if ( STR_UTF8_2BYTE_IS(pStr) )
                    {
                        pStr += 2; /* two-byte code */
                    }
                    else if ( STR_UTF8_3BYTE_IS(pStr) )
                    {
                        pStr += 3; /* three-byte code */
                    }
                    else
                    {
                        FAPI_SYS_PRINT_DEBUG(4,"[SYS] UTF-8: invalid encoding!\n");
                        break;
                    }
                }
                break;
        }
    }

    return (pStr - string.chr);
}


/* 21b9ef90 - complete */
SYS_STRING_S STR_GetASCII (const char_t* str)
{
    SYS_STRING_S string;

//    memset(&string,0,sizeof(SYS_STRING_S));

    string.cs  = SYS_CHARSET_ASCII;
    string.chr = str;

    return string;
}


//* 21b9ef70 - complete */
void STR_Terminate(void* data, uint32_t size)
{
//   FAPI_SYS_PRINT_MSG("STR_Terminate\n");

   if ((data != NULL) && (size != 0))
   {
      ((uint8_t*)data)[0] = 0;

      if (size > 1)
      {
         ((uint8_t*)data)[1] = 0;
      }
   }
}


/* 21b9ef60 - complete */
void STR_Clear(struct Struct_21ba1a6c* a)
{
//   FAPI_SYS_PRINT_MSG("STR_Clear\n");

   a->string.cs = 0;
   a->string.chr = 0;
}


/* 21b9ef54 - complete */
SYS_STRING_S STR_Build (SYS_CHARSET set, const char_t* str)
{
    SYS_STRING_S string;

//    memset(&string,0,sizeof(SYS_STRING_S));

    string.cs  = set;
    string.chr = str;

    return string;
}


/* 21b9f7f4 - todo */
/*FSTATIC*/ uint32_t STR_CharGetTab0 (const char_t* pStr, SYS_CHAR* pChr)
{
    uint32_t                charBytes = 1;
    SYS_CHAR                currChar;
    STR_TAB0_MAP_S*         pTable;
    char_t                  nextByte;

    if( (*pStr) == 0 )
    {
        currChar  = STR_UD;
        charBytes = 0;
    }
    else if ( (uint8_t)(*pStr) < STR_8859_UPPERSTART )
    {
        /* low 7 bits + control codes are mapped directly. */
        currChar  = *pStr;
        charBytes = 1;
    }

    /* ----- two-byte characters + undefined chars 0xC9 and 0xCC ----------- */

    else if (( ((uint8_t)(*pStr) >= 0xC1) && ((uint8_t)(*pStr) <= 0xCF) ) )
    {
        pTable = table_tab0_twobyte[(uint8_t)(*pStr) - 0xC1];

        currChar  = STR_UD;
        charBytes = 1;

        if ( pTable != NULL )
        {
            nextByte = pStr[1];

            if ( nextByte == 0 )
            {
                /* NOTE: A lead byte at the end of the string is considered as
                         free-standing and thus treated as if being followed
                         by a blank character. */
                nextByte = 0x20;
            }

            while ( pTable->followByte != 0 )
            {
                if ( pTable->followByte == nextByte )
                {
                    currChar = pTable->unicodeChar;

                    if ( pStr[1] != 0 ) charBytes = 2;

                    break;
                }

                pTable++;
            }
        }
    }
    /* ----- mapping for single-byte characters ---------------------------- */
    else
    {
        switch ( (uint8_t)(*pStr) )
        {
            /* specially-mapped characters */
            case 0xA4:  currChar = 0x20AC; break;   // euro currency sign
            case 0xA8:  currChar = 0x00A4; break;   // gnr. currency sign
            case 0xA9:  currChar = 0x2018; break;
            case 0xAA:  currChar = 0x201C; break;
            case 0xAC:  currChar = 0x2190; break;   // leftwards arrow
            case 0xAD:  currChar = 0x2191; break;   // upwards arrow
            case 0xAE:  currChar = 0x2192; break;   // rightwards arrow
            case 0xAF:  currChar = 0x2193; break;   // downwards arrow
            case 0xB4:  currChar = 0x00D7; break;
            case 0xB8:  currChar = 0x00F7; break;
            case 0xB9:  currChar = 0x2019; break;
            case 0xBA:  currChar = 0x201D; break;
            case 0xD0:  currChar = 0x2014; break;
            case 0xD1:  currChar = 0x00B9; break;
            case 0xD2:  currChar = 0x00AE; break;   // registered sign
            case 0xD3:  currChar = 0x00A9; break;   // copyright sign
            case 0xD4:  currChar = 0x2122; break;
            case 0xD5:  currChar = 0x266A; break;
            case 0xD6:  currChar = 0x00AC; break;   // not-sign.
            case 0xD7:  currChar = 0x00A6; break;   // broken bar
            case 0xDC:  currChar = 0x215B; break;
            case 0xDD:  currChar = 0x215C; break;
            case 0xDE:  currChar = 0x215D; break;
            case 0xDF:  currChar = 0x215E; break;
            case 0xE0:  currChar = 0x2126/*0x03A9*/; break;    // OMEGA / Ohm
            case 0xE1:  currChar = 0x00C6; break;
            case 0xE2:  currChar = 0x0110; break;
            case 0xE3:  currChar = 0x00AA; break;
            case 0xE4:  currChar = 0x0126; break;
            case 0xE6:  currChar = 0x0132; break;
            case 0xE7:  currChar = 0x013F; break;
            case 0xE8:  currChar = 0x0141; break;
            case 0xE9:  currChar = 0x00D8; break;
            case 0xEA:  currChar = 0x0152; break;
            case 0xEB:  currChar = 0x00BA; break;
            case 0xEC:  currChar = 0x00DE; break;
            case 0xED:  currChar = 0x0166; break;
            case 0xEE:  currChar = 0x014A; break;
            case 0xEF:  currChar = 0x0149; break;
            case 0xF0:  currChar = 0x0138; break;
            case 0xF1:  currChar = 0x00E6; break;
            case 0xF2:  currChar = 0x0111; break;
            case 0xF3:  currChar = 0x00F0; break;
            case 0xF4:  currChar = 0x0127; break;
            case 0xF5:  currChar = 0x0131; break;
            case 0xF6:  currChar = 0x0133; break;
            case 0xF7:  currChar = 0x0140; break;
            case 0xF8:  currChar = 0x0142; break;
            case 0xF9:  currChar = 0x00F8; break;
            case 0xFA:  currChar = 0x0153; break;
            case 0xFB:  currChar = 0x00DF; break;
            case 0xFC:  currChar = 0x00FE; break;
            case 0xFD:  currChar = 0x0167; break;
            case 0xFE:  currChar = 0x014B; break;
            case 0xFF:  currChar = 0x00AD; break;   // soft hyphen

            /* undefined characters */
            case 0xA6:
            case 0xC0:
            case 0xD8:
            case 0xD9:
            case 0xDA:
            case 0xDB:
            case 0xE5:
                currChar = STR_UD;
                break;

            default:
                /* directly-mapped characters */
                currChar = *pStr;
                break;
        }

        charBytes = 1;
    }
    /* ----- three-byte characters do not exist in ISO table ----- */


    if ( pChr != NULL )
    {
        *pChr = currChar;
    }

    return charBytes;
}


/* 21ba1880 - complete */
uint32_t STR_Copy (SYS_STRING_S src, char_t* dstBuf, SYS_CHARSET* dstCs,
              SYS_CHARSET reqCs, uint32_t maxBytes)
{
    uint32_t retVal;

    if ( (maxBytes == 0)                        ||
         (src.chr  == NULL)                     ||
         (src.cs   == SYS_CHARSET_UNDEFINED)    ||
         (dstBuf   == NULL)                     ||
         (reqCs    == SYS_CHARSET_UNDEFINED) )
    {
        if ( dstCs != NULL ) *dstCs = SYS_CHARSET_UNDEFINED;

        STR_Terminate (dstBuf, maxBytes);

        retVal = 0;
    }
    else
    {
/*723*/ DBG_Assert(strDat->conv[src.cs][reqCs] != NULL);

        retVal = strDat->conv[src.cs][reqCs] (src.cs, src.chr,
                                               reqCs, dstBuf, maxBytes,
                                               0xFFFFFFFF);

        //FAPI_SYS_PRINT_DEBUG(4,"STR_COPY: set %i -> %i - '%s' ret %i addr 0x%08X\n",
        //           src.cs, reqCs, src.chr, retVal, dstBuf);

        if ( dstCs != NULL )
        {
            if ( retVal > 0 )
            {
                *dstCs = reqCs;
            }
            else
            {
                *dstCs = SYS_CHARSET_UNDEFINED;
            }
        }
    }

    return retVal;
}


/* 21ba1998 - complete */
uint32_t STR_BufAppend (SYS_STRBUF_S* pBuf, uint32_t bytePos, SYS_STRING_S string,
                   SYS_CHARSET reqCs)
{
    uint32_t retVal;

    if ( pBuf == NULL ) pBuf = &(strDat->lineBuf);

    if ( bytePos >= pBuf->bufSize )
    {
        retVal = 0;
    }
    else if ( (bytePos > 0) &&
              (pBuf->string.cs != reqCs) )
    {
        /* Buffer already contains string in different format */

        FAPI_SYS_PRINT_DEBUG(4,"[SYS] Character sets mixed in string buffer! \n");
        retVal = 0;
    }
    else
    {
        pBuf->string.chr = pBuf->buf;

        retVal = STR_Copy (string, pBuf->buf + bytePos, &(pBuf->string.cs),
                           reqCs, pBuf->bufSize - bytePos);
    }

    return retVal;
}


/* 21ba16d8 - complete */
uint32_t STR_NCopy (SYS_STRING_S src, char_t* dstBuf, SYS_CHARSET* dstCs,
               SYS_CHARSET reqCs, uint32_t maxBytes, uint32_t numBytes)
{
    uint32_t retVal;

    if ( (maxBytes == 0)                        ||
         (numBytes == 0)                        ||
         (src.chr  == NULL)                     ||
         (src.cs   == SYS_CHARSET_UNDEFINED)    ||
         (dstBuf   == NULL)                     ||
         (reqCs    == SYS_CHARSET_UNDEFINED) )
    {
        if ( dstCs != NULL ) *dstCs = SYS_CHARSET_UNDEFINED;

        /* terminate string */
        STR_Terminate (dstBuf, maxBytes);

        retVal = 0;
    }
    else
    {
/*773*/ DBG_Assert(strDat->conv[src.cs][reqCs] != NULL);

        retVal = strDat->conv[src.cs][reqCs] (src.cs, src.chr,
                                               reqCs, dstBuf, maxBytes,
                                               numBytes);

        if ( dstCs != NULL )
        {
            if ( retVal > 0 )
            {
                *dstCs = reqCs;
            }
            else
            {
                *dstCs = SYS_CHARSET_UNDEFINED;
            }
        }
    }

    return retVal;
}


/* 21ba17f8 - complete */
uint32_t STR_BufNAppend (SYS_STRBUF_S* pBuf, uint32_t bytePos, SYS_STRING_S string,
                    SYS_CHARSET reqCs, uint32_t numBytes)
{
    uint32_t retVal;

    if ( pBuf == NULL ) pBuf = &(strDat->lineBuf);

    if ( bytePos >= pBuf->bufSize )
    {
        retVal = 0;
    }
    else if ( (bytePos > 0) &&
              (pBuf->string.cs != reqCs) )
    {
        /* Buffer already contains string in different format */

        FAPI_SYS_PRINT_DEBUG(4,"[SYS] Character sets mixed in string buffer! \n");
        retVal = 0;
    }
    else
    {
        pBuf->string.chr = pBuf->buf;

        retVal = STR_NCopy (string, pBuf->buf + bytePos, &(pBuf->string.cs),
                            reqCs, pBuf->bufSize - bytePos, numBytes);
    }

    return retVal;
}


/* 21b9f7c0 - complete */
char_t* STR_IntASCIIBuf (void)
{
    return (char_t*)(strDat->asciiStr.chr);
}



