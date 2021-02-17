/*
 * hx711.h
 *
 * Created: 12.01.2018 8:55:46
 *  Author: electro_metrotex
 */ 


#ifndef HX711_H_
#define HX711_H_

#include "main.h"

//long int OFFSET1 = 0;	// used for tare weight
//float SCALE1 = 1;	// used to return weight in grams, kg, ounces, whatever


#define HX_PORT PORTC
#define HX_DDR  DDRC
#define HX_PIN  PINC

#define data 0
#define sck 1

void ADC_HX711_Init(void);
unsigned char ADC_Read_8bit(void);
unsigned long int ADC_Get_Value24bit(unsigned char gain);
unsigned long int ADC_Read(unsigned char gain);

long int ADC_Get_average(char time);
double ADC_Get_value(char time);
float ADC_Get_units(char time);
void tare(char time);
void Set_scale(float scale);
float Get_scale();
void set_offset(long int offset);
long int Get_set_offset();

#endif /* HX711_H_ */