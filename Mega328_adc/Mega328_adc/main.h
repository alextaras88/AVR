#pragma once

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int adc_value;


#include "lcd.h"
#include "tim.h"
#include "adc.h"


