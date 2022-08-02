#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1200;j++);
	}
}
void main (void){
	while(1){
		P2= 0x00;
		mydelay(200);
		P2= 0xFF;
		mydelay(200);
	}
}