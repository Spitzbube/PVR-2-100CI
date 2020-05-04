#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include "adi_types.h"
#include "adi_sys.h"
#include "mksensor.h"

GADI_VI_SensorDetectInfoT   sensor_detect;

extern GADI_ERR gadi_priv_driver_get_fd(GADI_S32* driverFd);
#define GK_MEDIA_IOC_VI_SRC_SENSOR_DETECT   _IOW('s', 0x18, GADI_VI_SensorDetectInfoT*)
int main(int argc, char* argv[])
{
    char cmd[1000];
    GADI_U32 retVal;
    GADI_S32 fdmedia;
    FILE *fp;

    retVal = gadi_sys_init();
    if(retVal != GADI_OK)
    {
        printf("gadi_sys_init() failed!\n");
        return 0;
    }
    retVal = gadi_priv_driver_get_fd(&fdmedia);
    if(retVal != GADI_OK)
    {
        printf("gadi_priv_driver_get_fd() failed!\n");
        gadi_sys_exit();
        return 0;
    }

    sprintf(cmd, "/etc/sensors/sensor_detect.bin");

    if ((fp = fopen(cmd, "rb")) != NULL)
    {
        if (fread(&sensor_detect, 1, sizeof(GADI_VI_SensorDetectInfoT), fp) !=
            sizeof(GADI_VI_SensorDetectInfoT))
        {
            GADI_ERROR("fread %s failed\n", cmd);
            fclose(fp);
            gadi_sys_exit();
            return 0;
        }
        fclose(fp);
    }
    else
    {
        gadi_sys_exit();
        return 0;
    }

    retVal = ioctl(fdmedia, GK_MEDIA_IOC_VI_SRC_SENSOR_DETECT, &sensor_detect);
    if((retVal >= 0) && (retVal < sensor_detect.num))
    {
        printf("find:%s at 0x%0x\n", sensor_detect.HwInfo[retVal].name, sensor_detect.HwInfo[retVal].hw_addr << 1);
        system("rm /tmp/sensor_hw.bin");
        sprintf(cmd, "rm /tmp/sensor_ex.ko");
        system(cmd);
        sprintf(cmd, "ln -s /etc/sensors/%s_hw.bin /tmp/sensor_hw.bin", sensor_detect.HwInfo[retVal].name);
        system(cmd);
        sprintf(cmd, "ln -s /lib/modules/$(uname -r)/extra/%s_ex.ko /tmp/sensor_ex.ko", sensor_detect.HwInfo[retVal].name);
        system(cmd);
        retVal = 1;
    }
    else
    {
        retVal = 0;
    }
    gadi_sys_exit();
    return retVal;
}

