/*
 * main.c
 *
 * Created: 2/2/2023 5:43:45 PM
 *  Author: dell
 */ 
#include "ADC.h"
#include "DIO.h"
#include "LCD.h"
#include "timer.h"
#include <avr/delay.h>
#define  F_CPU 1000000
int main(void)
{
	LCD_init();
	ADC_init();
	unsigned short LCD_temp;
	unsigned short volt;
	unsigned char arr[]="temperature=";
	DIO_vsetPINDir('B',1,1);
	DIO_vsetPINDir('B',2,1);
	LCD_Str(arr);
    while(1)
    {
		volt=2.5*ADC_read(); 
		if (volt<1000)
		{	
			DIO_write('B',2,0);
			DIO_write('B',1,1);
			LCD_temp=((1000-volt)/10);
				if (LCD_temp>0)
				{
					if (LCD_temp<20)
					{
					OCR0=((LCD_temp*255)/20);
					timer_wave_fastPWM();
					}
				}
				else if (LCD_temp>20)
				{
				OCR0=255;
				timer_wave_fastPWM();	
				}
				else
				{
					OCR0=0;
					timer_wave_fastPWM();
				}
			if (LCD_temp<10)
			{ 
				LCD_moveCursor(1,13);
				LCD_data('-');
				LCD_data(LCD_temp+48);	
				LCD_data(0x20);
			}
			else if (LCD_temp<100)
			{
				LCD_moveCursor(1,13);
				LCD_data('-');
				LCD_data((LCD_temp/10)+48);
				LCD_data((LCD_temp%10)+48);
				LCD_data(0x20);
			}
			else
			{
				
			}
		}
		else 
		{
			DIO_write('B',1,0);
			DIO_write('B',2,1);
			LCD_temp=(volt-1000)/10;
			if (LCD_temp>20 )
			{
				if (LCD_temp<40)
				{
					OCR0=((LCD_temp-20)*255)/20;
					timer_wave_fastPWM();
				}
			}
				else if (LCD_temp>40)
				{
					OCR0=255;
					timer_wave_fastPWM();
				}
				else
				{
					OCR0=0;
					timer_wave_fastPWM();
				}

			if (LCD_temp<10)
			{
					LCD_moveCursor(1,13);
					LCD_data(LCD_temp+48);
					LCD_data(0x20);
			}
			else if (LCD_temp<100)
			{
					LCD_moveCursor(1,13);
					LCD_data((LCD_temp/10)+48);
					LCD_data((LCD_temp%10)+48);
					
			}
			else
			{
					
			}
		}
		
	}
}