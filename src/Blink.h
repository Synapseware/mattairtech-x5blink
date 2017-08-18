/** ***************************************************************************
 * Description       : Blink.h
 *************************************************************************** **/

#ifndef _BLINK_H_
#define _BLINK_H_


/** ************** Includes ************** **/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/xmega.h>
#include <avr/cpufunc.h>
#include <util/delay.h>


/** ************** Defines ************** **/
// LED
#define LED_PORT	&PORTC
#define LED_PIN		(1 << 2)

#define LED_RED		(1<<1)
#define LED_YLW		(1<<0)

// Atmel toolchain has this macro named PROTECTED_WRITE
#ifndef _PROTECTED_WRITE
#define _PROTECTED_WRITE(reg, value) PROTECTED_WRITE(reg, value)
#endif

/** ************** Function Prototypes ************** **/
void board_init(void);
void sysclk_init(void);
void WDT_Disable(void);
void timer_init(void);

#endif
