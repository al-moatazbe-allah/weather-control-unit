/*
 * ADC.c
 *
 * Created: 2/4/2023 1:35:45 AM
 *  Author: dell
 */ 
#include "ADC.h"
void ADC_init(){
SET_BIT(ADMUX,7); //configure VREF
SET_BIT(ADMUX,6);
SET_BIT(ADMUX,4);
SET_BIT(ADCSRA,7); // enable ADC
/* adjust ADC clock*/
SET_BIT(ADCSRA,2);
SET_BIT(ADCSRA,1);

}
unsigned short ADC_read(){
	unsigned short ADC_Value;
	SET_BIT(ADCSRA,6);
	while (IS_BIT_CLR(ADCSRA,4));
	SET_BIT(ADCSRA,4);
	ADC_Value=ADCL;
	ADC_Value |=(ADCH<<8);
	
	return ADC_Value;
	
	
}

