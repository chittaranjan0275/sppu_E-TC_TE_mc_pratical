#include <reg51.h>
void mydelay(unsigned int time);
void main(void)
{
unsigned int i;
P1=0x00;
mydelay(200);
for (i=255;i>=0;i--)
{
P1=i;
mydelay(200);
};
}
void mydelay(unsigned int time)
{
unsigned int i,j;
for (i=0;i<time;i++)
for (j=0;j<1200;j++);
}