
#include "main.h"
#include "ads1110.h"

char str[100];
unsigned int data = 0;
unsigned int weight = 0;
unsigned int zero = 0;


ISR (TIMER1_COMPA_vect)

{
	data =  Get_ADS1110_Data(0x48);
	weight = data;
	weight -= zero;
	weight /= 35;
	
	
	setpos(0, 1);
	sendchar(data/10000+0x30);         //Преобразуем число в код числа
	sendchar((data%10000)/1000+0x30);  //Преобразуем число в код числа
	sendchar((data%1000)/100+0x30);    //Преобразуем число в код числа
	sendchar((data%100)/10+0x30);      //Преобразуем число в код числа
	sendchar(data%10+0x30);            //Преобразуем число в код числа
	str_lcd ("  ");
	sendchar(weight/10000+0x30);         //Преобразуем число в код числа
	sendchar((weight%10000)/1000+0x30);  //Преобразуем число в код числа
	sendchar((weight%1000)/100+0x30);    //Преобразуем число в код числа
	sendchar((weight%100)/10+0x30);      //Преобразуем число в код числа
	sendchar(weight%10+0x30);
	weight = 0;
	
}

int main(void)
{
	
	 LCD_Init();
	 I2C_Init (0x0C); // F_CPU-16->400kHz speed i2C
	 
	 Write_ADS1110_Config(0x48, DATARATE_15SPS, PGA_GAIN_8);
	 
	 
	 zero += Get_ADS1110_Data(0x48);
	 zero += Get_ADS1110_Data(0x48);
	 zero += Get_ADS1110_Data(0x48);
	 zero /= 3;
	 
	 
	 USART_init();
	 timer_ini();
	 
	 setpos(4, 0);
	 str_lcd ("ADS1110");
	 
	 USART_putstring("ADS1110 Test\r\n");
	 
	 
	  
	  
	 sei();
    
    while (1) 
    {
		
    }
}

