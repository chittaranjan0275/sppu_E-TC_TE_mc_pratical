#include <reg51.h>
void main(void){
unsigned char *ptr1 = 0x20;
unsigned char *ptr2 = 0x40;
unsigned char i;
for(i=0;i<10;i++){
*(ptr2+i) = *(ptr1+i);
}
}