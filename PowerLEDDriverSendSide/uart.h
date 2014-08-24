#ifndef _SERIAL_H_
#define _SERIAL_H_

#define BAUD 38400L
#define NINE 0     /* Use 9bit communication? FALSE=8bit */
#define TOPC 0	  /*?Use PC ? tx?invert */
#define HIGH_SPEED 1


#if NINE == 1
#define NINE_BITS 0x40
#else
#define NINE_BITS 0
#endif

#if HIGH_SPEED == 1
#define SPEED 0x4
#define RATE 16L
#else
#define SPEED 0
#define RATE 64L
#endif

#if TOPC == 1
#define INV 0x10
#else
#define INV 0
#endif

#if defined(_16F87) || defined(_16F88)
	#define RX_PIN TRISB2
	#define TX_PIN TRISB5
#else
	#define RX_PIN TRISC7
	#define TX_PIN TRISC6
#endif

#define DIVIDER ((int)((_XTAL_FREQ)/((RATE)*(BAUD)))-1)

/* Serial initialization */
#define init_comms()\
	RX_PIN = 1;	\
	TX_PIN = 0;		\
	SPBRG = DIVIDER;	\
	RCSTA = (NINE_BITS|0x90);	\
	TXSTA = (SPEED|NINE_BITS|0x20);	\
	BAUDCON = INV

void putch(unsigned char);
unsigned char getch();

#endif