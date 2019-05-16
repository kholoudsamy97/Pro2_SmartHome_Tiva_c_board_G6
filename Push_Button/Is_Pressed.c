#include "Button.h"
#include "Dio.h"
#include "Port.h"


Switch_StatusType Is_Pressed(uint8 switch_number)
{
	Switch_StatusType x;
	switch (switch_number)
	{
		case SWITCH_0: 
		{
			if(DIO_ReadPort(SWITCH_0_PORT,SWITCH_0_PIN))
				x = NOT_PRESSED;
			else
				x = PRESSED;
			break;
		}
		case SWITCH_1:
		{
			if(DIO_ReadPort(SWITCH_1_PORT,SWITCH_1_PIN))
			x = NOT_PRESSED;
			else
				x = PRESSED;
			break;
		}
		case SWITCH_2:
		{
			if(DIO_ReadPort(SWITCH_2_PORT,SWITCH_2_PIN))
			x = NOT_PRESSED;
			else
				x = PRESSED;
			break;
		}
	}
	return x;
}
