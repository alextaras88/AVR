/*
 * hx711.h
 *
 * Created: 12.01.2018 8:55:46
 *  Author: electro_metrotex
 */ 


#ifndef HX711_H_
#define HX711_H_

#include "main.h"

#define HX_PORT PORTC
#define HX_DDR  DDRC
#define HX_PIN  PINC

#define data 0
#define sck 1



void ADC_HX711_Init(void);
unsigned char ADC_Read_8bit(void);
unsigned long int ADC_HX711_Get_Value24bit(unsigned char gain);
long int ADC_Read(unsigned char gain);
unsigned long int ADC_HX711_Get_Zero(unsigned char time);
unsigned long int ADC_HX711_Get_Weight(unsigned long int time, unsigned long  int coff, unsigned long int zero);



#endif /* HX711_H_ */