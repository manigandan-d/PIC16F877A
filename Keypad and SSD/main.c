#include <xc.h>

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 10000000

#define MAX 10

uint8_t data[MAX] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void main() {
    TRISB0 = TRISB1 = TRISB2 = 0;
    TRISB3 = TRISB4 = TRISB5 = TRISB6 = 1;
    TRISD = 0x00;
    PORTD = 0X00;
    
    while(1) {
        RB0 = 1;
        RB1 = RB2 = 0;
        
        if(RB3 == 1) {
            while(RB3 == 1);
            PORTD = data[1];
        }
        
        if(RB4 == 1) {
            while(RB4 == 1);
            PORTD = data[4];
        }
        
        if(RB5 == 1) {
            while(RB5 == 1);
            PORTD = data[7];
        }
        
        if(RB6 == 1) {
            while(RB6 == 1);
            PORTD = data[0];
        }
        
        RB1 = 1;
        RB0 = RB2 = 0;
        
        if(RB3 == 1) {
            while(RB3 == 1);
            PORTD = data[2];
        }
        
        if(RB4 == 1) {
            while(RB4 == 1);
            PORTD = data[5];
        }
        
        if(RB5 == 1) {
            while(RB5 == 1);
            PORTD = data[8];
        }
        
        if(RB6 == 1) {
            while(RB6 == 1);
            PORTD = data[0];
        }
        
        RB2 = 1;
        RB0 = RB1 = 0;
        
        if(RB3 == 1) {
            while(RB3 == 1);
            PORTD = data[3];
        }
        
        if(RB4 == 1) {
            while(RB4 == 1);
            PORTD = data[6];
        }
        
        if(RB5 == 1) {
            while(RB5 == 1);
            PORTD = data[9];
        }
        
        if(RB6 == 1) {
            while(RB6 == 1);
            PORTD = data[0];
        }
    }
}
