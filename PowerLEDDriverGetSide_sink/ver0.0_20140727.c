/*
 * File:   ver0.0_20140727
 * Author: akihiro
 *
 * Created on 2014/07/27, 14:38
 */

#include <xc.h>
#include <stdlib.h>
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
     char i=1,j,str[10];
     unsigned char stoclocal;
     char test[8][4];
     setpin();
     init_comms();
     OPTION_REG = 0b00000110 ; // ??????(Fosc/4)?TIMER0???????????????? 1:128
     TMR0   = T0COUT ;         // ????0????
     TMR0IF = 0 ;              // ????0?????(T0IF)?0???
     time   = 0 ;              // ??????????????0???
     TMR0IE = 1 ;              // ????0???(T0IE)?????
     WPUB = 0xC0;
     nWPUEN = 0;
     GIE    = 0 ;              // ???????????
    RA1=1;
    RA2=1;
    RA3=1;
    RA4=1;
    RA5=1;
    RB0=1;
    RB1=1;
    RB2=1;
    RB3=1;
    RB4=1;
    RB5=1;
    RB6=1;
    RB7=1;
    RE0=1;
    RE1=1;
    RE2=1;

    PORTA=0xFF;
    PORTB=0xFF;
    PORTC=0xFF;
    PORTD=0xFF; 
    PORTE=0xFF;
        RA7=0;
        RA6=0;
        RC0=0;
        RC1=0;
        RC2=0;
        RC3=0;
        RD0=0;
        RD1=0;
        i=1;0;
        RD6=1;
     while(1){
         while(RD4==0);
         if(RD5==1)
             i=8;
         //__delay_ms(500);
         switch(i){
            case 1:RA7=1;break;
            case 2:RA6=1;break;
            case 3:RC0=1;break;
            case 4:RC1=1;break;
            case 5:RC2=1;break;
            case 6:RC3=1;break;
            case 7:RD0=1;break;
            case 8:RD1=1;i=0;break;
         }
         //__delay_ms(500);
         while(RD4==1);

        RA7=0;
        RA6=0;
        RC0=0;
        RC1=0;
        RC2=0;
        RC3=0;
        RD0=0;
        RD1=0;
        PORTC=0b11110000;
        PORTA=0b00111111;
        PORTD=0b11111100;

         i++;
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