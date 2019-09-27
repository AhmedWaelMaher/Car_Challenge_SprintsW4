/******************************************************************************
 *
 * Module: Timer Configuration Header
 *
 * File Name: timer_confg.h
 *
 * Description: Header file for Timer Configurations module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_

#include "std_types.h"

#ifndef NOK
#define NOK 0
#endif
#ifndef OK
#define OK 1
#endif

/*
 * AVR timers : 3 (Timer0,Timer1,Timer2)
 */
#define MAX_NUM_OF_TIMERS 3

/*
 * Initialized or UNinitialized timer
 */
#define INITIALIZED    1
#define UN_INITIALIZED 0

/*
 * Timer Types
 */
#define TIMER0 		  0
#define TIMER1		  1
#define TIMER2 		  2
#define NUM_OF_TIMERS 3

/*
 * Waveform generations modes for timer 0/2
 */
#define NORMAL_MODE   0
#define PWM_MODE	  1
#define CTC_MODE	  2
#define FAST_PWM_MODE 3

/*
 * Output compare in timer 0/2
 */
#define NON_PWM  	  0
#define FAST_PWM	  1
#define PHASE_CORRECT 2

/*
 * Output compare modes in timer 0/2
 */
#define OC_OFF	   				 0
#define OC_TOGGLE				 1
#define RESERVED_FAST_PWM		 1
#define RESERVED_PHASE_CORRECT   1
#define OC_CLEAR_NON_PWM		 2
#define OC_CLEAR_FAST_PWM 		 2
#define OC_CLEAR_PHASE_CORRECT   2
#define OC_SET  			     3

/*
 * Frequency of CPU
 */
#define CLK_1M 0
#define CLK_2M 1
#define CLK_4M 2
#define CLK_8M 3

/*
 * Prescaler of timer
 */
#define NO_CLOCK 		 0
#define F_CPU_CLOCK 	 1
#define F_CPU_8 		 2
#define F_CPU_64		 3
#define F_CPU_256		 4
#define F_CPU_1024		 5
#define EXTERNAL_FALLING 6
#define EXTERNAL_RISING  7

/*
 * Enabling and disabling the interrupts
 */
#define DISABLE_ISR 0
#define ENABLE_ISR     1

/*
 * Defines for bits in timer0 registers
 */
#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

/*
 * Defines for bits in timer2 registers
 */
#define FOC2 7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22 2
#define CS21 1
#define CS20 0

/*
 * Defines of common registers for all timer types
 */
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#ifndef NA
#define NA 0xFF
#endif

#define PWM_8bit 1
#define PWM_9bit 2
#define PWM_10bit 3
#define CTC_TIMER1 4
#define FAST_8bit 5
#define FAST_9bit 6
#define FAST_10bit 7
#define FREQUENCY_CORRECT1 8
#define FREQUENCY_CORRECT2 9
#define PWM_TIMER1 10
#define PWM_TIMER_2 11
#define CTC_TIMER1_2 12
#define RESERVED 13
#define FAST_PMW_TIMER1 14
#define FAST_PWM_TIMER1_2 15

#define OVF_USE 0
#define ICR_USE 1
#define OCRA_USE 2
#define OCRB_USE 3

/*
 * Structure containing Configuration of Timer Driver
 */
typedef struct {
	uint8 Type;
	uint8 Init;
	uint8 Mode;
	uint8 Timer1_Mode;
	uint8 Outcomp;
	uint8 Outcomp_Mode;
	uint8 Clk;
	uint8 Prescaler;
	uint8 VAL;
	uint8 ICRorOCRAorOCRB;
	uint8 ISR_ENABLE;
}Timer_Config;

/*
 * Array of Timers
 */
extern Timer_Config Timer_Config_arr[NUM_OF_TIMERS];

#endif /* TIMER_CONFG_H_ */
