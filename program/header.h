#ifndef HEADER_H
#define HEADER_H
#include<REGX52.H>
#include<stdio.h>
#define FLOW_DELAY 10;
unsigned int check_flow();
unsigned int delay(unsigned int T_Secs);
void Enable_SFR();
void increment_time();
void turn_on_motor_at_6am();
//void Power_Idle();
//void Power_On();
#endif