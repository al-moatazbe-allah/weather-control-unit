/*
 * LCD.h
 *
 * Created: 2/3/2023 3:33:47 PM
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#define RS 4
#define EN 5
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_OFF 0x0C
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define FOUR_BIT_MODE 0X28
void LCD_init(void);
void LCD_cmd(u_8int command);
void LCD_data(u_8int data);
void LCD_moveCursor(u_8int row,u_8int col);
void LCD_CLR(void);
void LCD_Str(u_8int *arr);
void LCD_En();
#endif /* LCD_H_ */