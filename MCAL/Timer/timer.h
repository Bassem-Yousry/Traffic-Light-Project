/*
 * timer.h
 *
 * Created: 1/10/2023 1:20:29 AM
 *  Author: amrba
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "..\..\STD_TYPES.h"

#define TimerMode NormalMode

void Timer_Init();
void Timer_DelayIn_ms(u16 Copy_u16Value);
void Timer_Stop();
void Timer_Start();
u8 Timer_Test();

#endif /* TIMER_H_ */