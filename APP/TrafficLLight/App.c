/*
 * App.c
 *
 * Created: 1/10/2023 4:59:51 AM
 *  Author: amrba
 */ 
#include "..\..\HAL\BUTTON\button.h"
#include "..\..\HAL\Delay\delay.h"
#include "..\..\HAL\LED\LED.h"
#include "..\..\STD_TYPES.h"

u8 PedestrianMode=0;
u8 NextState=0;
u8 CurrentState=0;
u8 IncrementFlag=1;
void PedestrianModeFunc(){
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
		return;	//do nothing
	}
	_disableInt();	
	Delay_InMs(200);
	BUTTON_GetState(ButtonPin,&ButtonState);
	if (ButtonState)
	{
		_enableInt();
		return; //do nothing in long press . user story 4
	}
	LED_OFF(LED_CarGreen);LED_OFF(LED_CarYellow);LED_OFF(LED_CarRed);
	LED_OFF(LED_PedGreen);LED_OFF(LED_PedYellow);LED_OFF(LED_PedRed);

	PedestrianMode=1;
	Delay_Start();
	while(1){
	switch(CurrentState){
		case 0:
			NextState=1;
			CurrentState=NextState;
			break;
		case 1:
			NextState=2;
			for(int i=0;i<5;i++){
				LED_TOG(LED_CarYellow);
				LED_TOG(LED_PedYellow);
				Delay_InMs(1000);
			}
			LED_OFF(LED_CarYellow);
			LED_OFF(LED_PedYellow);
			CurrentState=NextState;
			break;
		case 2:
			NextState=1;
			LED_ON(LED_PedGreen);
			LED_ON(LED_CarRed);
			Delay_InMs(5000);
			LED_OFF(LED_PedGreen);
			LED_OFF(LED_CarRed);
			IncrementFlag=0;
			CurrentState=NextState;
			LED_ON(LED_PedYellow);
			LED_ON(LED_CarYellow);
			_enableInt();
			return;
			break;
		
	}	
	}
}

u8 App_Init(){
	/*Function Skeleton
	1-initiate the timer and start counting
	2-initiate pin2 portD as input for the button
	3-initiate PortA 0,1,2 for car traffic light
	4-initiate PortB 0,1,2 for pedestrian traffic light
	5-enable interrupt
	6-set INT0 sense to RisingEdge
	*/
	Delay_Start();
	
		/* car*/
	LED_Init(LED_CarGreen );//green
	LED_Init(LED_CarYellow);//yellow
	LED_Init(LED_CarRed	 );//red
		/*pedestrian*/
	LED_Init(LED_PedGreen );//green
	LED_Init(LED_PedYellow);//yellow
	LED_Init(LED_PedRed   );//red

	BUTTON_Init(ButtonPin,1);
	BUTTON_SetHandler(ButtonPin,PedestrianModeFunc);
	_enableInt();
	return 0;
}

u8 App_Start(){
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
				LED_ON(LED_CarGreen);
				LED_ON(LED_PedRed);
				if (PedestrianMode)
				{
					LED_OFF(LED_CarGreen );
					LED_OFF(LED_CarYellow);
					LED_OFF(LED_CarRed	 );
					LED_OFF(LED_PedGreen );
					LED_OFF(LED_PedYellow);
					LED_OFF(LED_PedRed   );
					PedestrianMode=0;IncrementFlag=0;
					continue;
				} 
				Delay_InMs(5000);
				LED_OFF(LED_CarGreen);
				LED_OFF(LED_PedRed);
				CurrentState=NextState;
				break;
			case 1:
				(IncrementFlag)?(NextState=2) : (NextState=0);
				for(int i=0;i<5;i++){
					LED_TOG(LED_CarYellow);
					LED_TOG(LED_PedYellow);
					Delay_InMs(1000);
				}
				LED_OFF(LED_CarYellow);
				LED_OFF(LED_PedYellow);
				CurrentState=NextState;
				break;
			case 2:
				NextState=1;
				LED_ON(LED_PedGreen);
				LED_ON(LED_CarRed  );
				if (PedestrianMode)
				{
					LED_OFF(LED_CarGreen );
					LED_OFF(LED_CarYellow);
					LED_OFF(LED_CarRed	 );
					LED_OFF(LED_PedGreen );
					LED_OFF(LED_PedYellow);
					LED_OFF(LED_PedRed   );
					PedestrianMode=0;IncrementFlag=0;
					continue;
 				}
				Delay_InMs(5000);
				LED_OFF(LED_PedGreen);
				LED_OFF(LED_CarRed  );				
				CurrentState=NextState;IncrementFlag=0;
				break;
		}		
		}
		return 0;
	}