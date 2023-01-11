/*
 * App.h
 *
 * Created: 1/10/2023 5:00:07 AM
 *  Author: amrba
 */ 


#ifndef APP_H_
#define APP_H_


#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\MCAL\Timer\timer.h"
#include "..\..\MCAL\Interrupt\interrupt.h"
#include "..\..\HAL\BUTTON\button.h"
#include "..\..\HAL\LED\LED.h"
#include "..\..\STD_TYPES.h"



void App_Init();
void App_Start();



#endif /* APP_H_ */