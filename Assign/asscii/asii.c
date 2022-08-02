#include<reg51.h>

sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
void delay(unsigned int m);
void Lcd_command(unsigned char cmd);
void start_lcd(void);
void lcd_work(unsigned int d);

void main(void)
{
unsigned int i,j;
j=0x41;
start_lcd();
delay(15);
for(i=0;i<26;i++)
{
start_lcd();
delay(15);
P1=j;
lcd_work(j);
delay(200);
j++;
}
}

void delay(unsigned int m)
{
unsigned int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<1200;j++)
{
}
}
}
void Lcd_command(unsigned char cmd)
{
P1=cmd;
rs=0;
rw=0;
en=1;
delay(15);
en=0;
	}
void start_lcd(void)
{
Lcd_command(0x38);
delay(15);
Lcd_command(0x01);
delay(15);
Lcd_command(0x0C);
delay(15);
Lcd_command(0x84);
delay(15);
}
void lcd_work(unsigned int d)
{
P1=d;
rs=1;
rw=0;
en=1;
delay(15);
en=0;
}