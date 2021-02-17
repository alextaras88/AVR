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
unsigned long int ADC_Get_Value24bit(unsigned char gain)    // gain =  CH_A Gain128 = 1, CH_B Gain32 = 2, CH_A Gain64 = 3 
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
unsigned long int ADC_Read(unsigned char gain)
{
	unsigned long int adc_value = 0;
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
			
	adc_value = ((unsigned long int)(filler) <<24 
	| (unsigned long int)(byte[2]) <<16 
	| (unsigned long int)(byte[2]) <<8 
	| (unsigned long int)(byte[0]));
	
	return (unsigned long int)adc_value;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
long int ADC_Get_average(char time)
{
	long int  sum = 0;
	for(char i = 0; i<time; i++)
	{
		sum +=ADC_Read(1);
		_delay_ms(1);
	}
	
	return (long int)sum /(char)time;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//double ADC_Get_value(char time)
//{
	//return ADC_Get_average(time) - OFFSET1;
//}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//float ADC_Get_units(char time)
//{
	//return ADC_Get_value(time) / SCALE1;
//}
//
////---------------------------------------------------------------------------------------------------------------------------------------------------------------
//void tare(char time)
//{
	//double sum = ADC_Get_average(time);
	//set_offset(sum);
//}
//
////---------------------------------------------------------------------------------------------------------------------------------------------------------------
//void Set_scale(float scale)
//{
	//SCALE1 = scale;
//}
//
////---------------------------------------------------------------------------------------------------------------------------------------------------------------
//float Get_scale()
//{
	//return SCALE1;
//}
////---------------------------------------------------------------------------------------------------------------------------------------------------------------
//void set_offset(long int offset)
//{
	//OFFSET1 = offset;
//}
//
////---------------------------------------------------------------------------------------------------------------------------------------------------------------
//long int Get_set_offset()
//{
	//return OFFSET1;
//}
