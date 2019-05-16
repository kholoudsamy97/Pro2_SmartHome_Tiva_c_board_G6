 /******************************************************************************
 * Service: Port_init
 *
 * File Name: Port_init.h
 *
 * Description: Source code of Port_init service4
 * 
 *
 *******************************************************************************/

#include"Port.h"


/*********************************************************************************** 
* Service Name: Port_init
* Parameters (in): port_index - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize port.
************************************************************************************/


uint8 delay ; 


void Port_init(uint8 port_index,uint8 pins_mask)
{
			 SYSCTL_RCGC2_R |= port_index;
			 delay = SYSCTL_RCGC2_R;
			 delay++;
			 delay++;
			switch(port_index)
			{
				case PORT_A:
				{
					GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTA_CR_R |= pins_mask; 
					GPIO_PORTA_AMSEL_R &= ~(pins_mask); 
					GPIO_PORTA_PCTL_R = 0x00000000;
					GPIO_PORTA_AFSEL_R &= ~(pins_mask); 
					GPIO_PORTA_DEN_R |= pins_mask;    
					break;
				}
					
				case PORT_B:
				{
					GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTB_CR_R |= pins_mask; 
					GPIO_PORTB_AMSEL_R &= ~(pins_mask); 
					GPIO_PORTB_PCTL_R = 0x00000000; 
					GPIO_PORTB_AFSEL_R &= ~(pins_mask); 
					GPIO_PORTB_DEN_R = pins_mask;    

					break;
				}
				case PORT_C:
				{
					GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTC_CR_R |= pins_mask; 
					GPIO_PORTC_AMSEL_R &= ~(pins_mask); 
					GPIO_PORTC_PCTL_R = 0x00000000;
					GPIO_PORTC_AFSEL_R &= ~(pins_mask); 
					GPIO_PORTC_DEN_R = pins_mask;    
					break;
				}
				case PORT_D:
				{
					GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTD_CR_R |= pins_mask; 
					GPIO_PORTD_AMSEL_R &= ~(pins_mask); 
					GPIO_PORTD_PCTL_R = 0x00000000;
					GPIO_PORTD_AFSEL_R &= ~(pins_mask); 
					GPIO_PORTD_DEN_R = pins_mask;    
					break;
				}
				case PORT_E:
				{
					GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTE_CR_R |= pins_mask; 
					GPIO_PORTE_AMSEL_R &= ~(pins_mask);
					GPIO_PORTE_PCTL_R = 0x00000000;
					GPIO_PORTE_AFSEL_R &= ~(pins_mask); 					
					GPIO_PORTE_DEN_R = pins_mask;    	
					break;
				}
				case PORT_F:
				{
					GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
					GPIO_PORTF_CR_R |= pins_mask; 
					GPIO_PORTF_AMSEL_R &= ~(pins_mask); 
					GPIO_PORTF_PCTL_R = 0x00000000;
					GPIO_PORTF_AFSEL_R &= ~(pins_mask);
					GPIO_PORTF_DEN_R = pins_mask;    					
					break;
				}
				
			}
			 
			 
}
