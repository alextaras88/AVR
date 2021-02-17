/*
 * zephyr.c
 *
 * Created: 19.12.2017 10:03:57
 *  Author: electro_metrotex
 */ 


#include "zephyr.h"


unsigned long int zephyrREAD_SN(void)
{
	unsigned char b1, b2, b3, b4;
	unsigned long int data;
	
	I2C_StartCondition();
	I2C_SendByte(0x93);
	I2C_SendByte(0x01);	
    b1 = I2C_ReadByte();        //msb
	b2 = I2C_ReadLastByte();    //lsb
	I2C_StopCondition();
	_delay_ms(15);
	
	I2C_StartCondition();
	I2C_SendByte(0x93);
	I2C_SendByte(0x01);
	b3 = I2C_ReadByte();        //msb
	b4 = I2C_ReadLastByte();    //lsb
	I2C_StopCondition();
	
	data = (b1<<24) + (b2<<16) + (b3<<8) + b4;
	
	return data;
}
//-----------------------------------------------------------
unsigned int GetDataZephyr(void)
{
	unsigned char b1, b2;
	unsigned int data;
	
	I2C_StartCondition();
	I2C_SendByte(0x93);
	b1 = I2C_ReadByte();        //msb
	b2 = I2C_ReadLastByte();    //lsb
	I2C_StopCondition();
		
	data =(b1 << 8) + b2;
	
	return data;		
}
