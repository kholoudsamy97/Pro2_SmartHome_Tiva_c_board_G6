#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND);
	//LCD_sendCommand(SET_CURSOR_LOCATION);	//clear display 
	//LCD_goToRowColumn(0,0);
}
