#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <signal.h> // Get sig_atomic_t

#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_wdog.h"
#include "em_device.h"
#include "em_gpio.h"

#include "dn_ipmt.h"
#include "dn_hdlc.h"

#include "config_efm32.h"
#include "burtc_timer.h"
#include "dn_fsm.h"
#include "aux_data.h"
#include "repeter.h"
#include "lcd.h"

#define MIN(x0, x1) ((x0) < (x1) ? (x0) : (x1))

volatile uint16_t aux_min_interval = 15;
volatile unsigned int secs_since_mote_check = 0; // set to high value in order to force measurments on boot

volatile sig_atomic_t gl_sleep_mode_recording = 3;
volatile sig_atomic_t gl_sleep_mode_uart_rx = 3;
volatile sig_atomic_t gl_sleep_mode_uart_tx = 3;

volatile sig_atomic_t sleep_mode_uart = 3;
volatile sig_atomic_t sleep_mode = 3;
volatile sig_atomic_t sleep_mode_temp = 3;


    /**************************************************************************//**
     * @brief  Main function
     *****************************************************************************/

    int main(void) {

        efm32_config();

        gpio_config();

        uart0_config();
        //uart1_config();

        button_config();

        rtc_dn_fsm_config();

        burtc_config();
        wdog_config(); // May depend on setup of clocks done in burtc_config() (not tested).

        //lcd_init(secs_since_mote_check);

        dn_fsm_start();


        unsigned int iter = 0;

        while (true) {

        	if (secs_since_mote_check >= 60*aux_min_interval){

        	     aux_data_start();
        	     secs_since_mote_check = 0;

        	}

        	if (gl_get_aux_data == true){

        		aux_data_aquire_and_send();

        	}

        	sleep_mode_uart = MIN(gl_sleep_mode_uart_rx,gl_sleep_mode_uart_tx);
        	sleep_mode = MIN(gl_sleep_mode_recording,sleep_mode_uart);


        	bool lcd_on = lcd_update(secs_since_mote_check, aux_min_interval, iter, sleep_mode, dn_up, dn_mode, battery_level);

        	//if(lcd_on){
        	//	sleep_mode = 1;
        	//}

            secs_since_mote_check += wait_in_burtc(lcd_on);

            WDOG_Feed();

            if(iter > 9999){
            	iter = 0;
            }else{
            	iter++;
            }


        }

}
