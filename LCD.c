/*
 * LCD.c
 *
 * Created: 2/3/2023 3:34:14 PM
 *  Author: dell
 */ 
#include "LCD.h"
#include <avr/delay.h>

void LCD_init(void){
	_delay_ms(200);
	for (u_8int i=0;i<6;i++)
	{
		DIO_vsetPINDir('C',i,1);
	}
	LCD_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_cmd(FOUR_BIT_MODE); //4bit mode
	_delay_ms(1);
	LCD_cmd(CURSOR_ON_DISPLAN_OFF);//display on cursor on
	_delay_ms(1);
	LCD_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
}
void LCD_En(){
	DIO_write('C',EN,1);
	_delay_ms(2);
	DIO_write('C',EN,0);
	_delay_ms(2);
}
void LCD_data(u_8int data){
	DIO_write_WORD('C',data>>4,0);
	DIO_write('C',4,1);
	LCD_En();
	DIO_write_WORD('C',data,0);
	DIO_write('C',4,1);
	LCD_En();
}
void LCD_cmd(u_8int command){
	DIO_write_WORD('C',command>>4,0);
	DIO_write('C',4,0);
	LCD_En();
	DIO_write_WORD('C',command,0);
	DIO_write('C',4,0);
	LCD_En();
}
void LCD_Str(u_8int*arr){
	u_8int i=0;
	while(arr[i]!='\0'){
		LCD_data(arr[i]);
		i++;
	}
}
void LCD_moveCursor(u_8int row,u_8int col){
	switch (row)
	{
		case 1:
		LCD_cmd(0x80+col-1);
		break;
		case 2:
		LCD_cmd(0xC0+col-1);
		break;
		default:
		LCD_cmd(0x80+col-1);
	}
}
