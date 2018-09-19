#ifndef CONFIG_H_
#define CONFIG_H_

#include "em_acmp.h"
#include "em_adc.h"

#define CONFIG_AD_NCHANS 4

typedef uint16_t sample_t;

//typedef sample_t scan_t[CONFIG_AD_NCHANS];


//extern volatile int gl_ad_sampling_rate; // Per sample, not scan
//extern volatile double gl_ad_scan_rate; // Per scan

extern volatile ADC_SingleInput_TypeDef adc_ch_liste[];
extern volatile bool adc_diff_liste[];
extern volatile ADC_Ref_TypeDef adc_reff_liste[];
extern volatile int num_channels;




int AD_config(void);

void aux_sensor_config(const int ch_number);

//void dac_config(void); //added for testing of preamp

void comp_config(const uint32_t *const trig_levels, const ACMP_Channel_TypeDef *const pos_sel1);

void preamp_config(const uint8_t *const preamp_status);

void preamp_set_status(const uint8_t *const preamp_status);

int battery_charge_status(const uint16_t battery_voltage, const int16_t logger_temperature);

void uart0_config(void);

void uart1_config(void);

void leuart_config(void);

void rtc_config(void);

void burtc_config(void);

void wdog_config();

void rtc_dn_fsm_config(void);

void gpio_config(void);

void dac_ps_config(const uint8_t *const channel);

void efm32_config(void);

void button_config(void);

#endif
