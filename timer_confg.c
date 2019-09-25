/******************************************************************************
 *
 * Module: Timer Configurations Source
 *
 * File Name: timer_confg.c
 *
 * Description: Source file for Timer Configurations module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "timer_confg.h"

/*
 * Input user Configurations
 */

Timer_Config Timer_Config_arr[NUM_OF_TIMERS] = {
		{TIMER0,INITIALIZED,FAST_PWM_MODE,NA,FAST_PWM,OC_CLEAR_FAST_PWM,NA,NA,CLK_1M,F_CPU_8,ENABLE_ISR}
};
