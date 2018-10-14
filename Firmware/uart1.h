#ifndef UART1_H_
#define UART1_H_

#include <stdint.h>

void initialise_uart(void);
void send_data_uart(uint8_t data);
void uart_wait(void);
void send_string(char string[],uint8_t size);
uint8_t recieve_data_uart(void);

#endif /*UART_H_*/
