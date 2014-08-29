#include <xc.h>
#include "header.h"
unsigned char E2promRead( unsigned char adr )
{
	EEADR = adr;
	RD = 1;				// Set read bit
	return( EEDATA );		// Return read data
}
void setpin(){
     OSCCON = 0b01110000 ;     // ???????????????
     ANSELA = 0b00000000 ;     // AN0-AN4????????????I/O???
     ANSELB = 0b00000000 ;     // AN8-AN13????????????I/O???
     ANSELD = 0x00 ;     // AN8-AN13????????????I/O???
     ANSELE = 0b00000000 ;     // AN0-AN4????????????I/O???

     TRISA  = 0b00000000 ;     // ??(RA)??????????(0:?? 1:??)
     TRISB  = 0b00000000 ;     //
     TRISC  = 0b10110000 ;     //
     TRISD  = 0b00001100 ;      //RD2,3?????????????
     TRISE  = 0X00  ;

     PORTA  = 0b00000000 ;     // RA????????(??LOW???)
     PORTB  = 0b00000000 ;     // RB????????(??LOW???)
     PORTC  = 0b10000000 ;     // RC????????(??LOW???)
     PORTD  = 0b00000000 ;

     CCP2CON=0x00;
     CCP1CON=0x00;

    CPSCON0 =0x00;
    CPSCON1 =0x00;
    LATD =0x00;
    LCDCON =0x00;
    LCDSE2 =0x00;

}