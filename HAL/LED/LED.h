/*
 * LED.h
 *
 * Created: 1/9/2023 4:25:51 PM
 *  Author: amrba
 */ 


#ifndef LED_H_
#define LED_H_
#include "..\..\STD_TYPES.h"

void LED_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void LED_OFF(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void LED_TOG(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void LED_ON(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
u8 LED_Test();


#endif /* LED_H_ */