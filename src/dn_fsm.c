#include "dn_fsm.h"
#include "em_rtc.h"
#include "repeter.h"
#include "segmentlcd.h"
#include "aux_data.h"
#include "em_gpio.h"


volatile static uint8_t gl_socketID = 0;
volatile static bool check_and_report = true;

volatile int dn_mode = 0;
volatile bool dn_up = false;


//=========================== interrupts ======================================

void dn_fsm_start(void){

    // reset local variables
    memset(&app_vars,    0, sizeof(app_vars));

    // initialize the ipmt module
    dn_ipmt_init(
       dn_ipmt_notif_cb,                // notifCb
       app_vars.notifBuf,               // notifBuf;
       sizeof(app_vars.notifBuf),       // notifBufLen
       dn_ipmt_reply_cb                 // replyCb
    );

   fsm_scheduleEvent(ONE_SEC, &api_reset);

    //api_reset();

}


void dn_fsm_irq(void){

	gl_sleep_mode_uart_tx = 3;
	app_vars.fsmCb();

}


void fsm_scheduleEvent(uint16_t delay, fsm_timer_callback cb) {
   
   // remember what function to call

   gl_sleep_mode_uart_tx = 1;

   app_vars.fsmCb       = cb;

   RTC_CounterReset();
   RTC_CompareSet(0, delay);
   RTC_IntClear(2);
   RTC_IntEnable(2);
   //RTC_Enable(true);

   // configure/start the RTC

}

void fsm_cancelEvent(void) {
	// stop the RTC

	//RTC_Enable(false);
	RTC_IntDisable(2);
	gl_sleep_mode_uart_tx = 3;

	// clear function to call
	app_vars.fsmCb       = NULL;
}

void fsm_startEvent(fsm_timer_callback cb) {

   // remember what function to call
   app_vars.fsmCb       = cb;
   app_vars.fsmCb();

}


void fsm_setCallback(fsm_reply_callback cb) {
   app_vars.replyCb     = cb;
}

void dn_ipmt_reply_cb(uint8_t cmdId) {
   app_vars.replyCb();

}

//===== ipmt

void dn_ipmt_notif_cb(uint8_t cmdId, uint8_t subCmdId) {

   dn_ipmt_events_nt* dn_ipmt_events_notif;
   dn_ipmt_receive_nt* dn_ipmt_receive_notif;

   
   switch (cmdId) {
      case CMDID_EVENTS:
         
         // parse notification
         dn_ipmt_events_notif = (dn_ipmt_events_nt*)app_vars.notifBuf;
         
         switch (dn_ipmt_events_notif->events) {
         	 case MOTE_EVENT_BOOT:
         		 fsm_scheduleEvent(CMD_PERIOD, api_join);
         		 dn_mode = 1;
         		 break;
         	 case MOTE_EVENT_ALARMCHANGE:
         		 dn_mode = 2;
         		 break;
         	 case MOTE_EVENT_TIMECHANGE:
         		 dn_mode = 3;
         		 break;
         	 case MOTE_EVENT_JOINFAIL:
         		 dn_mode = 4;
         		 break;
         	 case MOTE_EVENT_DISCONNECTED:
         		 dn_mode = 5;
         		 break;
         	 case MOTE_EVENT_OPERATIONAL:
         		 fsm_scheduleEvent(CMD_PERIOD, &api_closeSocket);
         		 dn_mode = 6;
       			 dn_up = true;
         		 break;
         	 case MOTE_EVENT_SVCCHANGE:
         		 dn_mode = 7;
         		 aux_data_start();
         		 break;
         	 case MOTE_EVENT_JOINSTARTED:
         		 dn_mode = 8;
         		 break;
         	 default:
         		 break;// nothing to do

         }

         switch (dn_ipmt_events_notif->state) {
         	 case MOTE_STATE_INIT:
         		 break;
         	 case MOTE_STATE_IDLE: //boot event
         		 dn_up = false;
         		 break;
         	 case MOTE_STATE_SEARCHING:
         	     break;
         	 case MOTE_STATE_NEGOCIATING:
         	     break;
         	 case MOTE_STATE_CONNECTED:
         	     break;
         	 case MOTE_STATE_OPERATIONAL:
         		 break;
         	 case MOTE_STATE_DISCONNECTED:
         		 dn_up = false;
         		 //fsm_scheduleEvent(CMD_PERIOD, &api_closeSocket);
         	     break;
         	 case MOTE_STATE_RADIOTEST:
         	     break;
         	 case MOTE_STATE_PROM_LISTEN:
         	     break;
         	 default:
         		 break;// nothing to do

         }
         break;

      case CMDID_RECEIVE:

    	 // parse datapacket
    	 dn_ipmt_receive_notif = (dn_ipmt_receive_nt*)app_vars.notifBuf;

    	 const unsigned char *rx_data = dn_ipmt_receive_notif ->payload;
    	 uint8_t ngi_packet = rx_data[0];

    	 switch (ngi_packet) {
    	 	 case IMSG_REBOOT:

    	 		GPIO_PinModeSet(gpioPortD,8,gpioModeWiredAnd,0); /*external hard reset*/

    	 		gl_sleep_mode_recording = 1;
    	 		gl_num_aux = 0;
    	 	    RTC_CounterReset();
    	 	    RTC_CompareSet(1, 1000);
    	 	    RTC_IntClear(4);
    	 	    RTC_IntEnable(4);

    	 	    //som i praksis bør bli det samme som:
    	 		//wait(1000);
    	 		//GPIO_PinModeSet(gpioPortD,8,gpioModeInput,0); /*clear external reset*/

    	     	break;
    	 	 case IMSG_CHECKSTATUS:
    	 		aux_data_start();
    	 		break;
    	  	case IMSG_CHECKMOTE:
    	  		break;
    	  	case IMSG_RESERVED:
    	  		break;
    	  	case IMSG_STARTLOGGING:
    	  		break;
    	  	case IMSG_GETPARS:
    	  	    break;
    	  	case IMSG_SETPARS:
    	  	    break;
    	  	case IMSG_LISTDATA:
    	  	    break;
    	  	case IMSG_SENDDATA:
    	  		break;
    	  	case IMSG_CHECKBACKUPRADIO:
    	  	    break;
    	  	case IMSG_SETJOINDUTYCYCLE:
    	  	    break;
    	  	case IMSG_AUX_INTERVAL:
    	  		aux_min_interval = rx_data[1] + 256*rx_data[2];
    	  	    break;
    	  	default:
     	  	    break;// nothing to do
    	 }
    	 break;
    case CMDID_TIMEINDICATION:
    	break;
    case CMDID_MACRX:
        break;
    case CMDID_TXDONE:
    	if (true){

    		// gl_sleep_mode_uart_rx = 3; note to self - dette fungerte ikke
    		// kan det være at pakker som ikke gnererer noe svar går tilbake til em3 før cm_clib har fått sendt en acc??

    		dn_ipmt_txDone_nt* reply;
    		reply = (dn_ipmt_txDone_nt*)app_vars.replyBuf;

    		if (reply->status == 1){
    			dn_mode = 10;
    		}else{
    			dn_mode = 9;
    		}

    	}
    	break;
    case CMDID_ADVRECEIVED:
        break;
    default:
         // nothing to do
         break;
   }

}


void api_response_timeout(void) {
  // issue cancel command
   dn_ipmt_cancelTx();

}


void api_reset(void) {

   // arm callback
   fsm_setCallback(api_reset_reply);

   // issue function
   dn_ipmt_reset((dn_ipmt_reset_rpt*)(app_vars.replyBuf));     // reply

   // schedule timeout event
   fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);

}

void api_reset_reply(void) {
   // cancel timeout
   fsm_cancelEvent();

}

void api_join(void) {

   // arm callback
   fsm_setCallback(api_join_reply);

   // issue function
   dn_ipmt_join(
      (dn_ipmt_join_rpt*)(app_vars.replyBuf)     // reply
   );

   // schedule timeout event
   fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);


}

void api_join_reply(void) {
   // cancel timeout
   fsm_cancelEvent();

}

void api_closeSocket(void) {

	// arm callback
	fsm_setCallback(api_closeSocket_reply);

	// issue function
	dn_ipmt_closeSocket(
		app_vars.socketId,                                              // protocol
		(dn_ipmt_closeSocket_rpt*)(app_vars.replyBuf)    // reply
	);


	fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);

}

void api_closeSocket_reply(void) {

   // cancel timeout
   fsm_cancelEvent();

   // choose next step
   fsm_scheduleEvent(CMD_PERIOD, api_openSocket);

}

//=== openSocket

void api_openSocket(void) {

   // arm callback
   fsm_setCallback(api_openSocket_reply);

   // issue function
   dn_ipmt_openSocket(
      0,                                              // protocol
      (dn_ipmt_openSocket_rpt*)(app_vars.replyBuf)    // reply
   );

   // schedule timeout event
   fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);

}

void api_openSocket_reply(void) {

   // cancel timeout
   fsm_cancelEvent();

   dn_ipmt_openSocket_rpt* reply;

   // parse reply
   reply = (dn_ipmt_openSocket_rpt*)app_vars.replyBuf;

   // store the socketID
   app_vars.socketId = reply->socketId;

   gl_socketID = reply->socketId;

   // choose next step
   fsm_scheduleEvent(CMD_PERIOD, api_bindSocket);

}

//===== bindSocket

void api_bindSocket(void) {

   // arm callback
   fsm_setCallback(api_bindSocket_reply);

   // issue function
   dn_ipmt_bindSocket(
      app_vars.socketId,                              // socketId
      SRC_PORT,                                       // port
      (dn_ipmt_bindSocket_rpt*)(app_vars.replyBuf)    // reply
   );

   // schedule timeout event
   fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);

}

void api_bindSocket_reply(void) {
   // cancel timeout
   fsm_cancelEvent();

}


//void api_sendTo(void){
void api_sendTo(const unsigned char msg_id, const unsigned char pack[], const unsigned char length){

    unsigned char payload[length+DUST_COMMAND_ID_LEN];
   	for (int k =  0; k < DUST_COMMAND_ID_LEN-1; ++k)
   		payload[k] = 0;
   	payload[DUST_COMMAND_ID_LEN-1] = msg_id;
   	memcpy(payload+DUST_COMMAND_ID_LEN, pack, length);

	//uint8_t  payload = 6;
    uint8_t  dest_addr[16];
    memcpy(dest_addr,ipv6Addr_manager,16);

   
   // arm callback
   fsm_setCallback(api_sendTo_reply);
   

   // issue function
   dn_ipmt_sendTo(
      //app_vars.socketId,                                   // socketId
	  gl_socketID,
      dest_addr,                                           // destIP
      DST_PORT,                                            // destPort
      SERVICE_TYPE_BW,                                     // serviceType
      0,                                                   // priority
      0xfffe,                                              // packetId  /note to self - feil sleep mode etter txdone
      payload,                                             // payload
      sizeof(payload),                                     // payloadLen
      (dn_ipmt_sendTo_rpt*)(app_vars.replyBuf)             // reply
   );
   
   // schedule timeout event

   fsm_scheduleEvent(SERIAL_RESPONSE_TIMEOUT, api_response_timeout);

}

void api_sendTo_reply(void) {
   
   // cancel timeout
   fsm_cancelEvent();
   
	dn_ipmt_sendTo_rpt* reply;

   reply = (dn_ipmt_sendTo_rpt*)app_vars.replyBuf;

   // store the socketID
   int sendTo_status = reply->RC;

   if(sendTo_status > 0){

	   fsm_scheduleEvent(CMD_PERIOD, &api_closeSocket);

   }

}




