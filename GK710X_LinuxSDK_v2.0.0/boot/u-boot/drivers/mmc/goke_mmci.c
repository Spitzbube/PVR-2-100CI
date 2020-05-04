#include <common.h>
#include"gtypes.h"
#include"gd_sdio.h"
#include"gh_sdio.h"
#include <asm/io.h>
#include <asm/gpio.h>
#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <part.h>

struct gksd_host gk_host;
void *aligned_buffer;

int gksd_send_command(struct mmc *mmc, struct mmc_cmd *cmd,
               struct mmc_data *data)
{
    struct gksd_host *host = (struct gksd_host *)mmc->priv;
    unsigned int wdog = 1000;
    int trans_bytes = 0, is_aligned = 1;
    unsigned int start_addr = 0;
    u32 dmaen = 1,multblk  =0;
    u32 tmp_cmd = 0;

    if(cmd->cmdidx == 12)
        return 0;
    
    if (data != NULL) 
    {   
        if (data->blocks > 1)
            multblk=1;
        else   
            multblk=0;
        host->bsize = data->blocksize;
        host->bcount = data->blocks;
        sdioSetBlkSizeRegister(7,data->blocksize);
        sdioSetBlkCntRegister(data->blocks);
        tmp_cmd = sdioSetTraModeRegister(multblk,(data->flags == MMC_DATA_READ),multblk,multblk,dmaen);
        if (data->flags == MMC_DATA_READ)
            start_addr = (unsigned int)data->dest;
        else
            start_addr = (unsigned int)data->src;
        if ((start_addr & 0x7) != 0x0)
        {
            is_aligned = 0;
            start_addr = (unsigned int)host->aligned_buffer;
            if (data->flags != MMC_DATA_READ)
                memcpy(host->aligned_buffer, data->src, trans_bytes);
        }
        sdioSetSystemAddressReg((U32)start_addr);
        host->start_addr = start_addr;
    }
    
    host->g_sdioError      = SDIO_OK;
    host->g_cmdStatus      = SDIO_WAIT;
    host->g_transferStatus = SDIO_WAIT;
    host->resp = (unsigned int*)cmd->response;
    tmp_cmd |=cmd->cmdidx;
    if(sdioIssueCmd(tmp_cmd,cmd->cmdarg,(data != NULL),cmd->resp_type) == GD_OK)
    {
        while(--wdog && host->g_cmdStatus !=SDIO_ERR_CMD && host->g_cmdStatus != SDIO_CMD_COMPLETE)
        {
            mdelay(1);
        }
        host->g_cmdStatus = SDIO_WAIT;
        if(host->g_sdioError != GD_OK || wdog == 0)
        {
            host->g_sdioError = GD_OK;
            return GD_ERR_SDIO_CMD_FAILED;
        }
        
        if(data != NULL)
        {   
            wdog = 1000;
            while(--wdog && host->g_transferStatus != SDIO_ERR_CMD && host->g_transferStatus != SDIO_TRANSFER_COMPLETE)
            {
                mdelay(1);
            }           
            host->g_transferStatus=SDIO_WAIT;
            
            if(host->g_sdioError != GD_OK || wdog == 0)
            {
                host->g_sdioError = GD_OK;         
                return (data->flags == MMC_DATA_READ)?GD_ERR_SDIO_READ_FAILED:GD_ERR_SDIO_WRITE_FAILED;
            }
        }
    }
    else
    {
        return GD_ERR_SDIO_CMD_FAILED;
    }
 
    if (!is_aligned && (data->flags == MMC_DATA_READ))
        memcpy(data->dest, host->aligned_buffer, trans_bytes);
    return 0;
}

static int gksd_set_clock(struct mmc *mmc, unsigned int clock)
{
    return 0;
}



int gksd_get_cd(struct mmc *mmc)
{
    int cd_level = 0;
    gk7101_gpio_config((u32)SYSTEM_GPIO_SD_DETECT, (u32)GPIO_TYPE_INPUT_1);
    cd_level = 0x1 & gk7101_gpio_get(SYSTEM_GPIO_SD_DETECT);
    gk7101_gpio_config((u32)SYSTEM_GPIO_SD_DETECT, (u32)GPIO_TYPE_INPUT_SD_CD_N);
    return !cd_level;
}

void gksd_set_ios(struct mmc *mmc)
{
    gksd_set_clock(mmc, mmc->clock);
    //Set bus width 
    if (mmc->bus_width == 8)
    {
        sdioSetHostctlWidth(0);
        sdioSetHostctl8BitMode(0,1);
    } 
    else if (mmc->bus_width == 4)
        sdioSetHostctlWidth(1);
    else if (mmc->bus_width == 0)
        sdioSetHostctlWidth(0);
    
    if (mmc->clock > 26000000)
        sdioSetHostctlSpeed(1);
    else
        sdioSetHostctlSpeed(0);
}

int gksd_init(struct mmc *mmc)
{
    GD_SDIO_Init();
    return 0;
}

int goke_mmc_init(int channel)
{
    struct mmc *mmc;
    static struct gksd_host *host = &gk_host;
    
    mmc = malloc(sizeof(struct mmc));
    if (!mmc) {
        printf("mmc malloc fail!\n");
        return -1;
    }
    host->aligned_buffer = memalign(32, 512*1024);
    host->clock = 0;
    mmc->priv = host;
    host->mmc = mmc;
    strcpy(host->name,"SD/MMC");
    sprintf(mmc->name, "%s", host->name);
    mmc->send_cmd = gksd_send_command;
    mmc->set_ios = gksd_set_ios;
    mmc->init = gksd_init;
    mmc->getcd = gksd_get_cd;
    mmc->voltages = MMC_VDD_32_33 | MMC_VDD_33_34 | MMC_VDD_165_195;
    mmc->host_caps = MMC_MODE_4BIT;
    mmc->host_caps |= MMC_MODE_HS | MMC_MODE_HC; 
    mmc->f_min = 400000;
    mmc->f_max = 46000000;
    mmc->b_max = 1024;
    mmc_register(mmc);
    
    return 0;
}


