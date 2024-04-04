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

uint8_t a, b, c, d, e, f;

uint8_t keypad();

void main() {
    TRISB0 = TRISB1 = TRISB2 = 0;
    TRISB3 = TRISB4 = TRISB5 = TRISB6 = 1;
    TRISB7 = 0;
    TRISD = 0x00;
    PORTD = 0x00;
    RB7 = 0;
    
    while(1) {
        a = keypad();
        PORTD = data[a];
        
        b = keypad();
        PORTD = data[b];
        
        c = keypad();
        PORTD = data[c];
        
        d = keypad();
        PORTD = data[d];
        
        if(a == 2 && b == 0 && c == 2 && d == 4) {
            e = keypad();
            PORTD = data[e];
            if(e == 0) {
                RB7 = 1;
            }
        }
        
        else {
            RB7 = 0;
        }
        
        f = keypad();
        PORTD = data[f];
        RB7 = 0;
    }
}

uint8_t keypad() {
    while(1) {
        RB0 = 1;
        RB1 = RB2 = 0;

        if(RB3 == 1) {
            while(RB3 == 1);
            return 1;
        }

        if(RB4 == 1) {
            while(RB4 == 1);
            return 4;
        }

        if(RB5 == 1) {
            while(RB5 == 1);
            return 7;
        }

        if(RB6 == 1) {
            while(RB6 == 1);
            return 0;
        }

        RB1 = 1;
        RB0 = RB2 = 0;

        if(RB3 == 1) {
            while(RB3 == 1);
            return 2;
        }

        if(RB4 == 1) {
            while(RB4 == 1);
            return 5;
        }

        if(RB5 == 1) {
            while(RB5 == 1);
            return 8;
        }

        if(RB6 == 1) {
            while(RB6 == 1);
            return 0;
        }

        RB2 = 1;
        RB0 = RB1 = 0;

        if(RB3 == 1) {
            while(RB3 == 1);
            return 3;
        }

        if(RB4 == 1) {
            while(RB4 == 1);
            return 6;
        }

        if(RB5 == 1) {
            while(RB5 == 1);
            return 9;
        }

        if(RB6 == 1) {
            while(RB6 == 1);
            return 0;
        } 
    }
}
