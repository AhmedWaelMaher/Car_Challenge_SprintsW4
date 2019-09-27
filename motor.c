/******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file for Motor Driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "motor.h"

extern void MOTOR_state(void){
	static uint8 count =0;
	if(0 == count){
		MOTOR_forward();
		count++;
	}
	else if(1 == count){
		MOTOR_reverse();
		count++;
	}
	else{
		MOTOR_stop();
		count =0;
	}
}

void MOTOR_forward(void){
	Dio_write(PORT_C,PIN0,LOW);
	Dio_write(PORT_C,PIN1,HIGH);
}

void MOTOR_reverse(void){
	Dio_write(PORT_C,PIN0,HIGH);
	Dio_write(PORT_C,PIN1,LOW);
}

void MOTOR_stop(void){
	Dio_write(PORT_C,PIN0,LOW);
	Dio_write(PORT_C,PIN1,LOW);
