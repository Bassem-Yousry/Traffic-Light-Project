/*
 * button.h
 *
 * Created: 1/9/2023 4:56:58 PM
 *  Author: amrba
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "..\..\STD_TYPES.h"

#define ButtonPin	PortD,2
#define ButtonPressed	1
#define ButtonNotPressed	0
u8 BUTTON_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8EnableINT);
u8 BUTTON_SetHandler(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,void(*HandlerFunc)(void));
u8 BUTTON_GetState(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8* Copy_u8State);
u8 BUTTON_Test();

#endif /* BUTTON_H_ */