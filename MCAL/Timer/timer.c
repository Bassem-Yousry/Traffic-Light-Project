/*
 * timer.c
 *
 * Created: 1/10/2023 1:20:40 AM
 *  Author: amrba
 */ 
#include "timer.h"
#include "..\..\BIT_MATH.h"
#include "..\..\STD_TYPES.h"
#include "..\..\Registers.h"
void Timer_Init(){
		/*	Function skeleton 
		set the timer to normal mode
	*/
	#if TimerMode==NormalMode
		TCCR0=0;
    #endif	
}
void Timer_Start(){
		/*	Function skeleton 
			1-clear timer
			2-start timer
		*/
	TCNT0=0;
	TCCR0=1;
}
void Timer_DelayIn_ms(u16 Copy_u16Value){		
		/*	Function skeleton 
			1-calculate num of overflows needed
			2-calculate num of remaining ticks needed
			3-Loop till num of overflows reached
			4-wait for the remaining ticks
		*/
	u32 OFNum=0;u8 RemainingTicks=0;
	RemainingTicks=(Copy_u16Value*1000)%256;
	OFNum=((u32)Copy_u16Value*1000);
	OFNum/=256;	//num of overflows in us
	while (OFNum)
	{
		while(!GET_BIT(TIFR,0));
		TIFR=1;
		OFNum--;
	}
	TCNT0=256-RemainingTicks;
	while(!GET_BIT(TIFR,0));
	TIFR=1;
}
void Timer_Stop(){
	/*
	clear pin0 in TCCR0
	*/
	TCCR0=0;
}

u8 Timer_Test(){
	/*
	-initiate timer
	-start the the timer
	-wait for 1 ms
	-disable timer
	*/
	Timer_Init();
	Timer_Start();
	Timer_DelayIn_ms(1);
	Timer_Stop();
	return 0;
}