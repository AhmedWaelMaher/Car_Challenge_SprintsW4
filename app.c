/*
 * app.c
 *
 *  Created on: Sep 20, 2019
 *      Author: Rafaat
 */

#include "dio.h"
#include "seven_segment.h"
#include "regs.h"
#include "timer.h"
#include <avr/interrupt.h>

int main(void){
	Dio_init();
	displayDigit(5);
	while(1);
}

/*
void delay(uint32 x);
uint32 Digit= 0;
int main()
{
	Dio_init();
	displayDigit(7);
	Timer_init(TIMER0);
	//if(c == OK)
	//displayDigit(0);
	sei();
	while(1)
	{
		Dio_write(PORT_D,PIN0,HIGH);
		delay(1000);
		Dio_write(PORT_D,PIN0,LOW);
		delay(1000);
		//_delay_ms(100);
	}
	return 0;
}
/*just for polling */

/*
void delay(uint32 x)
{
	while(Digit != x);
	Digit = 0;
}
uint8 flag = 0;
ISR(TIMER0_OVF_vect)
{

	TCNT0 = 129;
	Digit++;
	flag = 1;
}

*/
