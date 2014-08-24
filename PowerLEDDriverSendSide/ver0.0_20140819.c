/*
 * File:   ver0.0_20140727
 * Author: akihiro
 *
 * Created on 2014/07/27, 14:38
 */

#include <xc.h>
#include "header.h"
#include "uart.h"

#define NO 0
#define T0COUT     61   // ??????????????(256 - 195 = 61)


//CLOCK???
#define MHz 000000
#define	_XTAL_FREQ 32MHz
//??????
#define DEB	RB2

void changeLED(){
    if(time==0)
        noxinit();
    else if(NO==0)
        no0(time);
    else if(NO==1)
        no1(time);
    else if(NO==2)
        no2(time);
    else if(NO==3)
        no3(time);
}

/*******************************************************************************
*  InterTimer()   ??????????                                         *
*******************************************************************************/
void interrupt InterTimer( void )
{
     if (TMR0IF == 1) {           // ????0????????
          TMR0 = T0COUT ;         // ????0????
          time++ ;               // ???????????????
          changeLED();
          putch(0x09);
          TMR0IF = 0 ;            // ????0??????????
     }
}
/*******************************************************************************
*  ??????                                                                *
*******************************************************************************/
void main()
{
     char i,j;
     unsigned char stoclocal;
     char test[8][4];
     setpin();

     OPTION_REG = 0b00000110 ; // ??????(Fosc/4)?TIMER0???????????????? 1:128
     TMR0   = T0COUT ;         // ????0????
     TMR0IF = 0 ;              // ????0?????(T0IF)?0???
     time   = 0 ;              // ??????????????0???
     TMR0IE = 1 ;              // ????0???(T0IE)?????
     WPUB = 0xC0;
     nWPUEN = 0;
     GIE    = 0 ;              // ???????????
//test[0][0]=0xFF;
//test[0][1]=0xFF;
//test[0][2]=0xFF;
//test[0][3]=0xFF;
//test[1][0]=0xFF;
//test[1][1]=0xFF;
//test[1][2]=0xFF;
//test[1][3]=0xFF;
//test[2][0]=0xFF;
//test[2][1]=0xFF;
//test[2][2]=0xFF;
//test[2][3]=0xFF;
//test[3][0]=0xFF;
//test[3][1]=0xFF;
//test[3][2]=0xFF;
//test[3][3]=0xFF;
//test[4][0]=0xFF;
//test[4][1]=0xFF;
//test[4][2]=0xFF;
//test[4][3]=0xFF;
//test[5][0]=0xFF;
//test[5][1]=0xFF;
//test[5][2]=0xFF;
//test[5][3]=0xFF;
//test[6][0]=0xFF;
//test[6][1]=0xFF;
//test[6][2]=0xFF;
//test[6][3]=0xFF;
//test[7][0]=0xFF;
//test[7][1]=0xFF;
//test[7][2]=0xFF;
//test[7][3]=0xFF;
//test[0][0]=0x2C;
//test[0][1]=0x49;
//test[0][2]=0xF3;
//test[0][3]=0x59;
//test[1][0]=0xF8;
//test[1][1]=0x7B;
//test[1][2]=0x2B;
//test[1][3]=0x8D;
//test[2][0]=0xA5;
//test[2][1]=0xCA;
//test[2][2]=0xC3;
//test[2][3]=0x3;
//test[3][0]=0xC3;
//test[3][1]=0x2E;
//test[3][2]=0xB9;
//test[3][3]=0x8C;
//test[4][0]=0xC1;
//test[4][1]=0xD2;
//test[4][2]=0x9E;
//test[4][3]=0x1E;
//test[5][0]=0x8B;
//test[5][1]=0x4E;
//test[5][2]=0xFB;
//test[5][3]=0x8E;
//test[6][0]=0x63;
//test[6][1]=0x80;
//test[6][2]=0xD2;
//test[6][3]=0x67;
//test[7][0]=0xDF;
//test[7][1]=0xFA;
//test[7][2]=0x40;
//test[7][3]=0x40;
	PORTB=0x00;
        PORTA=0xFF;
        PORTC=0xFF;
        PORTD=0b01111111;
     while(1){
         PORTB=0b00000001;
         PORTB=0x00;
         PORTB=0b00000010;
         PORTB=0x00;
         PORTB=0b00000100;
         PORTB=0x00;
         PORTB=0b00001000;
         PORTB=0x00;
         PORTB=0b00010000;
         PORTB=0x00;
         PORTB=0b00100000;
         PORTB=0x00;
         PORTB=0b01000000;
         PORTB=0x00;
         PORTB=0b10000000;
         PORTB=0x00;
    }
//     while(1){
//         RD6=0;
//         RD7=0;
//     }
//     while(1){
//         __delay_ms(500);
//         RD7=1;
//         __delay_ms(500);
//         RD6=1;
//         __delay_ms(500);
//         RD7=0;
//         __delay_ms(500);
//         RD6=0;
//     }
     while(1) {
         waitstart();
         for(i=0;i<IMAX;i++){
             for(j=0;j<JMAX;j++){
                 if((stoclocal=getch())==0x0D){
                    stoc[i][j]=0x0D;
                    if(countup(&i,&j));
                    else if((stoclocal=getch())==0x0A){
                        if(0xDD!=getch()){
                            i=IMAX;
                            j=JMAX;
                        }
                    }else{
                        stoc[i][j]==stoclocal;
                    }
                 }
                 else
                     stoc[i][j]=stoclocal;
             }
         }
         if(i>IMAX);
         else{
             if(0x0D==getch()){
                 if(0x0A==getch()){
                     if(0xDD!=getch())
                         setdata();
                 }
             }
         }
     }
}
int countup(char *i,char *j){
    if(*j<JMAX-1)
        *j++;
    else{
        if(*i<IMAX-1){
          *j=0;
          *i++;
        }else{
            *j++;
            *i++;
            return 1;
        }
    }
    return 0;
}
void setdata(){
    char i,j;
    for(i=0;i<IMAX;i++){
        for(j=0;j<JMAX;j++)
            led[i][j]=stoc[i][j];
    }
}
void waitstart(){
    char ch=1;
    do{
        while(getch()==0xFF);
        if(0x53==getch()){
            if(0x54==getch())
                ch=0;
        }
    }while(ch);
}