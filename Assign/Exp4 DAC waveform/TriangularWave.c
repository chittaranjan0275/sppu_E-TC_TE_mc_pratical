#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}
}
void main (void){
	while(1){
		int i,j=1;
		for(i=0;1;i+=j){
		if(i==256||i==-1){j = -j;continue;}
		P2= i;
		mydelay(1);
	}}
}