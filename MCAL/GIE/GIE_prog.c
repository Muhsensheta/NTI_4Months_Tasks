/*
 * GIE_prog.c
 *
 *  Created on: ١٦‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_init.h"
#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"

void M_void_GIE_Enable()
{
SET_BIT(SREG_REG,I_BIT);
}
void M_void_GIE_disable()
{
 CLR_BIT(SREG_REG,I_BIT);
}


