 /******************************************************************************
 * Service: LCD_init
 *
 * File Name: LCD_init.c
 *
 * Description: Source code of LCD_init service
 * 
 *
 *******************************************************************************/


#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"

/*********************************************************************************** 
* Service Name: LCD_init
* Parameters (in):None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize LCD.
************************************************************************************/
void LCD_init(void)
{	 
	_delay_ms(50);
	 Port_init(LCD_DATA_PORT,0xFF); 
	 Port_init(LCD_CTRL_PORT,0x07); 
	 Port_SetPinDirection(LCD_DATA_PORT, 0xFF, PORT_PIN_OUT);  /* Configure the data port as output port */ 
	 Port_SetPinDirection( LCD_CTRL_PORT, 0x07, PORT_PIN_OUT);/* Configure the control pins(E,RS,RW) as output pins */
	 LCD_sendCommand(0x0E);
	 LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	 LCD_sendCommand(CURSOR_OFF); /* cursor off */
	 LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
	 LCD_intgerToString(0);

}
