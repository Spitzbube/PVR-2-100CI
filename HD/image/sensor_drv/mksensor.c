#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include "adi_types.h"
#include "adi_sys.h"
#include "adi_isp.h"
#include "mksensor.h"

#include "drv/imx122_reg_tbl.c"
#include "drv/imx291_reg_tbl.c"
#include "drv/jxh42_reg_tbl.c"
#include "drv/jxh61_reg_tbl.c"
#include "drv/jxh62_reg_tbl.c"
#include "drv/jxf22_reg_tbl.c"
#include "drv/ar0130_reg_tbl.c"
#include "drv/ar0230_reg_tbl.c"
#include "drv/ar0237_reg_tbl.c"
#include "drv/ar0330_reg_tbl.c"
#include "drv/ar0331_reg_tbl.c"
#include "drv/bg0701_reg_tbl.c"
#include "drv/gc1024_reg_tbl.c"
#include "drv/ov2710_reg_tbl.c"
#include "drv/ov9710_reg_tbl.c"
#include "drv/ov9750_reg_tbl.c"
#include "drv/ov9732_reg_tbl.c"
#include "drv/sc1035_reg_tbl.c"
#include "drv/sc1045_reg_tbl.c"
#include "drv/sc1135_reg_tbl.c"
#include "drv/sc1145_reg_tbl.c"
#include "drv/sc2035_reg_tbl.c"
#include "drv/sc2045_reg_tbl.c"
#include "drv/sc2135_reg_tbl.c"
#include "drv/tw9912_reg_tbl.c"
#include "drv/pv6418_reg_tbl.c"

GADI_VI_SensorDrvInfoT* sensor[] =
{
    &imx122_sensor,
    &imx291_sensor,
    &jxh42_sensor,
    &jxh61_sensor,
    &jxh62_sensor,
    &jxf22_sensor,
    &sc1035_sensor,
    &sc1135_sensor,
    &sc2035_sensor,
    &sc2135_sensor,
    &sc1045_sensor,
    &sc1145_sensor,
    &sc2045_sensor,
    &ov2710_sensor,
    &ov9710_sensor,
    &ov9750_sensor,
    &ov9732_sensor,
    &bg0701_sensor,
    &gc1024_sensor,
    &ar0130_sensor,
    &ar0230_sensor,
    &ar0237_sensor,
    &ar0330_sensor,
    &ar0331_sensor,
    &tw9912_sensor,
    &pv6418_mach,
};

GADI_VI_SensorDetectInfoT   sensor_detect =
{
    .magic_start        = GADI_SENSOR_DETECT_MAGIC_START,
    .version            = GADI_SENSOR_DETECT_VERSION,
    .length             = sizeof(GADI_VI_SensorDetectInfoT),
    .num                = 0,
    .debug_print        = 1,
    .magic_end          = GADI_SENSOR_DETECT_MAGIC_END,
};

int main(int argc, char* argv[])
{
    FILE *fp = NULL;;
    int i;
    int size;
    int count;
    char name[64];
    size    = sizeof(GADI_VI_SensorDrvInfoT);
    count   = sizeof(sensor)/sizeof(sensor[0]);
    for(i=0;i<count;i++)
    {
        sprintf(name, "./bin/%s_hw.bin", sensor[i]->HwInfo.name);
        fp = fopen(name, "wb");
        if(!fp)
        {
            printf("create %s error\n", name);
            return -1;
        }
        fwrite(sensor[i], 1, size, fp);
        fclose(fp);
        printf("create %s success\n", name);
    }

    sensor_detect.num = 0;
    for(i=0;i<count;i++)
    {
        if(sensor[i]->HwInfo.id_reg[0].reg != GADI_VI_SENSOR_TABLE_FLAG_END)
        {
            memcpy(&sensor_detect.HwInfo[sensor_detect.num], &sensor[i]->HwInfo, sizeof(sensor_detect.HwInfo[sensor_detect.num]));
            sensor_detect.num ++;
        }
    }
    sprintf(name, "./bin/sensor_detect.bin");
    fp = fopen(name, "wb");
    if(!fp)
    {
        printf("create %s error\n", name);
        return -1;
    }
    size = sizeof(sensor_detect);
    fwrite(&sensor_detect, 1, size, fp);
    fclose(fp);
    printf("create %s success\n", name);

    return 0;
}

