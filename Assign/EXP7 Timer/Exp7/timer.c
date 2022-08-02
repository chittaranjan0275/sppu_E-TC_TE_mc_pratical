//Expt.No.4: Generation of Square wave using timer interrupt
//Includes
#include <p18f4550.h>
//Configration bits setting/
#pragma config FOSC = HS //Oscillator Selection
#pragma config WDT = OFF //Disable Watchdog timer
#pragma config LVP = OFF //Disable Low Voltage Programming
#pragma config PBADEN = OFF //Disable PORTB Analog inputs


void mdelay(unsigned int m){
unsigned int i, j;
for (i = 0; i < m; i++) // Loop for itime
for (j = 0; j < 710; j++); // Calibrated for a 1 ms delay in MPLAB

}

//Timer ISR Function Prototype
void timer_isr(void);

// Timer ISR Definition
#pragma interrupt timer_isr
void timer_isr(void)
{
	TMR0H = 0X6D;          //Reload the timer values after overflow
	TMR0L = 0X82;
	PORTBbits.RB0 = ~PORTBbits.RB0; //Toggle the RB0
 	INTCONbits.TMR0IF = 0; //Reset the timer overflow interrupt flag
}

//Interrupt Vector for Timer0 Interrupt
#pragma code _HIGH_INTERRUPT_VECTOR = 0x0008
void high_ISR (void)
{
	_asm 
		goto timer_isr //The program is relocated to execute the ISR
	_endasm    
}
#pragma code

// Start of main Program
void main()
{	
TRISD=0x00;
	ADCON1 = 0x0F;        //Configuring the PORTE pins as digital I/O 
	TRISBbits.TRISB0 = 0; //Configruing the RB0 as output
	PORTBbits.RB0 = 0;    //Setting the initial value	
	T0CON = 0x02;		  //Set the timer to 16-bit,Fosc/4,1:16 prescaler
  	TMR0H = 0x85;         //load timer value to genearate delay 50ms
  	TMR0L = 0xEE;
   	INTCONbits.TMR0IF = 0;// Clear Timer0 overflow flag
	INTCONbits.TMR0IE = 1;// TMR0 interrupt enabled
 	T0CONbits.TMR0ON = 1; // Start timer0
	INTCONbits.GIE = 1;	  // Global interrupt enabled
PORTD=0x55;
mdelay(1000);
PORTD=0xAA;

	while(1);             //Program execution stays here untill the timer overflow interrupt is generated
	
}