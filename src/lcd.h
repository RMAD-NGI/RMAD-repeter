#include <signal.h>


void lcd_config(void);

void lcd_close(void);

void lcd_write(int, sig_atomic_t, bool, int, int);

bool lcd_update(unsigned int, unsigned int, int, sig_atomic_t, bool, int, int);

void lcd_init(unsigned int);


//extern volatile unsigned int secs_since_mote_check;
//extern volatile uint16_t aux_min_interval;
