#include<reg51.h>
void sawtooth()
{
int i;
{
P1 = 0X00;
for(i=0;i<256;i++)
{
P1 = i;
}

}
}
void main()
{
while(1)
{
sawtooth();
}
}