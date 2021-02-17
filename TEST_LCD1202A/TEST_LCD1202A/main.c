/*
 * TEST_LCD1202A.c
 *
 * Created: 18.12.2017 22:38:18
 * Author : 1621
 */ 

#include "main.h"

unsigned int i = 0;
char str[10];

ISR (TIMER1_COMPA_vect)

{
	
	setpos(0, 1);
	sprintf(str,"%i", i);
	str_lcd (str);
	 
	if (i>100){i = 0;}
		else{i++;}

}

int main(void)
{
   LCD_ini();
   
   timer_ini();
   
   clearlcd();
   setpos(0, 0);
   str_lcd ("tim1");
   
   
   sei();
   
   
   
   
   
    while (1) 
    {
    }
}

