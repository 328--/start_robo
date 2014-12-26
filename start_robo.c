#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"


#define DEVICE_NAME       "START!"
#define PASS_KEY          "1234"

#define CMD_START         '1'

const U8 BD_ADDR[7] = {0x00,0x16,0x53,0x0F,0x27,0x62,0x00};

char rx_buf[BT_MAX_RX_BUF_SIZE];

void ecrobot_device_initialize()
{
	ecrobot_init_bt_master(BD_ADDR,PASS_KEY);
}

void ecrobot_device_terminate()
{
	ecrobot_term_bt_connection();
}

void user_1ms_isr_type2(void){}

TASK(TaskMain)
{
	unsigned int rx_len = 1;
	while(1){
		if(ecrobot_get_touch_sensor(NXT_PORT_S4) == 1){
			rx_buf[0]=CMD_START;
			ecrobot_send_bt(rx_buf, 0, rx_len);
			display_goto_xy(1,3);
			display_string("START!");
			display_update();
		}	
	}
}
