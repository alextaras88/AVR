#include "ads1110.h"


void Write_ADS1110_Config(unsigned char addr, ads1110_datarate dr, ads1110__gain gain){
	
	unsigned char config = gain | dr | ADS1110_MODE_CONTINUOUS | BIT_5 | BIT_6 | RDY ;
	
	I2C_StartCondition();				//Отправим условие START
	I2C_SendByte((addr<<1)+0);			//адресс с битом записи
	I2C_SendByte(config);
	I2C_StopCondition();
}
/******************************************************************************/
unsigned int Get_ADS1110_Data(unsigned char addr){
	
	unsigned char byte1, byte2, byte3;
	unsigned int data_adc;
	unsigned char r_config;
	
	I2C_StartCondition();				//Отправим условие START
	I2C_SendByte((addr<<1)+1);			//отправим в устройство бит чтения
	byte1 = I2C_ReadByte();				//MSB
	byte2 = I2C_ReadByte();				//LSB
	byte3 = I2C_ReadLastByte();			//Config
	I2C_StopCondition();
	
	data_adc = (byte1<<8)|byte2;
	r_config = byte3;
	
	return data_adc;
	
	}
/******************************************************************************/



