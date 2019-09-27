/******************************************************************************
 *
 * Module: DIO Registers
 *
 * File Name: regs.h
 *
 * Description: Header file for DIO and Timer modules Registers for AVR(ATMEGA32)
 *
 * Author: Ahmed Wael
 *
 *******************************************************************************/

#ifndef DIO_REGS_H
#define DIO_REGS_H

#define NULL_PTR ((void*)0)

#include "std_types.h"

/* Definition for PORTA Registers */
#define PORTA	(*(volatile uint8 * const)0x003B)
#define DDRA	(*(volatile uint8 * const)0x003A)
#define PINA 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB	(*(volatile uint8 * const)0x0038)
#define DDRB	(*(volatile uint8 * const)0x0037)
#define PINB 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC	(*(volatile uint8 * const)0x0035)
#define DDRC	(*(volatile uint8 * const)0x0034)
#define PINC 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD	(*(volatile uint8 * const)0x0032)
#define DDRD	(*(volatile uint8 * const)0x0031)
#define PIND 	(*(volatile const uint8 * const)0x0030)

/* Definition for Timer Registers */
#define TCCR0 (*((volatile uint8*)0x53))
#define TIMSK (*((volatile uint8*)0x59))
#define TIFR  (*((volatile uint8*)0x58))
#define OCR0  (*((volatile uint8*)0x5c))
#define TCNT0 (*((volatile uint8*)0x52))
#define SREG  (*((volatile uint8*)0x5f))
#define MCUCR  (*((volatile uint8*)0x55))
#define MCUCSR  (*((volatile uint8*)0x54))
#define GICR  (*((volatile uint8*)0x5B))
#define GIFR  (*((volatile uint8*)0x5A))
#define TCCR1A  (*((volatile uint8*)0x4F))
#define TCCR1B  (*((volatile uint8*)0x4E))
#define TCNT1H  (*((volatile uint8*)0x4D))
#define TCNT1L  (*((volatile uint8*)0x4C))
#define TCNT1   (*((volatile uint16*)0x4C))
#define OCR1AH  (*((volatile uint8*)0x4B))
#define OCR1AL  (*((volatile uint8*)0x4A))
#define OCR1BH  (*((volatile uint8*)0x49))
#define OCR1BL  (*((volatile uint8*)0x48))
#define ICR1H  (*((volatile uint8*)0x47))
#define ICR1L  (*((volatile uint8*)0x46))
#define ICR1  (*((volatile uint16*)0x46))
#define TIMSK  (*((volatile uint8*)0x59))
#define TIFR  (*((volatile uint8*)0x58))
#define OCR1A  (*((volatile uint8*)0x4A))
#define TCCR2  (*((volatile uint8*)0x45))
#define TCNT2  (*((volatile uint8*)0x44))
#define OCR2  (*((volatile uint8*)0x43))

#endif /* DIO_REGS_H */
