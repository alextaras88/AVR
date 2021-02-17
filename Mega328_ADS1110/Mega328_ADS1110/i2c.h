
#ifndef I2C_H_
#define I2C_H_

#include "main.h"

void I2C_Init (unsigned char speed); //������������� i2c
void I2C_StartCondition(void); //�������� ������� START
void I2C_StopCondition(void); //�������� ������� STOP
void I2C_SendByte(unsigned char c); //�������� ����� � ����
void I2C_SendByteByADDR(unsigned char c,unsigned char addr); //�������� ����� � ���� �� ���������� �� ������
unsigned char I2C_ReadByte(void); //������ ����
unsigned char I2C_ReadLastByte(void); //������ ��������� ����





#endif 