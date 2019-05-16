#ifndef UART_H_
#define UART_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"


void UART_init();
void UART_Write(char DataWrite); //send
char UART_Read(); //recieve



#endif