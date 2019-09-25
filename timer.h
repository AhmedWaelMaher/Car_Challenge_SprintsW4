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
uint8 PWM_init(uint8 id,uint8 duty_cycle);
void Icu_setCallBack(void(*a_ptr)(void));
void Timer_start(void);
void Timer_stop(void);
uint8 Timer_Deinit(void);

#endif /* TIMER_H_ */
