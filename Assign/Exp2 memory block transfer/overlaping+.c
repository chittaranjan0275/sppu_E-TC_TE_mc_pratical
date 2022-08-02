#include<reg51.h> 
void main(void) 
{
	unsigned char *ptr=0x40; 
	unsigned char x;
	for(x=4;x>=0;x--){
		*(ptr+2+x)= *(ptr+x);
	}	
}
/// run then go to view window memory 2
/// type in address D:0x40 type any numbers in row of 40 
/// run step by step using {} this symbol in upper menu
/// watch is it shifing
