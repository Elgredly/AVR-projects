/*
 * Keypad ADC.c
 *
 * Created: 17/02/2024 04:08:46 م
 * Author : EL-Gredly
 */ 

#include <avr/io.h>
#define  F_CPU 8e6
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ADC.h"
#include "DIO.h"
#include "LCD.h"


int main(void)
{
    /* Replace with your application code */
    ADC_init();
	LCD_vInit();
	uint16_t v ;
	while (1) 
    {
		v = ADC_u16Read();
		
		/*if(v<10){
			LCD_vSend_char(v+'0');
		}else if(v<100){
			LCD_vSend_char((v/10)+'0');
			LCD_vSend_char((v%10)+'0');
			
		}else if(v<1000){
			LCD_vSend_char((v/100)+'0');
			LCD_vSend_char(((v/10)%10)+'0');	
			LCD_vSend_char((v%10)+'0');
			
		}*/
		//LCD_vSend_char(v+'0');
		switch(v){
			case 48 : 
				//LCD_vSend_string("48");
				break;
			case 204:
				LCD_vSend_string("ON");
				break;
				
			case 146 : 
				LCD_vSend_string("0");
				break;
			case 79 : 
				LCD_vSend_string("=");
				break;
			case 0:
				LCD_vSend_string("+");
				break;
			case 371:
				LCD_vSend_string("1");
				break;
			case 335:
			LCD_vSend_string("2");
			break;
			
			case 294 :
			LCD_vSend_string("3");
			break;
			case 248 :
			LCD_vSend_string("-");
			break;
			case 399:
			LCD_vSend_string("*");
			break;
			case 429:
			LCD_vSend_string("6");
			break;
			case 456:
			LCD_vSend_string("5");
			break;
			
			case 481 :
			LCD_vSend_string("4");
			break;
			case 560 :
			LCD_vSend_string("7");
			break;
			case 542:
			LCD_vSend_string("8");
			break;
			case 522:
			LCD_vSend_string("9");
			break;
			case 501:
			LCD_vSend_string("/");
			break;
		}	
		_delay_ms(200);
		//LCD_clearscreen();
    }
}

