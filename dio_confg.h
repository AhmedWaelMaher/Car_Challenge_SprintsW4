 /******************************************************************************
 *
 * Module: Dio Configuration Header
 *
 * File Name: dio_config.h
 *
 * Description: Configuration Header file for Dio Module.
 *
 * Author: Ahmed Wael
 *
 ******************************************************************************/

#ifndef DIO_CONFG_H_
#define DIO_CONFG_H_

#include "std_types.h"

typedef enum{SEGA,SEGB,SEGC,SEGD,SERVO1,SERVO2,NUM_OF_PINS}pins;

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT		1
#define INPUT		0

#define HIGH		1
#define LOW			0

#define PULLUP		1
#define EXTRES		0

#define INITIALIZED			1
#define NOT_INITIALIZED		0

#define NA			0xff

typedef struct {
	uint8 Port;
	uint8 Dir;
	uint8 Pin;
	uint8 Out;
	uint8 Res;
	uint8 Init;
}Dio_Config;

extern Dio_Config Dio_Config_arr[NUM_OF_PINS];

#endif /* DIO_CONFG_H_ */
