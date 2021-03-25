#ifndef TIME_H_
#define TIME_H_



typedef enum
{
    TIMER_SINGLE = 0,
    TIMER_PERIODIC

} SYS_TIMER_TYPE_E;

typedef struct              /* Event: User timer expired */
{
    SYS_EVTHDR_S        hdr;        //!< Common event header.
    SYS_TIMER_TYPE_E    type;
    uint8_t             num;        //!< Index of expired timer.

} SYS_EVT_TIMER_S;


typedef struct
{
   uint8_t hour; //0
   uint8_t min; //1
   uint8_t sec; //2
   //3   
} Time;

typedef struct
{
   uint16_t year; //0
   uint8_t mon; //2
   uint8_t day; //3
   uint32_t weekday; //4
   //8
} Date;



extern int32_t TIME_Init(void);
extern int TIME_StartTimer(int a, unsigned short b);
extern int TIME_StopTimer(int a);
extern int32_t TIME_SingleTimerAbort(uint8_t timerNum);
extern int TIME_StartCyclicTimer(int a, int b);
extern int TIME_StopCyclicTimer(int a);
extern int func_36d088(int* a);
extern unsigned time_get_diff(unsigned a, unsigned b);
extern int func_370488(Time* a, Date* b, int* c);
extern int func_36d2dc(void);
extern void time_set(int a, int b);
extern int time_need_sync(void);
extern int func_36d458(void);
extern int func_36d480(void);
extern void func_36d844(Time* a, unsigned b);
extern int func_37106c(Time* a, Date* b);
extern void time_bcd_to_hms(unsigned a, Time* b);
extern void time_mjd_to_date(int mjd, Date* b);
extern int32_t time_get_current(Time* a, Date* b, uint32_t* c);
extern void time_change(Time* a, Date* b, int c);
extern void time_change_date(Date* a, int b);
extern int time_compare(Time* a, Date* b, Time* c, Date* d);
extern int time_get_seconds(Time* a);
extern void time_change_by_hours(Time* a, Date* b, int hours);
extern int func_36df14(Time* a, Time* b);
extern int func_36dff8(Date* a, Date* b);



#endif /*TIME_H_*/
