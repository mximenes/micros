/*
 * PIC16F877A Samples
 * Sample 07: AD Conversion and LCD
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

#define bot1     !PORTBbits.RB0 // button at RB0 pin
#define led1     PORTBbits.RB1  // led at RB1 pin

/* LCD: Always define: */
#define LCD_nbits 8             // number of LCD data bits
#define LCD_RS	PORTEbits.RE0   // LCD command/character selection
#define LCD_EN	PORTEbits.RE1   // LCD enable pin

/* LCD: define on 8 bits mode: */
#define LCD_dat PORTD           // LCD byte for command and character

/* LCD: define on 4 bits mode: */
//#define LCD4	PORTDbits.RD4   // bit 4 of lcd
//#define LCD5	PORTDbits.RD5   // bit 5 of lcd
//#define LCD6	PORTDbits.RD6   // bit 6 of lcd
//#define LCD7	PORTDbits.RD7   // bit 7 of lcd

// VARIABLES

volatile unsigned int ad_value; // get value of conversion
unsigned char ad_char_val[5];   // receive char value
