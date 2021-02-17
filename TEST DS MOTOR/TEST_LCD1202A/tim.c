/*
 * tim.c
 *
 * Created: 18.12.2017 23:24:25
 *  Author: 1621
 */ 

#include "tim.h"

void timer_ini(void)

{

	TCCR1B |= (1<<WGM12); // устанавливаем режим СТС (сброс по совпадению)
	TIMSK1 |= (1<<OCIE1A); //устанавливаем бит разрешения прерывания 1ого счетчика по совпадению с OCR1A(H и L)
	OCR1AH = 0b00011110; //записываем в регистр число для сравнения
	OCR1AL = 0b10000100;
	TCCR1B |= (1<<CS10)|(1<<CS12);//установим делитель.
}

void timer0_PWM_ini(void)
{
	DDRD |= (1 << PORTD5)|(1 << PORTD6);					// PD5 ,PD6 is now an output
	OCR0A = 0;	
	OCR0B = 0;												// Set PWM for N% duty cycle
	TCCR0A |= (1 << COM0A1)|(1 << COM0B1);					// Set none-inverting mode
	TCCR0A |= (1 << WGM00)|(1 << WGM01);					// Set fast PWM Mode
	TCCR0B |= (1 << CS00);									// Set prescaler to 8 and starts PWM
	//TCCR0B |= (1 << CS01);
	//TCCR0B |= (1 << CS02);									
		
}



