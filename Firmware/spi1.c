#include <stm32l452xx.h>
#include "spi1.h"

void config_SPI1(void)
{
	SPI1->CR1=(SPI1->CR1&(~SPI_CR1_BR))|SPI_CR1_BR_2|SPI_CR1_BR_0;//|SPI_CR1_BR_0|
	//SPI1->CR1|=SPI_CR1_LSBFIRST;
	SPI1->CR1|=(SPI_CR1_MSTR|SPI_CR1_CPOL|SPI_CR1_CPHA);//SPI_CR1_LSBFIRST|SPI_CR1_CPHA);
	SPI1->CR2|=(SPI_CR2_SSOE|SPI_CR2_NSSP|SPI_CR2_DS_0|SPI_CR2_DS_1|SPI_CR2_DS_2|SPI_CR2_DS_3);	
}

void spi_wait(void)
{
	while((SPI1->SR & SPI_SR_BSY)!=0)
		{
			
		}
}

void SPI1_enable(void)
{
	SPI1->CR1|=SPI_CR1_SPE;
}

void send_SPI_data(uint32_t data)
{
	
	SPI1->DR=data;
	spi_wait();

}
