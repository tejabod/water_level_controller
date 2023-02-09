#include<header.h>

unsigned int flow_count; 
extern unsigned int hour;
extern unsigned int minute;
extern unsigned int second;


//unsigned int delay(unsigned int T_Secs)
//	{
//		unsigned int i =0;
//		for (i =0;i<(T_Secs*1000)/50;i++)
//		{
//		TR0 =1;      // timer start
//		while(TF0==0);  // check overflow condition
//		TR0 =0;     // Stop Timer
//		TF0 =0;    // Clear flag
//		}
//		return 1;
//	}
//		
	
	
void delay(unsigned int T_Secs)
{
unsigned int count=0;
 while(count!=500*T_Secs)
  {
   TMOD=0x01;  //16-bit timer0 selected
   TH0=0xF8;   // Loading high byte in TH
   TL0=0xCC;   // Loaded low byte in TL
   TR0=1;      // Running the timer
    while(!TF0);   //Checking the timer flag register if it is not equal to 1 
   TR0 = 0;      // If TF0=1 stop the timer
   TF0 = 0;      // Clear the Timer Flag bit for next calculation
   count++;
  }

}
	
unsigned int check_flow()
	{
		flow_count = 0;
		EX0 = 1;      // Enable INT0
		P1_3 =1;         // keep open tap for water
		delay(2);
		second=+2;
		EX0 = 0;      // Disble INT0
		P1_3 = 0;         // keep tap closed
		if(flow_count > 3)
		{
		return 1;
		}
		else
		{
			return 0;
		}
	}


void increment_time() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

void turn_on_motor_at_6am() {
    // Check if it is 6am
    if (hour == 0 && minute == 0 && second == 10) 
			{
			if(check_flow())
			{
				EX1 = 1;
				while(!INT1)
				{
					increment_time();
					delay(1);
					P1_2 = 1;
				}
				EX1 = 0;
				P1_2 = 0;
			}
    }
}