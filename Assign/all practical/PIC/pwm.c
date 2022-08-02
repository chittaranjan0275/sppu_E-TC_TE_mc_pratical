#include<P18F4550.h>
void delay(int d){
int i,j;
for(i=0;i<100;i++){
for(j=0;j<d;j++){
}
}
}
void main(void){
TRISCbits.TRISC2=0; //Set As output
TRISDbits.TRISD5=0;
TRISDbits.TRISD6=0;
PR2=0xBA; //Calculated
CCP1CON=0x0C; //PWM mode selection
T2CON=0x07; //Turn ON Timer 2 Prescale 16
PORTDbits.RD5=0;
PORTDbits.RD6=1;
while(1){
CCP1CONbits.DC1B1=0;
CCP1CONbits.DC1B0=0;
CCPR1L=0x96; //Duty Cycle of 20%
delay(1000);
CCP1CONbits.DC1B1=0;
CCP1CONbits.DC1B0=0;
CCPR1L=0x70;
delay(1000);
CCP1CONbits.DC1B1=0;
CCP1CONbits.DC1B0=0;
CCPR1L=0x4B;
delay(1000);
CCP1CONbits.DC1B1=1;
CCP1CONbits.DC1B1=0;
CCPR1L=0x25;
(1000);
}
}