#include <stm32l452xx.h>
#include "gpio.h"

void config_GPIOA(void)
{
//	
//		GPIOA->MODER|= GPIO_MODER_MODER8_0;//Select the Mode of PA8 to General Purpose Output
//		GPIOA->MODER&=~GPIO_MODER_MODER8_1;//Select the Mode of PA8 to General Purpose Output
//		
//		GPIOA->MODER =(GPIOA->MODER & ~(GPIO_MODER_MODER4 | GPIO_MODER_MODER5 | GPIO_MODER_MODER6 | GPIO_MODER_MODER7)) | GPIO_MODER_MODER4_1 | GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER7_1;// Alternate mode selection for SPI1
//		
//		GPIOA->AFR[0]|=GPIO_AFRL_AFSEL4_0|GPIO_AFRL_AFSEL4_2;//For SPI A4
//		GPIOA->AFR[0]|=GPIO_AFRL_AFSEL5_0|GPIO_AFRL_AFSEL5_2;//For SPI A5
//		GPIOA->AFR[0]|=GPIO_AFRL_AFSEL6_0|GPIO_AFRL_AFSEL6_2;//For SPI A6
//		GPIOA->AFR[0]|=GPIO_AFRL_AFSEL7_0|GPIO_AFRL_AFSEL7_2;//For SPI A7
//		
			GPIOA->MODER =(GPIOA->MODER & ~(GPIO_MODER_MODER9 | GPIO_MODER_MODER10)) | GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1;// Alternate mode selection for UART1
			GPIOA->AFR[1]|=GPIO_AFRH_AFSEL9_0|GPIO_AFRH_AFSEL9_1|GPIO_AFRH_AFSEL9_2;//Alternate Function AF7 select for A9 and A10
			GPIOA->AFR[1]|=GPIO_AFRH_AFSEL10_0|GPIO_AFRH_AFSEL10_1|GPIO_AFRH_AFSEL10_2;//Alternate Function AF7 select for A9 and A10
	
			GPIOA->MODER =(GPIOA->MODER & ~(GPIO_MODER_MODER5 | GPIO_MODER_MODER6 | GPIO_MODER_MODER15)) | GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER15_1;// Alternate mode selection for SPI1
			GPIOA->AFR[0]|=GPIO_AFRL_AFSEL5_0|GPIO_AFRL_AFSEL5_2;//For SPI A5
			GPIOA->AFR[0]|=GPIO_AFRL_AFSEL6_0|GPIO_AFRL_AFSEL6_2;//For SPI A6
			GPIOA->AFR[1]|=GPIO_AFRH_AFSEL15_0|GPIO_AFRH_AFSEL15_2;//For SPI A15
	
//		GPIOA->MODER&=~GPIO_MODER_MODER5_0;//Select the Mode of PB0 to General Purpose Input
//		GPIOA->MODER&=~GPIO_MODER_MODER5_1;

//		GPIOA->MODER&=~GPIO_MODER_MODER6_0;//Select the Mode of PB0 to General Purpose Input
//		GPIOA->MODER&=~GPIO_MODER_MODER6_1;
//		
//		GPIOA->MODER&=~GPIO_MODER_MODER15_0;//Select the Mode of PB0 to General Purpose Input
//		GPIOA->MODER&=~GPIO_MODER_MODER15_1;

			GPIOA->MODER =(GPIOA->MODER & ~(GPIO_MODER_MODER7)) | GPIO_MODER_MODER7_1;// Alternate mode selected for PA7 for I2C3
			GPIOA->AFR[0]|=GPIO_AFRL_AFSEL7_2;// Alternate mode selected for PA7 for I2C3
			
}

void config_GPIOB(void)
{
	
		GPIOB->MODER&=~GPIO_MODER_MODER0_0;//Select the Mode of PB0 to General Purpose Output
		GPIOB->MODER&=~GPIO_MODER_MODER0_1;//Select the Mode of PB0 to General Purpose Output
	
		GPIOB->MODER|= GPIO_MODER_MODER7_0;//Select the Mode of PB7 to General Purpose Output
		GPIOB->MODER&=~GPIO_MODER_MODER7_1;//Select the Mode of PB7 to General Purpose Output
	
		GPIOB->MODER|= GPIO_MODER_MODER11_0;//Select the Mode of PB7 to General Purpose Output
		GPIOB->MODER&=~GPIO_MODER_MODER11_1;//Select the Mode of PB7 to General Purpose Output
	
		GPIOB->MODER =(GPIOB->MODER & ~(GPIO_MODER_MODER5 )) | GPIO_MODER_MODER5_1 ;// Alternate mode selection for SPI1
		GPIOB->AFR[0]|=GPIO_AFRL_AFSEL5_0 | GPIO_AFRL_AFSEL5_2;//Alternate Function AF1 select for B15
//		GPIOB->MODER =(GPIOB->MODER & ~(GPIO_MODER_MODER11 | GPIO_MODER_MODER10)) | GPIO_MODER_MODER11_1 | GPIO_MODER_MODER10_1;// Aternate funtion selected for I2C2 Peripheral
//		GPIOB->AFR[1]|=GPIO_AFRH_AFSEL11_2;//Alternate Function AF1 select for B11
//		GPIOB->AFR[1]|=GPIO_AFRH_AFSEL10_2;//Alternate Function AF1 select for B10
		
	
		GPIOB->MODER =(GPIOB->MODER & ~(GPIO_MODER_MODER4)) | GPIO_MODER_MODER4_1;//Alternate mode selected for PB4 for I2C3
		GPIOB->AFR[0]|=GPIO_AFRL_AFSEL4_2;//Alternate mode selected for PB4 for I2C3
			
}


//void config_GPIOC(void)
//{
//		GPIOC->MODER=(GPIOC->MODER|(1U<<16)|(1<<18));
//		GPIOC->OTYPER=(GPIOC->OTYPER&(~(1<<8U)|(1<<9)));
//		
//		GPIOC->MODER =(GPIOC->MODER & ~(GPIO_MODER_MODER1 | GPIO_MODER_MODER0)) | GPIO_MODER_MODER1_1 | GPIO_MODER_MODER0_1;// Aternate funtion selected for I2C3 Peripheral
//		GPIOC->AFR[0]|=GPIO_AFRL_AFSEL1_2;//Alternate Function AF4 select for C1-SDA
//		GPIOC->AFR[0]|=GPIO_AFRL_AFSEL0_2;//Alternate Function AF4 select for C0-SCL
//}
