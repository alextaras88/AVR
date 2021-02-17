
#include "main.h"

unsigned int adc_data = 0;
char str[10];

ISR (TIMER1_COMPA_vect)

{
	//adc_data = ADC_Result(0);
	setpos(0, 1);
	sendchar(adc_value/1000+0x30);			//Преобразуем число в код числа
	sendchar((adc_value%1000)/100+0x30);	//Преобразуем число в код числа
	sendchar((adc_value%100)/10+0x30);		//Преобразуем число в код числа
    sendchar(adc_value%10+0x30);			//Преобразуем число в код числа
	
}

int main(void)
{
	
   adc_value=0;
   
   LCD_ini();
   
   timer_ini();
   
   ADC_Init_ISR(0);
   
   clearlcd();
  
   sei();
   
    while (1) 
    {
    }
}

