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

void INT0_Init(u8 Copy_u8IntSense){
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
		
	}
	SET_BIT(GICR,6)	;
}
void INT0_ClearInt(){
		/*	Function skeleton 
		clear INT flag
		*/
	SET_BIT(GIFR,6);
}