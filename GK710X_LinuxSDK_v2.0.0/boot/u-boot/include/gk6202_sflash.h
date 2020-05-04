/* include\gk6202_sflash.h
*
* Copyright: 2012 - 2013 (C) GoKe Microelectronics LIMITED
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston,
* MA 02111-1307 USA
*/

/*----------------------------------------------------------------------------*/
/* registers                                                                  */
/*----------------------------------------------------------------------------*/

#define    REG_SFLASH_DATA                      	0xD8000000 	/* read/write */
#define    REG_SFLASH_COMMAND                   	0xD8000004 	/* read/write */
#define    REG_SFLASH_CE                        	0xD8000008 	/* read/write */
#define    REG_SFLASH_SPEED                     	0xD800000C 	/* read/write */
#define    REG_SFLASH_PARA_XIP                  	0xD8000010  	/* read/write */


/*-------------------------------------------------------------------------------*/

/*   sflash cmd attribute                                                                                                         	*/
/*   sflash cmd register bit definition																		*/
/*   bit 31    30    29    28    27    26    25    24    23    22    21         20        19           18    17    
        | rsrd    | hold time | transfer data bytes       |data cycle|adr and dummy cycle | cmd cycle |
                      00-100ns   11111 -- 4 bytes                                                           00 -x1
                      01-3us      other(e.g.,n) -- n bytes   0-3 cycle        0-3 cycle              01 -x2
                      10-100us                                                                                      10 -x4

    bit       16           15          14        13        12        11     10     9            8                      [7: 0]
        |         RWN            |  dummy cycle number   |  adr byte num    |                        |      cmd to DF                 |
          00 - rd data for SF     0 - 7 bytes cycle            0-7 bytes          1 - send cmd
          01 - wr data to SF                                                                0 - no send cmd        see specific flash cmd 
          11 - nothing to do																					*/
/*-------------------------------------------------------------------------------*/



/* send cmd or not [ 8]*/
#define SFLASH_SEND_CMD    0x00000100
#define SFLASH_NO_SEND_CMD 0x00000000

/* byte number of address to send [11:9]*/
#define SFLASH_SEND_ADDR_BYTE_NUM_0  0x00000000
#define SFLASH_SEND_ADDR_BYTE_NUM_1  0x00000200
#define SFLASH_SEND_ADDR_BYTE_NUM_2  0x00000400
#define SFLASH_SEND_ADDR_BYTE_NUM_3  0x00000600
#define SFLASH_SEND_ADDR_BYTE_NUM_4  0x00000800
#define SFLASH_SEND_ADDR_BYTE_NUM_5  0x00000a00
#define SFLASH_SEND_ADDR_BYTE_NUM_6  0x00000c00
#define SFLASH_SEND_ADDR_BYTE_NUM_7  0x00000e00

/*Byte number of dummy cycle to send [14:12]*/

#define SFLASH_SEND_DUMMY_BYTE_NUM_0  0x000000000
#define SFLASH_SEND_DUMMY_BYTE_NUM_1  0x000001000
#define SFLASH_SEND_DUMMY_BYTE_NUM_2  0x000002000
#define SFLASH_SEND_DUMMY_BYTE_NUM_3  0x000003000
#define SFLASH_SEND_DUMMY_BYTE_NUM_4  0x000004000
#define SFLASH_SEND_DUMMY_BYTE_NUM_5  0x000005000
#define SFLASH_SEND_DUMMY_BYTE_NUM_6  0x000006000
#define SFLASH_SEND_DUMMY_BYTE_NUM_7  0x000007000

/* Command operation[16:15]: 00 for read data from SF; 01 for write data to SF; 11 for nothing to do */

#define SFLASH_RWN_READ    0x00000000
#define SFLASH_RWN_WRITE   0x00008000
#define SFLASH_RWN_NOTHING 0x00018000

/*I/O mode of command cycle to SF[18:17]: 00 for x1; 01 for x2; 10 for x4*/
#define SFLASH_CMD_MODE_1X 0x00000000
#define SFLASH_CMD_MODE_2X 0x00020000
#define SFLASH_CMD_MODE_4X 0x00040000

/* I/O mode of address and dummy cycle to SF[20:19]*/
#define SFLASH_ADDR_DUMMY_CYCLE_NUM_0 0x00000000
#define SFLASH_ADDR_DUMMY_CYCLE_NUM_1 0x00080000
#define SFLASH_ADDR_DUMMY_CYCLE_NUM_2 0x00100000
#define SFLASH_ADDR_DUMMY_CYCLE_NUM_3 0x00180000

/*I/O mode of data cycle to or from SF [22:21] */

#define SFLASH_DATA_CYCLE_NUM_0    0x00000000
#define SFLASH_DATA_CYCLE_NUM_1    0x00200000
#define SFLASH_DATA_CYCLE_NUM_2    0x00400000
#define SFLASH_DATA_CYCLE_NUM_3    0x00600000

/*Transfer data byte number to or from SF[27:23]. For 11111 case, transfer 4bytes per request. For other case, transfer number bytes.*/

#define SFLASH_TRANSFER_BYTE_NUM_4 0x0f800000
#define SFLASH_TRANSFER_BYTE_LOC   23

#define SFLASH_HOLD_TIME_100ns 0x00000000
#define SFLASH_HOLD_TIME_3us   0x10000000 
#define SFLASH_HOLD_TIME_100us 0x20000000



/*----------------------------------------------------------------------------*/
/* bit group structures                                                       */
/*----------------------------------------------------------------------------*/
typedef union { /* SFLASH_Command */
    u32 all;
    struct {
        u32 code                        	: 8;
        u32 send_cmd                     	: 1;
        u32 adr_num                      	: 3;
        u32 dummy_num                   	: 3;
        u32 rwn                         	: 2;
        u32 cmd_mode                    	: 2;
        u32 adr_mode                     	: 2;
        u32 data_mode                    	: 2;
        u32 data_num                     	: 5;
        u32 hold_time                    	: 2;
        u32                             	: 2;
    } bitc;
} goke_sflash_command_s;

typedef union { /* SFLASH_CE */
    u32 all;
    struct {
        u32 ce                          	: 1;
        u32 wp                          	: 1;
        u32 hold                        	: 1;
        u32 ce_mode                      	: 1;
        u32 wp_mode                      	: 1;
        u32 hold_mode                    	: 1;
        u32 ch_select                    	: 1;
        u32                             	: 25;
    } bitc;
} goke_sflash_ce_s;

typedef union { /* SFLASH_Speed */
    u32 all;
    struct {
        u32 sf_sclk_sel                 	: 3;
        u32                             	: 29;
    } bitc;
} goke_sflash_speed_s;

typedef union { /* SFLASH_PARA_XIP */
    u32 all;
    struct {
        u32 sflash_command              	: 8;
        u32                             	: 1;
        u32 adr_num                     	: 3;
        u32 dummy_num                   	: 3;
        u32                             	: 2;
        u32 cmd_mod                     	: 2;
        u32 adr_mod                     	: 2;
        u32 data_mod                    	: 2;
        u32                             	: 1;
        u32 dumy_data                   	: 8;
    } bitc;
} goke_sflash_para_xip_s;

/*-------------------------------------------------------------------------------*/
/* \brief Flash channel number.																			*/
/*-------------------------------------------------------------------------------*/

typedef enum
{
   GOKE_SFLASH_CHANNEL_0 = 0,
   GOKE_SFLASH_CHANNEL_1,
   GOKE_SFLASH_CHANNEL_NUM
}goke_sflash_channel_e;

/*-------------------------------------------------------------------------------*/
/* \brief Flash I/O feature.																				*/
/*-------------------------------------------------------------------------------*/

typedef enum
{
   GOKE_SFLASH_FEATURE_IO1 = 0,
   GOKE_SFLASH_FEATURE_IO2,
   GOKE_SFLASH_FEATURE_IO4
}goke_sflash_feature_e;

/*-------------------------------------------------------------------------------*/
/* \brief Flash feature type.																				*/
/*-------------------------------------------------------------------------------*/

typedef enum
{
   GOKE_SFLASH_TYPE_READ = 0,
   GOKE_SFLASH_TYPE_WRITE
}goke_sflash_type_e;

/*-------------------------------------------------------------------------------*/
/* serial flash specific commands and statis register bit definitions										*/
/*-------------------------------------------------------------------------------*/

typedef struct
{
    u8  read_ID;        			/*!< command to read the chip identification*/
    u8  write_enable;   			/*!< command to enable a write/erase sequence*/
    u8  write_disable;  			/*!< command to disable a write/erase sequence*/
    u8  read_status;    			/*!< command to read from status register*/
    u8  write_status;   			/*!< command to write to status register*/
    u8  read_data;      			/*!< command to read data*/
    u8  read_data_fast;  		/*!< command to read data in fast mode*/
    u8  erase_sector;   			/*!< command to erase a single sector*/
    u8  erase_chip;     			/*!< command to erase the entire chip*/
    u8  program_page;   			/*!< command to program a sector page*/
    u32 status_mask_wip; 		/*!< status register mask for bit write-in-progress*/
    u32 status_mask_wel; 		/*!< status register mask for bit write-enable-latch*/
    u8  read_io2;       			/*!< command to read data by IO2*/
    u8  read_io4;       			/*!< command to read data by IO4*/
    u8  program_page2;  			/*!< command to program a sector page by IO2*/
    u8  program_page4;  			/*!< command to program a sector page by IO4*/
}goke_sflash_cmd_s;

/*-------------------------------------------------------------------------------*/
/* serial flash specific geometry and information data structure										*/
/*-------------------------------------------------------------------------------*/

typedef struct
{
    u8               manufacture_ID;   			/*!< Manufacture identification*/
    u16              device_ID;        			/*!< Device identification (memory type/capacity)*/
    char*            manufacture_name; 			/*!< Pointer to manufacture name*/
    char*            device_name;      			/*!< Pointer to device name*/
    u32              device_bytes;     			/*!< Size of flash device in bytes*/
    u32              sector_count;     			/*!< Number of sectors*/
    u32              sector_bytes;     			/*!< Size of a single flash sector in bytes*/
    u32              sector_pages;     			/*!< Number of pages per sector*/
    u32              page_bytes;       			/*!< Size of a programmable page in bytes*/
    const goke_sflash_cmd_s* commands;        		/*!< Device specific access commands*/
    u32              feature;         			/*!<bit0(IO1 read)  bit1(IO2 read)  bit2(IO4 read)*/
                                      				/*!<bit3(IO1 write) bit4(IO2 write) bit5(IO4 write)*/
    goke_sflash_channel_e     channel;
}goke_sflash_dev_s;

/*-------------------------------------------------------------------------------*/
/* \brief Flash driver error codes.																		*/
/*-------------------------------------------------------------------------------*/

enum
{
    GOKE_ERR_SFLASH_TYPE_NOT_SUPPORTED = 0,				    	/*!< Device not supported.*/
    GOKE_ERR_SFLASH_IN_USE,                                  	/*!< Read error.*/
    GOKE_ERR_SFLASH_READ,                                    	/*!< Read error.*/
    GOKE_ERR_SFLASH_WRITE,                                   	/*!< Write error.*/
    GOKE_ERR_SFLASH_ERASE,
    GOKE_ERR_UNLOCK_FAIL
};


typedef enum
{
   GOKE_SFLASH_FREQ_81M = 0,
   GOKE_SFLASH_FREQ_40M,
   GOKE_SFLASH_FREQ_27M,
   GOKE_SFLASH_FREQ_20M,
   GOKE_SFLASH_FREQ_16M
}goke_sflash_speed_mode;

struct goke_spi_flash_t
{
	struct spi_flash flash;
	const goke_sflash_dev_s* device;
};

const goke_sflash_dev_s* goke_sflash_init( void);

int spi_flash_read_common(struct spi_flash *flash, u32 offset, 
	const void *buf, size_t data_len);

int spi_flash_write_common(struct spi_flash *flash, u32 offset,
	const void *buf, size_t data_len);


