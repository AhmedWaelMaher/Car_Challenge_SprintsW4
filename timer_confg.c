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
		{TIMER0,INITIALIZED,NORMAL_MODE,0xFF,NON_PWM,OC_OFF,CLK_8M,F_CPU_CLOCK,0xFF,0xFF,ENABLE_ISR}
};
