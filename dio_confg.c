/******************************************************************************
 *
 * Module: DIO Configuration Source
 *
 * File Name: dio_config.c
 *
 * Description: Configuration Source file for Dio Module.
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#include "dio_confg.h"

Dio_Config Dio_Config_arr[NUM_OF_PINS] = {
		{PORT_A,OUTPUT,PIN0,LOW,NA,NOT_INITIALIZED},
		{PORT_A,OUTPUT,PIN1,LOW,NA,NOT_INITIALIZED},
		{PORT_A,OUTPUT,PIN2,LOW,NA,NOT_INITIALIZED},
		{PORT_A,OUTPUT,PIN3,LOW,NA,NOT_INITIALIZED},
		{PORT_C,OUTPUT,PIN0,LOW,NA,NOT_INITIALIZED},
		{PORT_C,OUTPUT,PIN1,LOW,NA,NOT_INITIALIZED},
		{PORT_B,OUTPUT,PIN3,LOW,NA,NOT_INITIALIZED}
};
