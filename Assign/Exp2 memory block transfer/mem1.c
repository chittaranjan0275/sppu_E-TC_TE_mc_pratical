#include<reg51.h> 
void main(void) 
{
	unsigned char *ptr=0x40; 
	unsigned char *ptr1=0x50;
	unsigned char x;
	for(x=0;x<10;x++){
		*(ptr1+x)=*(ptr+x);
	}	
}
/// debug code - viwe> memory> window 2 - Adderes D:0x40 - change valeus from 00 to xy - run code with {step} 