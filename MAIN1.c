#include "PLL.h"
#include "Button.h"
#include "lcd.h"
#include "delay.h"
#include "adc.h"
#include "motor.h"
#include "temp.h"
#include "UART.h"

#define CLOCKWISE SW1
#define COUNTERCLOCKWISE SW2

void SystemInit(void)
{
		PLL_Init();
		Switch_init(CLOCKWISE|COUNTERCLOCKWISE);
		LCD_init();
		Motor_init();
	  ADC0_Init();
		UART_init();
		return;
}

int __main(void)
{
	
	uint8 swStatus =NOT_PRESSED;
	uint8 tempsensor = 0;
	uint16_t data = 0;
	
	
	


	
	while(1)
	{
		
		swStatus =NOT_PRESSED;
		
	 if(Is_Pressed(CLOCKWISE) == PRESSED )
		{
			_delay_ms(20);
			if(Is_Pressed(CLOCKWISE) == PRESSED)
			{
				swStatus = 'R';
			}		
		}
	
		
		else if(Is_Pressed(COUNTERCLOCKWISE) == PRESSED )
		{
			_delay_ms(20);
			if(Is_Pressed(COUNTERCLOCKWISE) == PRESSED)
			{

				swStatus = 'L';
			}		
		}
		UART_outChar(swStatus);
		ADC0_SS3_In(&data);
		UART_outChar(data & (0xFFFF));
		UART_outChar(data >> (8));
	

		
	
	}
}
