/*
 * interrupt.c
 *
 * Created: 1/10/2023 4:05:36 AM
 *  Author: amrba
 */ 
#include "interrupt.h"
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "..\..\Registers.h"
void(*INT0_Handler)(void);
ISR(INT0_vect){
	INT0_Handler();
	INT0_ClearInt();
}
u8 INT0_Init(u8 Copy_u8IntSense){
		/*	Function skeleton 
		set INT0 sense through MCUCR register
		(RisingEdge,FallingEdge or LowLevel)
		Enable  interrupt
	*/
	switch(Copy_u8IntSense){
		case RisingEdge:
			MCUCR=3;
			break;
		case FallingEdge:
			MCUCR=2;
			break;
		case LowLevel:
			MCUCR=0;
			break;
		default: return 1;
	}
	SET_BIT(GICR,6)	;
	return 0;
}

u8 INT0_SetHandler(void(*HandlerFunc)(void)){
	INT0_Handler=HandlerFunc;
	return 0;
}


u8 INT0_ClearInt(){
		/*	Function skeleton 
		clear INT flag
		*/
	SET_BIT(GIFR,6);
	return 0;
}