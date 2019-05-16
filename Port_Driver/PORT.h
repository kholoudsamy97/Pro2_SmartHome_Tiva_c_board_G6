#ifndef PORT_H_
#define PORT_H_

#include "stdint.h"
#include "C:\Keil\EE319Kware\test1\tm4c123gh6pm.h"



#define PORTA 	0x40004000
#define PORTB 	0x40005000
#define PORTC 	0x40006000
#define PORTD 	0x40007000
#define PORTE 	0x40024000
#define PORTF 	0x40025000

#define PORTA_Index		0
#define PORTB_Index		1
#define PORTC_Index		2
#define PORTD_Index		3
#define PORTE_Index		4
#define PORTF_Index		5


typedef enum {
PORT_PIN_IN = 0 
,PORT_PIN_OUT = 1
} Port_PinDirectionType;

void port_Init( uint8_t port_index);
void Port_SetPinDirection( uint8_t port_index, uint8_t pins_mask ,Port_PinDirectionType pins_direction );
void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask , uint8_t enable);
void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask , uint8_t enable);

#endif /*PORT_H_*/ 



