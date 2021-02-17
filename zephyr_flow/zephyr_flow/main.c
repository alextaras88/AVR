/*
 * zephyr_flow.c
 *
 * Created: 19.12.2017 9:58:42
 * Author : electro_metrotex
 */ 

#include "main.h"


unsigned int data = 0;
 

float flow;

char str[10];

ISR (TIMER1_COMPA_vect)

{
	data = GetDataZephyr();
	flow = 10*(((float)data/16384) - 0.1)/0.8;
	setpos(0, 1);
	sprintf(str,"%.2f", flow);
	str_lcd (str);
	setpos(6, 1);
	sprintf(str,"%i", data);
	str_lcd (str);		
}


int main(void)
{
	port_lcd();
	LCD_ini();
	I2C_Init();
	timer_ini();
	clearlcd();
	
	setpos(5, 0);
	str_lcd ("Zephyr");
	
	
	sei();
    
    while (1) 
    {
		
    }
}

