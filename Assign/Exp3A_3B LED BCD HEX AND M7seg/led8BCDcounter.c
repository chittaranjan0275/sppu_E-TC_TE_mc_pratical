#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}
}
void main (void){
	while(1){
		int i,j;
		int a = 0x00;
		for(i=0;i<10;i++){
		for(j=0;j<10;j++){
		P2= a;
		mydelay(80);
		a= a+1;
	}
		a=a+0x06;}}
}