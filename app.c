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
	static uint8 count =0;
	static uint32 overflow =0;
	static uint8 digit =0;
	if(count == 0){
		overflow++;
		if(31000 == overflow){
			++digit;
			if(digit == 9){
				MOTOR_state();
				count =1;
			}
			displayDigit(digit);
			overflow =0;
		}
	}
	else if(count == 1){
		overflow++;
		if(31000 == overflow){
			--digit;
			if(digit == 0){
				MOTOR_state();
				count =0;
			}
			displayDigit(digit);
			overflow =0;
		}
	}
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
	sei();
	MOTOR_state();
	//PWM_init(App);

	delay(1000,TIMER0,App);
	while(1);
	return 0;
}
