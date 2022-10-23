#include<header.h>

unsigned int flow_count; 
enum Motor_Status{Off, On} status;

//void ext_int_0() interrupt 0
//{ 
//		P1_0 = 0;
//    flow_count++;
//		P1_0 = 1;
//}


void main()
{
		status = Off;
		P0 = 0x00;
		P1 = 0x00;
		P2 = 0x00;
		P3 = 0x00;
		Enable_SFR();
	  P1_0 = 0;
    while(1)
    {
			switch(status)
			{
				case Off:
									//Power_Idle();
									P1_2 = 0;					// Turn motor off
									if(P3_3 == 1 && check_tap_water())        // if tank is full go to tank status wait
									{
									status = On;
									}
									break;

				case On:
								  if(P3_3 == 1)  // if tank is not full go to tank status ON
									{
											P1_2 = 1;				// Turn motor on
											status = On;
									}
									else
									{
										   status = Off;										
									}
									break;		
			  default:	
								 status = Off;
							   break;		
    }
}
}