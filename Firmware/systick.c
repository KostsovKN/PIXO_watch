#include <stm32l452xx.h>
#include "systick.h"

void config_systick(void)
{
	SysTick->LOAD=0x00FFFFFF;
	SysTick->VAL=0;
	SysTick->CTRL=(SysTick->CTRL|(SysTick_CTRL_ENABLE_Msk)|(SysTick_CTRL_CLKSOURCE_Msk));//|(SysTick_CTRL_TICKINT_Msk));
}

