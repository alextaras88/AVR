/*
 * TEST_LCD1202A.c
 *
 * Created: 18.12.2017 22:38:18
 * Author : 1621
 */ 

#include "main.h"

void Forward_move(int speed)
{
	TCCR0A &= ~(1 << COM0B1)|(1 << COM0B0);
	_delay_ms(5);
	PORTD |= (1<<PORTD4);
	TCCR0A |= (1 << COM0A1);
	OCR0A = speed;
}
void Back_move(int speed)
{
	TCCR0A &= ~(1 << COM0A1)|(1 << COM0A0);
	_delay_ms(5);
	PORTD |= (1<<PORTD3);
	TCCR0A |= (1 << COM0B1);
	OCR0B = speed;	
}

void Stop_forward_move(void)
{
	PORTD &= ~(1<<PORTD4);
	TCCR0A &= ~(1 << COM0A1)|(1 << COM0A0);	
}
void Stop_back_move(void)
{
	PORTD &= ~(1<<PORTD3);
	TCCR0A &= ~(1 << COM0B1)|(1 << COM0B0);	
}


int main(void)
{
	DDRD |= (1<<PORTD3)|(1<<PORTD4);
	PORTD &= ~(1<<PORTD3)|(1<<PORTD4);
	timer0_PWM_ini();
	
	Forward_move(128);

    while (1) 
    {	
		
    }
}

