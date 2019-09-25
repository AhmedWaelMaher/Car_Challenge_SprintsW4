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

/*
 * Function Prototypes
 */


void delay(uint8 id,uint32 delay);
void PWM_init(uint8 id,uint8 duty_cycle);

#endif /* SERVICE_H_ */
