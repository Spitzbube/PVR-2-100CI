#ifndef AV_API_H_
#define AV_API_H_


typedef struct
{
  int a; 
  int b;
  int Data_8; //8
  
} Struct_349d90;


#if 0
extern void func_348830(int a);
extern int av_api_tune_next_service(void);
extern int av_api_tune_previous_service(void);
extern int func_34c2a8(int a);
extern int av_api_set_ac3_stream(int a, signed char b);
extern int av_api_set_audio_stream(signed char a);
extern int func_34c514(int* a, signed char* b);
extern int func_349710(void);
extern int func_34cb34(void);
extern int func_349a98(void);
extern int av_api_get_tv_system(int* a);
extern int av_api_set_lnb_power(int a, int b);
extern int av_api_get_service_list_index(struct slist_index* a);
#endif
extern int func_21b7c6c8(signed char a, Struct_349d90* b);

#endif /*AV_API_H_*/
