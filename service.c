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

static volatile void (*l_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_callBackPtr_PWM)(void) = NULL_PTR;

uint32 g_var;

ISR(TIMER0_OVF_vect){

	if(*g_callBackPtr != NULL_PTR){
		(*g_callBackPtr)();
	}
}

void wait(void){
	static uint32 counts =0;
	counts++;
	if(counts == g_var){
		counts =0;
		if((*g_callBackPtr != NULL_PTR)){

			(*g_callBackPtr)();
		}
	}
}

void delay(uint32 delay,uint8 timer_type,void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
	l_callBackPtr = wait;
	g_var = delay;
	TCNT0 = 0;
	TCCR0 |= (1<<FOC0);
	TIMSK |= (1<<TOIE0);
}

void PWM_init(void(*a_ptr)(void)){
	g_callBackPtr_PWM = a_ptr;
	TIMSK |= (1<<TOIE0);
}
