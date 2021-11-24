#ifndef HEADER_H
#define HEADER_H
#include<REGX52.H>

void Power_Idle();
void Power_On();
void init_uart();
void send(unsigned char *s);
void delay();
void enable_interrupt();
#endif