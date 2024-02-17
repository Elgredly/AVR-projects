/*
 * ADC.h
 *
 * Created: 29/04/2023 10:03:35 PM
 *  Author: El-Gredly
 */ 



#include <avr/io.h>
#include "std_macros.h"

void ADC_init();
unsigned short ADC_u16Read();
