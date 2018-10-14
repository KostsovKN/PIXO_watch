#ifndef SPI1_H_
#define SPI1_H_

#include <stdint.h>

void config_SPI1(void);

void spi_wait(void);

void SPI1_enable(void);

void send_SPI_data(uint32_t data);

#endif /*SPI1_H_*/
