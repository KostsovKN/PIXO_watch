#include <stm32l452xx.h>
#include "clock.h"
#include "gpio.h"
#include "systick.h"
#include "Timer.h"
#include "spi1.h"
#include "uart1.h"
#include "ledmatrix.h"
#include "frames.h"
#include "i2c.h"
#include "MPU9250.h"
#include "rtc.h"


//#define DEBUG

#define RGB_EN 11
#define SCREEN_ON_TIME_BTN_PRESS 2


void runnig_pixel(void);
void config_exti_lines(void);

uint8_t i=0;
uint8_t j=0;
uint8_t pixel[2]={0,0};

uint16_t acc_x_axis;
uint16_t acc_y_axis;
uint16_t acc_z_axis;

uint16_t acc_neg_x_axis;
uint16_t acc_neg_y_axis;
uint16_t acc_neg_z_axis;

uint16_t gyr_x_axis;
uint16_t gyr_y_axis;
uint16_t gyr_z_axis;

uint8_t gx;

uint8_t i2c_write_flag=0;

uint8_t mpu_ready=0;// To give time to Motion Sensor to start up before pulling the data

volatile uint32_t tr_snapshot=0;
volatile uint8_t led_on_timer_flag=0;

void config_exti_lines(void)
{
	
	SYSCFG->EXTICR[0]|=SYSCFG_EXTICR1_EXTI0_PB;// Configure Pin PB0 as the source of interuppt for EXTI0
	EXTI->IMR1|=EXTI_IMR1_IM0;//Line 0 or EXTI0 is not masked
	EXTI->FTSR1|=EXTI_FTSR1_FT0;//Select Falling Edge as the Trigger for EXTI0	

}

void runnig_pixel(void)
{

#ifdef DEBUG
			send_string("pixel[0]=",sizeof("pixel[0]=")-1);
			send_data_uart(pixel[0]+48);
			send_data_uart(0x0D);
			send_string("pixel[1]=",sizeof("pixel[1]=")-1);
			send_data_uart(pixel[1]+48);
			send_data_uart(0x0D);
			send_data_uart(0x0D);
#endif
			for(i=0;i<ROWS;i++)
			{
				for(j=0;j<COLMS;j++)
				{
					if((i==pixel[1])&&(j==pixel[0]))
					{	
						b_w_frame[i][j]=1;
					}
					else
					{
						b_w_frame[i][j]=0;
					}
				}
				frame_sent_flag=0;
			}

			
			if (pixel[0]==COLMS-1)
			{
				pixel[0]=0xFF;
				pixel[1]++;
			}
			
			if(pixel[1]==ROWS)
			{
				pixel[1]=0;
			}
			pixel[0]++;
}

void EXTI0_IRQHandler(void)
{
	EXTI->PR1|=EXTI_PR1_PIF0;// Clear the Pending register of EXTI0 
	led_on_timer_flag=1;
	tr_snapshot=(((RTC->TR)&0xF)+SCREEN_ON_TIME_BTN_PRESS)%10;
	//GPIOB->ODR^=(1<<7U);
}
void TIM6_DAC_IRQHandler(void)
{
	
	TIM6->SR&=~(TIM_SR_UIF);
	
	if(led_on_timer_flag==1)
	{
	if((RTC->TR&0xF)>=tr_snapshot)
	{
		GPIOB->ODR&=~GPIO_ODR_OD11;
		led_on_timer_flag=0;
	}
	
	else
	{
		GPIOB->ODR|=GPIO_ODR_OD11;
	}
}
//	if((GPIOB->IDR&0x1)==1)
//	{
//		GPIOB->ODR|=(1<<7U);
//	}
//	else
//	{
//		GPIOB->ODR&=~(1<<7U);
//	}
	
//	GPIOB->ODR^=(1<<7U);
	
	draw_rgb_frame();

//if(mpu_ready>=5)// To give time to Motion Sensor to start up before pulling the data
//	
//	{
//	
//		//send_i2c_data(I2C_WRITE,MPU_9250,I2C_STOP,I2C_NO_RESTART,ACCEL_XOUT_L,1);
//	acc_x_axis=MPU_reg_read(ACCEL_XOUT_H);
//	//GPIOB->ODR&=~(1<<7U);
//	acc_x_axis|=(acc_x_axis<<8)|(MPU_reg_read(ACCEL_XOUT_L));
//	acc_y_axis=MPU_reg_read(ACCEL_YOUT_H);
//	
//	acc_y_axis|=(acc_y_axis<<8)|(MPU_reg_read(ACCEL_YOUT_L));
//	acc_z_axis=MPU_reg_read(ACCEL_ZOUT_H);
//	acc_z_axis|=(acc_z_axis<<8)|(MPU_reg_read(ACCEL_ZOUT_L));
//	
//	if(((acc_x_axis)&(1<<15))>0)
//	{
//		gx=((0xFFFF-acc_x_axis)*61)/10000;
//		//gx=0xFFFF-acc_x_axis;
//	}
//	
//	else
//		{ 
//			gx=((acc_x_axis)*61)/10000;
//			//gx=acc_x_axis;
//		}
//	
//	
//		send_data_uart(gx);
//		
//		
//		
//		gyr_x_axis=MPU_reg_read(GYRO_XOUT_H);
//		gyr_x_axis|=(gyr_x_axis<<8)|(MPU_reg_read(GYRO_XOUT_L));
//		//gyr_x_axis=(UINT16_MAX+1)+gyr_x_axis;
//		gyr_y_axis=MPU_reg_read(GYRO_YOUT_H);
//		gyr_y_axis|=(gyr_y_axis<<8)|(MPU_reg_read(GYRO_YOUT_L));
//		gyr_z_axis=MPU_reg_read(GYRO_ZOUT_H);
//		gyr_z_axis|=(gyr_z_axis<<8)|(MPU_reg_read(GYRO_ZOUT_L));
//		//send_string("AA",2);
//		//send_string("x-",2);
//		////MPU_reg_uart(acc_x_axis);
//		//send_string("\n",1);
//		//send_string("y-",2);
//		////MPU_reg_uart(acc_y_axis);
//		//send_string("\n",1);
//		//send_string("z-",2);
//		////MPU_reg_uart(acc_z_axis);
//		//send_string("\n",1);
//	//	MPU_reg_uart(gyr_x_axis);
//	//	MPU_reg_uart(gyr_y_axis);
//	//	MPU_reg_uart(gyr_z_axis);
//}
//	mpu_ready++;// To give time to Motion Sensor to start up before pulling the data
}

void USART1_IRQHandler(void)
{
	
	uint8_t cmd[2];
	uint8_t byte_cnt=0;
	
	for(byte_cnt=0;byte_cnt<2;byte_cnt++)
	{
		cmd[byte_cnt]=recieve_data_uart();
	}
	
//	for(byte_cnt=0;byte_cnt<2;byte_cnt++)
//	{
//		send_data_uart(cmd[byte_cnt]);
//	}
	
	if(cmd[0]=='l')
	{
		if(cmd[1]=='0')
		{
			GPIOB->ODR&=~(1<<RGB_EN);
		}
		
		else if(cmd[1]=='1')
		{
			GPIOB->ODR|=(1<<RGB_EN);
		}
	}
	
}
	

int main (void)
{
	
	config_clock();
	config_systick();
	config_GPIOA();
	config_GPIOB();
	GPIOB->ODR|=(1<<7U);
	
	config_exti_lines();

	
	
	setup_timer();
	//config_I2C3();
	config_SPI1();
	SPI1_enable();
	initialise_uart();
	initialise_rtc_clock();
	//NVIC_SetPriority(USART1_IRQn,2);
	NVIC_SetPriority(TIM6_DAC_IRQn,3);
	NVIC_SetPriority(EXTI0_IRQn,4);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
	//NVIC_EnableIRQ(USART1_IRQn);
	
	GPIOB->ODR&=~(1<<RGB_EN);
	
	
	while(1)
	{
		if(frame_sent_flag)
		{
			send_data_uart('5');
			runnig_pixel();
			make_date_frame();
		}
	}
}
