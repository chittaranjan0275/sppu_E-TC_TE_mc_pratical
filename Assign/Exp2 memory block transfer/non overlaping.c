#include<reg51.h> 
void main(void) 
{
	unsigned char *ptr=0x40; 
	unsigned char x;
	for(x=0;x<4;x++){
		*(ptr-2+x)= *(ptr+x);
	}	
}