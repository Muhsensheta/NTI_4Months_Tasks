/*
 * EXT1_priv.h
 *
 *  Created on: ١٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef EXT_INT1_EXT1_PRIV_H_
#define EXT_INT1_EXT1_PRIV_H_

#define MCUCR_REG  *((volatile u8*)0x55)

#define ISC00_BIT   0
#define ISC01_BIT   1
#define ISC10_BIT   2
#define ISC11_BIT   3

//**********************

#define GICR_REG  *((volatile u8*)0x5B)

#define INT0_BIT  6
#define INT1_BIT  7
#define INT2_BIT  5

//*************************
#define GIFR_REG  *((volatile u8*)0x5A)

#define INTF0_BIT  6
#define INTF1_BIT  7
#define INTF2_BIT  5



#endif /* EXT_INT1_EXT1_PRIV_H_ */
