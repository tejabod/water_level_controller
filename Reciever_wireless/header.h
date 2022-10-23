#ifndef HEADER_H
#define HEADER_H
#include<REGX52.H>
#include<stdio.h>
#define FLOW_DELAY 100;
unsigned int check_tap_water();
unsigned int check_flow();
unsigned int delay(unsigned int T_Secs);
void Enable_SFR();
//void Power_Idle();
//void Power_On();
#endif