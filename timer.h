/******************************************************************************
 *
 * Module: Timer Header
 *
 * File Name: timer.h
 *
 * Description: Header file for Timer module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

/*
 * Include registers header of AVRatmega32 microcontroller
 * Include Timer configurations
 */
#include "regs.h"
#include "timer_confg.h"
#include <avr/interrupt.h>

#ifndef NOK
#define NOK 0
#endif
#ifndef OK
#define OK 1
#endif

/*
 * Functions Prototypes
 */
uint8 Timer_init(uint8 id);
uint8 Timer_PWM(uint8 type,uint8 duty_cycle);
uint8 Timer_delay(uint8 type,uint8 time);
uint8 Timer_Deinit(void);

#endif /* TIMER_H_ */
