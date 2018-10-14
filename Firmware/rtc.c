#include <stm32l452xx.h>
#include "rtc.h"

void rmv_rtc_write_protection()
{
	PWR->CR1|=(1<PWR_CR1_DBP);// Backup domain register write protection Disabled
	
	RTC->WPR = 0xCA;//Entering KEY into Write Protection Register
	RTC->WPR = 0x53;//Entering KEY into Write Protection Register
}

void initialise_rtc_clock()
{
	
	rmv_rtc_write_protection();
	RTC->ISR|=RTC_ISR_INIT;//Enering the Initialization mode of the RTC
	
	while(1)//Polling to check if the RTC has enterd the initialization mode
	{
		if((RTC->ISR&RTC_ISR_INITF)!=0)
		{
			break;
		}
	}
	RTC->TR=0x103210;
	//RTC->PRER is already set to the default values to generate 1Hz clock
	
	
	
	RTC->ISR&=~RTC_ISR_INIT;// Exits out of the Initialization mode and starts the RTC counter
	
}
