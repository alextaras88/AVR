/*
 * TEST_LCD1202A.c
 *
 * Created: 18.12.2017 22:38:18
 * Author : 1621
 */ 

#include "main.h"
long int adc_data = 0;
char str[10];

ISR (TIMER1_COMPA_vect)

{
	clearlcd();
	setpos(0, 1);
	sprintf(str,"%lu", adc_data);
	str_lcd (str);
	//adc_data = ADC_Read(1);					// gain =  CH_A Gain128 = 1, CH_B Gain32 = 2, CH_A Gain64 = 3 
	adc_data = ADC_Get_Value24bit(1);
	
}

int main(void)
{
   LCD_ini();
   
   timer_ini();
   ADC_HX711_Init();
   
   clearlcd();
   setpos(0, 0);
   str_lcd ("TEST HX711");
   
   sei();
  
    while(1) 
    {
    }
}

