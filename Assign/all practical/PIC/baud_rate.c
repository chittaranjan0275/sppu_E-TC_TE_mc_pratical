#include <p18f4550.h>
//Variables
unsigned char rx_data[20];
unsigned char string1[]={"\n\rPIC Microcontroller "};
//Function Prototypes
void TXbyte(unsigned char data); //To transmit single character
void TXstring (unsigned char *string); //To transmit string
//Start of Main Program
void main()
{
unsigned int i=0;
TRISCbits.TRISC7=1; // RXD line as input
TRISCbits.TRISC6=0; // TXD line as output
SPBRG = 0xE1;
SPBRGH = 0x04; // 0x04E1 for 9600 baud
TXSTA = 0x24; // TX enable BRGH=1
RCSTA = 0x90; // continuous RX
BAUDCON = 0x08; // BRG16 = 1
TXstring (string1); // Transmit string 1
for(i=0;i<10;i++)
{
while(PIR1bits.RCIF==0);
rx_data[i]= RCREG;
}
rx_data[10]= '\0';
TXstring (rx_data);
while(1); //loop forever
}
void TXbyte(unsigned char data)
{
while(TXSTAbits.TRMT==0); //wait till transmit buffer is not empty
TXREG = data; // Transmit Data
}
void TXstring(unsigned char *string)
{
unsigned char i=0;
for(i=0;string[i]!='\0';i++) //loop till end of the string
TXbyte(string[i]); //Send single character
}