
#ifndef LIB_MEMMAP128_H_
#define LIB_MEMMAP128_H_

/* DIO_Registers */
//data direction register
#define DDRA	(*(volatile unsigned char*)0x3A)
#define DDRB	(*(volatile unsigned char*)0x37)
#define DDRC	(*(volatile unsigned char*)0x34)
#define DDRD	(*(volatile unsigned char*)0x31)
#define DDRE    (*(volatile unsigned char*)0x22)
#define DDRF    (*(volatile unsigned char*)0x61)
#define DDRG    (*(volatile unsigned char*)0x64)
//input control register
#define PINA	(*(volatile unsigned char*)0x39)
#define PINB	(*(volatile unsigned char*)0x36)
#define PINC	(*(volatile unsigned char*)0x33)
#define PIND	(*(volatile unsigned char*)0x30)
#define PINE    (*(volatile unsigned char*)0x21)
#define PINF    (*(volatile unsigned char*)0x20)
#define PING    (*(volatile unsigned char*)0x63)
//output control register
#define PORTA	(*(volatile unsigned char*)0x3B)
#define PORTB	(*(volatile unsigned char*)0x38)
#define PORTC	(*(volatile unsigned char*)0x35)
#define PORTD	(*(volatile unsigned char*)0x32)
#define PORTE   (*(volatile unsigned char*)0x23)
#define PORTF   (*(volatile unsigned char*)0x62)
#define PORTG   (*(volatile unsigned char*)0x65)

/* PA7-PA0 = ADC7-ADC0 */
/* PORTA */
#define PA7     7
#define PA6     6
#define PA5     5
#define PA4     4
#define PA3     3
#define PA2     2
#define PA1     1
#define PA0     0

/* DDRA */
#define DDA7    7
#define DDA6    6
#define DDA5    5
#define DDA4    4
#define DDA3    3
#define DDA2    2
#define DDA1    1
#define DDA0    0

/* PINA */
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

/********************************************************************************************************/
//EXTERNAL INTERRUPT
/* External Interrupt Control Register A - EICRA */
/* Interrupt_Registers */
#define EIMSK   (*(volatile unsigned char*)0x59)
/* External Interrupt Control Register A */
#define EICRA   (*(volatile unsigned char*)0x6A)
/* External Interrupt Control Register B */
#define EICRB   (*(volatile unsigned char*)0x5A)
#define    ISC31        7
#define    ISC30        6
#define    ISC21        5
#define    ISC20        4
#define    ISC11        3
#define    ISC10        2
#define    ISC01        1
#define    ISC00        0
//..................................................................................
/* External Interrupt Control Register B - EICRB */
#define    ISC71        7
#define    ISC70        6
#define    ISC61        5
#define    ISC60        4
#define    ISC51        3
#define    ISC50        2
#define    ISC41        1
#define    ISC40        0
//......................................................................................
/* ADC_Registers */
//ADMUX REGISTER AND ITS USED BITS
#define ADMUX (*(volatile unsigned char*)0x27)
#define ADLAR 5
#define REFS0 6
#define REFS1 7
//ADCSRA REGISTER AND ITS BITS
#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
//DATA REGISTER HIGH AAND LOW AND WE CAN COMBINE THEM IN ONE NAME ADC
#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)
#define ADC (*(volatile unsigned short*)0x24)
//..............................................................................................

/*WATCH DOG TIMER*/
//REGISTER TO CONTROL AND ITS BITS
#define WDTCR (*(volatile unsigned char*)0x41)
/* bits 7-5 reserved */
#define WDCE    4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

/****************************************************************************************************/

/*TIMER 0*/
/* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0
#define MCUSR   (*(volatile unsigned char*)0x54)
#define MCUCR   (*(volatile unsigned char*)0x55)

#define TWCR    (*(volatile unsigned char*)0x56)


#define TIFR    (*(volatile unsigned char*)0x58)

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* TIFR */
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2

#define TIMSK   (*(volatile unsigned char*)0x57)

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define GIFR    (*(volatile unsigned char*)0x5A)
#define GICR    (*(volatile unsigned char*)0x5B)

#define OCR0    (*(volatile unsigned char*)0x51)
/****************************************************************************************************/

/*TIMER 1*/
/* Timer 1 */

#define ICR1         (*(volatile unsigned short*)0x46)
#define ICR1L        (*(volatile unsigned char*)0x46)
#define ICR1H        (*(volatile unsigned char*)0x47)

#define ICR3         (*(volatile unsigned short*)0x80)
#define ICR3L        (*(volatile unsigned char*)0x80)
#define ICR3H        (*(volatile unsigned char*)0x81)


#define OCR1C        (*(volatile unsigned short*)0x78)
#define OCR1CL       (*(volatile unsigned char*)0x78)
#define OCR1CH       (*(volatile unsigned char*)0x79)


#define OCR1B        (*(volatile unsigned short*)0x48)
#define OCR1BL       (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)


#define OCR3A       (*(volatile unsigned short*)0x86)
#define OCR3AL      (*(volatile unsigned char*)0x86)
#define OCR3AH      (*(volatile unsigned char*)0x87)

#define OCR3C        (*(volatile unsigned short*)0x82)
#define OCR3CL       (*(volatile unsigned char*)0x82)
#define OCR3CH       (*(volatile unsigned char*)0x83)


#define OCR3B        (*(volatile unsigned short*)0x84)
#define OCR3BL       (*(volatile unsigned char*)0x84)
#define OCR3BH       (*(volatile unsigned char*)0x85)


#define OCR1A       (*(volatile unsigned short*)0x4A)
#define OCR1AL      (*(volatile unsigned char*)0x4A)
#define OCR1AH      (*(volatile unsigned char*)0x4B)

#define TCNT1       (*(volatile unsigned short*)0x4C)
#define TCNT1L      (*(volatile unsigned char*)0x4C)
#define TCNT1H      (*(volatile unsigned char*)0x4D)

#define TCNT3       (*(volatile unsigned short*)0x88)
#define TCNT3L      (*(volatile unsigned char*)0x88)
#define TCNT3H      (*(volatile unsigned char*)0x89)

#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0
#define TCCR1A        (*(volatile unsigned char*)0x4F)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define COM1C0  2
#define COM1C1  3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
//timer3
#define TCCR3A        (*(volatile unsigned char*)0x8B)
#define COM3A1  7
#define COM3A0  6
#define COM3B1  5
#define COM3B0  4
#define FOC3A   3
#define COM3C0  2
#define COM3C1  3
#define FOC3B   2
#define WGM31   1
#define WGM30   0

#define TCCR3B       (*(volatile unsigned char*)0x8A)
#define ICNC3   7
#define ICES3   6
/* bit 5 reserved */
#define WGM33   4
#define WGM32   3
#define CS32    2
#define CS31    1
#define CS30    0



#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)

#define ETIMSK      (*(volatile unsigned char*)0x7D)
#define OCIE1C   0

/* ETIMSK */
#define TICIE3  5
#define OCIE3A  4
#define OCIE3B  3
#define TOIE3   2
#define OCIE3C   1

#define ETIFR    (*(volatile unsigned char*)0x7C)

/* ETIFR */
#define ICF3    5
#define OCF3A   4
#define OCF3B   3
#define TOV3    2
#define OCF3C   1
#define OCF1C   0

//...........................................................................................
//TIMER 2
/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0
//.........................................................................................
//UAART0

/* USART0 Baud Rate Register Low */
#define UBRR0L    (*(volatile unsigned char*)0x29)

/* USART0 Control and Status Register B */
#define UCSR0B   (*(volatile unsigned char*)0x2A)

/* USART0 Control and Status Register A */
#define UCSR0A    (*(volatile unsigned char*)0x2B)

/* USART0 I/O Data Register */
#define UDR0       (*(volatile unsigned char*)0x2C)

/* USART0 Baud Rate Register High */
#define UBRR0H    (*(volatile unsigned char*)0x90)

/* USART0 Control and Status Register C */
#define UCSR0C     (*(volatile unsigned char*)0x95)



/* USART0 Status Register A - UCSR0A */
#define    RXC0         7
#define    TXC0         6
#define    UDRE0        5
#define    FE0          4
#define    DOR0         3
#define    UPE0         2
#define    U2X0         1
#define    MPCM0        0

/* USART0 Control Register B - UCSR0B */
#define    RXCIE0       7
#define    TXCIE0       6
#define    UDRIE0       5
#define    RXEN0        4
#define    TXEN0        3
#define    UCSZ02       2
#define    RXB80        1
#define    TXB80        0

/* USART0 Register C - UCSR0C */
#define    UMSEL0       6
#define    UPM01        5
#define    UPM00        4
#define    USBS0        3
#define    UCSZ01       2
#define    UCSZ00       1
#define    UCPOL0       0
//........................................................
//UART1

/* USART1 Baud Rate Register High */
#define UBRR1H     (*(volatile unsigned char*)0x98)

/* USART1 Baud Rate Register Low*/
#define UBRR1L    (*(volatile unsigned char*)0x99)

/* USART1 Control and Status Register B */
#define UCSR1B    (*(volatile unsigned char*)0x9A)

/* USART1 Control and Status Register A */
#define UCSR1A     (*(volatile unsigned char*)0x9B)

/* USART1 I/O Data Register */
#define UDR1     (*(volatile unsigned char*)0x9C)

/* USART1 Control and Status Register C */
#define UCSR1C    (*(volatile unsigned char*)0x9D)


/* USART1 Status Register A - UCSR1A */
#define    RXC1         7
#define    TXC1         6
#define    UDRE1        5
#define    FE1          4
#define    DOR1         3
#define    UPE1         2
#define    U2X1         1
#define    MPCM1        0

/* USART1 Control Register B - UCSR1B */
#define    RXCIE1       7
#define    TXCIE1       6
#define    UDRIE1       5
#define    RXEN1        4
#define    TXEN1        3
#define    UCSZ12       2
#define    RXB81        1
#define    TXB81        0

/* USART1 Register C - UCSR1C */
#define    UMSEL1       6
#define    UPM11        5
#define    UPM10        4
#define    USBS1        3
#define    UCSZ11       2
#define    UCSZ10       1
#define    UCPOL1       0

//

/* USART Status Register A (generic) */
#define    RXC          7
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0

/* USART Control Register B (generic) */
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2       /* new name in datasheet (2467E-AVR-05/02) */
#define    RXB8         1
#define    TXB8         0

/* USART Register C (generic) */
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0
//.........................................................................................
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

/* SPI Status Register */
#define SPSR      (*(volatile unsigned char*)0x2E)
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

//..........................................................................................
//I2C

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0
//...........................................................................
/* MCUCSR */
#define JTD     7
#define ISC2    6
/* bit 5 reserved */
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

/* SFIOR */
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5
/* bit 4 reserved */
#define ACME    3
#define PUD     2
#define PSR2    1
#define PSR10   0


/* ASSR */
/* bits 7-4 reserved */
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0



//.............................................................
//STORE MEMORY
/* SPMCR */
#define SPMIE   7
#define RWWSB   6
/* bit 5 reserved */
#define RWWSRE  4
#define BLBSET  3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0
//.............................................................................
/* Interrupt vectors      for atmega 128*/


/* External Interrupt Request 0 */
#define INT0_vect			    _VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect			    _VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect			    _VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)

/* External Interrupt Request 3 */
#define INT3_vect			_VECTOR(4)
#define SIG_INTERRUPT3			_VECTOR(4)

/* External Interrupt Request 4 */
#define INT4_vect			_VECTOR(5)
#define SIG_INTERRUPT4			_VECTOR(5)

/* External Interrupt Request 5 */
#define INT5_vect			_VECTOR(6)
#define SIG_INTERRUPT5			_VECTOR(6)

/* External Interrupt Request 6 */
#define INT6_vect			_VECTOR(7)
#define SIG_INTERRUPT6			_VECTOR(7)

/* External Interrupt Request 7 */
#define INT7_vect			_VECTOR(8)
#define SIG_INTERRUPT7			_VECTOR(8)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		_VECTOR(9)
#define SIG_OUTPUT_COMPARE2		_VECTOR(9)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			_VECTOR(10)
#define SIG_OVERFLOW2			_VECTOR(10)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		_VECTOR(11)
#define SIG_INPUT_CAPTURE1		_VECTOR(11)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		_VECTOR(12)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(12)

/* Timer/Counter Compare Match B */
#define TIMER1_COMPB_vect		_VECTOR(13)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(13)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			_VECTOR(14)
#define SIG_OVERFLOW1			_VECTOR(14)

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		_VECTOR(15)
#define SIG_OUTPUT_COMPARE0		_VECTOR(15)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			_VECTOR(16)
#define SIG_OVERFLOW0			_VECTOR(16)

/* SPI Serial Transfer Complete */
#define SPI_STC_vect			_VECTOR(17)
#define SIG_SPI				_VECTOR(17)

/* USART0, Rx Complete */
#define USART0_RX_vect			_VECTOR(18)

/* USART0 Data Register Empty */
#define USART0_UDRE_vect		_VECTOR(19)


/* USART0, Tx Complete */
#define USART0_TX_vect			_VECTOR(20)


/* ADC Conversion Complete */
#define ADC_vect			_VECTOR(21)
#define SIG_ADC				_VECTOR(21)

/* EEPROM Ready */
#define EE_READY_vect			_VECTOR(22)
#define SIG_EEPROM_READY		_VECTOR(22)

/* Analog Comparator */
#define ANALOG_COMP_vect		_VECTOR(23)
#define SIG_COMPARATOR			_VECTOR(23)

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect		_VECTOR(24)
#define SIG_OUTPUT_COMPARE1C		_VECTOR(24)

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect		_VECTOR(25)
#define SIG_INPUT_CAPTURE3		_VECTOR(25)

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect		_VECTOR(26)
#define SIG_OUTPUT_COMPARE3A		_VECTOR(26)

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect		_VECTOR(27)
#define SIG_OUTPUT_COMPARE3B		_VECTOR(27)

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect		_VECTOR(28)
#define SIG_OUTPUT_COMPARE3C		_VECTOR(28)

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect			_VECTOR(29)
#define SIG_OVERFLOW3			_VECTOR(29)

/* USART1, Rx Complete */
#define USART1_RX_vect			_VECTOR(30)
#define SIG_USART1_RECV			_VECTOR(30)
#define SIG_UART1_RECV			_VECTOR(30)

/* USART1, Data Register Empty */
#define USART1_UDRE_vect		_VECTOR(31)
#define SIG_USART1_DATA			_VECTOR(31)
#define SIG_UART1_DATA			_VECTOR(31)

/* USART1, Tx Complete */
#define USART1_TX_vect			_VECTOR(32)
#define SIG_USART1_TRANS		_VECTOR(32)
#define SIG_UART1_TRANS			_VECTOR(32)

/* 2-wire Serial Interface */
#define TWI_vect			_VECTOR(33)
#define SIG_2WIRE_SERIAL		_VECTOR(33)

/* Store Program Memory Read */
#define SPM_READY_vect			_VECTOR(34)
#define SIG_SPM_READY			_VECTOR(34)


/*interrupt functions*/
#  define __INTR_ATTRS used, externally_visible

#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#define _VECTOR(N) __vector_ ## N

# define sei()  __asm__ __volatile__   ("sei" ::)
# define cli()  __asm__ __volatile__   ("cli" ::)
#  define reti()  __asm__ __volatile__ ("reti" ::)


#endif /* LIB_MEMMAP128_H_ */
