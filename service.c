/******************************************************************************
 *
 * Module: Service Layer Source
 *
 * File Name: service.c
 *
 * Description: Source file of service layer.
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "service.h"
#include <avr/interrupt.h>

static volatile void (*l_callBackPtr)(void) = NULL_PTR;//Call function for local function
static volatile void (*g_callBackPtr)(void) = NULL_PTR;//Call back function to application
static volatile void (*g_callBackPtr_PWM)(void) = NULL_PTR;//Call back function to application

uint32 g_var;//global variable acts as a flag indicator for call back function

/*
 * ISR function for TIMER2 COMPARE mode
 */
ISR(TIMER2_COMP_vect){

	/*
	 * Checking for pointer has the address
	 */
	if(*g_callBackPtr != NULL_PTR){

		(*g_callBackPtr)();

	}
}

/*
 * ISR function for TIMER2 NORMAL mode OverFlow
 */
ISR(TIMER2_OVF_vect){

	/*
	 * Checking for pointer has the address
	 */
	if(*g_callBackPtr != NULL_PTR){

		(*g_callBackPtr)();

	}
}

/*
 * ISR function for TIMER0 COMPARE mode
 */
ISR(TIMER0_COMP_vect){

	/*
	 * Checking for pointer has the address
	 */
	if(*g_callBackPtr != NULL_PTR){

		(*g_callBackPtr)();

	}
}

/*
 * ISR function for TIMER0 NORMAL mode OverFlow
 */
ISR(TIMER0_OVF_vect){

	/*
	 * Checking for pointer has the address
	 */
	if(*g_callBackPtr != NULL_PTR){

		(*g_callBackPtr)();

	}
}

/*
 * Call back function to API returning void and getting void
 */
void wait(void){

	static uint32 counts =0;

	counts++;

	if(counts == g_var){

		counts =0;

		/*
		 * Checking for pointer has the address
		 */
		if((*g_callBackPtr != NULL_PTR)){

			(*g_callBackPtr)();

		}
	}
}

/*
 * Delay function of TIMER0 Normal Mode non_PWM getting
 * delay in seconds and timer type and the address of the application function
 */
void delay(uint32 delay,uint8 timer_type,void(*a_ptr)(void)){

	g_callBackPtr = a_ptr;
	//putting local pointer into global pointer
	l_callBackPtr = wait;

	g_var = delay;//putting local variable into global variable

	TCNT0 = 0;

	TCCR0 |= (1<<FOC0);

	TIMSK |= (1<<TOIE0);

}

/*
 * PWM_initialization function getting address of application function returning void
 */
void PWM_init(void(*a_ptr)(void)){

	//putting local pointer into global pointer
	g_callBackPtr_PWM = a_ptr;

	TIMSK |= (1<<TOIE0);

}
