#ifndef LCD_H_
#define LCD_H_

#include "main.h"

//----------------------------------------
#define e1     PORTD|=0b00001000 // ��������� ����� E � 1            PD3
#define e0     PORTD&=0b11110111 // ��������� ����� E � 0
#define rs1    PORTD|=0b00000100 // ��������� ����� RS � 1 (������)  PD2
#define rs0    PORTD&=0b11111011 // ��������� ����� RS � 0 (�������) 
//----------------------------------------

void port_lcd(void);
void sendchar(unsigned char c);
void setpos(unsigned char x, unsigned y);
void clearlcd(void);
void LCD_Init(void);
void str_lcd (char str1[]);



#endif 