/*
 * interrupt.h
 *
 * Created: 1/10/2023 4:05:15 AM
 *  Author: amrba
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "..\..\STD_TYPES.h"

/* External Interrupt Request 0 */
#define INT0_vect            __vector_1
/* External Interrupt Request 1 */
#define INT1_vect            __vector_2
/* External Interrupt Request 2 */
#define INT2_vect            __vector_3


#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

#define RisingEdge 0
#define FallingEdge 1
#define LowLevel 2

# define _enableInt()   __asm__ __volatile__ ("sei" ::: "memory")
# define _disableInt()  __asm__ __volatile__ ("cli" ::: "memory")

u8 INT0_Init(u8 Copy_u8IntSense);
u8 INT0_SetHandler(void(*HandlerFunc)(void));
u8 INT0_ClearInt();

#endif /* INTERRUPT_H_ */