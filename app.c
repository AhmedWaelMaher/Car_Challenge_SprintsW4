 /******************************************************************************
 *
 * Module: APIs
 *
 * File Name: app.c
 *
 * Description: Application layer (Functions)
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/


/*
#include "DIO.h"
#include "seven_segment.h"
#include "regs.h"
#include "TIMER.h"
#include <avr/interrupt.h>

#define DUTY 50
void delay(uint32 x,uint8 Timer);
uint8 Digit= 0;
uint32 Counter =0;

int main()
{

	//uint32 index =0;
	Dio_init();
	Timer_Init();
	DDRB |=1<<PIN0;
	DDRD |=1<<PIN5;

	//OCR0=((DUTY*256)/100)-1;
	//sei();
	while(1)
	{
		PORTB ^=1<<PIN0;
		SegmentDisplay(Digit++);
		//delay(1000,TIMER_0);
		delay(1000,TIMER_1);
		//delay(1000,TIMER_2);
	}
	return 0;
}
*/

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

void App(void){
	static uint8 digit =0;
	if(digit == 9){
		digit =0;
	}
	displayDigit(digit++);
}

int main(void){
	Dio_init();
	Timer_init(TIMER0);
	sei();
	//PWM_init(TIMER0,50);
	delay(1000,TIMER0,App);
	while(1){
	/*delay(1000,TIMER0);
	MotoFwd();
	delay(9000,TIMER0);
	MotorFwd();
	delay(9000,TIMER0);
	MotorStop();*/
	}
	return 0;
}
