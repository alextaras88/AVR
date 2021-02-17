#pragma once

#include "main.h"

void ADC_Init(void);
unsigned int ADC_Result(unsigned char channel);
void ADC_Init_ISR(unsigned char channel);