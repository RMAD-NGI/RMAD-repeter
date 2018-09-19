/*


Port of the uart module to the EFM32 -HW3.

On the MSP430FR4133 LaunchPad, we connect the SmartMesh IP device's serial
API to UCA0 using:
- P1.0 (UCA0TXD)
- P1.1 (UCA0RXD)

\license See attached DN_LICENSE.txt.
*/


#include "dn_uart.h"
#include "em_usart.h"
#include "em_gpio.h"
#include "em_leuart.h"

//=========================== variables =======================================

typedef struct {
   dn_uart_rxByte_cbt   ipmt_uart_rxByte_cb;
} dn_uart_vars_t;

dn_uart_vars_t dn_uart_vars;

//=========================== prototypes ======================================

//=========================== public ==========================================

void dn_uart_init(dn_uart_rxByte_cbt rxByte_cb){
   
   // call back function
   dn_uart_vars.ipmt_uart_rxByte_cb = rxByte_cb;
   
   /* Initialize uart0 for communication with dust networks*/

}



void dn_uart_txByte(uint8_t outbyte){

	//USART_Tx(UART1,outbyte);
	USART_Tx(UART0,outbyte);

}

void dn_uart_txFlush(){
   // nothing to do since MSP430 driver is byte-oriented

	while(UART0->STATUS & 32 == 0){
		//wait here unthil tx buffer is empty
	}

}

