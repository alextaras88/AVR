#include "adc.h"

extern unsigned int adc_value;
//----------------------------------------
char high_adc = 0, low_adc = 0;
//----------------------------------------


ISR(ADC_vect)
{
	low_adc = ADCL;
	high_adc = ADCH;		// Верхняя часть регистра ADC должна быть считана последней, иначе не продолжится преобразование
	adc_value = high_adc<<8|low_adc;
}
/****************************************************************************************/
void ADC_Init(void){
	
	ADCSRA |= (1<<ADEN)							// Разрешение использования АЦП
	|(1<<ADPS2)|(1<<ADPS2)|(1<<ADPS0);			// Делитель 128 = 64 кГц
	ADMUX |= (1<<REFS0);						// VREF-gnd to VDD, вход ADC0

}
/****************************************************************************************/
void ADC_Init_ISR(unsigned char channel){
	
	ADCSRA |= (1<<ADEN)					// Разрешение использования АЦП
	|(1<<ADSC)							// Запуск преобразования
	|(1<<ADATE)							// Непрерывный режим работы АЦП
	|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)	// Делитель 128 = 64 кГц
	|(1<<ADIE);							// Разрешение прерывания от АЦП
	ADMUX |= (1<<REFS0);				// Внутренний Источник ОН 0-VDD
	
	switch(channel){
		
		case 0:									// ADC0
			break;
		case 1: ADMUX |= (1<<MUX0);				// ADC1
			break;
		case 2: ADMUX |= (1<<MUX1);				// ADC2
			break;
		case 3: ADMUX |= (1<<MUX0)|(1<<MUX1);	// ADC3
			break;
		case 4: ADMUX |= (1<<MUX2);				// ADC4
			break;
		case 5: ADMUX |= (1<<MUX0)|(1<<MUX2);	// ADC5
			break;
		case 6: ADMUX |= (1<<MUX1)|(1<<MUX2);	// ADC6
			break;
		case 7: ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2);	// ADC7
			break;
		case 8: ADMUX |= (1<<MUX3);						// Temperature sensor
			break;
		case 9: ADMUX |= (1<<MUX1)|(1<<MUX2)|(1<<MUX3); // 1.1V (VBG)
			break;
		case 10: ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3);  // 0V (GND)
			break;
		
	}
}
/****************************************************************************************/
unsigned int ADC_Result(unsigned char channel){
	
	switch(channel){
		
		case 0:									// ADC0
			break;
		case 1: ADMUX |= (1<<MUX0);				// ADC1
			break;
		case 2: ADMUX |= (1<<MUX1);				// ADC2
			break;
		case 3: ADMUX |= (1<<MUX0)|(1<<MUX1);	// ADC3
			break;
		case 4: ADMUX |= (1<<MUX2);				// ADC4
			break;
		case 5: ADMUX |= (1<<MUX0)|(1<<MUX2);	// ADC5
			break;
		case 6: ADMUX |= (1<<MUX1)|(1<<MUX2);	// ADC6
			break;
		case 7: ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2);	// ADC7
			break;
		case 8: ADMUX |= (1<<MUX3);						// Temperature sensor
			break;
		case 9: ADMUX |= (1<<MUX1)|(1<<MUX2)|(1<<MUX3); // 1.1V (VBG)
			break;
		case 10: ADMUX |= (1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3);  // 0V (GND)
			break;
			
	}
	
	ADCSRA |= (1<<ADSC);				// Начинаем преобразование
	while((ADCSRA & (1<<ADSC)));		// Проверим закончилось ли аналого-цифровое преобразование
	return (unsigned int) ADC;
		
}
/****************************************************************************************/
