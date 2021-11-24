#include<header.h>

void Power_Idle()
{
	PCON |= 1 << 0;
}
void Power_On()
{
		PCON &= ~(1 << 0);
}

void init_uart()
{	
SCON=0x50;          //Mode 1, Baudrate generating using Timer 1
TMOD=0x20;          //Timer 1 Auto reload mode
TH1=0xfd;       //Values Calculated for 9600 baudrate
TR1=1;              //Run the timer
}

void send(unsigned char *s)
{
    while(*s) {
        SBUF=*s++;
        while(TI==0);
        TI=0;
    }
}

void delay()
	{
		TMOD |= 1 << 0;    // Timer0 mode1
		TH0 = 0xFC; 	 //initial value for 1ms
		TL0 = 0x66;
		TR0 = 1;      // timer start
		while(TF0==0);  // check overflow condition
		TR0 = 0;     // Stop Timer
		TF0 = 0;    // Clear flag
	}