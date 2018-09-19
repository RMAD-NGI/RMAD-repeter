#include "segmentlcd.h"
#include "repeter.h"
#include "lcd.h"
#include <signal.h>


volatile bool display_on = false;
volatile int lcd_time_on = 120; // in seconds

volatile unsigned int total_secs_since_mote_check;
volatile unsigned int last_secs_since_mote_check;


void lcd_init(unsigned int temp_secs_since_mote_check){

		last_secs_since_mote_check = temp_secs_since_mote_check;
		total_secs_since_mote_check = 0;

	    lcd_config();
	    display_on = true;

}

bool lcd_update(unsigned int temp_secs_since_mote_check, unsigned int temp_aux_min_interval, int efm32_itteration, sig_atomic_t efm32_sleepmode, bool dn_up, int dn_mode, int battery_level){


	if (display_on){

		if (temp_secs_since_mote_check > last_secs_since_mote_check){

			total_secs_since_mote_check = total_secs_since_mote_check + temp_secs_since_mote_check - last_secs_since_mote_check;

		}else if (temp_secs_since_mote_check < last_secs_since_mote_check){

			total_secs_since_mote_check = total_secs_since_mote_check + temp_secs_since_mote_check + 60*temp_aux_min_interval - last_secs_since_mote_check;

		}

		last_secs_since_mote_check = temp_secs_since_mote_check;

		if (total_secs_since_mote_check < lcd_time_on){

		       lcd_write(efm32_itteration,efm32_sleepmode,dn_up,dn_mode,battery_level);

		}else{

		      lcd_close();
		      display_on = false;
		}

	}


	return display_on;
}

void lcd_config(void){

	 SegmentLCD_Init(false);
	 SegmentLCD_AllOff();

}


void lcd_close(void){

	SegmentLCD_AllOff();
	SegmentLCD_Disable();

}


void lcd_write(int efm32_itteration, sig_atomic_t efm32_sleepmode, bool dn_up, int dn_mode, int battery_level){


	int i=0;

		SegmentLCD_Number(efm32_itteration);

		SegmentLCD_Symbol(LCD_SYMBOL_ANT,dn_up);

		SegmentLCD_Battery(battery_level);

		while(i<5){

			if (efm32_sleepmode == i){
				SegmentLCD_EnergyMode(i, 1);
			}else{
				SegmentLCD_EnergyMode(i, 0);
			}

			i=i+1;
		}

		switch(dn_mode){

		case 1:
			SegmentLCD_Write("boot");
		break;
		case 2:
			SegmentLCD_Write("alarm");
		break;
		case 3:
			SegmentLCD_Write("time");
		break;
		case 4:
			SegmentLCD_Write("joinfai");
		break;
		case 5:
			SegmentLCD_Write("discon");
		break;
		case 6:
			SegmentLCD_Write("operat");
		break;
		case 7:
			SegmentLCD_Write("service");
		break;
		case 8:
			SegmentLCD_Write("joining");
		break;
		case 9:
			SegmentLCD_Write("tx_OK");
		break;
		case 10:
			SegmentLCD_Write("tx_fail");
		break;
		case 11:
			SegmentLCD_Write("auxsend");
		break;
		default:
		break;
		}

}
