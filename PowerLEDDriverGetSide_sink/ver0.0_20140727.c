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


char ledcount=0;
char putdata[18][5]={0};
char reservingNow=0;
char fulg=0;
//uartget()
     char i,j,n,test[8][4];
     char getdata[70]={0},getKeeping[17][2],getNum=0,onetime=0,resetFlug=0,gettingSuccess=0;
void change(){
         ledcount++;
         if(RD5==1)
             ledcount=16;

         PORTA=putdata[ledcount][0];
         PORTB=putdata[ledcount][1];
         PORTC=putdata[ledcount][2];
         PORTD=putdata[ledcount][3];
         PORTE=putdata[ledcount][4];

         if(ledcount==16)
            ledcount=0;
}
void uartget(){
//         // 0x 47 65 74 ="Get"
//         if(getNum>69)
//             getNum=0;
//         else if(reservingNow){
//             onetime=getch();
//             getdata[getNum]=onetime;
//             getNum++;
//             reservingNow=0;
//         }
//         if(onetime==0x47)
//             resetFlug=1;
//         else if(resetFlug){
//             if(resetFlug==1){
//                 if(onetime==0x65)
//                     resetFlug==2;
//                 else
//                     resetFlug=0;
//             }
//             else if(resetFlug==2){
//                 if(onetime=0x74)
//                     getNum=0;
//                 else
//                     resetFlug=0;
//             }
//         }
//         if(getNum==64){
//             if(onetime==0x0A)
//                 gettingSuccess=1;
//         }
//         else if(gettingSuccess==1){
//             if(onetime==0x0B)
//                 gettingSuccess=2;
//             else
//                 gettingSuccess=0;
//         }
         gettingSuccess=2;

getdata[0]= 0x51 ;
getdata[1]= 0x8F ;
getdata[2]= 0x3F ;
getdata[3]= 0x8 ;
getdata[4]= 0x40 ;
getdata[5]= 0x0 ;
getdata[6]= 0x0 ;
getdata[7]= 0x18 ;
getdata[8]= 0x48 ;
getdata[9]= 0x0 ;
getdata[10]= 0x0 ;
getdata[11]= 0x8 ;
getdata[12]= 0x40 ;
getdata[13]= 0x0 ;
getdata[14]= 0x0 ;
getdata[15]= 0x28 ;
getdata[16]= 0x44 ;
getdata[17]= 0x0 ;
getdata[18]= 0x0 ;
getdata[19]= 0x8 ;
getdata[20]= 0x40 ;
getdata[21]= 0x0 ;
getdata[22]= 0x0 ;
getdata[23]= 0x48 ;
getdata[24]= 0x42 ;
getdata[25]= 0x0 ;
getdata[26]= 0x0 ;
getdata[27]= 0x8 ;
getdata[28]= 0x7F ;
getdata[29]= 0xFF ;
getdata[30]= 0x3F ;
getdata[31]= 0xFF ;
getdata[32]= 0x7F ;
getdata[33]= 0xFF ;
getdata[34]= 0x3F ;
getdata[35]= 0xFF ;
getdata[36]= 0x40 ;
getdata[37]= 0x0 ;
getdata[38]= 0x0 ;
getdata[39]= 0x8 ;
getdata[40]= 0x40 ;
getdata[41]= 0x0 ;
getdata[42]= 0x0 ;
getdata[43]= 0x8 ;
getdata[44]= 0x40 ;
getdata[45]= 0x0 ;
getdata[46]= 0x0 ;
getdata[47]= 0x8 ;
getdata[48]= 0x40 ;
getdata[49]= 0x0 ;
getdata[50]= 0x0 ;
getdata[51]= 0x8 ;
getdata[52]= 0x40 ;
getdata[53]= 0x0 ;
getdata[54]= 0x0 ;
getdata[55]= 0x8 ;
getdata[56]= 0x40 ;
getdata[57]= 0x0 ;
getdata[58]= 0x0 ;
getdata[59]= 0x8 ;
getdata[60]= 0x41 ;
getdata[61]= 0x8F ;
getdata[62]= 0x3F ;
getdata[63]= 0x8 ;




//         for(i=0;i<64;i++)
//            getdata[i]=0xff;
         if(gettingSuccess==2){
             for(i=1;i<17;i++){
                 for(j=0;j<2;j++){
                     n=(i-1)*4+(j+2);
                     getKeeping[i][j]=getdata[n];
                 }
             }
             for(i=1;i<17;i++){
                 //A
                 putdata[i][0]=(getKeeping[i][1]&0b00011111)<<1;
                 //B
                 putdata[i][1]=getKeeping[i][0];
                 //E
                 putdata[i][4]=(getKeeping[i][1]&0b11100000)>>5;
             }
            putdata[2][0]=putdata[2][0]|0x80;
            putdata[4][0]=putdata[4][0]|0x40;
            putdata[6][2]=putdata[6][2]|0x01;
            putdata[8][2]=putdata[8][2]|0x02;
            putdata[10][2]=putdata[10][2]|0x04;
            putdata[12][2]=putdata[12][2]|0x08;
            putdata[14][3]=putdata[14][3]|0x01;
            putdata[16][3]=putdata[16][3]|0x02;
         }
}
/*******************************************************************************
*  InterTimer()   ??????????                                         *
*******************************************************************************/
void interrupt InterTimer( void )
{
     if (TMR0IF == 1) {           // ????0????????
          TMR0 = T0COUT ;         // ????0????
          uartget();
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
unsigned char E2promRead( unsigned char adr )
{
	EEADR = adr;
	RD = 1;				// Set read bit
	return( EEDATA );		// Return read data
}

/*******************************************************************************
*  ??????                                                                *
*******************************************************************************/
void main()
{

    char individual=255;
     setpin();
     init_comms();
     individual=E2promRead(0x00);
     OPTION_REG = 0b0000010 ; // ??????(Fosc/4)?TIMER0???????????????? 1:128
     TMR0   = T0COUT ;         // ????0????
     TMR0IF = 0 ;              // ????0?????(T0IF)?0???
     time   = 0 ;              // ??????????????0???
     TMR0IE = 1 ;              // ????0???(T0IE)?????
     WPUB = 0xC0;
     nWPUEN = 0;
     GIE    = 0 ;              // ???????????
//     while(individual==getch()){
//         putch(individual);
//         __delay_ms(100);
//     }
     uartget();
     while(1)
     {
         while(RD4==0);
         change();
         while(RD4==1);
         change();
     }

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
}