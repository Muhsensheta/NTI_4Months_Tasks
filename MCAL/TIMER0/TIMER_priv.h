/*
 * TIMER0_priv.h
 *
 *  Created on: ١٨‏/٠٦‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER_TIMER_PRIV_H_
#define TIMER_TIMER_PRIV_H_

#define TCCR0_REG   (*((volatile u8*)0x53))

#define CS00_BIT   0
#define CS01_BIT   1
#define CS02_BIT   2
#define WGM01_BIT  3
#define COM00_BIT  4
#define COM01_BIT  5
#define WGM00_BIT  6
#define FOC0_BIT   7

/************************************/
#define TCNT0_REG     (*((volatile u8*)0x52))

#define OCR0_REG      (*((volatile u8*)0x5C))

#define TIMSK_REG     (*((volatile u8*)0x59))//PIEs
#define TOIE0_BIT   0
#define OCIE0_BIT   1
/**********************************************/
#define TIFR_REG      (*((volatile u8*)0x58))//flags
#define TOV0_BIT   0
#define OCF0_BIT   1

/**********************************************/
#define TIMER0_NORMAL_MODE                    1
#define TIMER0_CTC_MODE                       2
#define TIMER0_FAST_PWM_MODE                  3
#define TIMER0_PHASECORRECT_MODE              4


#define TIMER0_PRESCALER_NO_CLK               0
#define TIMER0_PRESCALER_NO_PRESCALER         1
#define TIMER0_PRESCALER_8                    2
#define TIMER0_PRESCALER_64                   3
#define TIMER0_PRESCALER_256                  4
#define TIMER0_PRESCALER_1024                 5
#define TIMER0_PRESCALER_EXTCLK_FALL_EDGE     6
#define TIMER0_PRESCALER_EXTCLK_RAIS_EDGE     7



#define TIMER0_OC0_MODE_DISSCONECTED          0
#define TIMER0_OC0_MODE_TOGGLE                1
#define TIMER0_OC0_MODE_CLEAR                 2
#define TIMER0_OC0_MODE_SET                   3

#define TIMER0_PRESCALER_MASK      0b11111000


#endif /* TIMER0_TIMER_PRIV_H_ */
