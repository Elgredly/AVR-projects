/*
 * keypad.h
 *
 * Created: 11-Mar-23 11:34:36 AM
 *  Author: El-Gredly
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define NOTPRESSED 0xFF
#define KPORT 'd'

void keypad_init();

char keypad_get_data();

#endif /* KEYPAD_H_ */