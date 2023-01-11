/*
 * Registers.h
 *
 * Created: 1/9/2023 3:46:29 PM
 *  Author: amrba
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PORTA   *((volatile u8*)0x3B)
#define DDRA    *((volatile u8*)0x3A)
#define PINA    *((volatile u8*)0x39)
#define PORTB   *((volatile u8*)0x38)
#define DDRB    *((volatile u8*)0x37)
#define PINB    *((volatile u8*)0x36)
#define PORTC   *((volatile u8*)0x35)
#define DDRC    *((volatile u8*)0x34)
#define PINC    *((volatile u8*)0x33)
#define PORTD   *((volatile u8*)0x32)
#define DDRD	*((volatile u8*)0x31)
#define PIND    *((volatile u8*)0x30)
			/* Timer*/
#define OCR0    *((volatile u8*)0x5C)  
#define TCCR0   *((volatile u8*)0x53) 
#define TCNT0   *((volatile u8*)0x52) 
#define TIMSK   *((volatile u8*)0x59) 
#define TIFR    *((volatile u8*)0x58) 
/*	Int0	*/
#define MCUCR  *((volatile u8*)0x55)
#define GICR   *((volatile u8*)0x5B)  
#define GIFR   *((volatile u8*)0x5A) 





#endif /* REGISTERS_H_ */