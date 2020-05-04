#include "gtypes.h"
//#include <string.h>
#include "gd_int.h"
#include "gd_timer.h"
#include "gh_sdio.h"
#include "gd_sdio.h"
#include "gd_gpio.h"
#include <config.h>
#include <common.h>
#include <mmc.h>

//#define DEBUG_PRINT


extern struct gksd_host gk_host;

#define SDIO_INT_STATUS_EN  (1 | 1<<1 | 1<<3 | 1<<4 |1<<5 | 1<<6 | 1<<7)
#define SDIO_INT_SIG_EN     (1 | 1<<1 | 1<<3 | 1<<4 |1<<5 | 1<<6 | 1<<7)

#define SDIO_IRQ_CMD_COMPLETE        0x0001
#define SDIO_IRQ_TRANSFER_COMPLETE   0x0008
#define SDIO_IRQ_BLOCK_GAP_EVENT     0x0002
#define SDIO_IRQ_DMA                 0x0004
#define SDIO_IRQ_WRITE_READY         0x0010
#define SDIO_IRQ_READ_READY          0x0040
#define SDIO_IRQ_CARD_INSERTED       0x0020
#define SDIO_IRQ_CARD_REMOVED        0x0080

#define SDIO_IRQ_NO_CARD             0x0100
#define SDIO_ERROR_IRQ               0x8000

unsigned int gcmd = 0;

static void sdioSoftReset(void)
{
	int channel = 0;
    GH_SDIO_set_SF_RST_CTRL_SoftwareResetAll(channel,1);
    GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine(channel,1);
    GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine(channel,1);
}

static void sdioClockOnOff(U32 on)
{
    int channel = 0;
    if (on == 0)
    {
        GH_SDIO_set_CLK_CTRL_SdClkEn(channel,0);
    }
    else
    {
        GH_SDIO_set_CLK_CTRL_SdClkEn(channel,1);
    }
}

void sdioSetClockDiv( U8 div)
{
   int channel = 0;
   GH_SDIO_set_CLK_CTRL_SdclkFreSelect(channel,div);
   GH_SDIO_set_CLK_CTRL_InternalClkEn(channel,1);
   while(!GH_SDIO_get_CLK_CTRL_InternalClkStable(channel));
   sdioClockOnOff(1);
}

static void sdioSelectVoltage(void)
{
    U32 caps;
	int channel = 0;
    caps=GH_SDIO_get_CapReg(channel);
    
    if(caps & 0x1<<24)
    {
        GH_SDIO_set_Control00Reg_DriveCcsd(channel,0x7);
        GH_SDIO_set_Control00Reg_SdBusPower(channel,0x1);
#ifdef DEBUG_PRINT
        printf("sdio 3.3v\n");
#endif
    }
    else if(caps & 0x1<<25)
    {
        GH_SDIO_set_Control00Reg_DriveCcsd(channel,0x6);
        GH_SDIO_set_Control00Reg_SdBusPower(channel,0x1);
    }
    else if(caps & 0x1<<26)
    {
        GH_SDIO_set_Control00Reg_DriveCcsd(channel,0x5);
        GH_SDIO_set_Control00Reg_SdBusPower(channel,0x1);
    }
}

static void sdioSetTimeoutControl(U8 timeout)
{
    GH_SDIO_set_SF_RST_CTRL_DataTimeoutCounterValue(0,timeout);
}

void sdioSetHostctlSpeed(U8 mode)
{
    GH_SDIO_set_Control00Reg_HostSpeedEn(0,mode);
}

void sdioSetHostctlWidth(U8 mode)
{
    GH_SDIO_set_Control00Reg_DataTraWidth(0,mode);
}

void sdioSetHostctl8BitMode(U8 channel,U8 mode)
{
    GH_SDIO_set_Control00Reg_Sd8BitMode(channel,mode);
}

static void sdioEnableIntStatus(void)
{
    /*clear int*/
	int channel = 0;
    if(GH_SDIO_get_NOR_INT_STA_ErrInt(channel))
    {
        GH_SDIO_set_NOR_INT_STA(channel,GH_SDIO_get_NOR_INT_STA(channel));
    }
    GH_SDIO_set_NOR_INT_STA_EN(channel,0x0);
    GH_SDIO_set_NOR_INT_STA_EN(channel,SDIO_INT_STATUS_EN);
    GH_SDIO_set_ERR_INT_STA_EN(channel,0x0);
    GH_SDIO_set_ERR_INT_STA_EN(channel,0xFFFF);
}

static void sdioEnableIntSig(void)
{
	int channel = 0;
    GH_SDIO_set_NOR_INT_SIG_EN(channel,0);
    GH_SDIO_set_NOR_INT_SIG_EN(channel,SDIO_INT_SIG_EN);
    GH_SDIO_set_ERR_INT_SIG_EN(channel,0);
    GH_SDIO_set_ERR_INT_SIG_EN(channel,0xFFFF);
}


void sdioSetBlkSizeRegister(U8 boundary, unsigned short blksize)
{
	int channel = 0;

    GH_SDIO_set_BLK_SIZ_HostSdmaBufSize(channel,boundary);
    GH_SDIO_set_BLK_SIZ_TraBlkSize(channel,blksize);
}

void sdioSetBlkCntRegister(unsigned  short  blkcnt)
{
    GH_SDIO_set_BLK_COU(0,blkcnt);
}

void sdioSetArgRegister (U32 arg)
{
    int channel = 0;
    GH_SDIO_set_ArgReg(channel,arg);
}

U32 sdioSetTraModeRegister (U32  multblk, U32 direction, U32  autocmd12en,
    U32  blkcnten, U32  dmaen)
{
	int channel = 0;
    U32 modereg=GH_SDIO_get_MOD(channel);
#if defined(CONFIG_CPU_GK710X)
	modereg=(modereg & ~0xffff) | (multblk << 5) | (direction << 4) | (autocmd12en << 1) | (blkcnten) | (dmaen << 2);
#elif defined(CONFIG_CPU_GK710XS)
	modereg=(modereg & ~0xffff) | (multblk << 4) | (direction << 5) | (autocmd12en << 1) | (blkcnten) | (dmaen << 2);
#endif
    return modereg<<16;
}

void sdioSetSystemAddressReg(U32 addr)
{
	int channnel = 0;
    GH_SDIO_set_SysAddrReg(channnel,addr);
}


void GD_SDIO_Rest(void)
{
	int channel = 0;
    sdioSoftReset();
    sdioClockOnOff(0);
    sdioSetClockDiv(0x1);//24M
    sdioSelectVoltage();
    sdioSetTimeoutControl(0xe);
    sdioSetHostctlSpeed(0);
    sdioSetHostctlWidth(0);
    /*clear interrupt status*/

    GH_SDIO_set_NOR_INT_STA(channel,GH_SDIO_get_NOR_INT_STA(channel));
    GH_SDIO_set_ERR_INT_STA(channel,GH_SDIO_get_ERR_INT_STA(channel));

    sdioEnableIntStatus();
    sdioEnableIntSig();
}

/*!
********************************************************************************
**sdio set cmd reg
**
********************************************************************************
*/

void sdioSetCmdReg(U32 cmdarg,U32 data,U32 flags)
{
    U8 cmd=cmdarg & 0x3f;
    unsigned short cmdval=(cmd<<8);
    U32 channel = 0;
	gcmd = cmd;

    if(cmd==12)
    {
        /*abort cmd*/
        cmdval |=(3<<6);
    }
    else
    {
        /*suspend/resume cmd(sdio)*/
    }

    if (flags & MMC_RSP_136)                /* Long REP */
    {
        cmdval |= 0x01;
    }
    else if (flags & MMC_RSP_BUSY)        /* R1B */
    {
        cmdval |= 0x03;
    }
    else if (flags & MMC_RSP_PRESENT)            /* Normal REP */
    {
        cmdval |= 0x02;
    }

    if (flags & MMC_RSP_OPCODE)
    {
        cmdval |= (1<<5);
    }

    if (flags & MMC_RSP_CRC)
    {
        cmdval |= (1<<3);
    }

    if (data)
    {
        cmdval |= (1<<4);
    }
    GH_SDIO_set_MOD(channel,cmdarg>>16);
    GH_SDIO_set_COMM(channel,cmdval);
}

/*!
********************************************************************************
**
** \brief send command
** This function set and  send command.
**
** \param cmd     cmd mode
** \param arg      command argument
** \param data    data==1:data present:no data present
** \param flags    response mode
**
** \return
** - GD_OK  if no error
** - -1  if error
********************************************************************************
*/


int  sdioIssueCmd(U32 cmd, U32 arg, U32 data, U32 flags)
{
    int i;
#ifdef DEBUG_PRINT   
	printf("sdioIssueCmd cmd = %d arg %x flags %x data %d \n",cmd&0x3f,arg,flags,data);
#endif
    /*wait for cmd line free */
    for(i=0;i<0x1500;i++)
    {
        if(!(GH_SDIO_get_PresentStateReg(0) & 0x1))
            break;
        mdelay(10);
    }

    /*wait for data line free */
    if(flags & MMC_RSP_BUSY)
    {
         if(cmd==12)
         {
         }
         else
         {
             for(i=0;i<0x1500;i++)
             {
                 if(!(GH_SDIO_get_PresentStateReg(0)& (0x1<<1)))
                     break;
                 mdelay(10);
             }
         }
    }

    GH_SDIO_set_ArgReg(0,arg);
    sdioSetCmdReg(cmd,data,flags);
    return GD_OK;
}

/*!
********************************************************************************
**
** \brief SDIO interrupt handle
**
**
********************************************************************************
*/


GISR1 GD_SDIO_ISR(void)
{
	U32 channelIndex = 0;
    U32  data= 0,i=0;
    U32  bufferpos= 0;
#ifdef DEBUG_PRINT
    static int ts = 0;
#endif
    void *pdata;
    U32  irq_status_reg = GH_SDIO_get_NOR_INT_STA(channelIndex);
    gk_host.g_sdioError = 0;

    for(i=0;i<4;i++)
    {
        gk_host.resp[i]=0;
    }
        
#ifdef DEBUG_PRINT
   	printf(" irq_status_reg:%x cmd = %d error %x \n",irq_status_reg,gcmd,GH_SDIO_get_ERR_INT_STA(channelIndex));
#endif

    if( irq_status_reg & SDIO_ERROR_IRQ )
    {
#ifdef DEBUG_PRINT
        printf("error irq_status_reg:%x\n",irq_status_reg);
#endif

        if(irq_status_reg & 0x1)
        {
#ifdef DEBUG_PRINT
            printf("cmd complete\n");
#endif
        }
        else if(irq_status_reg & 0x2)
        {
#ifdef DEBUG_PRINT
            printf("transfer complete\n");
#endif
        }

        GH_SDIO_set_NOR_INT_STA(channelIndex,GH_SDIO_get_NOR_INT_STA(channelIndex));
        GH_SDIO_set_ERR_INT_STA(channelIndex,GH_SDIO_get_ERR_INT_STA(channelIndex));
        GH_SDIO_set_SF_RST_CTRL_SoftwareResetDatLine(channelIndex,1);
        GH_SDIO_set_SF_RST_CTRL_SoftwareResetCmdLine(channelIndex,1);
        gk_host.g_cmdStatus    = SDIO_ERR_CMD;
        gk_host.g_transferStatus = SDIO_ERR_CMD;
        gk_host.g_sdioError    = GH_SDIO_get_ERR_INT_STA(channelIndex);
#ifdef DEBUG_PRINT
        GM_Printf(" - Error IRQ %x\n", gk_host.g_sdioError);
#endif
   
    }
    else if( irq_status_reg & SDIO_IRQ_CMD_COMPLETE )
    {
        if(GH_SDIO_get_COMM_RepTypeSelect(channelIndex)==1)
        {
            gk_host.resp[0]=GH_SDIO_get_Resp3Reg(channelIndex)<<8 | (GH_SDIO_get_Resp2Reg(channelIndex) & 0xff000000)>>24;
            gk_host.resp[1]=GH_SDIO_get_Resp2Reg(channelIndex)<<8 | (GH_SDIO_get_Resp1Reg(channelIndex) & 0xff000000)>>24;
            gk_host.resp[2]=GH_SDIO_get_Resp1Reg(channelIndex)<<8 | (GH_SDIO_get_Resp0Reg(channelIndex) & 0xff000000)>>24;
            gk_host.resp[3]=GH_SDIO_get_Resp0Reg(channelIndex)<<8;
        }
        else
        {
            gk_host.resp[0]=GH_SDIO_get_Resp0Reg(channelIndex);
        }
        gk_host.g_sdioError     = 0;
        gk_host.g_cmdStatus    = SDIO_CMD_COMPLETE;
        gk_host.g_transferStatus=SDIO_WAIT;
        GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_CMD_COMPLETE);
    }
    else if( irq_status_reg & SDIO_IRQ_CARD_REMOVED )
    {
#ifdef DEBUG_PRINT
        printf(" - Card removed IRQ\n");
#endif
        GD_SDIO_Rest();
        GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_CARD_REMOVED);
    }
    else if( irq_status_reg & SDIO_IRQ_CARD_INSERTED )
    {
#ifdef DEBUG_PRINT
        printf(" - Card inserted IRQ\n");
#endif
        GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_CARD_INSERTED);
    }
    else if( irq_status_reg & SDIO_IRQ_READ_READY )
    {

        if (!(GH_SDIO_get_PresentStateReg(channelIndex) & 0x1<<11))
        {
            return;
        }
        else
        {
            GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_READ_READY);
            while( bufferpos < gk_host.bsize)
            {
                data = GH_SDIO_get_BufferDataPortReg(channelIndex);

                if( gk_host.start_addr)
                {
                    pdata=(void *)gk_host.start_addr;
                    *(U32 *)pdata = data;
                    gk_host.start_addr += 4;
                    bufferpos+=4;
                }
            }
#ifdef DEBUG_PRINT
            printf("read %d \n",ts++);
#endif
        }

    }
    else if( irq_status_reg & SDIO_IRQ_WRITE_READY )
    {
        if (!(GH_SDIO_get_PresentStateReg(channelIndex) & 0x1<<10))
        {
            return;
        }
        else
        {
            GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_WRITE_READY);
            while( bufferpos < gk_host.bsize )
            {
                if( gk_host.start_addr )
                {
                    pdata=(void *)gk_host.start_addr;
                    GH_SDIO_set_BufferDataPortReg(channelIndex,*((U32 *)pdata));
                    gk_host.start_addr +=4;
                    bufferpos+=4;
                }
            }
#ifdef DEBUG_PRINT
            printf("write %d \n",ts++);
#endif
        }
    }
    else if(irq_status_reg & SDIO_IRQ_DMA)
    {
        GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_DMA);
        gk_host.start_addr = (U32)gk_host.start_addr & (0xFFFFFFFF*512*1024);
        gk_host.start_addr += 0xFFFFFFFF*512*1024;
        sdioSetSystemAddressReg((U32)gk_host.start_addr);
#ifdef DEBUG_PRINT
        printf("dma int %d \n",ts++);
#endif
    }
    else if( irq_status_reg & SDIO_IRQ_TRANSFER_COMPLETE )
    {
        gk_host.g_sdioError        = 0;
        gk_host.g_transferStatus    = SDIO_TRANSFER_COMPLETE;

        GH_SDIO_set_NOR_INT_STA(channelIndex,SDIO_IRQ_TRANSFER_COMPLETE);
#ifdef DEBUG_PRINT
        ts = 0;
#endif
    }
//    printf("interrupt over\n");
}

/*!
********************************************************************************
**
** \brief Initialize the SDIO driver
**
** Initializes the SDIO interrupt and  Reset SDIO card.
**
** \return
** - GD_OK if successfull
** -else GD_INT_Open failed
**
********************************************************************************
*/
GERR GD_SDIO_Init()
{

    static int init = 0;
    GERR                     ret;
    GD_HANDLE                sdioHandle0;
    GD_HANDLE                sdioHandle1;
    GD_INT_OPEN_PARAMS_S     intParams0;
    GD_INT_OPEN_PARAMS_S     intParams1;
    if(init == 0)
    {
        GD_INT_Init(NULL);
        /*open the sdio control interrupt*/
        intParams0.type           = (S8)GD_INT_SD_CONTROLLER_IRQ;
        intParams0.sensitivity    = GD_INT_LEVEL_HIGH;
        intParams0.active         = GD_INT_INVERT_IRQ;
        intParams0.priority       = GD_INT_MID_PRIORITY;
        intParams0.isrFct.lowPrio = GD_SDIO_ISR;
        
        ret = GD_INT_Open(&intParams0, &sdioHandle0);
        if(ret != GD_OK)
        {
            return GD_ERR_SDIO_INT_ERR;
        }
     
        GD_INT_Enable(&sdioHandle0,GD_INT_ENABLED);
        /*open the sdio detec interrupt*/
        intParams1.type           = (S8)GD_INT_SD_CARD_DETECT_IRQ;
        intParams1.sensitivity    = GD_INT_BOTH_EDGES;
        intParams1.active         = GD_INT_INVERT_IRQ;
        intParams1.priority       = GD_INT_MID_PRIORITY;
        intParams1.isrFct.lowPrio = GD_SDIO_ISR;
        ret = GD_INT_Open(&intParams1, &sdioHandle1);
        if(ret != GD_OK)
        {
            return GD_ERR_SDIO_INT_ERR;
        }
        GD_INT_Enable(&sdioHandle1,GD_INT_ENABLED);
        GD_INT_EnableAllInterrupts();
    }
    
    init=1;
    GD_SDIO_Rest();
    return GD_OK;
}

