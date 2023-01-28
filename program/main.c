#include<header.h>

unsigned int flow_count; 
unsigned int hour = 12;
unsigned int minute = 0;
unsigned int second = 0;
//enum Motor_Status{Off, On, wait} status;

//void ext_int_0() interrupt 0
//{ 

//}

void main()
{
		P0 = 0x00;
		P1 = 0x00;
		P2 = 0x00;
		P3 = 0x00;
		Enable_SFR();
	  P1_0 = 0;
    while(1)
    {
		increment_time();
    turn_on_motor_at_6am();
    delay(1); // Wait for 1 second before incrementing time again
		}
}