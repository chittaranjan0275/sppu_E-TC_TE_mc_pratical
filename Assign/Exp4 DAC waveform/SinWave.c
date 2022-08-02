#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1200;j++);
	}
}
void main (void){
	unsigned int v[]={128,192,238,255,238,192,128,64,17,0,17,64};
	int i;
	while(1){
	for(i=0;i<12;i++){
		P2= v[i];
		mydelay(10);
	}}
}