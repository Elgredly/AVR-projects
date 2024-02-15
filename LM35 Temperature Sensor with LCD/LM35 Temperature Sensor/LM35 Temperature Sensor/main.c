/*
 * LM35 Temperature Sensor.c
 *
 * Created: 12/02/2024 07:57:48 م
 * Author : EL-Gredly
 */ 

#include <avr/io.h>
#define F_CPU 8e6
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"

int main(void)
{
    /* Replace with your application code */
    LCD_vInit();
	//LCD_vSend_string("TEST");
	ADC_init();	
	uint16_t temp;
	LCD_vSend_string("Temperature=   C");
		
	while(1){
		temp = (ADC_u16Read()*2.5);
		uint16_t t;
		LCD_movecursor(1,13);
			
		if(temp>=1000){
			t = (temp-1000)/10;
			
			if(t<10){
				LCD_movecursor(1,13);
				LCD_vSend_char(' ');
				LCD_vSend_char(' ');
				LCD_vSend_char(t+ '0');
				
			}else if(t<100){
				LCD_movecursor(1,13);
				LCD_vSend_char(' ');
				LCD_vSend_char((t/10) + '0');
				LCD_vSend_char((t%10) + '0');
				
			}else {
				LCD_movecursor(1,13);
				LCD_vSend_char((t/100) + '0');
				LCD_vSend_char(((t/10)%10) + '0');
				LCD_vSend_char((t%10) + '0');
			}
		}
		else{
			t = (1000-temp)/10;
			
			if(t<10){
				LCD_movecursor(1,13);
				LCD_vSend_char(' ');
				LCD_vSend_char('-');
				LCD_vSend_char(t+'0');

			}else if(t<100){
				LCD_movecursor(1,13);
				LCD_vSend_char('-');
				LCD_vSend_char(t/10 + '0');
				LCD_vSend_char(t%10 + '0');
			}
		}
	}
}


