#include "UART.h"


void UART_Write(char DataWrite) //send
{
  while ((UART0_FR_R & 0x00000020) != 0){}
	UART0_DR_R = DataWrite;
}

