/*
 * RSC.h
 *
 * Created: 05.02.2018 11:25:07
 *  Author: electro_metrotex
 */ 


#ifndef RSC_H_
#define RSC_H_


#include "main.h"
#include "SPI.h"

#define  PRESSURE_RANGE_1		27
#define  PRESSURE_RANGE_2		28
#define  PRESSURE_RANGE_3		29
#define  PRESSURE_RANGE_4		30

#define  PRESSURE_MINIMUM_1		31
#define  PRESSURE_MINIMUM_2		32
#define	 PRESSURE_MINIMUM_3     33  
#define  PRESSURE_MINIMUM_4		34

#define  PRESSURE_UNIT_1		35
#define  PRESSURE_UNIT_2		36
#define	 PRESSURE_UNIT_3		37
#define  PRESSURE_UNIT_4		38
#define  PRESSURE_UNIT_5		39

#define PRESSURE_REFERENCE		40

#define ADC_CONFIG_00			61
#define ADC_CONFIG_01			63
#define ADC_CONFIG_02			65
#define ADC_CONFIG_03			67

#define OFFSET_COFF_0			130
#define OFFSET_COFF_0			131
#define OFFSET_COFF_0			132
#define OFFSET_COFF_0			133

#define OFFSET_COFF_1			134
#define OFFSET_COFF_1			135
#define OFFSET_COFF_1			136
#define OFFSET_COFF_1			137

#define OFFSET_COFF_2			138
#define OFFSET_COFF_2			139
#define OFFSET_COFF_2			140
#define OFFSET_COFF_2			141

#define OFFSET_COFF_3			142
#define OFFSET_COFF_3			143
#define OFFSET_COFF_3			144
#define OFFSET_COFF_3			145

#define SPAN_COFF_0				210
#define SPAN_COFF_0				211
#define SPAN_COFF_0				212
#define SPAN_COFF_0				213

#define SPAN_COFF_1				214
#define SPAN_COFF_1				215
#define SPAN_COFF_1				216
#define SPAN_COFF_1				217

#define SPAN_COFF_2				218
#define SPAN_COFF_2				219
#define SPAN_COFF_2				220
#define SPAN_COFF_2				221

#define SPAN_COFF_3				222
#define SPAN_COFF_3				223
#define SPAN_COFF_3				224
#define SPAN_COFF_3				225

#define SHAPE_COFF_0			290
#define SHAPE_COFF_0			291
#define SHAPE_COFF_0			292
#define SHAPE_COFF_0			293

#define SHAPE_COFF_1			294
#define SHAPE_COFF_1			295
#define SHAPE_COFF_1			296
#define SHAPE_COFF_1			297

#define SHAPE_COFF_2			298
#define SHAPE_COFF_2			299
#define SHAPE_COFF_2			300
#define SHAPE_COFF_2			301

#define SHAPE_COFF_3			302
#define SHAPE_COFF_3			303
#define SHAPE_COFF_3			304
#define SHAPE_COFF_3			305


unsigned char EEPROM_RSC_Read(unsigned char EAD_EEPROM , unsigned char addrr);
void SPI_ADC_Init(void);
void ADC_RSC_Init(void);

void ADC_Read_Temp_Config(void);
void ADC_Read_Pressure_Config(void);

float ADC_Read_Temp_Work(void);
long int ADC_Read_Pressure_Value(void);

float ADC_Get_Pressure(void);





#endif /* RSC_H_ */