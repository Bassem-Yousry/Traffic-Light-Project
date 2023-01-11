/*
 * App.c
 *
 * Created: 1/10/2023 4:59:51 AM
 *  Author: amrba
 */ 
#include "..\..\MCAL\GPIO\GPIO.h"
#include "..\..\MCAL\Timer\timer.h"
#include "..\..\MCAL\Interrupt\interrupt.h"
#include "..\..\HAL\BUTTON\button.h"
#include "..\..\HAL\LED\LED.h"
#include "..\..\STD_TYPES.h"

u8 PedestrianMode=0;
u8 NextState=0;
u8 CurrentState=0;
u8 IncrementFlag=1;
ISR(INT0_vect){
	/*Function Skeleton
	1-if the pedestrian green on exit pedestrian mode
	2-wait for a small time interval
	3-if the button is still pressed exit pedestrian mode
	4-turn off all LEDs
	5-if the pedestrian's red on move to yellow state.
	6-if the yellow LEDs are on blink them for 5 seconds then move to next state (Pgreen on Cred on)
	7-exit pedestrian mode
	*/
	u8 ButtonState;
	if (CurrentState==2||PedestrianMode) //User story 3 the pedestrian's green is on OR user story 5 :disable double press user story 5
	{
		INT0_ClearInt();
		return;	//do nothing
	}
	_disableInt();	
	Timer_DelayIn_ms(200);
	BUTTON_GetState(ButtonPin,&ButtonState);
	if (ButtonState)
	{
		INT0_ClearInt();
		_enableInt();
		return; //do nothing in long press . user story 4
	}
	DIO_ClearPort(PortA);
	DIO_ClearPort(PortB);
	PedestrianMode=1;
	Timer_Start();
	while(1){
	switch(CurrentState){
		case 0:
			NextState=1;
			CurrentState=NextState;
			break;
		case 1:
			NextState=2;
			for(int i=0;i<5;i++){
				LED_TOG(PortA,1);
				LED_TOG(PortB,1);
				Timer_DelayIn_ms(1000);
			}
			LED_OFF(PortA,1);
			LED_OFF(PortB,1);
			CurrentState=NextState;
			break;
		case 2:
			NextState=1;
			LED_ON(PortB,0);
			LED_ON(PortA,2);
			Timer_DelayIn_ms(5000);
			LED_OFF(PortA,2);
			LED_OFF(PortB,0);
			IncrementFlag=0;
			CurrentState=NextState;
			LED_ON(PortA,1);
			LED_ON(PortB,1);
			INT0_ClearInt();
			_enableInt();
			return;
			break;
		
	}	
	}
}

void App_Init(){
	/*Function Skeleton
	1-initiate the timer and start counting
	2-initiate pin2 portD as input for the button
	3-initiate PortA 0,1,2 for car traffic light
	4-initiate PortB 0,1,2 for pedestrian traffic light
	5-enable interrupt
	6-set INT0 sense to RisingEdge
	*/
	Timer_Init();
	Timer_Start();
	
	BUTTON_Init(ButtonPin);
		/* car*/
	LED_Init(PortA,0);//green
	LED_Init(PortA,1);//yellow
	LED_Init(PortA,2);//red
		/*pedestrian*/
	LED_Init(PortB,0);//green
	LED_Init(PortB,1);//yellow
	LED_Init(PortB,2);//red
	
	_enableInt();
	INT0_Init(RisingEdge);	
}

void App_Start(){
	/*Function Skeleton
	1-start with car's green and pedestrian on
	2-wait for a time interval
	3-move to the next state
	*/
	while (1)
	{
		switch(CurrentState){		
			case 0:					
				NextState=1;IncrementFlag=1;
				LED_ON(PortA,0);
				LED_ON(PortB,2);
				if (PedestrianMode)
				{
					DIO_ClearPort(PortA);
					DIO_ClearPort(PortB);
					PedestrianMode=0;IncrementFlag=0;
					continue;
				} 
				Timer_DelayIn_ms(5000);
				LED_OFF(PortA,0);
				LED_OFF(PortB,2);
				CurrentState=NextState;
				break;
			case 1:
				(IncrementFlag)?(NextState=2) : (NextState=0);
				for(int i=0;i<5;i++){
					LED_TOG(PortA,1);
					LED_TOG(PortB,1);
					Timer_DelayIn_ms(1000);
				}
				LED_OFF(PortA,1);
				LED_OFF(PortB,1);
				CurrentState=NextState;
				break;
			case 2:
				NextState=1;
				LED_ON(PortA,2);
				LED_ON(PortB,0);
				if (PedestrianMode)
				{
					DIO_ClearPort(PortA);
					DIO_ClearPort(PortB);
					PedestrianMode=0;IncrementFlag=0;
					continue;
 				}
				Timer_DelayIn_ms(5000);
				LED_OFF(PortA,2);
 				LED_OFF(PortB,0);				
				CurrentState=NextState;IncrementFlag=0;
				break;
		}		
		}
		
	}