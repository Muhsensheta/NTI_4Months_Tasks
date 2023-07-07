/*
 * KEYPAD_prog.c
 *
 *  Created on: ١٢‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include<util/delay.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_init.h"

#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"
#include "KEYPAD_init.h"

void H_KP_void_init()
{
	//set all rows directions as output
	M_DIO_void_SetPinDir(KEYPAD_R0_PORT, KEYPAD_R0_PIN,OUT);
	M_DIO_void_SetPinDir(KEYPAD_R1_PORT, KEYPAD_R1_PIN,OUT);
	M_DIO_void_SetPinDir(KEYPAD_R2_PORT, KEYPAD_R2_PIN,OUT);
	M_DIO_void_SetPinDir(KEYPAD_R3_PORT, KEYPAD_R3_PIN,OUT);
	//set all cols directions as INPUTS
	M_DIO_void_SetPinDir(KEYPAD_C0_PORT, KEYPAD_C0_PIN,IN);
	M_DIO_void_SetPinDir(KEYPAD_C1_PORT, KEYPAD_C1_PIN,IN);
	M_DIO_void_SetPinDir(KEYPAD_C2_PORT, KEYPAD_C2_PIN,IN);
	M_DIO_void_SetPinDir(KEYPAD_C3_PORT, KEYPAD_C3_PIN,IN);
	//set all Rows pins high values
	M_DIO_void_SetPinValue(KEYPAD_R0_PORT, KEYPAD_R0_PIN, HIGH);
	M_DIO_void_SetPinValue(KEYPAD_R1_PORT, KEYPAD_R1_PIN, HIGH);
	M_DIO_void_SetPinValue(KEYPAD_R2_PORT, KEYPAD_R2_PIN, HIGH);
	M_DIO_void_SetPinValue(KEYPAD_R3_PORT, KEYPAD_R3_PIN, HIGH);
// SET COLS INTERNAL PULLUP
	M_DIO_void_SetPinValue(KEYPAD_C0_PORT, KEYPAD_C0_PIN, HIGH);
		M_DIO_void_SetPinValue(KEYPAD_C1_PORT, KEYPAD_C1_PIN, HIGH);
		M_DIO_void_SetPinValue(KEYPAD_C2_PORT, KEYPAD_C2_PIN, HIGH);
		M_DIO_void_SetPinValue(KEYPAD_C3_PORT, KEYPAD_C3_PIN, HIGH);



}
u8 H_KP_u8_GetPressedKey()
{
	u8 State = NON_PRESSED_KEY;
	u8 locRow;
	u8 LocCols;
	u8 KP_Arr[4][4]=KEYPAD_ARR_1;
	u8 Read;
	u8 Key;
	u8 KP_ROWS_PINS[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 KP_COLS_PINS[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};


	for (locRow=0;locRow<4;locRow++)
	{
		M_DIO_void_SetPinValue(KEYPAD_ROW_PORTS,KP_ROWS_PINS[locRow], LOW);
		for(LocCols=0;LocCols<4;LocCols++)
		{
		  M_DIO_void_GetPinValue(KEYPAD_COLS_PORTS,  KP_COLS_PINS[LocCols], &Read);
		  if (Read==0)
		  {
			  _delay_ms(100);
			  M_DIO_void_GetPinValue(KEYPAD_COLS_PORTS,  KP_COLS_PINS[LocCols], &Read);

				  while (Read==0){
					  M_DIO_void_GetPinValue(KEYPAD_COLS_PORTS,  KP_COLS_PINS[LocCols], &Read);


				  }//while
				  Key=KP_Arr[locRow ][LocCols ];
				  return Key;
			  //second if

		  }//first if
	    }//Second  for
		M_DIO_void_SetPinValue(KEYPAD_ROW_PORTS,KP_ROWS_PINS[locRow], HIGH);
	}//first for
		return State;


}
