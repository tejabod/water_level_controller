#include<header.h>

extern unsigned int flow_count; 
unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;
//enum Motor_Status{Off, On, wait} status;

void ext_int_0() interrupt 0
{ 
	flow_count++;
}

void main()
{

    P3 |= 0x0c;   // Configure the INT0 & INT1 pins as Inputs
    EA  = 1;      // Enable Global Interrupt bit will cause failure in compiler memory			
	  P1_0 = 0;
    while(1)
    {
		increment_time();
    turn_on_motor_at_6am();
    delay(1); // Wait for 1 second before incrementing time again
		}
}