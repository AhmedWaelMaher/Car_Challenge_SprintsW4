/******************************************************************************
 *
 * Module: Seven Segment
 *
 * File Name: seven_segment.c
 *
 * Description: Source file for Seven Segment
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "seven_segment.h"

/*
 * Function definition getting the digit number and showing it on 7-segment
 */
void displayDigit(uint8 digit){

	switch(digit){

	case 0 :

		Dio_write(PORT_A,PIN0,LOW);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 1 :

		Dio_write(PORT_A,PIN0,HIGH);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 2 :

		Dio_write(PORT_A,PIN0,LOW);
		Dio_write(PORT_A,PIN1,HIGH);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 3 :

		Dio_write(PORT_A,PIN0,HIGH);
		Dio_write(PORT_A,PIN1,HIGH);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 4 :

		Dio_write(PORT_A,PIN0,LOW);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,HIGH);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 5 :

		Dio_write(PORT_A,PIN0,HIGH);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,HIGH);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 6 :

		Dio_write(PORT_A,PIN0,LOW);
		Dio_write(PORT_A,PIN1,HIGH);
		Dio_write(PORT_A,PIN2,HIGH);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 7 :

		Dio_write(PORT_A,PIN0,HIGH);
		Dio_write(PORT_A,PIN1,HIGH);
		Dio_write(PORT_A,PIN2,HIGH);
		Dio_write(PORT_A,PIN3,LOW);

		break;
	case 8 :

		Dio_write(PORT_A,PIN0,LOW);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,HIGH);

		break;
	case 9 :

		Dio_write(PORT_A,PIN0,HIGH);
		Dio_write(PORT_A,PIN1,LOW);
		Dio_write(PORT_A,PIN2,LOW);
		Dio_write(PORT_A,PIN3,HIGH);

		break;
	}
}
