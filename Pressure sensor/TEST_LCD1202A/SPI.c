/*
 * SPI.c
 *
 * Created: 05.02.2018 11:23:33
 *  Author: electro_metrotex
 */ 

#include "SPI.h"

void Spi_Init(void){
	
	DDRB |= ((1 << PORTB1)|(1 << PORTB2) | (1 << PORTB3) | (1 << PORTB5));		// PB1-CS_ADC, PB2-CS_EE, PB3-MOSI, PB4-MISO, PB5-CLk
	CS_EE_HIGH;
	CS_ADC_HIGH;
	SPCR |= (1 << SPE) | (1 << MSTR) | (1<<SPR0);		// SPI ON, MASTER, 16MHz/16
	//SPCR |= (1 << CPOL);
	//SPCR |= (1 << CPHA);
	//SPSR |= (1 << SPI2X);
}
/***********************************************************************************************/
void Spi_send(unsigned char data){
	
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	
}
/***********************************************************************************************/
unsigned char Spi_txrx(unsigned char data){
	
	unsigned char data_rx = 0;
	
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	data_rx = SPDR;
	
	return data_rx;
}
unsigned char Read_SPI(void){

	return SPDR;
}
/***********************************************************************************************/



