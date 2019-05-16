#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"
void LCD_displayString(const uint8 *Str)
{
	uint8 i = 0;
	while (Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}
