#define HW_CONFIGURATION 0
#define SW_VERTION 2

#define HW_REVITION 5
#define HW_RADIO 0

//#define USE_LCD 1
// all revisjonsnummer er 4 bit


// HW_CONFIGURATION  0 = repeter; 1 = geofonlogger; 2 = sensornode (4dAI);
// SW_VERTION = iterativ for spessifik HW combinasjon

// HW_REVITION  0/1 (hw1) = green; 2 (hw2) = red (newer used); 3 (hw3) = blue; (hw4) = white; (hw3) = red (small PCB);
// HW_RADIO 0 = smartmesh IP; 1 = smertmesh+xbee; 2; LoRa


// "Commands/notifications" (messages) sent from or received in this program when communicating with controller (PC).
// This will be the first byte in "user data".
enum { // Out, from MCU to PC
    OMSG_AVALANCHE      = 0, // Std dev >= limit. Payload: avalanche_warning_t
    OMSG_SYSTEMSTATUS   = 1, // System status. PAYLOAD IS NOT FIXED. Payload: system_status_t
    OMSG_LOGGINGSTARTED = 2, // Notification that logging has started. No payload.
    OMSG_LOGGINGSTOPPED = 3, // Notification that logging has stopped. Payload: uint16_t, which is
                             //   the "temporary ID" of the most recent run attempted written to FLASH.
    OMSG_PARS           = 4, // Copy of adjustable params in use. Payload: adjustable_params_t
    OMSG_DATALIST       = 5, // List of data "runs" (COMP trigs), one per packet. Payload: data_list_item_t
    OMSG_DATA           = 6, // Data belonging to a single "run" (COMP trig), split into packets as needed.
                             //   Payload: data_desc_t + either nothing or the data described by data_desc_t
    OMSG_AUX           	= 7, // AUX sensor data, to replace OMSG_SYSTEMSTATUS, PAYLOAD IS NOT FIXED. Payload: system_status_t
    OMSG_CONFIG_DONE   	= 8, // EFM32 config updatet, one uint8_t as payload, 1 = OK
};
enum { // In, from PC to MCU
    IMSG_REBOOT         = 0, // Command MCU to reboot. No payload.
    IMSG_CHECKSTATUS    = 1, // Command MCU to check its status, and respond with OMSG_STATUS. No payload.
    IMSG_CHECKMOTE      = 2, // Command MCU to check mote status, and if necessary command it to reset. No payload.
    IMSG_RESERVED       = 3, // Currently not used, so that we can get a logical correspondence between order of
                             //   OMSGs and IMSGs without breaking compatibility.
    IMSG_STARTLOGGING   = 4, // Command MCU to start logging. No payload.
    IMSG_GETPARS        = 5, // Command MCU to send adjustable params in use. No Payload.
    IMSG_SETPARS        = 6, // Command MCU to set new adjustable params. Payload: adjustable_params_t
    IMSG_LISTDATA       = 7, // Command MCU to send list of data in FLASH. No payload.
    IMSG_SENDDATA       = 8, // Command MCU to send data belonging to a single "run" (COMP trig). Payload: data_desc_t
    IMSG_CHECKBACKUPRADIO = 9, // Same as IMSG_CHECKSTATUS except forces transmit through backup radio
    IMSG_SETJOINDUTYCYCLE = 10, // Command MCU to set the mote's joinDutyCycle, followed by a reboot of the mote
                                // (needed for parameter to take effekt). In the mote is really down (not just the network),
                                // this will in effect be a delay, and the backup radio will also in this case be "enabled".
    IMSG_AUX_INTERVAL	= 11,	// takes an uint16_t as payload, sets the reporting interval in minutes for AUX sensor data.
};

enum {
	DUST_COMMAND_ID_LEN = 1,// currently 8 bits command ID.
};

extern volatile bool gl_get_aux_data;
extern volatile bool dn_up;
extern volatile int dn_mode;
extern volatile int battery_level;


