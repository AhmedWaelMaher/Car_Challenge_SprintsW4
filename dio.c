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

uint8 Dio_init(void){
	uint8 status = OK;
	uint8 index;
	if(NUM_OF_PINS < MAX_NUM_OF_PINS){
		for(index=0;index<NUM_OF_PINS;index++){
			Dio_Config_arr[index].Init = INITIALIZED;
			switch(Dio_Config_arr[index].Port){
			case PORT_A :
				if(Dio_Config_arr[index].Dir == OUTPUT){
					DDRA |= (1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Out == HIGH){
						PORTA |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Out == LOW){
						PORTA &= ~(1u<<Dio_Config_arr[index].Pin);
					}
					else{
						Dio_Config_arr[index].Init = NOT_INITIALIZED;
						status = NOK;
					}
				}
				else if(Dio_Config_arr[index].Dir == INPUT){
					DDRA &= ~(1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Res == PULLUP){
						PORTA |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Pin == EXTRES){
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
				if(Dio_Config_arr[index].Dir == OUTPUT){
					DDRB |= (1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Out == HIGH){
						PORTB |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Out == LOW){
						PORTB &= ~(1u<<Dio_Config_arr[index].Pin);
					}
					else{
						Dio_Config_arr[index].Init = NOT_INITIALIZED;
						status = NOK;
					}
				}
				else if(Dio_Config_arr[index].Dir == INPUT){
					DDRB &= ~(1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Res == PULLUP){
						PORTB |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Res == EXTRES){
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
				if(Dio_Config_arr[index].Dir == OUTPUT){
					DDRC |= (1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Out == HIGH){
						PORTC |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Out == LOW){
						PORTC &= ~(1u<<Dio_Config_arr[index].Pin);
					}
					else{
						Dio_Config_arr[index].Init = NOT_INITIALIZED;
						status = NOK;
					}
				}
				else if(Dio_Config_arr[index].Dir == INPUT){
					DDRC &= ~(1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Res == PULLUP){
						PORTC |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Res == EXTRES){
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
				if(Dio_Config_arr[index].Dir == OUTPUT){
					DDRD |= (1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Out == HIGH){
						PORTD |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Out == LOW){
						PORTD &= ~(1u<<Dio_Config_arr[index].Pin);
					}
					else{
						Dio_Config_arr[index].Init = NOT_INITIALIZED;
						status = NOK;
					}
				}
				else if(Dio_Config_arr[index].Dir == INPUT){
					DDRD &= ~(1u<<Dio_Config_arr[index].Pin);
					if(Dio_Config_arr[index].Res == PULLUP){
						PORTD |= (1u<<Dio_Config_arr[index].Pin);
					}
					else if(Dio_Config_arr[index].Res == EXTRES){
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
		for(index=0;index<MAX_NUM_OF_PINS;index++){
			Dio_Config_arr[index].Init = NOT_INITIALIZED;
		}
		status = NOK;
	}
	return status;
}

uint8 Dio_read(uint8 port,uint8 pin,uint8 * val){
	uint8 status = OK;
	uint8 index;
	for(index=0;index<NUM_OF_PINS;index++){
		if((Dio_Config_arr[index].Port == port) && (Dio_Config_arr[index].Pin == pin)){
			if((Dio_Config_arr[index].Init == INITIALIZED) && (Dio_Config_arr[index].Dir == INPUT)){
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
				index = NUM_OF_PINS +1;
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

uint8 Dio_write(uint8 port,uint8 pin,uint8 val){
	uint8 status = OK;
	uint8 index;
	for(index=0;index<NUM_OF_PINS;index++){
		if((Dio_Config_arr[index].Port == port) && (Dio_Config_arr[index].Pin == pin)){
			if((Dio_Config_arr[index].Init == INITIALIZED)
					&& (Dio_Config_arr[index].Dir == OUTPUT)
					&& ((val == HIGH) || (val == LOW))){
				switch(port){
				case PORT_A :
					if(val == HIGH){
						PORTA |= (1u<<pin);
					}
					else{
						PORTA &= ~(1u<<pin);
					}
					break;
				case PORT_B :
					if(val == HIGH){
						PORTB |= (1u<<pin);
					}
					else{
						PORTB &= ~(1u<<pin);
					}
					break;
				case PORT_C :
					if(val == HIGH){
						PORTC |= (1u<<pin);
					}
					else{
						PORTC &= ~(1u<<pin);
					}
					break;
				case PORT_D :
					if(val == HIGH){
						PORTD |= (1u<<pin);
					}
					else{
						PORTD &= ~(1u<<pin);
					}
					break;
				}
				index = MAX_NUM_OF_PINS +1;
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
