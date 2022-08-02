#include <reg51.h>
void msDelay(int c);
void main()
{
while(1)
{
P0 = 0x00;
msDelay(100);
P0 = 0xff;
msDelay(100);
}

}
void msDelay(int a)
{
int i,j;
for(i = 0;i < a;i++)
{
for(j = 0;j<1000;j++)
{
}
}
}