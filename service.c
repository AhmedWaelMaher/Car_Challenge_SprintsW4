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
uint32 g_var;

ISR(TIMER0_OVF_vect){

	if(*l_callBackPtr != NULL_PTR){
		(*l_callBackPtr)();
	}
}

void wait(void){
	static uint32 counts =0;
	counts++;
	if(counts == g_var){
		DDRB |= (1<<0);
		PORTB ^= (1<<0);
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
	TCNT0 = 131;
	TCCR0 |= (1<<FOC0) | (1<<CS00) | (1<<CS01);
	TIMSK |= (1<<TOIE0);


}

/*
void delay(uint8 id,uint32 delay,void(*a_ptr)(void)){

	g_callBackPtr_T0_NORMAL = a_ptr;
	switch(id){

	case TIMER0 :
		if(Timer_Config_arr[id].ISR_ENABLE== ENABLE_ISR){
			if (Timer_Config_arr[id].Mode==NORMAL_MODE){
				TIMSK|=(1<<TOIE0);
				TIMSK&=~(1<<OCIE0);
			}
			else
			{
				TIMSK &= ~(1<<TOIE0);
				TIMSK |=(1<<OCIE0);
			}

		}
			TCNT0 = 0xB2;  		// Load TCNT0, count for 10ms
			while((TIFR&0x01)==0);  // Wait for TOV0 to roll over
			TCCR0 = 0;
			TIFR = 0x1;
		break;
	case TIMER2 :
		if(Timer_Config_arr[id].ISR_ENABLE== ENABLE_ISR){
			sei();
			if (Timer_Config_arr[id].Mode==NORMAL_MODE){
				TIMSK|=(1<<TOIE0);
				TIMSK&=~(1<<OCIE0);
			}
			else
			{
				TIMSK &= ~(1<<TOIE0);
				TIMSK |=(1<<OCIE0);
			}

			break;
		}
	}
}
 */


/*void start(uint8 id){
	Timer_start(id);
}

void stop(uint8 id){
	Timer_Deinit(id);
}

 */
