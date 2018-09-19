#include <stdint.h>
#include "dn_ipmt.h"
#include "segmentlcd.h"
#include <signal.h>

extern volatile sig_atomic_t gl_sleep_mode_uart_tx;
extern volatile sig_atomic_t gl_sleep_mode_uart_rx;
extern volatile uint16_t aux_min_interval;
extern volatile int gl_num_aux;


//=========================== defines =========================================

// mote state
#define MOTE_STATE_INIT           0x00
#define MOTE_STATE_IDLE           0x01
#define MOTE_STATE_SEARCHING      0x02
#define MOTE_STATE_NEGOCIATING    0x03
#define MOTE_STATE_CONNECTED      0x04
#define MOTE_STATE_OPERATIONAL    0x05
#define MOTE_STATE_DISCONNECTED   0x06
#define MOTE_STATE_RADIOTEST      0x07
#define MOTE_STATE_PROM_LISTEN    0x08

// mote events
#define MOTE_EVENT_BOOT           0x0001
#define MOTE_EVENT_ALARMCHANGE    0x0002
#define MOTE_EVENT_TIMECHANGE     0x0004
#define MOTE_EVENT_JOINFAIL       0x0008
#define MOTE_EVENT_DISCONNECTED   0x0010
#define MOTE_EVENT_OPERATIONAL    0x0020
#define MOTE_EVENT_SVCCHANGE      0x0080
#define MOTE_EVENT_JOINSTARTED    0x0100

// service types
#define SERVICE_TYPE_BW           0x00

// timings
#define SERIAL_RESPONSE_TIMEOUT   16384          // 16384@32kHz = 500ms
#define CMD_PERIOD                3277           // 3277@32kHz = 0,1s
#define ONE_SEC                   32768          // 32768@32kHz = 1s

//#define SERIAL_RESPONSE_TIMEOUT   500          // 500@1kHz = 500ms
//#define CMD_PERIOD                100          // 100@1kHz = 0.1s
//#define ONE_SEC                   1000          // 1000@1kHz = 1s

#define DATA_PERIOD_S                1          // number of second between data packets

// app
#define NUM_STEPS                 8
#define DIRECTION_UP              1
#define DIRECTION_DOWN            0

// api
#define SRC_PORT                  0xf0b9
#define DST_PORT                  0xf0b9

//=========================== typedef =========================================

typedef void (*fsm_timer_callback)(void);
typedef void (*fsm_reply_callback)(void);

//=========================== variables =======================================

typedef struct {
   // fsm
   fsm_timer_callback   fsmCb;
   // reply
   fsm_reply_callback   replyCb;
   // app
   uint8_t              counter;
   uint8_t              secUntilTx;
   uint8_t              direction;
   // api
   uint8_t              socketId;                          // ID of the mote's UDP socket
   uint8_t              replyBuf[MAX_FRAME_LENGTH];        // holds notifications from ipmt
   uint8_t              notifBuf[MAX_FRAME_LENGTH];        // notifications buffer internal to ipmt
} app_vars_t;

app_vars_t app_vars;

//=========================== prototypes ======================================

// fsm
void fsm_scheduleEvent(uint16_t delay, fsm_timer_callback cb);
void fsm_startEvent(fsm_timer_callback cb);
void fsm_cancelEvent(void);
void fsm_setCallback(fsm_reply_callback cb);
// ipmt
void dn_ipmt_notif_cb(uint8_t cmdId, uint8_t subCmdId);
void dn_ipmt_reply_cb(uint8_t cmdId);
// api
void api_response_timeout(void);

void api_getMoteStatus(void);
void api_getMoteStatus_reply(void);

void api_openSocket(void);
void api_openSocket_reply(void);

void api_bindSocket(void);
void api_bindSocket_reply(void);

void api_join(void);
void api_join_reply(void);

void api_sendTo(const unsigned char msg_id, const unsigned char pack[], const unsigned char length);
//void api_sendTo(void);
void api_sendTo_reply(void);

void dn_fsm_irq(void);

void dn_fsm_start(void);

void api_reset(void);
void api_reset_reply(void);

void api_closeSocket(void);
void api_closeSocket_reply(void);



