#include "Port.h"

void Port_SetPinDirection(uint8 port_index, uint8 pins_mask, Port_PinDirectionType pins_direction)
{
	if(pins_direction == PORT_PIN_IN)
	{
		if(port_index == PORT_A)
			GPIO_PORTA_DIR_R &= ~(pins_mask);
		else if(port_index == PORT_B)
			GPIO_PORTB_DIR_R &= ~(pins_mask);
		else if(port_index == PORT_C)
			GPIO_PORTC_DIR_R &= ~(pins_mask);
		else if(port_index == PORT_D)
			GPIO_PORTD_DIR_R &= ~(pins_mask);
		else if(port_index == PORT_E)
			GPIO_PORTE_DIR_R &= ~(pins_mask);
		else if(port_index == PORT_F)
			GPIO_PORTF_DIR_R &= ~(pins_mask);
	}
	else if(pins_direction == PORT_PIN_OUT)
	{
		if(port_index == PORT_A)
			GPIO_PORTA_DIR_R |= pins_mask;
		else if(port_index == PORT_B)
			GPIO_PORTB_DIR_R |= pins_mask;
		else if(port_index == PORT_C)
			GPIO_PORTC_DIR_R |= pins_mask;
		else if(port_index == PORT_D)
			GPIO_PORTD_DIR_R |= pins_mask;
		else if(port_index == PORT_E)
			GPIO_PORTE_DIR_R |= pins_mask;
		else if(port_index == PORT_F)
			GPIO_PORTF_DIR_R |= pins_mask;
	}
}
