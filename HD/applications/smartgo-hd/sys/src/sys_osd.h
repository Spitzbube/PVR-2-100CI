#ifndef SYS_OSD_H_
#define SYS_OSD_H_


struct sys_osd_layer_params
{
   OSDHANDLER_StartParamsT params; //0
   int layer; //32
};

extern int SYS_GetOsdLayer(struct sys_osd_layer_params*, int (*reqCb)(char));
extern int SYS_GiveOsdLayer(int layer);


#endif /*SYS_OSD_H_*/
