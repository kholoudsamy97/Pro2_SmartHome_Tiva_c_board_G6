#include "motor.h"
#include "Port.h"

#define PIN_1 0u
#define PIN_2 1u
#define PIN_3 2u
#define PIN_4 3u
#define Motor_Port 'A'

void Motor_init(void)
{
	
	Port_init(Motor_Port, PIN_1 | PIN_2 | PIN_3 | PIN_4 );
	Port_SetPinDirection(Motor_Port, PIN_1|PIN_2|PIN_3|PIN_4, PORT_PIN_OUT);
	
}
