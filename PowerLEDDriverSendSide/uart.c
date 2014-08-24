#include <xc.h>
#include "uart.h"

void putch( unsigned char Data){
	while(!TRMT){}
	TXREG = Data;
}

unsigned char getch(){	/* retrieve one byte */
	while(!RCIF){}		/* set when register is not empty */
	RCIF=0;
	return RCREG;
}