/*
 * GPIO.c
 *
 * Created: 1/9/2023 3:39:41 PM
 *  Author: amrba
 */ 
#include "GPIO.h"
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "..\..\Registers.h"
void DIO_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Direction){
	/*	Function skeleton 
		1-check Port number first
		2-Then check Direction (Input or Output)
		3-set Pin direction through DDR 
	*/
	switch (Copy_u8PortNumber){
		case PortA: 
			if (Copy_u8Direction==OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNumber);
			} 
			else
			{
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			break;
		case PortB:
			if (Copy_u8Direction==OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRB,Copy_u8PinNumber);
			}
			break;
		case PortC:
			if (Copy_u8Direction==OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNumber);
			}
			else
			{
				CLR_BIT(DDRC,Copy_u8PinNumber);
			}
			break;
		case PortD:
		if (Copy_u8Direction==OUTPUT)
		{
			SET_BIT(DDRD,Copy_u8PinNumber);
		}
		else
		{
			CLR_BIT(DDRD,Copy_u8PinNumber);
		}
		break;
	}
	
	
}
void DIO_Write(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Value){
		/*	Function skeleton
		 
			1-check Port number first
			2-Then check the Value 
			3-set or clear the Pin  through PORTn Register 
		*/
	switch (Copy_u8PortNumber){
		case PortA:
		if (Copy_u8Value==1)
		{
			SET_BIT(PORTA,Copy_u8PinNumber);
		}
		else
		{
			CLR_BIT(PORTA,Copy_u8PinNumber);
		}
		break;
		case PortB:
		if (Copy_u8Value==1)
		{
			SET_BIT(PORTB,Copy_u8PinNumber);
		}
		else
		{
			CLR_BIT(PORTB,Copy_u8PinNumber);
		}
		break;
		case PortC:
		if (Copy_u8Value==1)
		{
			SET_BIT(PORTC,Copy_u8PinNumber);
		}
		else
		{
			CLR_BIT(PORTC,Copy_u8PinNumber);
		}
		break;
		case PortD:
		if (Copy_u8Value==1)
		{
			SET_BIT(PORTD,Copy_u8PinNumber);
		}
		else
		{
			CLR_BIT(PORTD,Copy_u8PinNumber);
		}
		break;
	}
	
}
void DIO_Read(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8* Copy_u8ReturnValue){
		/*	Function skeleton 
		1-check Port number first
		2-assign pin value to the ReturnValue pointer
	*/
	switch (Copy_u8PortNumber){
		case PortA:
			 (*Copy_u8ReturnValue=GET_BIT(PINA,Copy_u8PinNumber));
			break;
		case PortB:
			(*Copy_u8ReturnValue=GET_BIT(PINB,Copy_u8PinNumber));
			break;
		case PortC:
			(*Copy_u8ReturnValue=GET_BIT(PINC,Copy_u8PinNumber));
			break;
		case PortD:
			(*Copy_u8ReturnValue=GET_BIT(PIND,Copy_u8PinNumber));
			break;
	}
}
void DIO_Toggle(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
		/*	Function skeleton 
		1-check Port number first
		2-toggle Pin through PORTn register 
	*/
	switch (Copy_u8PortNumber){
		case PortA:
		   TOG_BIT(PORTA,Copy_u8PinNumber);
		break;
		case PortB:
			TOG_BIT(PORTB,Copy_u8PinNumber);
		break;
		case PortC:
			TOG_BIT(PORTC,Copy_u8PinNumber);
		break;
		case PortD:
			TOG_BIT(PORTD,Copy_u8PinNumber);
		break;
	}
	
}
void DIO_ClearPort(u8 Copy_u8PortNumber){
		/*	Function skeleton 
		1-check Port number first
		2-clear the whole port data (set to 0) 
	*/
	switch (Copy_u8PortNumber){
		case PortA:
		PORTA=0;
		break;
		case PortB:
		PORTB=0;
		break;
		case PortC:
		PORTC=0;
		break;
		case PortD:
		PORTD=0;
		break;
	}
	
}
u8 DIO_Test(){
	/*
	1-initiate portA pin0 output PortA pin 1 input and check the DDRA register
	2-Set PortB pin 0 , clear pin 1 and toggle pin 2 then check PORTB register
	3-if any error occurred return 1 else return 0
	*/
	u8 PB0,PB1,PB2;
	DIO_Init(PortA,0,OUTPUT);
	DIO_Init(PortA,1,INPUT);
	if (!(GET_BIT(DDRA,0)==1 && GET_BIT(DDRA,1)==0)){return 1;}
	DIO_Init(PortB,0,OUTPUT);DIO_Init(PortB,1,OUTPUT);DIO_Init(PortB,2,OUTPUT);
	DIO_Write(PortB,0,1);DIO_Write(PortB,1,0);DIO_Toggle(PortB,2);
	DIO_Read(PortB,0,&PB0);DIO_Read(PortB,1,&PB1);DIO_Read(PortB,2,&PB2);
	if (!(PB0==1 &&PB1==0&&PB2==1))
	{
		return 1;
	}
	return 0;
}