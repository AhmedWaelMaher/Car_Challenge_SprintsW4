 /******************************************************************************
 *
 * Module: Service Layer Header
 *
 * File Name: service.c
 *
 * Description: Header file of service layer.
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef SERVICE_H_
#define SERVICE_H_

#include "timer.h"
#include "dio.h"
#include "seven_segment.h"

/*
 * Function Prototypes
 */

void wait(void);
void delay(uint32 delay,uint8 timer_type,void(*a_ptr)(void));
//PWM function

#endif  SERVICE_H_

