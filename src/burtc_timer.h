#include <signal.h>

#ifndef BURTC_TIMER_H_
#define BURTC_TIMER_H_


//void burtc_config(void);


unsigned int wait_in_burtc(bool lcd_on);

extern volatile bool gl_get_aux_data;

#endif /* BURTC_TIMER_H_ */
