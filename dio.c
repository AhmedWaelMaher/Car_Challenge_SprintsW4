/******************************************************************************
 *
 * Module: DIO Source
 *
 * File Name: dio.c
 *
 * Description: Source file for Dio module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "dio.h"

/*
 * Function Initialization for DIO pins used
 */
uint8 Dio_init(void){

	uint8 status = OK;

	uint8 index;

	if(NUM_OF_PINS < MAX_NUM_OF_PINS){

		//loop on all configured AVR pins
		for(index=0;index<NUM_OF_PINS;index++){

			Dio_Config_arr[index].Init = INITIALIZED;

			//switch the 4 ports
			switch(Dio_Config_arr[index].Port){

			case PORT_A :

				if(OUTPUT == Dio_Config_arr[index].Dir){//DDRX =OUT

					DDRA |= (1u<<Dio_Config_arr[index].Pin);

					if(HIGH == Dio_Config_arr[index].Out){//PORTX =1

						PORTA |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(LOW == Dio_Config_arr[index].Out){//PORTX =0

						PORTA &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else if(INPUT == Dio_Config_arr[index].Dir){//DDRX =IN

					DDRA &= ~(1u<<Dio_Config_arr[index].Pin);

					if(PULLUP == Dio_Config_arr[index].Res){//Pull UP resistance

						PORTA |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(EXTRES == Dio_Config_arr[index].Pin){//External resistance

						PORTA &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else{

					Dio_Config_arr[index].Init = NOT_INITIALIZED;

					status = NOK;

				}
				break;

			case PORT_B :

				if(OUTPUT == Dio_Config_arr[index].Dir){//DDRX =OUT

					DDRB |= (1u<<Dio_Config_arr[index].Pin);

					if(HIGH == Dio_Config_arr[index].Out){//PORTX =1

						PORTB |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(LOW== Dio_Config_arr[index].Out){//PORTX =0

						PORTB &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else if(INPUT == Dio_Config_arr[index].Dir){//DDRX =IN

					DDRB &= ~(1u<<Dio_Config_arr[index].Pin);

					if(PULLUP == Dio_Config_arr[index].Res){//Pull UP resistance

						PORTB |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(EXTRES == Dio_Config_arr[index].Res){//External resistance

						PORTB &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else{

					Dio_Config_arr[index].Init = NOT_INITIALIZED;

					status = NOK;

				}
				break;

			case PORT_C :

				if(OUTPUT == Dio_Config_arr[index].Dir){//DDRX =OUT

					DDRC |= (1u<<Dio_Config_arr[index].Pin);

					if(HIGH == Dio_Config_arr[index].Out){//PORTX =1

						PORTC |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(LOW == Dio_Config_arr[index].Out){//PORTX =0

						PORTC &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else if(INPUT == Dio_Config_arr[index].Dir){//DDRX =IN

					DDRC &= ~(1u<<Dio_Config_arr[index].Pin);

					if(PULLUP == Dio_Config_arr[index].Res){//Pull UP resistance

						PORTC |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(EXTRES == Dio_Config_arr[index].Res){//External resistance

						PORTC &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else{

					Dio_Config_arr[index].Init = NOT_INITIALIZED;

					status = NOK;

				}
				break;

			case PORT_D :

				if(OUTPUT == Dio_Config_arr[index].Dir){//DDRX =OUT

					DDRD |= (1u<<Dio_Config_arr[index].Pin);

					if(HIGH == Dio_Config_arr[index].Out){//PORTX =1

						PORTD |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(LOW == Dio_Config_arr[index].Out){//PORTX =0

						PORTD &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else if(INPUT == Dio_Config_arr[index].Dir){//DDRX =IN

					DDRD &= ~(1u<<Dio_Config_arr[index].Pin);

					if(PULLUP == Dio_Config_arr[index].Dir){//Pull UP resistance

						PORTD |= (1u<<Dio_Config_arr[index].Pin);

					}
					else if(EXTRES == Dio_Config_arr[index].Res){//External resistance

						PORTD &= ~(1u<<Dio_Config_arr[index].Pin);

					}
					else{

						Dio_Config_arr[index].Init = NOT_INITIALIZED;

						status = NOK;

					}
				}
				else{

					Dio_Config_arr[index].Init = NOT_INITIALIZED;

					status = NOK;

				}
				break;

			default :

				Dio_Config_arr[index].Init = NOT_INITIALIZED;

				status = NOK;

			}
		}
	}
	else{
		//loop on the rest of AVR pins
		for(index=0;index<MAX_NUM_OF_PINS;index++){

			//Close AVR pins not configured
			Dio_Config_arr[index].Init = NOT_INITIALIZED;

		}
		status = NOK;
	}
	return status;
}

/*
 * Function reading from specific PORT and PIN getting the value from a pointer as a return
 */
uint8 Dio_read(uint8 port,uint8 pin,uint8 * val){

	uint8 status = OK;

	uint8 index;

	for(index=0;index<NUM_OF_PINS;index++){

		if((port == Dio_Config_arr[index].Port) && (pin == Dio_Config_arr[index].Pin)){

			if((INITIALIZED == Dio_Config_arr[index].Init)&&
					(INPUT == Dio_Config_arr[index].Dir)){

				switch(port){

				case PORT_A :

					*val = (1u&(PINA>>pin));

					break;
				case PORT_B :

					*val = (1u&(PINB>>pin));

					break;
				case PORT_C :

					*val = (1u&(PINC>>pin));

					break;
				case PORT_D :

					*val = (1u&(PIND>>pin));

					break;
				default :

					status = NOK;

				}
				index = NUM_OF_PINS +1;//getting out of the loop as a break

			}
			else{

				status = NOK;

			}
		}
		else{

			status = NOK;

		}
	}
	return status;
}

/*
 * Function writing a high or low on specific port and pin by passing the value as
 * the third argument with getting the status as a return value
 */
uint8 Dio_write(uint8 port,uint8 pin,uint8 val){

	uint8 status = OK;

	uint8 index;

	for(index=0;index<NUM_OF_PINS;index++){

		if((port == Dio_Config_arr[index].Port)&&
				(pin == Dio_Config_arr[index].Pin)){

			if((INITIALIZED == Dio_Config_arr[index].Init)
					&& (OUTPUT == Dio_Config_arr[index].Dir)
					&& ((HIGH == val) || (LOW == val))){

				switch(port){

				case PORT_A :

					if(HIGH == val){

						PORTA |= (1u<<pin);

					}
					else{

						PORTA &= ~(1u<<pin);

					}
					break;
				case PORT_B :

					if(HIGH == val){

						PORTB |= (1u<<pin);

					}
					else{

						PORTB &= ~(1u<<pin);

					}
					break;
				case PORT_C :

					if(HIGH == val){

						PORTC |= (1u<<pin);

					}
					else{

						PORTC &= ~(1u<<pin);

					}
					break;
				case PORT_D :

					if(HIGH == val){

						PORTD |= (1u<<pin);

					}
					else{

						PORTD &= ~(1u<<pin);

					}
					break;
				}
				index = MAX_NUM_OF_PINS +1;//getting out of the loop as a break

			}
			else{

				status = NOK;

			}
		}
		else{

			status = NOK;

		}
	}
	return status;
}
