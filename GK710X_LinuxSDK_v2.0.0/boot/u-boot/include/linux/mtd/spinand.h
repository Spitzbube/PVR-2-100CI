/*
 linux/mtd/spinand.h

 Copyright (c) 2013 Gofortune Semiconductor Corporation.
  Kewell Liu  <liujingke@gofortune-semi.com>

 This software is licensed under the terms of the GNU General Public
 License version 2, as published by the Free Software Foundation, and
 may be copied, distributed, and modified under those terms.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 based on nand.h
*/
#ifndef _LINUX_MTD_SPINAND_H_
#define _LINUX_MTD_SPINAND_H_

#include <linux/mtd/nand.h>
#include <nand.h>

#define SPINAND_OOBSIZE    128
#define SPINAND_PAGESIZE   2048
#define SPINAND_PAGENUMB   2048
#define SPINAND_BLOCKNUM   2048

#define WR_ENABLE           1
#define WR_DISABLE          0

/* i/o mode */
#define SPINAND_1X_READ         0x01
#define SPINAND_2X_READ         0x02
#define SPINAND_4X_READ         0x04
#define SPINAND_1X_WRITE        0x10
#define SPINAND_2X_WRITE        0x20
#define SPINAND_4X_WRITE        0x40


/* The max num of chip select current support */
#define NUM_CHIP_SELECT     (2)

/* cmd */
#define CMD_READ                0x13
#define CMD_READ_RDM            0x03
#define CMD_PROG_PAGE_CLRCACHE  0x02
#define CMD_PROG_PAGE           0x84
#define CMD_PROG_PAGE_EXC       0x10
#define CMD_ERASE_BLK           0xd8
#define CMD_WR_ENABLE           0x06
#define CMD_WR_DISABLE          0x04
#define CMD_READ_ID             0x9f
#define CMD_RESET               0xff
#define CMD_READ_REG            0x0f
#define CMD_WRITE_REG           0x1f

/* feature/ status reg */
#define REG_PROTECTION          0xa0
#define REG_FEATURE             0xb0
#define REG_STATUS              0xc0    /* timing */
#define REG_OUTPUT_DRIVER       0xd0

/* status */
#define STATUS_OIP_MASK     0x01
#define STATUS_READY        0 << 0
#define STATUS_BUSY         1 << 0

#define STATUS_E_FAIL_MASK  0x04
#define STATUS_E_FAIL       1 << 2

#define STATUS_P_FAIL_MASK  0x08
#define STATUS_P_FAIL       1 << 3

#define STATUS_ECC_MASK     0x30
#define STATUS_ECC_1BIT_CORRECTED   1 << 4
#define STATUS_ECC_ERROR            2 << 4
#define STATUS_ECC_RESERVED         3 << 4

/* Output Driver */
#define OPD_DRV_MASK        0x60
#define OPD_DRV_S1_MASK     0x40
#define OPD_DRV_S0_MASK     0x20

/* ECC enable defines */
#define OTP_ECC_MASK        0x10
//#define OTP_ECC_OFF         0
//#define OTP_ECC_ON          1

//#define ECC_DISABLED
//#define ECC_IN_NAND
//#define ECC_SOFT

/* block lock */
#define BL_ALL_LOCKED      0x38
#define BL_1_2_LOCKED      0x30
#define BL_1_4_LOCKED      0x28
#define BL_1_8_LOCKED      0x20
#define BL_1_16_LOCKED     0x18
#define BL_1_32_LOCKED     0x10
#define BL_1_64_LOCKED     0x08
#define BL_ALL_UNLOCKED    0

/****************************************************************************/

/* send cmd or not [ 8]*/
#define FLASH_SEND_CMD    0x00000100
#define FLASH_NO_SEND_CMD 0x00000000

 /* byte number of address to send [11:9]*/
#define FLASH_SEND_ADDR_BYTE_NUM_0  0x00000000
#define FLASH_SEND_ADDR_BYTE_NUM_1  0x00000200
#define FLASH_SEND_ADDR_BYTE_NUM_2  0x00000400
#define FLASH_SEND_ADDR_BYTE_NUM_3  0x00000600
#define FLASH_SEND_ADDR_BYTE_NUM_4  0x00000800
#define FLASH_SEND_ADDR_BYTE_NUM_5  0x00000a00
#define FLASH_SEND_ADDR_BYTE_NUM_6  0x00000c00
#define FLASH_SEND_ADDR_BYTE_NUM_7  0x00000e00

 /*Byte number of dummy cycle to send [14:12]*/

#define FLASH_SEND_DUMMY_BYTE_NUM_0  0x000000000
#define FLASH_SEND_DUMMY_BYTE_NUM_1  0x000001000
#define FLASH_SEND_DUMMY_BYTE_NUM_2  0x000002000
#define FLASH_SEND_DUMMY_BYTE_NUM_3  0x000003000
#define FLASH_SEND_DUMMY_BYTE_NUM_4  0x000004000
#define FLASH_SEND_DUMMY_BYTE_NUM_5  0x000005000
#define FLASH_SEND_DUMMY_BYTE_NUM_6  0x000006000
#define FLASH_SEND_DUMMY_BYTE_NUM_7  0x000007000

 /* Command operation[16:15]: 00 for read data from SF; 01 for write data to SF; 11 for nothing to do */

#define FLASH_RWN_READ    0x00000000
#define FLASH_RWN_WRITE   0x00008000
#define FLASH_RWN_NOTHING 0x00018000

 /*I/O mode of command cycle to SF[18:17]: 00 for x1; 01 for x2; 10 for x4*/
#define FLASH_CMD_MODE_1X 0x00000000
#define FLASH_CMD_MODE_2X 0x00020000
#define FLASH_CMD_MODE_4X 0x00040000

 /* I/O mode of address and dummy cycle to SF[20:19]*/
#define FLASH_ADDR_DUMMY_CYCLE_NUM_0 0x00000000
#define FLASH_ADDR_DUMMY_CYCLE_NUM_1 0x00080000
#define FLASH_ADDR_DUMMY_CYCLE_NUM_2 0x00100000
#define FLASH_ADDR_DUMMY_CYCLE_NUM_3 0x00180000

 /*I/O mode of data cycle to or from SF [22:21] */

#define FLASH_DATA_CYCLE_NUM_0    0x00000000
#define FLASH_DATA_CYCLE_NUM_1    0x00200000
#define FLASH_DATA_CYCLE_NUM_2    0x00400000
#define FLASH_DATA_CYCLE_NUM_3    0x00600000

 /*Transfer data byte number to or from SF[27:23]. For 11111 case, transfer 4bytes per request. For other case, transfer number bytes.*/

#define FLASH_TRANSFER_BYTE_NUM_4 0x0f800000
#define FLASH_TRANSFER_BYTE_LOC   23

#define FLASH_HOLD_TIME_100ns 0x00000000
#define FLASH_HOLD_TIME_3us   0x10000000
#define FLASH_HOLD_TIME_100us 0x20000000

 /*!
 *******************************************************************************
 **
 ** \brief Flash channel number.
 **
 *******************************************************************************
 */
 typedef enum
 {
    FLASH_CHANNEL_0 = 0,
    FLASH_CHANNEL_1,
    FLASH_CHANNEL_NUM
 }flash_channel_e;

 /*!
 *******************************************************************************
 **
 ** \brief Flash I/O feature.
 **
 *******************************************************************************
 */
 typedef enum
 {
    FLASH_FEATURE_IO1 = 0,
    FLASH_FEATURE_IO2,
    FLASH_FEATURE_IO4
 }flash_feature_e;



/*----------------------------------------------------------------------------*/
/* bit group structures                                                       */
/*----------------------------------------------------------------------------*/
typedef union { /* SFLASH_Command */
    uint32_t all;
    struct {
        uint32_t code                        : 8;
        uint32_t sendcmd                     : 1;
        uint32_t adrnum                      : 3;
        uint32_t dummynum                    : 3;
        uint32_t rwn                         : 2;
        uint32_t cmdmode                     : 2;
        uint32_t adrmode                     : 2;
        uint32_t datamode                    : 2;
        uint32_t datanum                     : 5;
        uint32_t holdtime                    : 2;
        uint32_t                             : 2;
    } bitc;
}flash_command_s;

 typedef union { /* SFLASH_CE */
    uint32_t all;
    struct {
        uint32_t ce                          : 1;
        uint32_t wp                          : 1;
        uint32_t hold                        : 1;
        uint32_t cemode                      : 1;
        uint32_t wpmode                      : 1;
        uint32_t holdmode                    : 1;
        uint32_t chselect                    : 1;
        uint32_t                             : 25;
    } bitc;
}flash_ce_s;


/******************************************************************************
**
** serial flash specific commands and statis register bit definitions
**
*******************************************************************************
*/
typedef struct
{
    uint32_t  writeEnable;   // command to enable a write/erase sequence
    uint32_t  writeDisable;  // command to disable a write/erase sequence
    uint32_t  getFeatures;   // command to read from status register
    uint32_t  setFeatures;   // command to write to status register
    uint32_t  pageRead;      // command to read data to cache
    uint32_t  readCache;     // command to read data from cache
    uint32_t  readCacheX2;   // command to read data from cache X 2
    uint32_t  readCacheX4;   // command to read data from cache X 4
    uint32_t  readCacheIO2;  // command to read data from cache by IO2
    uint32_t  readCacheIO4;  // command to read data from cache by IO4
    uint32_t  readID;        // command to read the chip identification
    uint32_t  programLoad;   // command to program a page
    uint32_t  programLoadX4; // command to program a page X 4
    uint32_t  progExecute;   // command to program execute
    uint32_t  progLoadRand;  // command to program a page
    uint32_t  progLoadRandX4;    // command to program a page X 4
    uint32_t  progLoadRandIO2;   // command to program a page by IO2
    uint32_t  blockErase;    // command to erase a block
    uint32_t  reset;         // status register mask for bit write-in-progress

}spinand_cmd_t;

/*
*******************************************************************************
**
** serial flash specific geometry and information data structure
**
*******************************************************************************
*/
struct spinand_info {
    uint8_t         mid;
    uint16_t        did;
    char*           manuname;
    char*           deviceName;     // Pointer to device name
    uint32_t        nand_size;
    uint32_t        usable_size;

    uint32_t        block_size;
    uint32_t        block_main_size;
    uint32_t        block_per_chip;

    uint32_t        page_size;
    uint32_t        page_main_size;
    uint32_t        page_spare_size;
    uint32_t        page_per_block;

    uint32_t        block_shift;
    uint32_t        block_mask;

    uint32_t        page_shift;
    uint32_t        page_mask;      /* use to calc the offset address of byte in page */

    spinand_cmd_t*  commands;       /* Device specific access commands */
    uint32_t        feature;        /* bit0(IO1 read)  bit1(IO2 read)  bit2(IO4 read)
                                                             bit4(IO1 write) bit5(IO2 write) bit6(IO4 write) */
    uint32_t        channel;

    struct nand_ecclayout *ecclayout;

    int badblockbits;
    struct nand_bbt_descr *badblock_pattern;

};

struct spinand_chip { /* used for multi chip */

    struct spinand_info *info;
    struct mtd_info   *mtd;

    int (*reset) (struct spinand_chip *chip);
    int (*read_id) (struct spinand_chip *chip, uint32_t* id);
    int (*read_page) (struct spinand_chip *chip, uint32_t page_id,
                        uint32_t offset, uint32_t len, uint8_t* rbuf);
    int (*read_page_raw) (struct spinand_chip *chip, uint32_t page_id,
                        uint32_t offset, uint32_t len, uint8_t* rbuf);
    int (*program_page) (struct spinand_chip *chip, uint32_t page_id,
                        uint32_t offset, uint32_t len, uint8_t* wbuf);
    int (*program_page_raw) (struct spinand_chip *chip, uint32_t page_id,
                        uint32_t offset, uint32_t len, uint8_t* wbuf);
    int (*erase_block) (struct spinand_chip *chip, uint32_t block_id);
    int (*scan_bbt)(struct mtd_info *mtd);
    int (*block_markbad)(struct mtd_info *mtd, loff_t ofs);
    int (*block_bad)(struct mtd_info *mtd, loff_t ofs);

    u8 *pagebuf;
    u8 *oobbuf; /* temp buffer */

    unsigned int *tmpbuf; /* temp buffer */

    int page_id;
    int phys_erase_shift;
    int bbt_erase_shift;
    int page_shift;
    int pagemask;
    int chip_id;
    uint64_t chipsize;
    int badblockpos;
    int badblockbits;

    int chip_delay;
    unsigned int options;
    unsigned int bbt_options;

    uint8_t *oob_poi;
    struct nand_ecclayout *ecclayout;
    struct nand_buffers *buffers;

    uint8_t *bbt;
    struct nand_bbt_descr *bbt_td;
    struct nand_bbt_descr *bbt_md;

    struct nand_bbt_descr *badblock_pattern;

    void *priv;

};


extern struct mtd_info snand_mtd;

/* Functions */
extern int spinand_erase_opts(struct mtd_info *mtd,
                            const struct nand_erase_options *opts);
extern int spinand_read_skip_bad(struct mtd_info *mtd, loff_t offset,
                            size_t *length, u_char *buffer);
extern int spinand_write_skip_bad(struct mtd_info *mtd, loff_t offset,
                            size_t *length, u_char *buffer, int flags);

extern int spinand_scan(struct mtd_info * mtd);
extern int spinand_update_bbt(struct mtd_info *mtd, loff_t offs);
extern int spinand_default_bbt(struct mtd_info *mtd);
extern int spinand_isbad_bbt(struct mtd_info *mtd, loff_t offs, int allowbbt);
extern int spinand_erase_nand(struct mtd_info *mtd, struct erase_info *instr, int allowbbt);

/* board */
extern int spinand_board_init(struct mtd_info *mtd);

__attribute__((noreturn)) void nand_boot(void);

#endif

#ifdef CONFIG_ENV_OFFSET_OOB
#define ENV_OOB_MARKER      0x30425645 /*"EVB0" in little-endian -- offset is stored as block number*/
#define ENV_OOB_MARKER_OLD  0x30564e45 /*"ENV0" in little-endian -- offset is stored as byte number */
#define ENV_OFFSET_SIZE     8
extern int get_spinand_env_oob(struct mtd_info *mtd, unsigned long *result);
#endif

