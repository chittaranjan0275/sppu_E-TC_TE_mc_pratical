#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}   
}
void main (void){
	int i;
		unsigned int m[]={0x06,0x0C,0x09,0x03};
		while(1){
			for(i=3; i>=0;i--){
					P2=m[i];
					mydelay(200);
			}
		}
} 		