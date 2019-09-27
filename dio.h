 /******************************************************************************
 *
 * Module: DIO Header
 *
 * File Name: dio.h
 *
 * Description: Header file for Dio module
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "regs.h"
#include "dio_confg.h"

#define MAX_NUM_OF_PINS (uint8)32

#define OK 1
#define NOK 0

uint8 Dio_init(void);
uint8 Dio_read(uint8 port,uint8 pin,uint8 * val);
uint8 Dio_write(uint8 port,uint8 pin,uint8 val);

#endif /* DIO_H_ */
