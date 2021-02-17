#pragma once

#include "main.h"

//----------------------------------------
void LCD_ini(void);
void setpos(unsigned char x, unsigned y);
void str_lcd (char str1[]);
//----------------------------------------
#define e1     PORTD|=0b00001000 // установка линии E в 1            PD3
#define e0     PORTD&=0b11110111 // установка линии E в 0
#define rs1    PORTD|=0b00000100 // установка линии RS в 1 (данные)  PD2
#define rs0    PORTD&=0b11111011 // установка линии RS в 0 (команда) 
//----------------------------------------

void sendchar(unsigned char c);
void setpos(unsigned char x, unsigned y);
void clearlcd(void);
void LCD_ini(void);
void str_lcd (char str1[]);



