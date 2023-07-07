/*
 * DIO_priv.h
 *
 *  Created on: ١٠‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef DIO_DIO_PRIV_H_
#define DIO_DIO_PRIV_H_

//PORTA REG  >>>>>>

#define PORTA_REG        *((volatile u8 *)0x3B)
#define	DDRA	         *((volatile u8 *)0x3A)
#define	PINA_REG         *((volatile u8 *)0x39)

//PORTB REG  >>>>>>

#define	PORTB_REG		*((volatile u8 *)0x38)
#define	DDRB		    *((volatile u8 *)0x37)
#define	PINB_REG		*((volatile u8 *)0x36)

//PORTC REG  >>>>>>

#define	PORTC_REG		*((volatile u8 *)0x35)
#define	DDRC		    *((volatile u8 *)0x34)
#define	PINC_REG		*((volatile u8 *)0x33)

//PORTD REG  >>>>>>

#define	PORTD_REG		*((volatile u8 *)0x32)
#define	DDRD		    *((volatile u8 *)0x31)
#define	PIND_REG		*((volatile u8 *)0x30)





#endif /* DIO_DIO_PRIV_H_ */
