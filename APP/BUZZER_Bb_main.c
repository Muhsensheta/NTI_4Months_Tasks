/*
 * BUZZER_Bb_main.c
 *
 *  Created on: ٠٥‏/٠٧‏/٢٠٢٣
 *      Author: houras
 */
#if (0)

#include <util/delay.h>

#include "STD_TYPES.h"
#include "DIO_init.h"
#include "SSD_init.h"
#include"PB_init.h"
#include "LCD_int.h"
#include "KEYPAD_init.h"
#include "EXT1_Init.h"
#include "EXT1_config.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include "ADC_Init.h"
#include "TIMER_int.h"
#include "TIMER_priv.h"
#include "TIMER1_priv.h"
#include "TIMER1_int.h"



int main()
 {
	 u8 Read;
	 M_DIO_void_SetPinDir(PORTA, PIN4, OUT);
	 M_DIO_void_SetPinDir(PORTC, PIN6, OUT);


	 H_void_PB1_init();
	 while (1)
	 {
		H_void_PB_Read(&Read) ;
		if (Read==0)
		{
			M_DIO_void_SetPinValue(PORTA, PIN4, HIGH);
			_delay_ms(500);
			M_DIO_void_SetPinValue(PORTC, PIN6, HIGH);

			_delay_ms(500);
		}
		else
		{
			M_DIO_void_SetPinValue(PORTA, PIN4, LOW);
			_delay_ms(500);
			M_DIO_void_SetPinValue(PORTC, PIN6, LOW);
			_delay_ms(500);

		}
	 }
	return 0;
 }

#endif


