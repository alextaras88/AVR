/*
 * IncFile1.h
 *
 * Created: 18.12.2017 22:39:09
 *  Author: 1621
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>


#include "lcd.h"
#include "tim.h"


void port_lcd(void);
 



#endif /* MAIN_H_ */