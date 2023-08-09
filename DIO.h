/*
 * DIO.h
 *
 * Created: 2/3/2023 12:35:33 AM
 *  Author: dell
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "std_macros.h"
/*define the addresses of the DIO registers*/
#define PORTA (*((volatile u_8int*)(0x3B)))
#define PORTB (*((volatile u_8int*)(0x38)))
#define PORTC (*((volatile u_8int*)(0x35)))
#define PORTD (*((volatile u_8int*)(0x32)))
#define DDRA (*((volatile u_8int*)(0x3A)))
#define DDRB (*((volatile u_8int*)(0x37)))
#define DDRC (*((volatile u_8int*)(0x34)))
#define DDRD (*((volatile u_8int*)(0x31)))
#define PINA (*((volatile u_8int*)(0x39)))
#define PINB (*((volatile u_8int*)(0x36)))
#define PINC (*((volatile u_8int*)(0x33)))
#define PIND (*((volatile u_8int*)(0x30)))
/*prototype of functions*/
/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction);

/*
	Function Name        : DIO_write
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber,unsigned char outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue);

/*
	Function Name        : DIO_u8read
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : DIO_toggle
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_toggle(unsigned char portname,unsigned char pinnumber);

/*
	Function Name        : DIO_set_port_direction
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char direction
	Function Description : set the direction of whole port .
*/

void DIO_set_port_direction(unsigned char portname,unsigned char direction);


/*
	Function Name        : DIO_write_port
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char portvalue
	Function Description : Write the value to all port pins.
*/

void DIO_write_port(unsigned char portname,unsigned char portvalue);

/*
	Function Name        : DIO_read_port
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname
	Function Description : read the value of the port .
*/
unsigned char DIO_read_port(unsigned char portname);
/*
	Function Name        : DIO_vconnectpullup
	Function Returns     : void
	Function Arguments   : char portname ,char pinnumber, char connect_pullup
	Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup);
/*
	Function Name        : write_low_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the low nibble of the port 
*/
void write_low_nibble(unsigned char portname,unsigned char value);
/*
	Function Name        : write_high_nibble
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char value
	Function Description : write a value to the high nibble of the port 
*/
void write_high_nibble(unsigned char portname,unsigned char value);




void DIO_write_WORD(u_8int port,u_8int value,u_8int start_bit);
#endif /* DIO_H_ */