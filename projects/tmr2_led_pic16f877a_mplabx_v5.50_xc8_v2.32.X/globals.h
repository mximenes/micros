/*
 * PIC16F877A Samples
 * Sample 09: Timer 2
 * Author: David Nascimento Coelho
 * Last Update: 2021/09/25
 */

#ifndef GLOBALS_H
#define	GLOBALS_H
#endif	/* GLOBALS_H */

// CONFIGURATION BITS

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONSTANTS

#define _XTAL_FREQ 20000000     // Processor frequency for delay functions

#define bot1    !PORTBbits.RB0  // button at RB0 pin
#define led1    PORTBbits.RB1   // led at RB1 pin

#define tm2_pin PORTDbits.RD0   // timer2 output

#define rec_tmr2 49             // number of tmr2 counts - 1

// VARIABLES

volatile unsigned int count2 = 0;        // timer 2 counter
