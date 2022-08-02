#include<reg51.h>
void mydelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1000;j++);
	}   
}
void main (void){
	int i,j;
		unsigned int m[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
		while(1){
			for(i=0; i<10;i++){
				for(j=0;j<10;j++){
					P3=1;
					P2=m[j];
					mydelay(20);
					P3=2;
					P2=m[i];
					mydelay(20);
				}
			}
		}
} 		