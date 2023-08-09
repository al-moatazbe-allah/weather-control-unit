/*
 * ADC.h
 *
 * Created: 2/4/2023 1:35:27 AM
 *  Author: dell
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "std_macros.h"
#define ADMUX (*((volatile u_8int*)(0x27)))
#define ADCSRA (*((volatile u_8int*)(0x26)))
#define ADCH (*((volatile u_8int*)(0x25))) 
#define ADCL (*((volatile u_8int*)(0x24)))
void ADC_init(void);
unsigned short ADC_read(void);
#endif /* ADC_H_ */