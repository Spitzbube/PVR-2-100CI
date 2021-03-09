

#include <fapi/sys_services.h>
#include <fapi/drv_flash.h>
#include <fapi/drv_flash_priv.h>



flashDescriptorT fapiSFlashDescriptorArray[] = //21efa9bc
{
      {
            "S25FL004A",
            1,
            {
                  {8, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_SPANSION,
            0x212,
            0, 0, 0
      },
      {
            "S25FL008A",
            1,
            {
                  {16, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_SPANSION,
            0x213,
            0, 0, 0
      },
      {
            "S25FL064A",
            1,
            {
                  {128, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_SPANSION,
            0x216,
            0, 0, 0
      },
      {
            "S25FL032A",
            1,
            {
                  {64, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_SPANSION,
            0x215,
            0, 0, 0
      },
      {
            "S25FL128A",
            1,
            {
                  {256, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_SPANSION,
            0x218,
            0, 0, 0
      },
      {
            "M25P80",
            1,
            {
                  {16, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x2014,
            0, 0, 0
      },
      {
            "M25P40",
            1,
            {
                  {8, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x2013,
            0, 0, 0
      },
      {
            "M25P32",
            1,
            {
                  {64, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x2016,
            0, 0, 0
      },
      {
            "M25P3205D",
            1,
            {
                  {64, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_MACRONIX,
            0x2016,
            0, 0, 0
      },
      {
            "M25P64",
            1,
            {
                  {128, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x2017,
            0, 0, 0
      },
      {
            "M25P128",
            1,
            {
                  {64, 0x40000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x2018,
            0, 0, 0
      },
      {
            "M25P32-7116",
            1,
            {
                  {64, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_STMICRO,
            0x7116,
            0, 0, 0
      },
      {
            "AT25FS040",
            1,
            {
                  {8, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_ATMEL,
            0x6604,
            0, 0, 0
      },
      {
            "Unknow",
            1,
            {
                  {64, 0x10000},
                  {0, 0},
                  {0, 0},
                  {0, 0},
            },
            4, 4,
            FAPI_FLASH_MANUFACTURER_UNDEFINED,
            0,
            0, 0, 0
      },
      {
            0,
      },
};


