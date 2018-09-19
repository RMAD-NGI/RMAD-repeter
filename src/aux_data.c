#include "aux_data.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "em_gpio.h"
#include "em_adc.h"
#include "em_dac.h"
#include "em_rtc.h"

#include "config_efm32.h"
#include "repeter.h"

#include "segmentlcd.h"

#include "dn_fsm.h"


volatile int gl_num_aux;
volatile bool gl_init_aux_data = false;
volatile bool gl_get_aux_data = false;
volatile bool gl_aux_data_recived = false;

volatile int battery_level = 0;
volatile static int charging = 1;

volatile uint32_t aux_start_delay_ms = 32768;          // 32768@32kHz = 1s
//volatile uint32_t aux_start_delay_ms = 1000;

sample_t aux_sample[10];


//sensornode repeter
volatile ADC_SingleInput_TypeDef adc_ch_liste[] = {adcSingleInpVDDDiv3,adcSingleInpTemp, adcSingleInpCh7}; // two first channels must always be VDD3 and temp
volatile bool adc_diff_liste[] = {false,false,false};
volatile ADC_Ref_TypeDef adc_reff_liste[] = {adcRef2V5,adcRef2V5,adcRef2V5};
volatile int num_channels = 3;


void aux_data_start(){


	gl_sleep_mode_recording = 1;

	//dac_ps_config(1);
    //DAC0 -> CH1DATA = 4095;

	//GPIO_PinOutSet(gpioPortE,2); /*xSW gpio 1=on*/

    gl_num_aux = 0;


    RTC_CounterReset();
    RTC_CompareSet(1, aux_start_delay_ms);
    RTC_IntClear(4);
    RTC_IntEnable(4);
    //RTC_Enable(true);

	//må legge inne en RTC delay her for å "varme opp" sensorene

	//gl_get_aux_data = true;
	//gl_init_aux_data = true;

	//dn_mode = 11;
}


void aux_data_aquire_and_send(){


	if (gl_get_aux_data == true){

		if (gl_init_aux_data == true){

			aux_sensor_config(gl_num_aux);
			ADC_Start(ADC0, adcStartSingle);
			gl_init_aux_data = false;

		}else if ((gl_aux_data_recived == true) & (gl_num_aux < num_channels)){

			aux_sensor_config(gl_num_aux);
			ADC_Start(ADC0, adcStartSingle);

		}else if (gl_aux_data_recived == true) {

			DAC_Reset(DAC0);
			//GPIO_PinOutClear(gpioPortE,2); /*xSW gpio 0=off*/

			//GPIO_PinModeSet(gpioPortD,8,gpioModeInput,0); /*Clear external reset*/

			aux_data_send();

			gl_get_aux_data = false;
			gl_num_aux = 0;
			gl_sleep_mode_recording = 3;

		}

		gl_aux_data_recived = false;

	}

}

void aux_data_send() {
    //EFM32_PACK_START(1); // Actually a no-op for GNU it seems, for GNU we use __attribute__ ((__packed__))
    // More info: See https://gcc.gnu.org/onlinedocs/gcc/Type-Attributes.html#Type-Attributes
    typedef struct
        __attribute__ ((__packed__)) {

    		uint8_t system;
            uint8_t revition;
            uint8_t state;

            uint16_t vdd3;
            uint16_t temperature;

            uint8_t signed_number;

            uint16_t ai0;


        } system_status_t;
        //EFM32_PACK_END(); // Actually a no-op for GNU it seems

        system_status_t status;

        status.system =  HW_CONFIGURATION * 16 + SW_VERTION;
        status.revition = HW_REVITION * 16 + HW_RADIO;

        status.vdd3 = aux_sample[0];
        status.temperature = convertToCelsius(aux_sample[1]);



        int connected = dn_up;

        status.state = charging +  2*connected; // + 2*trigg2_status + 4*trigg1_status;




        uint8_t sign =0;
        int i = 2; // two first channels must always be VDD3 and temp
        do {
        	if (adc_diff_liste[i] == true){

        		sign = sign + pow(2,i-2);

        	}
        	i=i+1;
        } while (i<num_channels);

        status.signed_number = sign;

        status.ai0 = aux_sample[2];


        if (aux_sample[0]>29797){			//>4,1V
        	battery_level = 4;
        }else if (aux_sample[0]>28048){		//>3,9V
        	battery_level = 3;
        }else if (aux_sample[0]>26301){		//>3,7V
        	battery_level = 2;
        }else if (aux_sample[0]>22806){		//>3,3V
        	battery_level = 1;
        }else{
        	battery_level = 0;
        }

        if(dn_up){

        	api_sendTo(OMSG_AUX, &status, sizeof(status));

        }

        charging = battery_charge_status(status.vdd3, status.temperature); //statusbit endret til charge enable - PC7 - i hw4 og hw5 - flyttet hit for at sendt bit skal representere status ved avlesning av batterispenning

    }


    int convertToCelsius(sample_t adcSample)
    {
      int16_t temp;

      /* Factory calibration temperature from device information page. */
      float cal_temp_0 = (float)((DEVINFO->CAL & _DEVINFO_CAL_TEMP_MASK)
                                 >> _DEVINFO_CAL_TEMP_SHIFT);

      float cal_value_0 = (float)((DEVINFO->ADC0CAL2
                                   & _DEVINFO_ADC0CAL2_TEMP1V25_MASK)
                                  >> _DEVINFO_ADC0CAL2_TEMP1V25_SHIFT);

      /* Temperature gradient (from datasheet) */
      float t_grad = -6.3;

      temp = 100*(cal_temp_0 - ((cal_value_0 - adcSample/8) / t_grad));

      return temp;
    }

