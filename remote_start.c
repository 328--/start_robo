#define CMD_START         '1'
int remote_start(void)
{
	int i;
	unsigned int rx_len;
	unsigned char start = 0;
	
	char rx_buf[BT_MAX_RX_BUF_SIZE];

	for (i=0; i<BT_MAX_RX_BUF_SIZE; i++)
	{
		rx_buf[i] = 0;
	}

	rx_len = ecrobot_read_bt(rx_buf, 0, BT_MAX_RX_BUF_SIZE);
	if (rx_len > 0)
	{
		if (rx_buf[0] == CMD_START)
		{
			start = 1;
		}
		ecrobot_send_bt(rx_buf, 0, rx_len);
	}

	return start;
}
