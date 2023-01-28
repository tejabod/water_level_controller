#include<header.h>

void serial_txChar(char ch)
{
    SBUF = ch;
    while(ti_flag == 1);
    ti_flag = 0;
}

void serial_txString(char *ptr)
{
    while(*ptr)
        serial_txChar(*ptr++);
}

void serial_txNumber(unsigned char num)
{
    serial_txString("\n\rCount = ");
    serial_txChar(num/100+0x30);
    num = num%100;
    serial_txChar(num/10+0x30);
    serial_txChar(num%10+0x30);
}