
#include <signal.h>
#include "config_efm32.h"

extern volatile sig_atomic_t gl_sleep_mode_uart_rx;

extern volatile unsigned int secs_since_mote_check;

extern volatile int gl_num_aux;
extern volatile bool gl_get_aux_data;
extern volatile bool gl_aux_data_recived;
extern volatile bool gl_init_aux_data;
extern sample_t aux_sample[];

extern volatile bool burtc_delay_complete;
extern volatile uint32_t burtc_counter;

extern volatile bool use_lcd;


void RTC_IRQHandler(void);

void ADC0_IRQHandler(void);

void UART0_RX_IRQHandler(void);

void GPIO_EVEN_IRQHandler(void);

void RTC_IRQHandler(void);

//void BURTC_IRQHandler(void);

