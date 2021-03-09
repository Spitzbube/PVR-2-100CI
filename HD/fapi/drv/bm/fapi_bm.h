#ifndef FAPI_BM_H_
#define FAPI_BM_H_


extern struct fapi_driver fapi_bm_driver0; //21efa524 
extern struct fapi_driver fapi_bm_driver1; //21efa548
extern struct fapi_driver fapi_bm_driver2; //21efa56c
extern struct fapi_driver fapi_bm_driver3; //21efa590


struct fapi_bm_params
{
   unsigned Data_0; //0
   unsigned Data_4; //4
   int Data_8; //8
   int address; //12
   unsigned size; //16
   int Data_20; //20
   int Data_24; //24
   int Data_28; //28
   //32
};


struct Struct_21c128e8
{
   unsigned Data_0; //0
   unsigned Data_4; //4
   int Data_8; //8
   int address; //12
   unsigned size; //16
   int Data_20; //20
   int Data_24; //24
   int Data_28; //28
   void* Data_32; //32
};


extern void fapi_bm_set_buffer_base_address(unsigned, int);
extern int func_21c126a0(unsigned, int, int, int);
extern void* fapi_bm_open(struct fapi_bm_params* a, int*);
extern int fapi_bm_close(void*);
extern int func_21c14e60(void*, void (*)(int,int,void*), void*, int);
extern int func_21c12ae4(void*, void (*)(unsigned,unsigned,int), int, unsigned, int);
extern int func_21c12d18(void*, void (*)(unsigned,unsigned,int), int, unsigned, int);
extern int func_21c12760(unsigned);
extern int func_21c127c4(unsigned);
extern int func_21c12828(unsigned);
extern int func_21c128e8(void* h, struct Struct_21c128e8*);
extern unsigned func_21c12628(void);
extern int fapi_bm_set_read_pointer(void*, unsigned, int);
extern int fapi_bm_read(void*, void*, unsigned, unsigned);
extern int fapi_bm_write(void*, void*, unsigned, unsigned);
extern int fapi_bm_get_buffer_level(void*);
extern int fapi_bm_get_write_pointer(void*);
extern void* fapi_bm_get_virtual_write_pointer(void*);
extern void* fapi_bm_get_virtual_read_pointer(void*);
extern int fapi_bm_get_read_pointer(void*);
extern int func_21c13b9c(void*);
extern int func_21c13a84(void*, unsigned);


#endif /*FAPI_BM_H_*/
