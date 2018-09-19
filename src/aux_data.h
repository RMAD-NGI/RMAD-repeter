#include <signal.h>
#include "config_efm32.h"
#include "em_adc.h"
#include "em_device.h"


extern volatile sig_atomic_t gl_sleep_mode_recording;

void aux_data_start(void);

void aux_data_aquire_and_send(void);

void aux_data_send(void);

int convertToCelsius(sample_t);

extern volatile bool dn_up;
extern volatile int dn_mode;


