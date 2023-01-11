/*
 * GPIO.h
 *
 * Created: 1/9/2023 3:25:06 PM
 *  Author:bassem
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "..\..\STD_TYPES.h"

#define PortA 0 
#define PortB 1
#define PortC 2
#define PortD 3

#define INPUT 0
#define OUTPUT 1

void DIO_Init(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Direction);
void DIO_Write(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8Value);
void DIO_Read(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8* Copy_u8ReturnValue);
void DIO_Toggle(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void DIO_ClearPort(u8 Copy_u8PortNumber);

u8 DIO_Test();
#endif /* GPIO_H_ */