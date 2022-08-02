#include<reg51.h>

//CODE FOR DISPLAYING ON LCD
sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;
void delay(unsigned int);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char dta);
void init_LCD(void);
void main(void)
{
unsigned int i,j;
j=0xFF;
init_LCD();
delay(15);
for (i=0;i<256;i++)
{
init_LCD();
delay(15);
P1=j;
LCD_data(j);
delay(200);
j--;
}
}
void init_LCD(void)
{
LCD_command(0x38); // Select 8 bit mode of LCD
delay(15);
LCD_command(0x01); // clear lcd screen
delay(15);
LCD_command(0x0C); // Display on and cursor off
delay(15);
LCD_command(0x84); // select first line and fourth column
delay(15);
}
void LCD_command(unsigned char cmd)
{
P1=cmd;
rs=0; //To decide command or data
rw=0;
e=1;
delay(15);
e=0;
}
void LCD_data(unsigned char dta)
{
P1=dta;
rs=1;
rw=0;
e=1;
delay(15);
e=0;
}
void delay(unsigned int ms)
{
unsigned int i,j;
for (i=0;i<ms;i++)
{
for (j=0;j<1275;j++)
{}
}
}