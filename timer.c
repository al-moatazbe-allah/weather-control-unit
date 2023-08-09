/*
 * timer.c
 *
 * Created: 2/6/2023 2:04:38 AM
 *  Author: dell
 */ 
#include "timer.h"

void phaseCorrect_PWM(void){
		TCCR0=0;
		/* set OC0 as output pin */
		SET_BIT(DDRB,3);
		/* select phase correct PWM mode*/
		SET_BIT(TCCR0,6);
		/* select timer clock */
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,2);
		/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
		SET_BIT(TCCR0,5);
}
void timer_wave_fastPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	/* select timer clock */
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,2);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(non_inverting mode)*/
	SET_BIT(TCCR0,5);
}