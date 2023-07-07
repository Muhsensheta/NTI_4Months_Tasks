/*
 * PB_prog.c
 *
 *  Created on: ١٠‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include<util/delay.h>
#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_init.h"
#include "PB_priv.h"
#include "PB_config.h"
#include "PB_init.h"

void  H_void_PB1_init()
{
	M_DIO_void_SetPinDir(PB1_ROW_PORT, PB1_ROW_PIN, OUT);
	M_DIO_void_SetPinDir(PB1_COLM_PORT, PB1_COLM_PIN, IN);
	M_DIO_void_SetPinValue(PB1_ROW_PORT, PB1_ROW_PIN, HIGH);
}
void H_void_PB_Read(u8 *read)
{

 M_DIO_void_GetPinValue(PB1_COLM_PORT, PB1_COLM_PIN, read);
 if (read==0)
 {
	 _delay_ms(100);
	 M_DIO_void_GetPinValue(PB1_COLM_PORT, PB1_COLM_PIN, read);
	 while (read==0)
	 {
		 M_DIO_void_GetPinValue(PB1_COLM_PORT, PB1_COLM_PIN, read);
	 }

 }

}



