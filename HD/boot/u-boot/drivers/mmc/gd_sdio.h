#ifndef _GD_SDIO_H_
#define _GD_SDIO_H_
 
#include "gtypes.h"
#include "gmodids.h"


/*!
*******************************************************************************
**
** SDIO OPEN  parameter.
**
******************************************************************************/
typedef struct
{
    /*!
    Flag to request DMA for read/write transfer operation.
    */

   U32       isUseDmaWay;

} GD_SDIO_OPEN_PARAMS_S;


typedef struct
{
    U32    isConnected;   
    U32    sectorSize;
    U32    sectorCount;
    U32    mediaType;
    U32    manufacturerID;
    U32    applicationID;
    U32    productRevision;
    U32    serialNumber;
    U32    dataIoNumber;
    U8     productName[5];
}GD_SDIO_VolumeInfoT;



enum card_type 
{
    CARDTYPE_NONE = 0,
    CARDTYPE_MMC,
    CARDTYPE_SD10,
    CARDTYPE_SD20,
    CARDTYPE_SDHC
};


#define    GD_SDIO_ERR_BASE    (GD_SDIO_MODULE_ID<<16)
//#define    SDIO_INT_MODE
enum
{
    GD_ERR_SDIO_CARD_INIT_FAILED = GD_SDIO_ERR_BASE,
    GD_ERR_SDIO_INT_ERR,
    GD_ERR_SDIO_NO_CARD,
    GD_ERR_SDIO_CARD_BUSY,
    GD_ERR_SDIO_READ_FAILED,
    GD_ERR_SDIO_WRITE_FAILED,
    GD_ERR_SDIO_ERASE_FAILED,
    GD_ERR_SDIO_CMD_NO_SUPPORTED,
    GD_ERR_SDIO_SET_BLOCK_SIZE,
    GD_ERR_SDIO_CMD_FAILED,
    GD_ERR_SDIO_CARD_LOCKED
};


struct gksd_host {
	char name[100];
    U32  *resp;
	void *ioaddr;
	unsigned int quirks;
	unsigned int host_caps;
	unsigned int version;
	unsigned int clock;
    unsigned int bsize;
    unsigned int bcount;
	struct mmc *mmc;
	int index;
    int g_sdioError;
    int g_cmdStatus;
    int g_transferStatus;
    unsigned int start_addr;
    void *aligned_buffer;

	void (*set_control_reg)(struct gksd_host *host);
	void (*set_clock)(int dev_index, unsigned int div);
	U32	voltages;
};

/*!
*******************************************************************************
**
** SDIO API functions.
**
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

GERR GD_SDIO_Init(void);
GERR GD_SDIO_Exit(void);
void GD_SDIO_Rest(void);
void sdioSetBlkSizeRegister(U8 boundary, unsigned short blksize);
void sdioSetBlkCntRegister(unsigned  short  blkcnt);
void sdioSetArgRegister (U32 arg);
void sdioSetHostctlSpeed(U8 mode);
void sdioSetHostctlWidth(U8 mode);
void sdioSetHostctl8BitMode(U8 channel,U8 mode);
U32 sdioSetTraModeRegister (U32  multblk, U32 direction, U32  autocmd12en,U32  blkcnten, U32  dmaen);
void sdioSetSystemAddressReg(U32 addr);
int  sdioIssueCmd(U32 cmd, U32 arg, U32 data, U32 flags);
void sdioSetClockDiv( U8 div);

/*SDIO  STATUS*/
#define SDIO_ERR_CMD              -1
#define SDIO_WAIT                 0x00
#define SDIO_CMD_COMPLETE         0x01
#define SDIO_TRANSFER_COMPLETE    0x02

/*SDIO ERROR*/
#define SDIO_OK        0

#ifdef __cplusplus
}
#endif

#endif
