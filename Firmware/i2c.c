#include <stm32l452xx.h>
#include "i2c.h"

void config_I2C3(void)
{
	I2C3->CR1&=~(I2C_CR1_PE);
	__NOP();
	__NOP();
	__NOP();
	I2C3->CR1&=~(I2C_CR1_ANFOFF);
	I2C3->TIMINGR=0x00707CBB;
	I2C3->CR1&=~(I2C_CR1_NOSTRETCH);
	
	
	I2C3->CR1|=(I2C_CR1_PE);
	
}


uint8_t send_i2c_data(uint8_t read_write,uint8_t slave_addr,uint8_t start_stop,uint8_t restart,uint8_t reg_addr,uint8_t num_bytes)
{
	uint8_t data=0;
		if(restart==I2C_NO_RESTART)
	{
		while(I2C3->ISR&I2C_ISR_BUSY)
		{
		
		}
	}
	//I2C3->CR2|=(I2C_CR2_AUTOEND);
	I2C3->CR2=(I2C3->CR2&(~I2C_CR2_SADD_Msk))|((uint16_t)(slave_addr)<<1);//((uint16_t)(slave_addr))
	
	if(read_write==I2C_WRITE)
	{
		I2C3->CR2&=~(I2C_CR2_RD_WRN);
			
		I2C3->CR2=(I2C3->CR2&(~I2C_CR2_NBYTES_Msk))|(((uint16_t)num_bytes)<<16);
		I2C3->TXDR=reg_addr;
		
		I2C3->CR2|=I2C_CR2_START;
GPIOB->ODR&=~(1<<7U);		
	while(!(I2C3->ISR&I2C_ISR_TC))
	{
			
	}

	while(!(I2C3->ISR|I2C_ISR_TXE))
	{
	}
	}
		
	else
	{
		I2C3->CR2|=(I2C_CR2_RD_WRN);
	}
	
	
	if(read_write==I2C_READ)
	{
		I2C3->CR2=(I2C3->CR2&(~I2C_CR2_NBYTES_Msk))|(((uint16_t)num_bytes)<<16);
		//I2C3->CR2|=(I2C_CR2_AUTOEND);
		I2C3->CR2|=I2C_CR2_START;
		
		while(!(I2C3->ISR&I2C_ISR_RXNE))
		{
			
		}
		data=I2C3->RXDR;

//		while(!(I2C3->ISR&I2C_ISR_TC))
//	{
//		
//	}
	}
	
	
	if(start_stop==I2C_STOP)
	{
	I2C3->CR2|=I2C_CR2_STOP;
	}

	if(read_write==I2C_READ)
	{
		return data;
	}
	
	else
	{
		return 0;
	}
	
}

