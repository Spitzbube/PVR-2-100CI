#ifndef REG_BM_H_
#define REG_BM_H_


extern void FREG_BM_Init(void);
extern int freg_bm1_get_write_pointer(int);
extern int freg_bm2_get_write_pointer(int);
extern int freg_bm3_get_write_pointer(int);
extern int freg_bm4_get_write_pointer(int);
extern void func_21c6e444(int, int);
extern void func_21c6e838(int, int);
extern void func_21c6e884(int, int);
extern void func_21c6e490(int, int);
extern int freg_bm1_get_read_pointer(int);
extern int freg_bm2_get_read_pointer(int);
extern int freg_bm3_get_read_pointer(int);
extern int freg_bm4_get_read_pointer(int);
extern int func_21c6e3bc(void);
extern int func_21c6e7b0(void);
extern void func_21c6e380(int);
extern void func_21c6e774(int);
extern int func_21c6eab8(void);
extern int func_21c6e628(int);
extern int func_21c6ea1c(int);
extern int func_21c6e4d0(int);
extern int func_21c6e4bc(unsigned);
extern int func_21c6e8b0(unsigned);
extern int func_21c6e46c(unsigned);
extern int func_21c6e860(unsigned);
extern int freg_bm1_get_buffer_size(int);
extern int freg_bm2_get_buffer_size(int);
extern int freg_bm3_get_buffer_size(int);
extern int freg_bm4_get_buffer_size(int);
extern int freg_bm1_get_buffer_address(int);
extern int freg_bm2_get_buffer_address(int);
extern int freg_bm3_get_buffer_address(int);
extern int freg_bm4_get_buffer_address(int);
extern int func_21c6e4ac(int);
extern int func_21c6e8a0(int);



static inline void func_21c6e428_1(unsigned a, unsigned b, int c)
{
   if ((a == 0) || (a == 1))
   {
      FREG_BM01_SetBufLowLev(b, c);
   }
   else
   {
      FREG_BM23_SetBufLowLev(b, c);
   }
}


static inline void func_21c6e444_1(unsigned a, unsigned b, int c)
{
   if ((a == 0) || (a == 1))
   {
      func_21c6e444(b, c);
   }
   else
   {
      func_21c6e838(b, c);
   }
}


static inline void func_21c6e480_1(unsigned a, unsigned b, int c)
{
   if ((a == 0) || (a == 1))
   {
      FREG_BM01_SetBufHighLev(b, c);
   }
   else 
   {
      FREG_BM23_SetBufHighLev(b, c);
   }
}


static inline void func_21c6e490_1(unsigned a, unsigned b, int c)
{
   if ((a == 0) || (a == 1))
   {
      func_21c6e490(b, c);
   }
   else
   {
      func_21c6e884(b, c);
   }
}


static inline int func_21c6e3bc_1(unsigned a)
{
   int r0;
   
   if ((a == 0) || (a == 1))
   {
      r0 = func_21c6e3bc();
   }
   else
   {
      r0 = func_21c6e7b0();
   }
   
   return r0;
}


static inline void func_21c6e380_1(unsigned a, int b)
{
   if ((a == 0) || (a == 1))
   {
      func_21c6e380(b);
   }
   else
   {
      func_21c6e774(b);
   }
}


static inline int func_21c6e628_1(unsigned a, unsigned b)
{
   int r0;
   
   if ((a == 0) || (a == 1))
   {
      r0 = func_21c6e628(b);
   }
   else
   {
      r0 = func_21c6ea1c(b);
   }
   
   return r0;
}


static inline int func_21c6e4bc_1(unsigned a, unsigned b)
{
   int r0;
   
   if ((a == 0) || (a == 1))
   {
      r0 = func_21c6e4bc(b);
   }
   else
   {
      r0 = func_21c6e8b0(b);
   }

   return r0;
}


static inline int func_21c6e46c_1(unsigned a, unsigned b)
{
   int r0;
   
   if ((a == 0) || (a == 1))
   {
      r0 = func_21c6e46c(b);
   }
   else
   {
      r0 = func_21c6e860(b);
   }

   return r0;
}


#endif /*REG_BM_H_*/
