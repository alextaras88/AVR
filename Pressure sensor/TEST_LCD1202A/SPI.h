/*
 * SPI.h
 *
 * Created: 05.02.2018 11:23:45
 *  Author: electro_metrotex
 */ 


#ifndef SPI_H_
#define SPI_H_

#define CS_ADC_LOW		PORTB &= ~(1<<PORTB1);
#define CS_ADC_HIGH		PORTB |= (1<<PORTB1);
#define CS_EE_LOW		PORTB &= ~(1<<PORTB2);
#define CS_EE_HIGH		PORTB |= (1<<PORTB2);

#include "main.h"

void Spi_Init(void);
void Spi_send(unsigned char data);
unsigned char Spi_txrx(unsigned char data);
unsigned char Read_SPI(void);







#endif /* SPI_H_ */