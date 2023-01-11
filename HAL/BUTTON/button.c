/*
 * button.c
 *
 * Created: 1/9/2023 4:56:45 PM
 *  Author: amrba
 */ 

#include "button.h"
#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\MCAL\Interrupt\interrupt.h"
#include "..\..\MCAL\Timer\timer.h"
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "..\..\Registers.h"

u8 BUTTON_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8EnableINT){
	DIO_Init(Copy_u8PortNumber, Copy_u8PinNumber,INPUT);
	if (Copy_u8EnableINT && Copy_u8PortNumber==PortD && Copy_u8PinNumber==2)
	{
		INT0_Init(RisingEdge);
	}
	return 0;
}

u8 BUTTON_SetHandler( u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,void(*HandlerFunc)(void) ){
	if (Copy_u8PortNumber==PortD && Copy_u8PinNumber==2)
	{
		INT0_SetHandler(HandlerFunc);
	}
	else{return 1;}
	return 0;
}


u8 BUTTON_GetState(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8* Copy_u8State){
	DIO_Read(Copy_u8PortNumber, Copy_u8PinNumber,Copy_u8State);
	return 0;
}

u8  BUTTON_Test(){
	u8 ButtonState;
	BUTTON_Init(PortC,0,0);
	BUTTON_GetState(PortC,0,&ButtonState);
	return !(ButtonState ==0 && GET_BIT(DDRC,0)==0);
}