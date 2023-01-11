/*
 * button.c
 *
 * Created: 1/9/2023 4:56:45 PM
 *  Author: amrba
 */ 

#include "button.h"
#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "..\..\Registers.h"

void BUTTON_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	DIO_Init(Copy_u8PortNumber, Copy_u8PinNumber,INPUT);
}
void BUTTON_GetState(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8* Copy_u8State){
	DIO_Read(Copy_u8PortNumber, Copy_u8PinNumber,Copy_u8State);
}

u8  BUTTON_Test(){
	u8 ButtonState;
	BUTTON_Init(PortC,0);
	BUTTON_GetState(PortC,0,&ButtonState);
	return !(ButtonState ==0 && GET_BIT(DDRC,0)==0);
}