/*
 * PIC16F877A Samples
 * Sample 07: AD Conversion and LCD
 * Author: David Nascimento Coelho
 * Last Update: 2018/05/11
 */

// LIBRARIES INCLUDE

#include <xc.h>
#include <stdlib.h>
#include "globals.h"
#include "lcd.h"

// FUNCTIONS

/* Interruption Service Routine */
void __interrupt() myIsr(void)
{
    // Extern Interruption
    if(INTCONbits.INTE && INTCONbits.INTF)
    {
        INTCONbits.INTF = 0;
        led1 = ~led1;
    }
}

// Sampling function 1
void amost1(unsigned int *value)
{
    __delay_us(100);                        // wait 100uS 
    ADCON0bits.GO_nDONE = 1;                // init AD
    while(ADCON0bits.GO_nDONE);             // wait ad conversion finish
    *value = (unsigned int)(ADRESH << 8) + (ADRESL); // get 10 bits value
}

// Sampling function 2
unsigned int amost2(void)
{
    unsigned int value;
    __delay_us(100);                        // wait 100uS 
    ADCON0bits.GO_nDONE = 1;                // init AD
    while(ADCON0bits.GO_nDONE);             // wait ad conversion finish
    value = (unsigned int)(ADRESH << 8) + (ADRESL); // get 10 bits value
    return value;
}

/* Set all Needed registers */
void init(void)
{
// I/O
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    TRISD = 0b00000000;
    PORTE = 0b00000000;

    TRISA = 0b00000001;
    TRISB = 0b00000001;
    TRISC = 0b00000000;
    PORTD = 0b00000000;
    TRISE = 0b00000000;
    
// INT EXT & TMR0
    OPTION_REG = 0b10000001;
 /*	   			   ||||||||
	   			   |||||||ps0 -> preescaler 1:4
	   			   ||||||ps1 -^
	   			   |||||ps2 -^
	  			   ||||PSA (=0 pre-escaler para timer0)
	   			   |||TMR0SE (qdo como contador)
	   			   ||TMR0CS (=0 timer)
	  			   |INTEDG (int ext / =0 falling edge)
	   			   !PORTB Pull-up enable (=1 disabled)
*/
    INTCON = 0b00010000;
/*	   		   ||||||||
	   		   |||||||RBIF
	   		   ||||||INTF
	   		   |||||TMR0IF
	  		   ||||RBIE
	   		   |||INTE
	   		   ||TMR0IE
	  		   |PEIE		//TIMER 1 e 2, AD, Serial... 
	   		   GIE			//sao considerados perifericos
*/    

// CCP
    CMCON = 0x07;   // desabilita modulos comparadores

// AD
    ADCON0 = 0b10000001;
/*             ||||||||
               |||||||ADON
               ||||||GO_nDONE
               ||||CHS0
               |||CHS1
               ||CHS2
               |ADCS0
               ADCS1
 */
    ADCON1 = 0b10001110;
 /*            ||||||||
               |||||||PCFG0
               ||||||PCFG1
               |||||PCFG2
               ||||PCFG3
               ||| nao imp
               ||nao imp
               |ADCS2
               ADFM (=1 - � direita)
*/
}

void main(void) 
{
    // disable all interrupts
    INTCONbits.GIE = 0;
    
    // initialization routine
    init();
    
    // enable all interrupts
    INTCONbits.GIE = 1;
    
    // initialize LCD
    lcd_init();
    
    // write LCD
    lcd_goto(1,1);
    lcd_puts("A/D CONVERSION",14);

    // Infinity loop
    while(1)
    {
        // choose between the next two functions
        amost1(&ad_value);      
        //ad_value = amost2();
        ad_value = ad_value/2;
        // convert int value for string
        itoa(ad_char_val, ad_value, 10);
        // print char value at lcd
        lcd_goto(2,1);
        lcd_puts(ad_char_val,3);
        // wait 1s
        __delay_ms(1000);
    }
    return;
}
