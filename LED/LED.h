#ifndef __RGBLED_H__
#define __RGBLED_H__

#include <stdint.h>

#define GPIO_PF2_M	0x04

void BlueLED_Init(void);

void BlueLED_SetDutyCycle(uint16_t data);

#endif // __RGBLED_H__