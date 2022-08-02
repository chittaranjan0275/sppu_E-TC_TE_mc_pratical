#include<reg51.h>
void delay(int d);
void main(){
int i,j;
unsigned char seg[]={0x03,0x9f,0x25,0x0D,0x99,0x49,0x41,0x01,0x09};
while(1){
P1=0x00;
for(i=0;i<10;i++){
for(j=0;j<10;j++){
P2=0x01;
P1=seg[i];
delay(100);
P2=0x02;
P1=seg[j];
delay(100);
}
}
}
}
void delay(int d){
int i,l;
for(i=0;i<d;i++){
for(l=0;l<50;l++){
}
}
}