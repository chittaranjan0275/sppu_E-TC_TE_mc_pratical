#include <p18f4550.h>

#define LCD_DATA PORTD //LCD data port
#define en PORTCbits.RC7 // enable signal
#define rw PORTCbits.RC6 // read/write signal
#define rs PORTCbits.RC5 // register select signal
void init_LCD(void); //Function to initialise the LCD
void LCD_command(unsigned char cmd); //Function to pass command to the LCD
void LCD_data(unsigned char data); //Function to write character to the LCD
void LCD_write_string(static char *str);//Function to write string to the LCD
void msdelay (unsigned int time);//Function for delay

//Start of main program
void main()
{
char msg1[] = "PICT";
char msg2[] = "MC Lab";
unsigned char i;
TRISD = 0x00;
TRISC = 0x00;
init_LCD();// Init LCD Module
msdelay(15);
LCD_write_string(msg1);
LCD_command(0xC0); // Goto second line, 0th place of LCD
LCD_write_string(msg2);

}

void init_LCD(void) // Function to initialise the LCD
{
LCD_command(0x38); // initialization of 16X2 LCD in 8bit mode
msdelay(15);
LCD_command(0x01); // clear LCD
msdelay(15);
LCD_command(0x06); // clear LCD
msdelay(15);
LCD_command(0x0C); // cursor off
msdelay(15);
LCD_command(0x80); // go to first line and 0th position
msdelay(15);
}

void LCD_command(unsigned char cmd) //Function to pass command to the LCD
{
LCD_DATA = cmd; //Send data on LCD data bus
rs = 0; //RS = 0 since command to LCD
rw = 0; //RW = 0 since writing to LCD
en = 1; //Generate High to low pulse on EN
msdelay(15);
en = 0;
}

void LCD_data(unsigned char data)//Function to write data to the LCD
{
LCD_DATA = data; //Send data on LCD data bus
rs = 1; //RS = 1 since data to LCD
rw = 0; //RW = 0 since writing to LCD
en = 1; //Generate High to low pulse on EN
msdelay(15);
en = 0;
}
//Function to write string to LCD
void LCD_write_string(static char *str)
{
int i = 0;
while (str[i] != 0)
{
	LCD_data(str[i]); // sending data on LCD byte by byte
	msdelay(15);
	i++;
	}
}
void msdelay (unsigned int time)//Function for delay
{
unsigned int i, j;
 for (i = 0; i < time; i++)
	 for (j = 0; j < 275; j++);	//Calibrated for a 1 ms delay in MPLAB
}
