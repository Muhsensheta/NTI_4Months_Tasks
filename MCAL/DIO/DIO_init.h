/*
 * DIO_init.h
 *
 *  Created on: ١٠‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef DIO_DIO_INIT_H_
#define DIO_DIO_INIT_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

typedef enum {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7} PIN_T;

#define  IN     0
#define  OUT    1

#define  LOW    0
#define  HIGH   1

void M_DIO_void_SetPinDir  (u8 port,PIN_T pin ,u8 dir);
void M_DIO_void_SetPinValue(u8 port,PIN_T pin ,u8 val);
void M_DIO_void_TogPinValue(u8 port,PIN_T pin );
u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

void M_DIO_void_GetPinValue(u8 port,PIN_T pin ,u8 *pval);

#endif /* DIO_DIO_INIT_H_ */
