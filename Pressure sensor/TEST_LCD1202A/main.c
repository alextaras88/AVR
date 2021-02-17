/*
 * TEST_LCD1202A.c
 *
 * Created: 18.12.2017 22:38:18
 * Author : 1621
 */ 

#include "main.h"

unsigned char ee_buff[20]={0};
char str[100];
float temp = 0;
float presure_f = 0;
long int press = 0;



int main(void)
{
	
	LCD_Init();
	clearlcd();
	Spi_Init();
	
	
	ee_buff[0]= EEPROM_RSC_Read(0x03, ADC_CONFIG_00);
    ee_buff[1]=	EEPROM_RSC_Read(0x03, ADC_CONFIG_01);
    ee_buff[2]= EEPROM_RSC_Read(0x03, ADC_CONFIG_02);
    ee_buff[3]= EEPROM_RSC_Read(0x03, ADC_CONFIG_03);
    
	
    setpos(0, 0);
	sprintf (str, "%x %x %x %x", ee_buff[0], ee_buff[1], ee_buff[2], ee_buff[3]);
	str_lcd(str);

	ADC_RSC_Init();
	_delay_ms(100);
	//ADC_Read_Temp_Config();
    ADC_Read_Pressure_Config();
	
    while (1)
	{
		//temp = ADC_Read_Temp_Work();
		//press = ADC_Read_Pressure_Value();
		
		
		presure_f = ADC_Get_Pressure();
		_delay_ms(200);
		setpos(0, 1);
		sprintf (str, "%.2f", presure_f);
		//sprintf (str, "%lx", press);
		str_lcd(str);
		
    }
}

