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
#include "dio.h"
#include "timer.h"
#include "seven_segment.h"

void delay(uint8 id,uint32 delay){
	switch(Timer_Config_arr[id].Type){
	case TIMER0 :
		//Code
		break;
	}
}

