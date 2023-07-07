/*
 * TIMER1_priv.h
 *
 *  Created on: ٢٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER1_TIMER1_PRIV_H_
#define TIMER1_TIMER1_PRIV_H_

#define TCCR1A      *((volatile u8*)0x4F)
#define TCCR1B      *((volatile u8*)0x4E)

#define  ICES1_bit    6


#define TCNT1L      *((volatile u16*)0x4C)
#define TCNT1H      *((volatile u8*)0x4D)

#define OCR1AL      *((volatile u8*)0x4A)
#define OCR1AH      *((volatile u8*)0x4B)

#define ICR1L      *((volatile u16*)0x46)
#define ICR1H      *((volatile u8*)0x47)

#define TIMSK      *((volatile u8*)0x59)
#define  TICIE1_BIT   5


#define TIFR      *((volatile u8*)0x58)

#define OCR1BL      *((volatile u8*)0x48)
#define OCR1BH      *((volatile u8*)0x49)






#endif /* TIMER1_TIMER1_PRIV_H_ */
