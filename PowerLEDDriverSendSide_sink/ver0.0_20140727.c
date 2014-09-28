
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


char ledcount=0;
char putdata[18][5]={0};
char reservingNow=0;

void change(){
         ledcount++;

         PORTA=putdata[ledcount][0];
         PORTB=putdata[ledcount][1];
         PORTC=putdata[ledcount][2];
         PORTD=putdata[ledcount][3];
         PORTE=putdata[ledcount][4];

         if(ledcount==16)
            ledcount=0;
}

/*******************************************************************************
*  InterTimer()   ??????????                                         *
*******************************************************************************/
void interrupt InterTimer( void )
{
     if (TMR0IF == 1) {           // ????0????????
          TMR0 = T0COUT ;         // ????0????
//          if(RD7)
//            RD7=0;
//          else
//            RD7=1;

          change();
          if(RCIF)
              reservingNow=1;
//          putch(0x41);
          TMR0IF = 0 ;            // ????0??????????
     }
}
char x2(char num){
    char i,ret=0;
    if(num%2)
        ret=1;
    num=7-num/2;
    for(i=0;i<num;i++)
        ret=ret*2;
    return ret;
}
/*******************************************************************************
*  ??????                                                                *
*******************************************************************************/
void waitdelay(){
    __delay_ms(1);
}
unsigned char E2promRead( unsigned char adr )
{
	EEADR = adr;
	RD = 1;				// Set read bit
	return( EEDATA );		// Return read data
}
void main()
{
     char i,j,n,test[8][4],individual=255;
     char getdata[70]={0},getKeeping[16][2],getNum=0,onetime=0,resetFlug=0,gettingSuccess=0;
     setpin();
     init_comms();
     individual=E2promRead(0x00);
     for(i=0;i<16;i++)
      putdata[i][1]=x2(i);
     OPTION_REG = 0b0000100 ; // ??????(Fosc/4)?TIMER0???????????????? 1:128
     TMR0   = T0COUT ;         // ????0????
     TMR0IF = 0 ;              // ????0?????(T0IF)?0???
     time   = 0 ;              // ??????????????0???
     TMR0IE = 1 ;              // ????0???(T0IE)?????
     WPUB = 0xC0;
     nWPUEN = 0;
     GIE    = 1 ;
     while(1) {
         // 0x 47 65 74 ="Get"
         if(getNum>69)
             getNum=0;
         else if(reservingNow){
             onetime=getch();
             getdata[getNum]=onetime;
             getNum++;
             reservingNow=0;
         }
         if(onetime==0x47)
             resetFlug=1;
         else if(resetFlug){
             if(resetFlug==1){
                 if(onetime==0x65)
                     resetFlug==2;
                 else
                     resetFlug=0;
             }
             else if(resetFlug==2){
                 if(onetime=0x74)
                     getNum=0;
                 else
                     resetFlug=0;
             }
         }
         if(getNum==64){
             if(onetime==0x0A)
                 gettingSuccess=1;
         }
         else if(gettingSuccess==1){
             if(onetime==0x0B)
                 gettingSuccess=2;
             else
                 gettingSuccess=0;
         }
         if(gettingSuccess==2){
             gettingSuccess=0;
             for(i=1;i<17;i++){
                 for(j=0;j<2;j++){
                     n=(i-1)*4+j;
                     getKeeping[i][j]=getdata[n];
                 }
             }
             for(i=1;i<17;i++){
                 //A
                 putdata[i][0]=getKeeping[i][0]&0b11111110;
                 //C
                 putdata[i][2]=getKeeping[i][1]&0b00001111;
                 //D
                 putdata[i][3]=(getKeeping[i][0]&0b00000001)|((getKeeping[i][1]&0b10000000)>>6);
                 if(i==16)
                     putdata[i][3]=putdata[i][3]|0b10110000;
                 else if(i%2==0)
                     putdata[i][3]=putdata[i][3]|0b10010000;
                 //E
                 putdata[i][4]=(getKeeping[i][1]&0b01110000)>>4;
             }
         }
     }
}