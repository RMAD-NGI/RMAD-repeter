
//#include "em_gpio.h"
#include "em_adc.h"
//#include "em_dac.h"
//#include "em_acmp.h"
#include "em_usart.h"
#include "em_cmu.h"
#include "em_rtc.h"
#include "em_rmu.h"
#include "em_emu.h"
#include "em_int.h"
#include "em_burtc.h"
#include "burtc_timer.h"

#include "aux_data.h"
#include "lcd.h"
#include "segmentlcd.h"

//#include "irqs.h"

// Adapted from file main_gg_stk.c etc in AN0041, and other files from Silicon Labs / Micro Energy.
// Initialization of BURTC that we use to make sure we won't stay forever in EM3.


volatile bool burtc_delay_complete;
volatile uint32_t burtc_counter;
//volatile uint32_t counter;
//volatile uint32_t burtc_wait_max_ms = 60000; //maksimum antall milliskunder i burtc, må være mindre enn wdog.
volatile uint32_t burtc_wait_max_ms = 1000; //maksimum antall milliskunder i burtc, må være mindre enn wdog.

void BURTC_IRQHandler(void)
{
    burtc_delay_complete = true;
    burtc_counter = BURTC_CounterGet();
    BURTC_IntClear(BURTC_IF_COMP0);
    BURTC_IntDisable(BURTC_IF_COMP0);
}

unsigned int wait_in_burtc(bool lcd_on)
{

	bool em = RTC->IEN > 0 || ADC0->IEN > 0 || UART0->IEN > 0 || lcd_on;

	burtc_delay_complete = false;

    BURTC_CounterReset(); // Might already have been done by BURTC_Enable(false) above
    BURTC_CompareSet(0,burtc_wait_max_ms);

	BURTC_IntClear(BURTC_IF_COMP0);
    BURTC_IntEnable(BURTC_IF_COMP0);

    BURTC_Enable(true);

    //if (RTC->IEN > 0 || ADC0->IEN > 0 || UART0->IEN > 0 || lcd_on){    //dette fikser slik at vi entrer igtig sleepmode, men skaper ett problem med dust notifications -ser ut til og entre en mode hvor kun button interups kan avslutte - evig løkke?
    if (em){
    	EMU_EnterEM1();
    } else {
    	EMU_EnterEM3(true);
    }

    // disconnect mote - strømforbruket ned  - reconnect mote  - alt tilbake til normal
    // reset mote (cli eller radio) - mote restarter med kobler seg ikke opp til nettverket


    BURTC_Enable(false);

	if (!burtc_delay_complete)
		BURTC_IRQHandler(); // Set burtc_counter and disable interrupt.

    return (unsigned int)((float) burtc_counter/1000);


}


