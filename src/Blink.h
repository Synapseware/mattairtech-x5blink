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
#if defined(__AVR_ATxmega64A3U__) || defined(__AVR_ATxmega128A3U__) || defined(__AVR_ATxmega128C3__) || defined(__AVR_ATxmega128D3__) \
|| defined(__AVR_ATxmega256A3BU__) || defined(__AVR_ATxmega256C3__) || defined(__AVR_ATxmega256D3__) || defined(__AVR_ATxmega384C3__) || defined(__AVR_ATxmega384D3__)
#define LED_PORT	&PORTF
#define LED_PIN		(1 << 6)

#elif defined(__AVR_ATxmega16C4__) || defined(__AVR_ATxmega32A4U__) || defined(__AVR_ATxmega32C4__) || defined(__AVR_ATxmega32D4__) \
|| defined(__AVR_ATxmega64A4U__) || defined(__AVR_ATxmega128A4U__) || defined(__AVR_ATxmega128D4__)
#define LED_PORT	&PORTE
#define LED_PIN		(1 << 1)

#elif defined(__AVR_ATxmega32E5__)
#define LED_PORT	&PORTC
#define LED_PIN		(1 << 2)

#else
#error Incompatible chip
#endif

// Atmel toolchain has this macro named PROTECTED_WRITE
#ifndef _PROTECTED_WRITE
#define _PROTECTED_WRITE(reg, value) PROTECTED_WRITE(reg, value)
#endif

/** ************** Function Prototypes ************** **/
void board_init(void);
void sysclk_init(void);
void WDT_Disable(void);


#endif
