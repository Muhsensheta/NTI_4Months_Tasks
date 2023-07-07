/*
 * LCD_int.h
 *
 *  Created on: Feb 5, 2023
 *      Author: aya_enan
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

void H_LCD_void_Init(void);   //done
void H_LCD_void_sendData(u8 copy_u8data);//done
void H_LCD_void_sendCommand(u8 copy_u8Command);//done
void H_LCD_void_sendString(const s8 * pstr);//done
void H_LCD_void_clear(void);//done
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_gotXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray, u8 Copy_u8PatternNumber,  u8 Copy_u8Xposition,  u8 Copy_u8Yposition);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);

#endif /* LCD_LCD_INT_H_ */
