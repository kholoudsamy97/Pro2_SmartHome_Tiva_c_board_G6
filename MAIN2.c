#include "PLL.h"
#include "delay.h"
#include "adc.h"
#include "motor.h"
#include "temp.h"
#include "UART.h"
#include "LED.h"

#define CLOCKWISE SW1
#define COUNTERCLOCKWISE SW2

void SystemInit(void)
{
		PLL_Init();

		Motor_init();
	  ADC0_Init();
		UART_init();
	``BlueLED_Init();
		return;
}

int __main(void)
{
	uint8 motorStatus = 0;
	uint16 potReading = 0;
	uint8 tempReading =0;
	
	while(1)
	{
		motorStatus = UART_inChar();
		if(motorStatus == 'L' || motorStatus == 'R')
		{
			Motor_rotate(motorStatus);
		}
		potReading = UART_inChar();
		potReading |= ((UART_inChar()) << 8 );
		BlueLED_SetDutyCycle(potReading);
		tempReading = (uint8)Temperature_sensor();
		UART_outChar(tempReading);

	}
	}
	