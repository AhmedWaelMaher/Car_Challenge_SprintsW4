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
#include "service.h"

int main(void){
	Dio_init();
	Timer_init(TIMER0);
	PWM_init(TIMER0,50);
	SREG |=(1<<7);
	while(1);
	return 0;
}
