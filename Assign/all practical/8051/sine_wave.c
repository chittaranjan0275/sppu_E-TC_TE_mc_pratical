#include <reg51.h>
void main(void) {
unsigned char i;
unsigned char values[] = {128, 192, 238, 255, 238, 192, 128, 64, 17, 0, 17, 64, 128};
P1 = 0x00;
while(1) {
for(i = 0; i < 13; i++) {
P1 = values[i];
}
}
}