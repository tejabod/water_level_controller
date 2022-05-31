#include<header.h>

//void Power_Idle()
//{
//	PCON |= 1 << 0;
//}
//void Power_On()
//{
//		PCON &= ~(1 << 0);
//}
extern unsigned int sr_count;
extern unsigned int flow_count; 

void delay(unsigned int T_Secs)
	{
		unsigned int i =0;
		for (i =0;i<(T_Secs*1000)/50;i++)
		{
		TR0 =1;      // timer start
		while(TF0==0);  // check overflow condition
		TR0 =0;     // Stop Timer
		TF0 =0;    // Clear flag
		if(sr_count != 0)
		{
			sr_count =0;
			break;
		}
		}
	}
		
//	void Clr_IntrFlag_T2()
//	{
//		TF2 =0;
//		EXF2 =0;
//	}
			
	void Enable_SFR()
	{
		//init_uart
		SCON = 0x50;  // Asynchronous mode, 8-bit data and 1-stop bit
    TMOD = 0x21;  // Timer1 in Mode2 and Timer0 in Mode1
    TH1 =  0xFD;  // Load timer value for 9600 baudrate
    TR1 = 1;      // Turn ON the timer for Baud rate generation
		//init_uart
		
    ES  = 1;      // Enable Serial Interrupt
    P3 |= 0x0c;   // Configure the INT0 & INT1 pins as Inputs
    EX0 = 1;      // Enable INT0
    EX1 = 1;      // Enable INT1
		//    TH0 = 0x4B;   // Load timer value for 50ms
		//    TL0 = 0xFD;
    ET0 = 1;      // Enable Timer0 Interrupt
    TR0 = 1;      // Enable Timer1 Interrupt
    //EA  = 1;      // Enable Global Interrupt bit will cause failure in compiler memory
		
		//T2MOD interrupts
		ET2 =1;  // enable external interrupt for counter 2 counter by T2 pin input
		C_T2 =1;	 // select counter which 

		//timer registers
	  TH0 = 0X4B; 	 //initial value for 50ms
		TL0 = 0XFD;
		// Counter 2 reg values which will increment with T2 pin
		TH2 = 0xFF;
		TL2 = 0xFD;
		//timer registers
		
    PS =1;			// set serial interrupt high priority
	}
	
unsigned int check_tap_water()
	{
		flow_count = 0;
		EX0 = 1;      // Enable INT0
		P1_3 =1;         // keep open tap for water
		while(flow_count < 5);   // wait untill water flows from opened tap
		P1_3 = 0;         // keep tap closed
		EX0 = 0;      // Disble INT0
		flow_count = 0;
		return 1;
	}
	
	
unsigned int check_flow()
	{
		flow_count = 0;
		EX0 = 1;      // Enable INT0
		P1_3 =1;         // keep open tap for water
		delay(10);
		EX0 = 0;      // Disble INT0
		P1_3 =0;         // keep tap closed
		if (flow_count > 5)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
