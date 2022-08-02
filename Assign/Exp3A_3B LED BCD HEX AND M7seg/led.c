#include<reg51.h>
sbit mybit = P2^3;
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}
}
void main (void){
	while(1){
		mybit = 1; //turn on p2.3
		P1= 0xFF;
		mydelay(200);
		mybit = 0; //turn off p2.3
		P1= 0x00;
		mydelay(200);
	}
}