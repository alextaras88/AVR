/*
 * hx711.c
 *
 * Created: 12.01.2018 8:55:32
 *  Author: electro_metrotex
 */ 

#include "hx711.h"

void ADC_HX711_Init(void)
{ 
	HX_DDR |= (1<<sck);       //sck out
	HX_DDR &= ~(1<<data);     //data in
	
	
	HX_PORT |= (1<<data);    //data high
	HX_PORT &= ~(1<<sck);    //sck low
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
unsigned char ADC_Read_8bit(void)
{
	unsigned char i = 0;
	unsigned char byte = 0;
	
	HX_PORT &= ~(1<<sck);				// Strob low
	while((HX_PIN & (1<<data)));		// Wait end converse
	
	for(i=0; i<8; i++)
	{
		HX_PORT |= (1<<sck);			// Strob high
		byte <<= 1;				        // Shift ADC value, adc_value view .......0
		HX_PORT &= ~(1<<sck);			// Strob low
		if(HX_PIN & (1<<data))			// If data pin = 0 .......0 - right symbol = 0, if 1 - right symbol = 1 .......1
		{
			byte++;
		}
	}
	
	return (unsigned char)byte;		
}
//----------------------------------------------------------------------------------------------------------------------------------------
unsigned long int ADC_HX711_Get_Value24bit(unsigned char gain)    // gain =  CH_A Gain128 = 1, CH_B Gain32 = 2, CH_A Gain64 = 3 
{
	unsigned char i = 0;
	unsigned long int adc_value = 0;

	HX_PORT &= ~(1<<sck);				// Strob low
	while((HX_PIN & (1<<data)));		// Wait end converse
	
	for(i=0; i<24; i++)
	{
		HX_PORT |= (1<<sck);			// Strob high
		adc_value <<= 1;				// Shift ADC value, adc_value view .......0
		HX_PORT &= ~(1<<sck);			// Strob low
		if(HX_PIN & (1<<data))			// If data pin = 0 .......0 - right symbol = 0, if 1 - right symbol = 1 .......1
		{
			adc_value++;
		}
	}
	
	for(i=0; i<gain; i++)				// CH_A Gain128 = 1, CH_B Gain32 = 2, CH_A Gain64 = 3
	{
		HX_PORT |= (1<<sck);
	    HX_PORT &= ~(1<<sck);
	}
		HX_PORT &= ~(1<<sck);
	
	return (unsigned long int)adc_value;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
    long int ADC_Read(unsigned char gain)
{
	long int adc_value = 0;
	unsigned char byte[3] = {0};
	unsigned char filler = 0x00;
	
	byte[2] = ADC_Read_8bit();
	byte[1] = ADC_Read_8bit();
	byte[0] = ADC_Read_8bit();
	
	for(unsigned char i=0; i<gain; i++)					// CH_A Gain128 = 1, CH_B Gain32 = 2, CH_A Gain64 = 3
	{
		HX_PORT |= (1<<sck);
		HX_PORT &= ~(1<<sck);
	}
		HX_PORT &= ~(1<<sck);
	
	if (byte[2] & 0x80) {filler = 0xFF;} 
		else {filler = 0x00;}
			
	adc_value = ((long int)(filler) <<24 | (long int)(byte[2]) <<16 | (long int)(byte[2]) <<8 | (long int)(byte[0]));
	
	return (long int)adc_value;
	
}
//---------------------------------------------------------------------------------------------------------------------------------------
unsigned long int ADC_HX711_Get_Zero(unsigned char time){
	
	unsigned long int zero = 0;
	for(unsigned char i = 0; i<time; i++){
		
		zero += ADC_HX711_Get_Value24bit(1);
	}
	
	zero/=(unsigned long int)time;
	
	return zero;
		
}
//----------------------------------------------------------------------------------------------------------------------------------------
unsigned long int ADC_HX711_Get_Weight(unsigned long int time, unsigned long int coff, unsigned long int zeroo){
	
	unsigned long int weight = 0;
	
	for(unsigned char i = 0; i<time; i++){
		
		weight += ADC_HX711_Get_Value24bit(1);
	}
	
	weight /= time;
	weight -= zeroo;
	weight /= coff;
	
	if (weight > 16000000) weight = 0;
	
	return (unsigned long int)weight;
}



