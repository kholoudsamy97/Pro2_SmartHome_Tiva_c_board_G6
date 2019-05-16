
#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"

/*******************************************************************************
 *                      Function Definition                                  *
 *******************************************************************************/
void LCD_sendCommand(uint8 command)
{
	DIO_WritePort(LCD_CTRL_PORT,E,STD_HIGH); /* Enable LCD E=1 */
	
	DIO_WritePort(LCD_CTRL_PORT,RS,STD_LOW); /* Instruction Mode RS=0 */
	DIO_WritePort(LCD_CTRL_PORT,RW,STD_LOW); /* write data to LCD so RW=0 */
	
	_delay_us(10); /* delay for processing Tas = 50ns */
	//DIO_WritePort(LCD_CTRL_PORT,E,STD_LOW);
	//_delay_us(10);
	//DIO_WritePort(LCD_CTRL_PORT,E,STD_HIGH); /* Enable LCD E=1 */
 /* delay for processing Tpw - Tdws = 190ns */

//(DATA_BITS_MODE == 8)

	DIO_WritePort(LCD_DATA_PORT,command,STD_HIGH);	/* out the required command to the data bus D0 --> D7 for writing bits=1 */
	DIO_WritePort(LCD_DATA_PORT,~command,STD_LOW); /* out the required command to the data bus D0 --> D7 for writing bits=0 */
	_delay_us(10);
	DIO_WritePort(LCD_CTRL_PORT,E,STD_LOW); /* Enable LCD E=1 */
	_delay_ms(50);
}

