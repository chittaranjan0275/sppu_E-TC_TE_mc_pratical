#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}
}
void main (void){
		int i;
		while(1){
		for(i=0;i<256;i++){
		P2= i;
		mydelay(1);
	}}
}