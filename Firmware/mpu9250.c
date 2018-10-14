/*Notes
1) Sensor requires a certain startup time at the very begining when powered up before it can give out any data, Otherwise it would not acknowledge any command sent to it

*/



#include <stm32l452xx.h>
#include "i2c.h"
#include "MPU9250.h"
#include "uart1.h"

uint8_t  MPU_reg_read(uint8_t reg_addr)
{
	uint8_t data=0;
	send_i2c_data(I2C_WRITE,MPU_9250,I2C_NO_STOP,I2C_NO_RESTART,reg_addr,1);
	
	data=send_i2c_data(I2C_READ,MPU_9250,I2C_STOP,I2C_RESTART,0,1);
	return data;
}

void MPU_reg_uart(uint16_t data)
{
	send_data_uart(data);
	uart_wait();
	send_data_uart(data>>8);
	uart_wait();
}
