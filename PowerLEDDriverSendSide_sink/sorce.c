#include <xc.h>
#include "header.h"
void no0(){
	if(led[0][0]<time)RA2=0;
	if(led[0][1]<time) RA0=0;
	if(led[0][2]<time) RA3=0;
	if(led[1][0]<time) RA1=0;
	if(led[1][1]<time) RA5=0;
	if(led[1][2]<time) RA4=0;
	if(led[2][0]<time) RC2=0;
	if(led[2][1]<time) RA7=0;
	if(led[2][2]<time) RA6=0;
	if(led[3][0]<time) RC1=0;
	if(led[3][1]<time) RC3=0;
	if(led[3][2]<time) RC0=0;
}void no1(){
	if(led[4][0]<time) RA2=0;
	if(led[4][1]<time) RA0=0;
	if(led[4][2]<time) RA3=0;
	if(led[5][0]<time) RA1=0;
	if(led[5][1]<time) RA5=0;
	if(led[5][2]<time) RA4=0;
	if(led[6][0]<time) RC2=0;
	if(led[6][1]<time) RA7=0;
	if(led[6][2]<time) RA6=0;
	if(led[7][0]<time) RC1=0;
	if(led[7][1]<time) RC3=0;
	if(led[7][2]<time) RC0=0;
}void no2(){
	if(led[8][0]<time) RA2=0;
	if(led[8][1]<time) RA0=0;
	if(led[8][2]<time) RA3=0;
	if(led[9][0]<time) RA1=0;
	if(led[9][1]<time) RA5=0;
	if(led[9][2]<time) RA4=0;
	if(led[10][0]<time) RC2=0;
	if(led[10][1]<time) RA7=0;
	if(led[10][2]<time) RA6=0;
	if(led[11][0]<time) RC1=0;
	if(led[11][1]<time) RC3=0;
	if(led[11][2]<time) RC0=0;
}void no3(){
	if(led[12][0]<time) RA2=0;
	if(led[12][1]<time) RA0=0;
	if(led[12][2]<time) RA3=0;
	if(led[13][0]<time) RA1=0;
	if(led[13][1]<time) RA5=0;
	if(led[13][2]<time) RA4=0;
	if(led[14][0]<time) RC2=0;
	if(led[14][1]<time) RA7=0;
	if(led[14][2]<time) RA6=0;
	if(led[15][0]<time) RC1=0;
	if(led[15][1]<time) RC3=0;
	if(led[15][2]<time) RC0=0;
}void noxinit(){
	PORTA=0xFF;
	RC2=1;
	RC1=1;
	RC3=1;
	RC0=1;
}
void setpin(){
     OSCCON = 0b01110000 ;     // ???????????????
     ANSELA = 0b00000000 ;     // AN0-AN4????????????I/O???
     ANSELB = 0b00000000 ;     // AN8-AN13????????????I/O???
     ANSELD = 0b00000000 ;     // AN8-AN13????????????I/O???
     ANSELE = 0b00000000 ;     // AN0-AN4????????????I/O???

     TRISA  = 0b00000000 ;     // ??(RA)??????????(0:?? 1:??)
     TRISB  = 0b00000000 ;     //
     TRISC  = 0b10110000 ;     //
     TRISD  = 0b00001110 ;      //RD2,3?????????????
     TRISE  = 0X00  ;

     PORTA  = 0b00000000 ;     // RA????????(??LOW???)
     PORTB  = 0b00000000 ;     // RB????????(??LOW???)
     PORTC  = 0b10000000 ;     // RC????????(??LOW???)
     PORTD  = 0b00000000 ;

}
