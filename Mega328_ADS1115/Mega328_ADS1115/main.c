
#include "main.h"

int adc_data = 0;
char str[10];

ISR (TIMER1_COMPA_vect)

{
	setpos(5, 1);
	adc_data = ADS1115_READ_ADC_Diff_A0_1(ADS1115_ADDR_GND, DATARATE_128SPS, FSR_0_256);
	sendchar((adc_data%100000)/10000+0x30);
	sendchar((adc_data%10000)/1000+0x30);
	sendchar((adc_data%1000)/100+0x30);
	sendchar((adc_data%100)/10+0x30);
	sendchar(adc_data%10+0x30);
}

int main(void)
{
	
  
   
   LCD_ini();
   I2C_Init (0x0C); //400kHz
   
   timer_ini();
   
   clearlcd();
   setpos(5, 0);
   str_lcd ("ADS1115");
   setpos(0, 1);
   str_lcd ("Data:");
   
  
   sei();
   
    while (1) 
    {
		
    }
}

