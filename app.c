/******************************************************************************
 *
 * Module: API
 *
 * File Name: app.c
 *
 * Description: Main function of project (application layer)
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "seven_segment.h"
#include "icu.h"
#include "timer.h"
#include "dio.h"
#include "service.h"
#include "motor.h"

void App(void){
	// variable acts as a flag for displaying digit incrementing or decrementing
	static uint8 count =0;
	// variable equals the equation calculating one second with prescaler 1
	static uint32 overflow =0;
	// seconds display on 7-segment
	static uint8 digit =0;
	// conition of incrementing
	if(0 == count){
		overflow++;
		if(31000 == overflow){
			++digit;
			if(9 == digit){
				//after 9 seconds
				MOTOR_state();//Motor state
				count =1;
			}
			displayDigit(digit);
			overflow =0;
		}
	}
	// conition of deccrementing
	else if(1 == count){
		overflow++;
		if(31000 == overflow){
			--digit;
			if(0 == digit){
				//after 9 seconds
				MOTOR_state();//Motor state
				count =0;
			}
			displayDigit(digit);
			overflow =0;
		}
	}
	/*
	 * Code for PWM signal (deleted as it has been corrupted but it is once tested
	 * and correctly processing
	 */
	/*DDRA |= (1<<7);
	static uint32 overflow =0;
	static uint8 flag =0;
	overflow++;
	if(0 == flag){
		TCNT0 = 60;
		if(31 == overflow){
			PORTA ^= (1<<7);
			overflow =0;
			TCNT0 = 100;
			flag =1;
		}
	}
	else if(1 ==flag){
		TCNT0 = 240;
		if(31 == overflow){
			PORTA ^= (1<<7);
			overflow =0;
			TCNT0 = 100;
			flag =0;
		}
	}*/
}

int main(void){

	Dio_init();

	Timer_init(TIMER0);

	sei();//enable interrupts in SREG register

	MOTOR_state();//Motor initialization first (forward)

	//PWM_init(App);

	delay(1000,TIMER0,App);

	while(1);

	return 0;
}
