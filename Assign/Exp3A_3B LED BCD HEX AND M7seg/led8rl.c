#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}
}
void main (void){
	while(1){
		int i;
		int a = 0x01;
		for(i=0;i<8;i++){
		P2= a;
		mydelay(200);
		a= a<<1;
	}}
}