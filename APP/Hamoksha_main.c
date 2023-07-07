/*
 * Hamoksha_main.c
 *
 *  Created on: ٠٦‏/٠٧‏/٢٠٢٣
 *      Author: houras
 */
#if (0)

#include <util/delay.h>
#include "BIT_MATH.h"
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



 int main(){
u8 customChar[] = {
			  0x00,
			  0x00,
			  0x0E,
			  0x0E,
			  0x04,
			  0x0E,
			  0x11,
			  0x00
			};
	u8 customChar2[] = { 0x0E, 0x0E,0x15, 0x0E, 0x04, 0x0E, 0x11, 0x00};
	u8 customChar3[] = {  0x07,
			  0x07,
			  0x02,
			  0x12,
			  0x07,
			  0x09,
			  0x00,
			  0x00};
	u8 customChar4[] = {  0x07,
			  0x07,
			  0x02,
			  0x02,
			  0x17,
			  0x09,
			  0x00,
			  0x00};
	u8 customChar5[] = { 0x1F, 0x14,0x1C,0x18,0x10, 0x10, 0x10, 0x10};
	u8 customChar6[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00};
	u8 customChar7[] = { 0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x0E, 0x11, 0x00};
	u8 customChar8[] = {  0x00,
			  0x00,
			  0x00,
			  0x10,
			  0x08,
			  0x07,
			  0x08,
			  0x10};
	u8 customChar9[] = {    0x00,
			  0x00,
			  0x00,
			  0x07,
			  0x07,
			  0x1F,
			  0x00,
			  0x00};
	u8 customChar10[] = { 0x00, 0x0A, 0x00, 0x0E,0x11,0x11, 0x00, 0x00};
	u8 customChar11[] = {0x0A, 0x00, 0x11, 0x11, 0x0E, 0x00,  0x00,0x00};
	H_LCD_void_Init();

	while(1)
	{
		H_LCD_void_sendString("My Name is ");
		H_LCD_void_gotXY(1,3);
		H_LCD_void_sendString("7amoksha");
		H_LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		H_LCD_voidSendCustomCharacter(customChar2,1, 0, 14);

		H_LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		H_LCD_voidSendCustomCharacter(customChar2,1, 0, 14);

		H_LCD_voidSendCustomCharacter(customChar7,3, 0, 14);
		H_LCD_voidSendCustomCharacter(customChar2,1, 0, 14);
		H_LCD_void_clear();

		H_LCD_void_sendString("I Can Play");
		H_LCD_void_gotXY(1,3);
		H_LCD_void_sendString("Football");
		H_LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		H_LCD_voidSendCustomCharacter(customChar4,1, 0, 15);

		H_LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		H_LCD_voidSendCustomCharacter(customChar4,1, 0, 15);

		H_LCD_voidSendCustomCharacter(customChar3,1, 0, 15);
		H_LCD_voidSendCustomCharacter(customChar4,1, 0, 15);
		H_LCD_void_clear();

		H_LCD_void_sendString("Let's Play A");
		H_LCD_void_gotXY(1,2);
		H_LCD_void_sendString("Game");
		H_LCD_voidSendCustomCharacter(customChar11,1, 1, 7);
		_delay_ms(200);
		H_LCD_void_clear();

		H_LCD_void_gotXY(0,4);
		H_LCD_void_sendString("Don't Kill");
		H_LCD_void_gotXY(1,7);
		H_LCD_void_sendString("me");
		H_LCD_voidSendCustomCharacter(customChar5,2, 1, 1);
	//	LCD_voidSendCustomCharacter(customChar6,1, 1, 1);
		H_LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 2);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 4);
		H_LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 6);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 7);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 8);

		H_LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 9);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 10);
		H_LCD_voidSendCustomCharacter(customChar7,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar,3, 1, 14);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 11);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 12);
		H_LCD_voidSendCustomCharacter(customChar6,1, 1, 13);

		H_LCD_voidSendCustomCharacter(customChar7,3, 1, 14);

		H_LCD_void_clear();
		H_LCD_void_sendString("7amoksha is Dead");
		H_LCD_voidSendCustomCharacter(customChar10,1, 1, 7);

		H_LCD_voidSendCustomCharacter(customChar8,2, 1, 12);
		H_LCD_voidSendCustomCharacter(customChar9,3, 1, 13);
		_delay_ms(1000);
		H_LCD_void_clear();

	}


return 0;
}
#endif


