#include "PORT.h"

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