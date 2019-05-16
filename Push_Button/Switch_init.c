#include "Button.h"
#include "Dio.h"
#include "Port.h"
void Switch_init(uint8 switch_number){
/*
	Port_init(SWITCH_PORT(switch_number),SWITCH_PIN(switch_number));
	Port_SetPinDirection(SWITCH_PORT(switch_number), SWITCH_PIN(switch_number),PORT_PIN_IN);
	Port_SetPinPullUp(SWITCH_PORT(switch_number), SWITCH_PIN(switch_number),1);
	*/
	Port_init(PORT_F,switch_number);
	Port_SetPinDirection(PORT_F, switch_number,PORT_PIN_IN);
	Port_SetPinPullUp(PORT_F,switch_number,1);
	
	
	
	
}
