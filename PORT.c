#include "PORT.h"

void port_Init( uint8_t port_index)
{
	
	
	SYSCTL_RCGCGPIO_R	|= 1<<port_index ; // Clock = 000 0001 = PORT_ enable
	while((SYSCTL_PRGPIO_R & (1<<port_index)) == 0);

															//0x40005520
	if( port_index <= 3)
	{
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x40004520)) = 0x4C4F434B;//UNLOCK
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x40004524)) = 0x1F ;//CR
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x4000451C)) = 0x1F;//DEN
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x40004420)) = 0 ;//AFSEL
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x40004528)) = 0 ;//AMSEL_R
		(*(volatile uint32_t *)( (port_index * 0x00001000 ) + 0x4000452C)) = 0 ;//PCTL
	}
	else 
	{                                                 
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x40024520)) = 0x4C4F434B;//UNLOCK
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x40024524)) = 0x1F ;//CR
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x4002451C)) = 0x1F;//DEN
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x40024420)) = 0 ;//AFSEL
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x40024528)) = 0 ;//AMSEL_R
		(*(volatile uint32_t *)( ((port_index-4) * 0x00001000) + 0x4002452C)) = 0 ;//PCTL
	}
}
/////////////////////
void Port_SetPinDirection( uint8_t port_index, uint8_t pins_mask ,Port_PinDirectionType pins_direction )
{
	if( pins_direction == PORT_PIN_OUT)
	{
		if( port_index <=3)
			(*(volatile uint32_t *)		((port_index * 0x00001000)  + 0x40004400)) |= pins_mask  ;//DIR = output
		else 
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024400)) |= pins_mask  ;//DIR = output			
	}
	else
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x40004400)) &= ~pins_mask  ;//DIR = Input 
		else
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024400)) &= ~pins_mask  ;//DIR = output			
	}
}
////////////////////////
void Port_SetPinPullUp(uint8_t port_index, uint8_t pins_mask , uint8_t enable)
{	
	if( enable == 1 )
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x40004510)) |= pins_mask  ;//PUR
		else 
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024510)) |= pins_mask  ;//PUR			
	}
	else
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x40004510)) &= ~pins_mask  ;//PUR 
		else
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024510)) &= ~pins_mask  ;//PUR		
	}
}
///////////////////
void Port_SetPinPullDown(uint8_t port_index, uint8_t pins_mask , uint8_t enable)
{	
	if( enable == 1 )
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x40004514)) |= pins_mask  ;//PUR
		else 
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024514)) |= pins_mask  ;//DIR = output			
	}
	else
	{
		if( port_index <=3)
			(*(volatile uint32_t *)((port_index * 0x00001000) + 0x40004514)) &= ~pins_mask  ;//DIR = Input 
		else
			(*(volatile uint32_t *)(((port_index-4) * 0x00001000) + 0x40024514)) &= ~pins_mask  ;//DIR = output			
	}
}