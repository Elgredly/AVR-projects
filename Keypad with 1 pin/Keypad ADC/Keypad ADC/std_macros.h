/*
 * std_macros.h
 *
 * Created: 05-Feb-23 2:11:26 PM
 *  Author: El-Gredly
 */ 


/*
#define uint8_t (signed char)
#define uint16_t (signed short)
#define uint32_t (signed int)
#define uint64_t (signed long)*/



#define REGISTE_SIZE 8
#define SET_BIT(reg,bit) reg |=(1<<bit)
#define CLR_BIT(reg,bit) reg &=(~(1<<bit))
#define TOG_BIT(reg,bit) reg ^=(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)
#define ROR(reg,num)		reg = (reg<<(REGISTE_SIZE-num))|(reg>>(num))
#define ROL(reg,num)		reg = (reg>>(REGISTE_SIZE-num))|(reg<<(num))