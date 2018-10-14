#include <stm32l452xx.h>
#include "uart1.h"

void initialise_uart(void)
{
	USART1->BRR = 32000000 / 115200; /* (1) */
	USART1->CR1 = USART_CR1_TE | USART_CR1_RE|USART_CR1_UE|USART_CR1_RXNEIE;
}

void send_data_uart(uint8_t data)
{
	USART1->TDR=data;
	uart_wait();
}

void send_string(char string[],uint8_t size)
{
	int i=0;
	for (i=0;i<size;i++)
	{
		send_data_uart(string[i]);
	}
	
	//send_data_uart(0x0D);
	
}
void uart_wait(void)
{
	while ((USART1->ISR & USART_ISR_TXE)==0)
	{
		
	}
}

uint8_t recieve_data_uart(void)
{
	while((USART1->ISR & USART_ISR_RXNE)==0)
	{
	}
	return  USART1->RDR;
		
}
