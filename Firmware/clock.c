#include <stm32l452xx.h>
#include "clock.h"

void config_clock(void)
{
	/*1  Set the flash latency to 4 wait state waits, otherwise the systick timer will not work. Latency must be set before the clocks are modified,
			 if the clock speed is set too fast, the cpu fails too modify any latency configurations. 
	 *2  Turn on the HSE and clock startup Security.
	 *3  Wait in the loop untill the HSE is ready
	 *4  Turn the main PLL off make changes in the configuration
	 *5  Wait for the PLL to turn off
	 *6  Select HSE as input clock for the PLL and Select PLLN VCO driver is multiplied 8. 
			 ******Caution******All the Bits of PLLN have to be explicitly SET and Reset in order to change the PLLN register. The PLLN Multipler bits are some how saved.   
	 *7  Enable the PLLN
	 *8  Turn the PLL on after configuration
	 *9  Wait untill the PLL is ON
	 *10 Switch the System Clock to PLL Clock Output
	 *11 Enable the clock for PORTA
	*/
	
	
	FLASH->ACR|=FLASH_ACR_LATENCY_1WS;       //*1
	
	RCC->CR |= (RCC_CR_CSSON | RCC_CR_HSEON);//|RCC_CR_HSEBYP);//*2 Turn on the HSE and clock startup Security
	while(1)																 //*3 Wait in the loop untill the HSE is ready
	{
		if((RCC->CR & RCC_CR_HSERDY) != 0)
		{
			break;
		}
	}
	
	RCC->CR&=~(RCC_CR_PLLON);								//*4
	while(1)                                //*5 
	{
		if((RCC->CR & RCC_CR_PLLRDY) == 0)    
		{
			break;
		}		
	}	
	RCC->PLLCFGR|=(RCC_PLLCFGR_PLLSRC_HSE|RCC_PLLCFGR_PLLN_3);//|RCC_PLLCFGR_PLLN_4);//*6
	RCC->PLLCFGR&=~(RCC_PLLCFGR_PLLN_1);//*6 ***Caution
	RCC->PLLCFGR&=~(RCC_PLLCFGR_PLLN_2);//*6 ***Caution
	RCC->PLLCFGR&=~(RCC_PLLCFGR_PLLN_4);//*6 ***Caution
	RCC->PLLCFGR|=(RCC_PLLCFGR_PLLREN);     //*7
	
	RCC->CR|=RCC_CR_PLLON;									//*8
		while(1)															//*9			
	{
		if((RCC->CR & RCC_CR_PLLRDY) != 0)
		{
			RCC->CFGR |=(RCC_CFGR_SW_1 | RCC_CFGR_SW_0);//*10
			break;
		}
	}
	
	while((RCC->CFGR & RCC_CFGR_SWS)!=RCC_CFGR_SWS_PLL)
	{
	}
	
	//*********************Configuration of LSE Clock for RTC*************************************//
	RCC->BDCR|=(RCC_BDCR_BDRST);//Reset the Backup domain registers
	RCC->BDCR&=~(RCC_BDCR_BDRST);// NOT-reset the Backup domain register reset bit//check the reference manual 
	RCC->APB1ENR1|=(RCC_APB1ENR1_PWREN);//Clock enabled for Power Interface peripheral
	PWR->CR1|=(PWR_CR1_DBP);//Disable Backup domain protection
	RCC->BDCR|=(RCC_BDCR_LSEON);// Enable the LSE Clock
	
	while(1) // Wait for the the LSE clock to get stabalized																	
	{
		if((RCC->BDCR & RCC_BDCR_LSERDY) != 0)
		{
			break;
		}
	}
	
	RCC->BDCR|=(1<<8);// LSE selected as RTC Clock
	RCC->BDCR|=(RCC_BDCR_RTCEN);// Enable the RTC prepheral
	//***********************************************************************************************//
	
		RCC->AHB2ENR|=RCC_AHB2ENR_GPIOAEN;    //*11
		RCC->AHB2ENR|=RCC_AHB2ENR_GPIOBEN;
	//RCC->AHB2ENR|=RCC_AHB2ENR_GPIOCEN;//12
		RCC->APB2ENR|=(RCC_APB2ENR_SPI1EN);//Enable APB2 clock for SPI
		RCC->APB2ENR|=(RCC_APB2ENR_USART1EN);//Enable APB2 clock for UART1
		RCC->APB1ENR1|=RCC_APB1ENR1_I2C3EN;//Enable APB1 Clock for I2C3 
		RCC->APB1ENR1|=RCC_APB1ENR1_TIM6EN;//Enable clock for TIMER6
		RCC->APB2ENR|=RCC_APB2ENR_SYSCFGEN;//Enable the System Config Controller clock : Essential for configuring Interuppt input for the EXTI lines
	
			
}
