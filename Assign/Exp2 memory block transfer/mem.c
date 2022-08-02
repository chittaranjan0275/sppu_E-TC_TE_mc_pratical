#include<reg51.h> 
void main(void) 
{
	unsigned char ml[10]; 
x	unsigned char x, z=0xFF;
	for (x=0; x<10; x++){
			z = z-1;
			ml[x] = z;
			P1 = z;
	}
}