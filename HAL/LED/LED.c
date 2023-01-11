/*
 * LED.c
 *
 * Created: 1/9/2023 4:26:22 PM
 *  Author: amrba
 */ 

#include "LED.h"
#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\STD_TYPES.h"
#include "..\..\BIT_MATH.h"
#include "..\..\MCAL\Timer\timer.h"
#include "..\..\Registers.h"

void LED_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	DIO_Init(Copy_u8PortNumber,Copy_u8PinNumber,OUTPUT);
}
void LED_OFF(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	DIO_Write(Copy_u8PortNumber,Copy_u8PinNumber,0);
}
void LED_TOG(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	DIO_Toggle(Copy_u8PortNumber,Copy_u8PinNumber);
}
void LED_ON(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	DIO_Write(Copy_u8PortNumber,Copy_u8PinNumber,1);
}

u8 LED_Test(){
	LED_Init(PortA,0);LED_Init(PortA,1);
	LED_ON(PortA,0);LED_OFF(PortA,1);
	return (!(GET_BIT(PORTA,0) && ! GET_BIT(PORTA,1)));
}


