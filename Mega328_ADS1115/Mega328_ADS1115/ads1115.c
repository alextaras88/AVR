#include "ads1115.h"


void ADS1115_Write_Register(unsigned char addr, unsigned char reg, unsigned int data){
	
	I2C_StartCondition();
	I2C_SendByte((addr << 1) + 0);
	I2C_SendByte(reg);
	I2C_SendByte((unsigned char)(data >> 8));;
	I2C_SendByte((unsigned char)(data & 0xFF));
	I2C_StopCondition();

}
//------------------------------------------------------------------------//
unsigned int ADS1115_Read_Register(unsigned char addr, unsigned char reg ){
	
	unsigned int data;
	unsigned char byte_1, byte_2;
	
	I2C_StartCondition();
	I2C_SendByte((addr << 1) + 0);
	I2C_SendByte(reg);
	I2C_StopCondition();
	
	I2C_StartCondition();
	I2C_SendByte((addr << 1) + 1);
	byte_1 = I2C_ReadByte();
	byte_2 = I2C_ReadLastByte();
	I2C_StopCondition();
	
	data = byte_1<<8 | byte_2;
	
	return data;
}
//------------------------------------------------------------------------//
unsigned int ADS1115_READ_ADC_SingleEnded(unsigned char addr, unsigned char channel, ads1115_datarate dr, ads1115_fsr_gain gain){
	
	// Check channel number
	if(channel > 3)
	{
		return 0;
	}
	
	unsigned int adc_config = ADS1115_COMP_QUE_DIS	|
	ADS1115_COMP_LAT_NonLatching |
	ADS1115_COMP_POL_3_ACTIVELOW |
	ADS1115_COMP_MODE_TRADITIONAL |
	dr |
	//DR_128SPS |
	ADS1115_MODE_SINGLE |
	gain;
	//FSR_6_144;
	
	if(channel == 0)
	{
		adc_config |= ADS1115_MUX_AIN0_GND;
	}
	else if(channel == 1)
	{
		adc_config |= ADS1115_MUX_AIN1_GND;
	}
	else if(channel == 2)
	{
		adc_config |= ADS1115_MUX_AIN2_GND;
	}
	else if(channel == 3)
	{
		adc_config |= ADS1115_MUX_AIN3_GND;
	}
	
	adc_config |= ADS1115_OS_SINGLE;
	
	ADS1115_Write_Register(addr, ADS1115_REG_CONFIG, adc_config);
	//_delay_ms(8);
	
	return ADS1115_Read_Register(addr, ADS1115_REG_CONVERSION) >> 0;
}
/**************************************************************************************************************/
int ADS1115_READ_ADC_Diff_A0_1(unsigned char addr, ads1115_datarate dr, ads1115_fsr_gain gain){
	
	unsigned int adc_config = ADS1115_COMP_QUE_DIS	|
						  ADS1115_COMP_LAT_NonLatching |
						  ADS1115_COMP_POL_3_ACTIVELOW |	
						  ADS1115_COMP_MODE_TRADITIONAL | 
						  dr |
						  //ADS1115_DR_128SPS |
						  ADS1115_MODE_SINGLE | 
						  gain;
						  //FSR_6_144;
	
	adc_config |= ADS1115_MUX_AIN0_AIN1;
	
	adc_config |= ADS1115_OS_SINGLE;	
	
	ADS1115_Write_Register(addr, ADS1115_REG_CONFIG, adc_config);
	//_delay_ms(8);
	
	return (int)ADS1115_Read_Register(addr, ADS1115_REG_CONVERSION);
}


/*************************************************************************************************************/
int ADS1115_READ_ADC_Diff_A0_3(unsigned char addr, ads1115_datarate dr, ads1115_fsr_gain gain){
	
	unsigned int adc_config = ADS1115_COMP_QUE_DIS	|
						  ADS1115_COMP_LAT_NonLatching |
						  ADS1115_COMP_POL_3_ACTIVELOW |	
						  ADS1115_COMP_MODE_TRADITIONAL | 
						  dr |
						  //ADS1115_DR_128SPS |
						  ADS1115_MODE_SINGLE | 
						  gain;
						  //FSR_6_144;
	
	adc_config |= ADS1115_MUX_AIN0_AIN3;
	
	adc_config |= ADS1115_OS_SINGLE;	
	
	ADS1115_Write_Register(addr, ADS1115_REG_CONFIG, adc_config);
	//_delay_ms(8);
	
	return (int)ADS1115_Read_Register(addr, ADS1115_REG_CONVERSION);
}
/*************************************************************************************************************/
int ADS1115_READ_ADC_Diff_A1_3(unsigned char addr, ads1115_datarate dr, ads1115_fsr_gain gain){
	
	unsigned int adc_config = ADS1115_COMP_QUE_DIS	|
						  ADS1115_COMP_LAT_NonLatching |
						  ADS1115_COMP_POL_3_ACTIVELOW |	
						  ADS1115_COMP_MODE_TRADITIONAL | 
						  dr |
						  //ADS1115_DR_128SPS |
						  ADS1115_MODE_SINGLE | 
						  gain;
						  //FSR_6_144;
	
	adc_config |= ADS1115_MUX_AIN1_AIN3;
	
	adc_config |= ADS1115_OS_SINGLE;	
	
	ADS1115_Write_Register(addr, ADS1115_REG_CONFIG, adc_config);
	//_delay_ms(8);
	
	return (int)ADS1115_Read_Register(addr, ADS1115_REG_CONVERSION);
}


int ADS1115_READ_ADC_Diff_A2_3(unsigned char addr, ads1115_datarate dr, ads1115_fsr_gain gain){
	
	unsigned int adc_config = ADS1115_COMP_QUE_DIS	|
						  ADS1115_COMP_LAT_NonLatching |
						  ADS1115_COMP_POL_3_ACTIVELOW |	
						  ADS1115_COMP_MODE_TRADITIONAL | 
						  dr |
						  //ADS1115_DR_128SPS |
						  ADS1115_MODE_SINGLE | 
						  gain;
						  //FSR_6_144;
	
	adc_config |= ADS1115_MUX_AIN2_AIN3;
	
	adc_config |= ADS1115_OS_SINGLE;	
	
	ADS1115_Write_Register(addr, ADS1115_REG_CONFIG, adc_config);
	//_delay_ms(8);
	
	return (int)ADS1115_Read_Register(addr, ADS1115_REG_CONVERSION);
}