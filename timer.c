/******************************************************************************
 *
 * Module: Timer Source
 *
 * File Name: timer.c
 *
 * Description: Source file for Timer module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "timer.h"


/*
 * init Function Definition
 */
uint8 Timer_init(uint8 id){
	uint8 status;
	uint8 index =0;
	/*
	 * Checking Number of timers
	 */
	if(NUM_OF_TIMERS > MAX_NUM_OF_TIMERS){
		status =NOK;
	}
	else{
		status =OK;
		/*
		 * for loop on array of timers configured
		 */
		for(index=0;index<MAX_NUM_OF_TIMERS;index++){
			/*
			 * Switching on Timer type
			 */
			switch(Timer_Config_arr[id].Type){
			case TIMER0 :
				/*
				 * Checking the initialization of timer
				 */
				if(Timer_Config_arr[id].Init == UN_INITIALIZED){
					status =NOK;
				}
				else if(Timer_Config_arr[id].Init == INITIALIZED){
					TCNT0 =0;
					/*
					 * Switching on timer mode
					 */
					switch(Timer_Config_arr[id].Mode){
					case NORMAL_MODE :
						TCCR0 |= (1<<FOC0);
						break;
					case PWM_MODE :
						TCCR0 |= (1<<WGM00);
						break;
					case CTC_MODE :
						TCCR0 |= (1<<FOC0);
						TCCR0 |= (1<<WGM01);
						break;
					case FAST_PWM_MODE :
						TCCR0 |= (1<<WGM00);
						TCCR0 |= (1<<WGM01);
						break;
					default :
						status =NOK;
					}
					/*
					 * Switching on output compare type
					 */
					switch(Timer_Config_arr[id].Outcomp){
					case NON_PWM :
						/*
						 * Switching on output compare modes
						 */
						switch(Timer_Config_arr[id].Outcomp_Mode){
						case OC_OFF :
							break;
						case OC_TOGGLE :
							TCCR0 |= (1<<COM00);
							break;
						case OC_CLEAR_NON_PWM :
							TCCR0 |= (1<<COM01);
							break;
						case OC_SET :
							TCCR0 |= (1<<COM00);
							TCCR0 |= (1<<COM01);
							break;
						default :
							status =NOK;
						}
						break;
						case FAST_PWM :
							switch(Timer_Config_arr[id].Outcomp_Mode){
							case OC_OFF :
								break;
							case RESERVED_FAST_PWM :
								status =NOK;
								break;
							case OC_CLEAR_FAST_PWM :
								TCCR0 |= (1<<COM01);
								break;
							case OC_SET :
								TCCR0 |= (1<<COM00);
								TCCR0 |= (1<<COM01);
								break;
							default :
								status =NOK;
							}
							break;
							case PHASE_CORRECT :
								switch(Timer_Config_arr[id].Outcomp_Mode){
								case OC_OFF :
									break;
								case RESERVED_PHASE_CORRECT :
									status =NOK;
									break;
								case OC_CLEAR_PHASE_CORRECT :
									TCCR0 |= (1<<COM01);
									break;
								case OC_SET :
									TCCR0 |= (1<<COM00);
									TCCR0 |= (1<<COM01);
									break;
								default :
									status =NOK;
								}
								break;
								default :
									status =NOK;
					}
					/*
					 * Checking Clock of CPU 1M OR 2M OR 4M OR 8M
					 */
					if((Timer_Config_arr[id].Clk == CLK_1M) ||
							(Timer_Config_arr[id].Clk == CLK_2M) ||
							(Timer_Config_arr[id].Clk == CLK_4M) ||
							(Timer_Config_arr[id].Clk == CLK_8M)){
					}
					else{
						status =NOK;
					}
					/*
					 * Switching on Prescalers
					 */
					switch(Timer_Config_arr[id].Prescaler){
					case NO_CLOCK :
						break;
					case F_CPU_CLOCK :
						TCCR0 |= (F_CPU_CLOCK & 0xF7);
						break;
					case F_CPU_8 :
						TCCR0 |= (F_CPU_8 & 0xF7);
						break;
					case F_CPU_64 :
						TCCR0 |= (F_CPU_64 & 0xF7);
						break;
					case F_CPU_256 :
						TCCR0 |= (F_CPU_256 & 0xF7);
						break;
					case F_CPU_1024 :
						TCCR0 |= (F_CPU_1024 & 0xF7);
						break;
					case EXTERNAL_FALLING :
						TCCR0 |= (EXTERNAL_FALLING & 0xF7);
						break;
					case EXTERNAL_RISING :
						TCCR0 |= (EXTERNAL_RISING & 0xF7);
						break;
					default :
						status =NOK;
					}
					/*
					 * Checking Interrupt OR Polling
					 */
					if(Timer_Config_arr[id].ISR_ENABLE == ENABLE_ISR){
						TIMSK |= (1<<TOIE0);
						status =OK;
					}
					else if(Timer_Config_arr[id].ISR_ENABLE == DISABLE_ISR){
						TIMSK &= ~(1<<TOIE0);
						while((TIFR &(1<<TOV0)) >>TOV0);
						status =OK;
					}
					else{
						status =NOK;
					}
				}
				else{
					status =NOK;
				}
				break;
			case TIMER2 :
				/*
				 * Checking the initialization of timer
				 */
				if(Timer_Config_arr[id].Init == UN_INITIALIZED){
					status =NOK;
				}
				else if(Timer_Config_arr[id].Init == INITIALIZED){
					TCNT2 =0;
					/*
					 * Switching on timer mode
					 */
					switch(Timer_Config_arr[id].Mode){
					case NORMAL_MODE :
						TCCR2 |= (1<<FOC2);
						break;
					case PWM_MODE :
						TCCR2 |= (1<<WGM20);
						break;
					case CTC_MODE :
						TCCR2 |= (1<<FOC2);
						TCCR2 |= (1<<WGM21);
						break;
					case FAST_PWM_MODE :
						TCCR2 |= (1<<WGM20);
						TCCR2 |= (1<<WGM21);
						break;
					default :
						status =NOK;
					}
					/*
					 * Switching on output compare type
					 */
					switch(Timer_Config_arr[id].Outcomp){
					case NON_PWM :
						/*
						 * Switching on output compare modes
						 */
						switch(Timer_Config_arr[id].Outcomp_Mode){
						case OC_OFF :
							break;
						case OC_TOGGLE :
							TCCR2 |= (1<<COM20);
							break;
						case OC_CLEAR_NON_PWM :
							TCCR2 |= (1<<COM21);
							break;
						case OC_SET :
							TCCR2 |= (1<<COM20);
							TCCR2 |= (1<<COM21);
							break;
						default :
							status =NOK;
						}
						break;
						case FAST_PWM :
							switch(Timer_Config_arr[id].Outcomp_Mode){
							case OC_OFF :
								break;
							case RESERVED_FAST_PWM :
								status =NOK;
								break;
							case OC_CLEAR_FAST_PWM :
								TCCR2 |= (1<<COM21);
								break;
							case OC_SET :
								TCCR2 |= (1<<COM20);
								TCCR2 |= (1<<COM21);
								break;
							default :
								status =NOK;
							}
							break;
							case PHASE_CORRECT :
								switch(Timer_Config_arr[id].Outcomp_Mode){
								case OC_OFF :
									break;
								case RESERVED_PHASE_CORRECT :
									status =NOK;
									break;
								case OC_CLEAR_PHASE_CORRECT :
									TCCR2 |= (1<<COM21);
									break;
								case OC_SET :
									TCCR2 |= (1<<COM20);
									TCCR2 |= (1<<COM21);
									break;
								default :
									status =NOK;
								}
								break;
								default :
									status =NOK;
					}
					/*
					 * Checking Clock of CPU 1M OR 2M OR 4M OR 8M
					 */
					if((Timer_Config_arr[id].Clk == CLK_1M) ||
							(Timer_Config_arr[id].Clk == CLK_2M) ||
							(Timer_Config_arr[id].Clk == CLK_4M) ||
							(Timer_Config_arr[id].Clk == CLK_8M)){
					}
					else{
						status =NOK;
					}
					/*
					 * Switching on Prescalers
					 */
					switch(Timer_Config_arr[id].Prescaler){
					case NO_CLOCK :
						break;
					case F_CPU_CLOCK :
						TCCR2 |= (F_CPU_CLOCK & 0xF7);
						break;
					case F_CPU_8 :
						TCCR2 |= (F_CPU_8 & 0xF7);
						break;
					case F_CPU_64 :
						TCCR2 |= (F_CPU_64 & 0xF7);
						break;
					case F_CPU_256 :
						TCCR2 |= (F_CPU_256 & 0xF7);
						break;
					case F_CPU_1024 :
						TCCR2 |= (F_CPU_1024 & 0xF7);
						break;
					case EXTERNAL_FALLING :
						TCCR2 |= (EXTERNAL_FALLING & 0xF7);
						break;
					case EXTERNAL_RISING :
						TCCR2 |= (EXTERNAL_RISING & 0xF7);
						break;
					default :
						status =NOK;
					}
					/*
					 * Checking Interrupt OR Polling
					 */
					if(Timer_Config_arr[id].ISR_ENABLE == ENABLE_ISR){
						TIMSK |= (1<<TOIE2);
					}
					else if(Timer_Config_arr[id].ISR_ENABLE == DISABLE_ISR){
						TIMSK &= (1<<TOIE2);
						while((TIFR &(1<<TOV2)) >>TOV2);
					}
					else{
						status =NOK;
					}
				}
				else{
					status =NOK;
				}
				break;
			case TIMER1 :
				if(Timer_Config_arr[id].Init == UN_INITIALIZED){
					status =NOK;
				}
				else if(Timer_Config_arr[id].Init == INITIALIZED){
					TCNT2 =0;
					/*
					 * Switching on timer mode
					 */
					switch(Timer_Config_arr[id].Timer1_Mode){
					case NORMAL_MODE :
						break;
					case PWM_8bit :
						TCCR1A |= (1<<WGM10);
						break;
					case PWM_9bit :
						TCCR1A |= (1<<WGM11);
						break;
					case PWM_10bit :
						TCCR1A |= (1<<WGM11) | (1<<WGM10);
						break;
					case CTC_TIMER1 :
						TCCR1B |= (1<<WGM12);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case FAST_8bit :
						TCCR1A |= (1<<WGM10);
						TCCR1B |= (1<<WGM12);
						break;
					case FAST_9bit :
						TCCR1A |= (1<<WGM11);
						TCCR1B |= (1<<WGM12);
						break;
					case FAST_10bit :
						TCCR1A |= (1<<WGM10 ) | (1<<WGM11);
						TCCR1B |= (1<<WGM12);
						break;
					case FREQUENCY_CORRECT1 :
						TCCR1B |= (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case FREQUENCY_CORRECT2 :
						TCCR1A |= (1<<WGM01);
						TCCR1B |= (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case PWM_TIMER1 :
						TCCR1A |= (1<<WGM11);
						TCCR1B |= (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case PWM_TIMER_2 :
						TCCR1A |= (1<<WGM10) | (1<<WGM11);
						TCCR1B |= (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case CTC_TIMER1_2 :
						TCCR1A |= (1<<WGM12);
						TCCR1B |= (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case RESERVED :
						status = NOK;
						break;
					case FAST_PMW_TIMER1 :
						TCCR1A |= (1<<WGM11);
						TCCR1B |= (1<<WGM12) | (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					case FAST_PWM_TIMER1_2 :
						TCCR1A |= (1<<WGM10) | (1<<WGM11);
						TCCR1B |= (1<<WGM12) | (1<<WGM13);
						OCR1A = Timer_Config_arr[id].VAL;
						break;
					}
					switch(Timer_Config_arr[id].Outcomp){
					case NON_PWM :
						/*
						 * Switching on output compare modes
						 */
						switch(Timer_Config_arr[id].Outcomp_Mode){
						case OC_OFF :
							break;
						case OC_TOGGLE :
							TCCR1A |= (1<<COM1A0);
							break;
						case OC_CLEAR_NON_PWM :
							TCCR1A |= (1<<COM1A1);
							break;
						case OC_SET :
							TCCR1A |= (1<<COM1A0);
							TCCR1A |= (1<<COM1A1);
							break;
						default :
							status =NOK;
						}
						break;
						case FAST_PWM :
							switch(Timer_Config_arr[id].Outcomp_Mode){
							case OC_OFF :
								break;
							case OC_TOGGLE :
								TCCR1A |= (1<<COM1A0);
								break;
							case OC_CLEAR_FAST_PWM :
								TCCR1A |= (1<<COM1A1);
								break;
							case OC_SET :
								TCCR1A |= (1<<COM1A0);
								TCCR1A |= (1<<COM1A1);
								break;
							default :
								status =NOK;
							}
							break;
							case PHASE_CORRECT :
								switch(Timer_Config_arr[id].Outcomp_Mode){
								case OC_OFF :
									break;
								case OC_TOGGLE :
									TCCR1A |= (1<<COM1A0);
									break;
								case OC_CLEAR_PHASE_CORRECT :
									TCCR1A |= (1<<COM1A1);
									break;
								case OC_SET :
									TCCR1A |= (1<<COM1A0);
									TCCR1A |= (1<<COM1A1);
									break;
								default :
									status =NOK;
								}
								break;
								default :
									status =NOK;

					}
					if((Timer_Config_arr[id].Clk == CLK_1M) ||
							(Timer_Config_arr[id].Clk == CLK_2M) ||
							(Timer_Config_arr[id].Clk == CLK_4M) ||
							(Timer_Config_arr[id].Clk == CLK_8M)){
					}
					else{
						status =NOK;
					}
					switch(Timer_Config_arr[id].Prescaler){
					case NO_CLOCK :
						break;
					case F_CPU_CLOCK :
						TCCR1B |= (F_CPU_CLOCK & 0xF7);
						break;
					case F_CPU_8 :
						TCCR1B |= (F_CPU_8 & 0xF7);
						break;
					case F_CPU_64 :
						TCCR1B |= (F_CPU_64 & 0xF7);
						break;
					case F_CPU_256 :
						TCCR1B |= (F_CPU_256 & 0xF7);
						break;
					case F_CPU_1024 :
						TCCR1B |= (F_CPU_1024 & 0xF7);
						break;
					case EXTERNAL_FALLING :
						TCCR1B |= (EXTERNAL_FALLING & 0xF7);
						break;
					case EXTERNAL_RISING :
						TCCR1B |= (EXTERNAL_RISING & 0xF7);
						break;
					default :
						status =NOK;
					}
					if(Timer_Config_arr[id].ICRorOCRAorOCRB == ICR_USE){
						ICR1 = Timer_Config_arr[id].ICRorOCRAorOCRB;
					}
					else if(Timer_Config_arr[id].ICRorOCRAorOCRB == OCRA_USE){
						OCR1A = Timer_Config_arr[id].ICRorOCRAorOCRB;
					}
					else if(Timer_Config_arr[id].ICRorOCRAorOCRB == OCRB_USE){
						OCR1B = Timer_Config_arr[id].ICRorOCRAorOCRB;
					}
					else{
						status =NOK;
					}
					if(Timer_Config_arr[id].ISR_ENABLE == ENABLE_ISR){
						switch(Timer_Config_arr[id].ICRorOCRAorOCRB){
						case OVF_USE :
							TIMSK |= (1<<TOIE1);
							break;
						case ICR_USE :
							TIMSK |= (1<<TICIE1);
							break;
						case OCRA_USE :
							TIMSK |= (1<<OCIE1A);
							break;
						case OCRB_USE :
							TIMSK |= (1<<OCIE1B);
						}
					}
					else if(Timer_Config_arr[id].ISR_ENABLE == DISABLE_ISR){
						TIMSK &= ~(1<<TOIE0);
						while((TIFR &(1<<TOV0)) >>TOV0);
						status =OK;
					}
					else{
						status =NOK;
					}
				}
				else{
					status =NOK;
				}
				break;
			}
		}
	}
	return status;
}

/*
uint8 PWM_init(uint8 id,uint32 duty_cycle){
	uint16 pwm_val=0;
	uint8 status;
	switch(Timer_Config_arr[id].Type){
	case TIMER0 :
		Timer_Config_arr[id].Mode = FAST_PWM_MODE;
		Timer_Config_arr[id].Outcomp = FAST_PWM;
		Timer_Config_arr[id].Outcomp_Mode = OC_CLEAR_FAST_PWM;
		pwm_val = (duty_cycle*255)/100;
		OCR0 = pwm_val;
		break;
	case TIMER2 :
		Timer_Config_arr[id].Mode = FAST_PWM_MODE;
		Timer_Config_arr[id].Outcomp = FAST_PWM;
		Timer_Config_arr[id].Outcomp_Mode = OC_CLEAR_FAST_PWM;
		pwm_val = (duty_cycle*255)/100;
		OCR2 = pwm_val;
		break;
	case TIMER1 :
		Timer_Config_arr[id].Timer1_Mode = FAST_PWM_MODE;
		Timer_Config_arr[id].Outcomp = FAST_PWM;
		Timer_Config_arr[id].Outcomp_Mode = OC_CLEAR_FAST_PWM;
		pwm_val = (duty_cycle*65536)/100;
		OCR1A = pwm_val;
		break;
	default :
		status =NOK;
	}
	return status;
}
*/
