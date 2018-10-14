#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define I2C_WRITE 0
#define I2C_READ 0x01

#define I2C_STOP 1
#define I2C_NO_STOP 0
#define I2C_RESTART 1
#define I2C_NO_RESTART 0

#define MPU_9250 0x68


void config_I2C3(void);
uint8_t send_i2c_data(uint8_t read_write,uint8_t slave_addr,uint8_t start_stop, uint8_t restart,uint8_t reg_addr,uint8_t num_bytes);

#endif /*I2C_H_*/
