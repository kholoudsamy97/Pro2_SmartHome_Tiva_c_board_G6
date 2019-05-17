#include "motor.h"
#include "Port.h"
#include "Dio.h"

#define PIN_1 0u
#define PIN_2 1u
#define PIN_3 2u
#define PIN_4 3u
#define STEPANGLE (7.5f)
#define PINMASK (PIN_1 | PIN_2 | PIN_3 | PIN_4) // wrong
#define Motor_Port 'A'
#define FULL_WAVE_STEPS 4

void Motor_rotate(uint8 direction)
{
	unsigned char motor_steps[FULL_WAVE_STEPS] = {12,6,3,9};
	switch(direction)
	{
		case 'L':
		{
			for(int j=0; j < (int) (30.0 / STEPANGLE) ; j++)
			{
				for(int i=3; i >= 0; i--)
				{
						DIO_WritePort(Motor_Port, ~ motor_steps[i] ,LOW);
						DIO_WritePort(Motor_Port,motor_steps[i],HIGH);
				}
		 }
		}
		break;
		
		case 'R':
		{
			for(int j=0; j < (int) (30.0 / STEPANGLE) ; j++)
			{
				for(int i=0; i <= FULL_WAVE_STEPS; i++)
				{
						DIO_WritePort(Motor_Port, ~ motor_steps[i] ,LOW);
						DIO_WritePort(Motor_Port,motor_steps[i],HIGH);
				}
		 }
		}
		break;
		
	}
}
