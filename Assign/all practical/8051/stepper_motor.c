#include<reg51.h>
#define ON 1
#define OFF 0
unsigned int i,j;
void delay(){

TMOD = 0x01;
TH0 = 0xFC;
TL0 = 0x66;
TR0 = 1;
while(TF0 == 0);{
TR0 = 0;
TF0 = 0;
}
}
void main(){
int rot_angle[]={0x04,0x08,0x02,0x01};
while(1){
for(i=0;i<4;i++){
P2 = rot_angle[i];
for(j=0;j<500;j++){
delay();
}
}
}
}