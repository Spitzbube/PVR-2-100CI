
#include "rtos_kernel.h"


extern void ARM1176_INTR_Initialise(void);


/* flasher: 21b02550 - complete */
void RTOS_InitServices(void)
{
    ARM1176_INTR_Initialise();
    RTOS_STUB_InitServices();
}

