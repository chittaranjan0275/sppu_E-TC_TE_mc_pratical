#include<P18F4550.h>
extern void _startup(void);
void delay(int d);
#pragma code _RESET_INTERRUPT_VECTOR=0X1000
void _reset(void)
{
_asm
goto _startup
_endasm
}
#pragma code
#pragma code _LOW_INTERRUPT_VECTOR = 0x1018
void low_ISR(void)
{
}
#pragma code
void timer_ISR(void);
#pragma interrupt timer_isr
void timer_isr(void)
{
TMR0H = 0x6D;
TMR0L = 0x7B;
PORTBbits.RB0 = ~PORTBbits.RB0;
INTCONbits.TMR0IF = 0;
}
#pragma code _HIGH_INTERRUPT_VECTOR = 0x1008
void high_ISR(void)
{
_asm
goto timer_isr
_endasm
}
#pragma code
void main()
{
int i;
INTCON2bits.RBPU = 0;
ADCON1 = 0x0F;
TRISBbits.TRISB0 = 0;
PORTBbits.RB0 = 0;
T0CON = 0x03;// PRESCALAR AS 16
TMR0H = 0x6D;
TMR0L = 0x7B;
INTCONbits.TMR0IF = 0;
INTCONbits.GIE = 1;
INTCONbits.TMR0IE = 1;
T0CONbits.TMR0ON = 1;
TRISD = 0X00;
while (1)
{
PORTD = 0X55;
delay(500);
PORTD = 0XAA;
delay(500);
}
}
void delay(int d)
{
int i,j;
for(i=0;i<d;i++)
{
for(j=0;j<1000;j++)
{
}
}
}