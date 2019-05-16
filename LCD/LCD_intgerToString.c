#include "lcd.h"
#include "Dio.h"
#include "Port.h"
#include "delay.h"
#include "std_types.h"

/*******************************************************************************
 *                      Function Definition                                  *
 *******************************************************************************/
void LCD_intgerToString(uint32 data)
{
  uint8 buff[16]; /* String to hold the ascii result */
	uint8 i;
	 for(i=0; i<3; i++)
	{	
		buff[2-i] = (data %10) + 48;
		data = data /10;
	}
	buff[i] = '\0';
	
				
   LCD_displayString(buff);
}

