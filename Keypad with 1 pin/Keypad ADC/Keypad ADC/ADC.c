/*
 * ADC.c
 *
 * Created: 29/04/2023 10:03:25 PM
 *  Author: El-Gredly
 */ 
#include "ADC.h"

 void ADC_init(){
	 /*
	 REFS1		REFS0		stat
	   0		  0			Volt = ARef Volt
	   0		  1			Volt = VCC Volt
	   1		  0			*Not implemented*
	   1		  1			Volt = 2.56v
	 
	 */
	 
	 SET_BIT(ADMUX,REFS0); //ADC voltage = AVCC
	 //SET_BIT(ADMUX,REFS1); //Both of REFS1 & REFS0 if Activated it will take 2.56V
	 //SET_BIT(ADMUX,MUX4); // 2 pins ADC
	 SET_BIT(ADMUX,MUX0); //set PA1 to be ADC pin
	 SET_BIT(ADCSRA,ADEN); //enable ADC
	 
	 // set ADC clock (MCU_cloc/64k)
	 SET_BIT(ADCSRA,ADPS2);
	 SET_BIT(ADCSRA,ADPS1);
}

unsigned short ADC_u16Read()
{
	unsigned short read_val;
	
	SET_BIT(ADCSRA,ADSC);  //set Start Conversion bit
	while(READ_BIT(ADCSRA,ADSC)==1); //wait until flag become 1
	SET_BIT(ADCSRA,ADIF); //clear ADIF
	read_val = (ADCL); 
	read_val |= (ADCH<<8); //read ADC high &low 
	return read_val;
}

