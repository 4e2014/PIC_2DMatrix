/* 
 * File:   header.h
 * Author: akihiro
 *
 * Created on 2014/07/27, 15:42
 */

#ifndef HEADER_H
#define	HEADER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define EXIT_SUCCESS 0
#define IMAX 16
#define JMAX 3


// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

#define	AN0	RA0
#define	T31	RA1
#define	T29	RA2
#define	T27	RA3
#define	T25	RA4
#define	T23	RA5
#define	T13	RA6
#define	T15	RA7
#define	S15	RB0
#define	S13	RB1
#define	S11	RB2
#define	S9	RB3
#define	S7	RB4
#define	S5	RB5
#define	S3	RB6
#define	S1	RB7
#define	T11	RC0
#define	T9	RC1
#define	T7	RC2
#define	T5	RC3
#define	SW0	RC4
#define	SW1	RC5
#define	TX	RC6
#define	RX	RC7
#define	T3	RD0
#define	T1	RD1
#define	UNUSED	RD2
#define	UNUSED	RD3
#define	CLOCK	RD4
#define	RESET	RD5
#define	LED0	RD6
#define	LED1	RD7
#define	T21	RE0
#define	T19	RE1
#define	T17	RE2
#define	MCLR	RE3


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)



    unsigned char stoc[IMAX][JMAX]={0};
    unsigned char led[IMAX][JMAX]={0};
    unsigned char time=0;

    void no0();
    void no1();
    void no2();
    void no3();
    void noxinit();
    void setpin();
    int countup(char*,char*);
    void setdata();
    void waitstart();


#ifdef	__cplusplus
}
#endif

#endif	/* HEADER_H */

