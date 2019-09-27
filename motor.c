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

/*
 * Function definition motor state returning void and no arguments
 */
void MOTOR_state(void){

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

/*
 * Forward MOVE 01
 */
void MOTOR_forward(void){

	Dio_write(PORT_C,PIN0,LOW);
	Dio_write(PORT_C,PIN1,HIGH);

}

/*
 * Reverse MOVE 10
 */
void MOTOR_reverse(void){

	Dio_write(PORT_C,PIN0,HIGH);
	Dio_write(PORT_C,PIN1,LOW);

}

/*
 * Stop MOTOR 00
 */
void MOTOR_stop(void){

	Dio_write(PORT_C,PIN0,LOW);
	Dio_write(PORT_C,PIN1,LOW);

}
