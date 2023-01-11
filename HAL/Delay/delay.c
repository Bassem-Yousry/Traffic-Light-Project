/*
 * delay.c
 *
 * Created: 1/11/2023 11:54:17 PM
 *  Author: amrba
 */ 
#include "delay.h"
#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\STD_TYPES.h"
#include "..\..\BIT_MATH.h"
#include "..\..\MCAL\Timer\timer.h"
#include "..\..\Registers.h"

u8 Delay_Start(){
	Timer_Init();
	Timer_Start();
	return 0;
}
u8 Delay_InMs(u32 Copy_TimeInterval){
	Timer_DelayIn_ms(Copy_TimeInterval);
	return 0;	
}
