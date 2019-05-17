
#include "UART_read.h"
char UART_Read() //recieve
{
  while ((UART0_FR_R & 0x0020) != 0){}
	return ( UART0_DR_R & 0xFF); 
}