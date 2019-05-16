#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"

void LCD_displayCharacter(uint8 data)
{
	
	DIO_WritePort(LCD_CTRL_PORT,E,STD_HIGH); /* Enable LCD E=1 */
	DIO_WritePort(LCD_CTRL_PORT, RS, STD_HIGH); /* Data Mode RS=1 */
	DIO_WritePort(LCD_CTRL_PORT, RW, STD_LOW);  /* write data to LCD so RW=0 */
	_delay_us(10); /* delay for processing Tas = 50ns */

	//DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW); /* disable LCD E=0 */
	//_delay_us(10); /* delay for processing Tpw - Tdws = 190ns */


	//DIO_WritePort(LCD_CTRL_PORT,E,STD_HIGH); 
	DIO_WritePort(LCD_DATA_PORT, data, STD_HIGH);
	DIO_WritePort(LCD_DATA_PORT, ~data, STD_LOW);
	_delay_us(10); /* delay for processing Tpw - Tdws = 190ns */

	DIO_WritePort(LCD_CTRL_PORT, E, STD_LOW); /* Disable LCD E=0 */
	_delay_ms(50); /* delay for processing Tpw - Tdws = 190ns */
}
