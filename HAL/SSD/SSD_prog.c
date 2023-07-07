/*
 * SSD_prog.c
 *
 *  Created on: ١٠‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_init.h"
#include "SSD_init.h"

void H_SSD_void_Init(void)
{
	M_DIO_void_SetPinDir(PORTB, PIN0, OUT);
	M_DIO_void_SetPinDir(PORTB, PIN1, OUT);
	M_DIO_void_SetPinDir(PORTB, PIN2, OUT);
	M_DIO_void_SetPinDir(PORTB, PIN4, OUT);

	M_DIO_void_SetPinDir(PORTA, PIN3, OUT);
	M_DIO_void_SetPinDir(PORTA, PIN2, OUT);
	M_DIO_void_SetPinDir(PORTB, PIN5, OUT);
	M_DIO_void_SetPinDir(PORTB, PIN6, OUT);

	//FOR ENABLE PINS
	M_DIO_void_SetPinValue(PORTA, PIN3, HIGH);
	M_DIO_void_SetPinValue(PORTA, PIN2, HIGH);
	M_DIO_void_SetPinValue(PORTB, PIN5, HIGH);
	M_DIO_void_SetPinValue(PORTB, PIN6, HIGH);

}
void H_SSD_void_display(u8 number)
{
	u8 units;
	u8 Tens;
	units = number% 10;
	Tens = number/ 10;
	if(number<99)

	{

		switch(units)
		{
		case 0:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 1:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 2:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 3:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 4:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 5:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 6:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 7:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 8:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, HIGH);
			break;
		case 9:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, HIGH);
			break;
		}
		M_DIO_void_SetPinValue(PORTA, PIN3, LOW);
		M_DIO_void_SetPinValue(PORTA, PIN2, HIGH);
		M_DIO_void_SetPinValue(PORTB, PIN5, HIGH);
		M_DIO_void_SetPinValue(PORTB, PIN6, HIGH);
		_delay_ms(10);
		M_DIO_void_SetPinValue(PORTA, PIN3, HIGH);

		switch(Tens)
		{
		case 0:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 1:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 2:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 3:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 4:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 5:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 6:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 7:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN2, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN4, LOW);
			break;
		case 8:
			M_DIO_void_SetPinValue(PORTB, PIN0, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, HIGH);
			break;
		case 9:
			M_DIO_void_SetPinValue(PORTB, PIN0, HIGH);
			M_DIO_void_SetPinValue(PORTB, PIN1, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN2, LOW);
			M_DIO_void_SetPinValue(PORTB, PIN4, HIGH);
			break;
		}
		M_DIO_void_SetPinValue(PORTA, PIN3, HIGH);
		M_DIO_void_SetPinValue(PORTA, PIN2, LOW);
		M_DIO_void_SetPinValue(PORTB, PIN5, HIGH);
		M_DIO_void_SetPinValue(PORTB, PIN6, HIGH);
		_delay_ms(10);
		M_DIO_void_SetPinValue(PORTA, PIN2, HIGH);

	}

}

