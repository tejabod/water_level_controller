#include<header.h>

unsigned int sr_count;
unsigned int flow_count; 
enum Motor_Status{Off, On} status;

void ext_int_0() interrupt 0
{ 
    flow_count++;
}

void serial_isr() interrupt 4
{ 
  //receivedChar = SBUF; 
  if(SBUF == 'F') 
  {
  sr_count++;       // Clear the count if 'c' is pressed on serial terminal
  }
	//receivedChar = ' ';
  RI = 0;              // Clear the Receive interrupt flag
}


void main()
{
	  sr_count = 0;
		flow_count = 0;
		status = Off;
		Enable_SFR();
    while(1)
    {
			switch(status)
			{
				case Off:
									//Power_Idle();
									P1_2 = 0;					// Turn motor off
									delay(10);			//wait for reoccuring uart serial in
									sr_count = 0;
									if(sr_count == 0 && check_tap_water())        // if tank is not full go to tank status ON
									{
									status = On;
									}
									break;

				case On:
								  if(sr_count == 0 && check_flow() == 1)  // if tank is not full go to tank status ON
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