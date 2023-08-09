/*
 * timer.h
 *
 * Created: 2/6/2023 2:04:17 AM
 *  Author: dell
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "DIO.h"
#include "std_macros.h"
#define OCR0 (*((volatile u_8int*)(0x5C)))
#define TCCR0 (*((volatile u_8int*)(0X53)))
#define  TCNT0 (*((volatile u_8int*)(0x52)))
void timer_wave_fastPWM(void);

void phaseCorrect_PWM(void);


#endif /* TIMER_H_ */