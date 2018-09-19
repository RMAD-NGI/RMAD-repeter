
#include "em_gpio.h"
#include "em_adc.h"
#include "em_dac.h"
#include "em_acmp.h"
#include "em_usart.h"
#include "em_rtc.h"
#include "em_burtc.h"
#include "irqs.h"

#include "dn_fsm.h"

#include "dn_ipmt.h"
#include "dn_hdlc.h"

#include "aux_data.h"
#include "lcd.h"


void ADC0_IRQHandler(void) {
	if (gl_get_aux_data == true) {

		ADC_IntDisable(ADC0, ADC_IF_SINGLE);
		aux_sample[gl_num_aux] = ADC_DataSingleGet(ADC0);

		ADC_Reset(ADC0);

		gl_aux_data_recived = true;
		gl_num_aux = gl_num_aux + 1;

		}

}

void UART0_RX_IRQHandler(void) {

	uint8_t inbyte = USART_RxDataGet(UART0);
	dn_hdlc_rxByte(inbyte);

    USART_IntClear(UART0, USART_IF_RXDATAV);

}


// An odd GPIO port changes.
void GPIO_EVEN_IRQHandler(void) {

	//uint32_t test = GPIO_IntGetEnabled();

	if((GPIO->IF & GPIO->IEN) == 256){

		if (GPIO_PinInGet(gpioPortC, 8) == false) {

		        GPIO_PinOutClear(gpioPortC, 9);
		        gl_sleep_mode_uart_rx = 1;

		        USART_IntClear(UART0, USART_IF_RXDATAV);
		        USART_IntEnable(UART0, USART_IF_RXDATAV);

		    } else {

		        GPIO_PinOutSet(gpioPortC, 9);
		        gl_sleep_mode_uart_rx = 3;

		        USART_IntDisable(UART0, USART_IF_RXDATAV);
		        USART_IntClear(UART0, USART_IF_RXDATAV);

		    }

		GPIO_IntClear(256);

	} else if ((GPIO->IF & GPIO->IEN) == 1024){

		aux_data_start();
		GPIO_IntClear(1024);

	}


}

void GPIO_ODD_IRQHandler(void)
{
  /* Acknowledge interrupt */
  GPIO_IntClear(1 << 9);

  lcd_init(secs_since_mote_check);

}



void RTC_IRQHandler(void){


	if ((RTC->IF & RTC->IEN) == 2){

		//RTC_Enable(false);
	 	RTC_IntDisable(2);
	 	RTC_IntClear(2);

	 	dn_fsm_irq();


	}else if ((RTC->IF & RTC->IEN)  == 4){

		//RTC_Enable(false);
		RTC_IntDisable(4);
		RTC_IntClear(4);
		gl_get_aux_data = true;
		gl_init_aux_data = true;

		GPIO_PinModeSet(gpioPortD,8,gpioModeInput,0); /*clear external reset - har lagt inn denne her fordi vi allerede har brukt opp de to RTC interuptene, burde muligens også hatte en case for og skille mellom hard reset og aux_send*/

		aux_data_aquire_and_send();

	}


}
