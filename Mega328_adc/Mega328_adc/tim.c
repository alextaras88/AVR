

#include "tim.h"

void timer_ini(void){

	TCCR1B |= (1<<WGM12); // ������������� ����� ��� (����� �� ����������)
	TIMSK1 |= (1<<OCIE1A); //������������� ��� ���������� ���������� 1��� �������� �� ���������� � OCR1A(H � L)
	OCR1AH = 0b00000001; //���������� � ������� ����� ��� ���������
	OCR1AL = 0b11110100;
	TCCR1B |= (1<<CS10)|(1<<CS12);//��������� ��������.
}

