
#include <p18f4550.h>


void myMsDelay (unsigned int time) 	
{
	unsigned int i, j;
	for (i = 0; i < time; i++)		
		for (j = 0; j < 710; j++);	
}

void main()
{ 
	TRISCbits.TRISC2 = 0 ;
    TRISDbits.TRISD5 = 0 ;	
	TRISDbits.TRISD6 = 0 ;	
	PR2 = 0xBA;            
    CCP1CON = 0x0C;         
 	T2CON = 0x07;	
	PORTDbits.RD6 = 1;	// Turn ON the Motor
    PORTDbits.RD5 = 0;
  while(1)	// Endless Loop
	{
		// ----------Duty Cycle 80%-----------
		CCP1CONbits.DC1B0 = 0;
		CCP1CONbits.DC1B1 = 0;
		CCPR1L = 0x96;
		myMsDelay(1000);
		// -----------------------------------
		// ----------Duty Cycle 60%-----------
		CCP1CONbits.DC1B0 = 0;
		CCP1CONbits.DC1B1 = 1;
		CCPR1L = 0x70;
		myMsDelay(1000);
		// -----------------------------------
		// ----------Duty Cycle 40%-----------
		CCP1CONbits.DC1B0 = 0;
		CCP1CONbits.DC1B1 = 0;
		CCPR1L = 0x4B;
		myMsDelay(1000);
		// -----------------------------------
		// ----------Duty Cycle 20%-----------
		CCP1CONbits.DC1B0 = 0;
		CCP1CONbits.DC1B1 = 1;
		CCPR1L = 0x25;
		myMsDelay(1000);
		// -----------------------------------
 	}   
 
}

