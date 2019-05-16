 /******************************************************************************
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button driver
 *
 *******************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include"std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/*Switchs number*/
#define SWITCH_0 (2u) 
#define SWITCH_1 (4u) 
#define SWITCH_2 (8u) 

/*switchs ports will be defined in c file*/

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
 
/* Enum for Switch_StatusType */
typedef enum
{
  PRESSED,
	NOT_PRESSED
}Switch_StatusType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Function to check if switch is pressed or not*/

void Switch_init(uint8 Port_index);
Switch_StatusType Is_Pressed(uint8 switch_number);




#endif 
