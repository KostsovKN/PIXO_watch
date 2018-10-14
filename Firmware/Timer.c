#include <stm32l452xx.h>
#include "Timer.h"

void setup_timer(void)
{
	
	TIM6->PSC=0xFFFF;//Divide APB CLK by 8000000
	TIM6->ARR=0x5;
	TIM6->CR1|=(TIM_CR1_ARPE);

	TIM6->DIER|=(TIM_DIER_UIE);
	
	TIM6->CR1|=(TIM_CR1_CEN);
		
}
