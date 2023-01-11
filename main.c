/*
 * TrafficLight.c
 *
 * Created: 1/9/2023 3:23:42 PM
 * Author : amrba
 */ 
#include ".\APP\TrafficLLight\App.h"
int main(void)
{
	u8 volatile TimerReturn,DIOReturn,LEDReturn,ButtonReturn;
	/* Test The Drivers */
	TimerReturn=Timer_Test();
	DIOReturn=DIO_Test();
	LEDReturn=LED_Test();
	ButtonReturn=BUTTON_Test();
	//App_Init();
	//App_Start();
    /* Replace with your application code */
    
}

