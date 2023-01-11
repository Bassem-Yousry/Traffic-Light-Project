/************************************************************************************************************************/
/* Author	: Bassem																									*/
/* Date		: 17 Aug 2020																								*/
/* Version	: V01																										*/	
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT )					VAR |=  (1 << (BIT) )
#define CLR_BIT(VAR,BIT )					VAR &= ~(1 << (BIT) )
#define GET_BIT(VAR,BIT )				    ( (VAR >> BIT) & 1 )
#define TOG_BIT(VAR,BIT )					VAR ^=  (1 << (BIT) )

/* CLEAR BYTE FIRST BEFORE SETTING */ 
#define SET_BYTE(VAR,BYTE,VALUE )			VAR |=  ((VALUE) << (BYTE)*8 )
#define CLR_BYTE(VAR,BYTE )					VAR &= ~(0xFF << (BYTE)*8 )
#define GET_BYTE(VAR,BYTE )				    ( (VAR >> (BYTE)*8) & 0xFF )
#define TOG_BYTE(VAR,BYTE )					VAR ^=  (0xFF << (BYTE)*8 )

#define SET_4BIT(VAR,INDEX,VALUE )			VAR |=  ((VALUE) << (INDEX)*4 )
#define CLR_4BIT(VAR,INDEX )				VAR &= ~(0xF << (INDEX)*4 )
#define GET_4BIT(VAR,INDEX )				( (VAR >> (INDEX)*4) & 0xF )
#define TOG_4BIT(VAR,INDEX )				VAR ^=  (0xF << (INDEX)*4 )

#define SET_2BIT(VAR,INDEX,VALUE )			VAR |=  (VALUE << (INDEX)*2 )
#define CLR_2BIT(VAR,INDEX )				VAR &= ~(3 << (INDEX)*2 )
#define GET_2BIT(VAR,INDEX )				( (VAR >> (INDEX)*2) & 3 )
#define TOG_2BIT(VAR,INDEX )				VAR ^=  (3 << (INDEX)*2 )

#define SET_VALUE(VAR,OFFSET,VALUE)			VAR |= ((VALUE) << (OFFSET))

#endif