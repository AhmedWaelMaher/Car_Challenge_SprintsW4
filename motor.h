/******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for Motor Driver
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "dio.h"

/*
 * Functions Prototypes for motor driver
 */
extern void MOTOR_state(void);//state of motor

extern void MOTOR_forward(void);

extern void MOTOR_reverse(void);

extern void MOTOR_stop(void);

#endif /* MOTOR_H_ */
