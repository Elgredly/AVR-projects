/*
 * keypad.c
 *
 * Created: 11-Mar-23 11:34:25 AM
 *  Author: El-Gredly
 */ 
#include <avr/io.h>

#include "DIO.h"
#include "keypad.h"

void keypad_init()
{
	DIO_vSetPINDir(KPORT,0,1);
	DIO_vSetPINDir(KPORT,1,1);
	DIO_vSetPINDir(KPORT,2,1);
	DIO_vSetPINDir(KPORT,3,1);
	DIO_vSetPINDir(KPORT,4,0);
	DIO_vSetPINDir(KPORT,5,0);
	DIO_vSetPINDir(KPORT,6,0);
	DIO_vSetPINDir(KPORT,7,0);
	
	DIO_vconnectpullup(KPORT,4,1);
	DIO_vconnectpullup(KPORT,5,1);
	DIO_vconnectpullup(KPORT,6,1);
	DIO_vconnectpullup(KPORT,7,1);
	
	
	
}

char keypad_get_data()
{
	char arr[4][4]={
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'-','0','+','D'},
	};
	char row, col,x;
	char val = NOTPRESSED;
	for(row = 0; row<4 ; ++row)
	{
		DIO_writePIN(KPORT,0,1);
		DIO_writePIN(KPORT,1,1);
		DIO_writePIN(KPORT,2,1);
		DIO_writePIN(KPORT,3,1);
		
		DIO_writePIN(KPORT,row,0);
		
		for(col = 0 ; col<4 ; ++col)
		{
			x = DIO_u8read(KPORT, (col+4));
			if(0==x){
				val = arr[row][col];
				break;
			}
				
		}
		if(0==x)
		{
			break;
		}
	}
	
	return val;
}