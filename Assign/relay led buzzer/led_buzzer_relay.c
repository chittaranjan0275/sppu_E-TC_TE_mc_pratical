#include<P18F4550.h>
#define SW0 PORTBbits.RB0
#define SW1 PORTBbits.RB1
#define RELAY PORTCbits.RC1
#define BUZZ PORTCbits.RC2
#define val value
void msdelay(int c);
void main()
{
int i;
unsigned char value=0;
unsigned char x;
INTCON2bits.RBPU=0;
ADCON1=0X0F;
TRISBbits.TRISB0=1;
TRISBbits.TRISB1=1;
TRISCbits.TRISC1=0;
TRISCbits.TRISC2=0;
TRISD=0x00;
while(1)
{
if(SW0==0)
{
val=1;
}
if(SW1==0)
{
val=2;
}
if(val==1)
{
BUZZ=1;
RELAY=1;
x=0x80;
for(i=0;i<8;i++)
{
PORTD=x;
msdelay(50);
x=x>>1;
}
}
if(val==2)
{
BUZZ=0;
RELAY=0;
x=0x01;
for(i=0;i<8;i++)
{
PORTD=x;
msdelay(50);
x=x<<1;
}
}
}
}
void msdelay(int c)
{
int i,j;
for(i=0;i<c;i++)
{
for(j=0;j<1275;j++)
{
}
}
}