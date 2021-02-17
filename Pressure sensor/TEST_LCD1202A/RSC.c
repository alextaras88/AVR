/*
 * RSC.c
 *
 * Created: 05.02.2018 11:24:50
 *  Author: electro_metrotex
 */ 

#include "RSC.h"

char str[10];

/* if addrr 8bit-EAD_EEPROM = 0x03, else 9bit - 0x0B */
unsigned char EEPROM_RSC_Read(unsigned char EAD_EEPROM , unsigned char addrr){
	CS_ADC_HIGH;
	unsigned char data = 0;
	CS_EE_LOW;
	Spi_send(EAD_EEPROM);
	Spi_send(addrr);
	data = Spi_txrx(0xFF);
	CS_EE_HIGH;

	return data;

}
/*************************************************************************************/
void SPI_ADC_Init(void){
	
	CS_EE_HIGH;
	CS_ADC_HIGH;
	SPCR |= (1 << SPE) | (1 << MSTR);		// SPI ON, MASTER, 16MHz/4 (1<<SPR0)
	SPCR |= (1 << CPHA);
   _delay_ms(50);
	
}
/*************************************************************************************/
void ADC_RSC_Init(void){

	SPI_ADC_Init();
	CS_ADC_LOW;
	Spi_send(0x06);   // Reset ADC
	_delay_ms(10);
	Spi_send(0x43);

	Spi_send(0x0A);
	Spi_send(0x84);
	Spi_send(0x40);
	Spi_send(0x00);
	CS_ADC_HIGH;
	
}
/*************************************************************************************/
void ADC_Read_Temp_Config(void){
	CS_ADC_LOW;
	Spi_send(0x44);
	Spi_send(0x0E);
	CS_ADC_HIGH;
	_delay_ms(100);
}
/*************************************************************************************/
void ADC_Read_Pressure_Config(void){
	CS_ADC_LOW;
	Spi_send(0x44);
	Spi_send(0x0C);
	CS_ADC_HIGH;
	_delay_ms(100);
}
/*************************************************************************************/
float ADC_Read_Temp_Work(void){
	
	unsigned char i = 0;
	unsigned char data1 = 0, data2 = 0;
	unsigned int temp = 0;
	
	while ((PINB & PINB0) !=0){
		_delay_ms(1);
		i++;
		if(i>100) break;
	}
	
	CS_ADC_LOW;
	data1 = Spi_txrx(0x00);
	data2 = Spi_txrx(0x00);
	Spi_send(0x00);
	CS_ADC_HIGH
	temp = ((data1<<8 ) + (data2<<0)) & 0xFFFC;
	temp = temp / 4;
	
	return temp * 0.03125;
}
/*************************************************************************************/ 
 long int ADC_Read_Pressure_Value(void){
	 
     long int Pressure = 0;
	 unsigned char i = 0;
	 while ((PINB & PINB0) !=1){
		 _delay_ms(1);
		 i++;
		 if(i>100) break;
	 }
	 
	 CS_ADC_LOW;
	 Pressure |= (long int)Spi_txrx(0x00)<<16;
	 Pressure |= (long int)Spi_txrx(0x00)<<8;
	 Pressure |= (long int)Spi_txrx(0x00);
	 CS_ADC_HIGH;
	 
	 return Pressure<<8 ;  
 }
 /*************************************************************************************/
 float ADC_Get_Pressure(void){
	 
	 float  pressure = 0;
	 
	 pressure = (float)ADC_Read_Pressure_Value()/256;
	 pressure = (pressure/0x7FFFFF)* (float)2.5;
	 return pressure;
 }
 /*************************************************************************************/
