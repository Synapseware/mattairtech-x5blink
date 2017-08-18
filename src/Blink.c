/** ***************************************************************************
 * Description       : Blink.c
 *************************************************************************** **/

#include "Blink.h"

int main (void)
{
	WDT_Disable();
	sysclk_init();
	board_init();

	while (1) {
		(LED_PORT)->OUTSET = LED_PIN;
		_delay_ms(500);
		(LED_PORT)->OUTCLR = LED_PIN;
		_delay_ms(500);
	}
}

void sysclk_init(void)
{
	uint8_t temp;
	
	// set prescalers (must use Xmega configuration change protection (CCP) mechanism)
	_PROTECTED_WRITE(CLK_PSCTRL, (CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc));
	
	// enable external crystal
	OSC.XOSCCTRL = (OSC_XOSCSEL_XTAL_16KCLK_gc | OSC_FRQRANGE_12TO16_gc);
	temp = SREG;
	cli();
	OSC.CTRL |= OSC_XOSCEN_bm;
	_MemoryBarrier();
	SREG = temp;
	
	// wait for crystal to be ready
	while (!(OSC.STATUS & OSC_XOSCEN_bm));
	
	// select external crystal as system clock (must use Xmega configuration change protection (CCP) mechanism)
	_PROTECTED_WRITE(CLK_CTRL, CLK_SCLKSEL_XOSC_gc);
	
	// disable default 2MHz RC oscillator
	temp = SREG;
	cli();
	OSC.CTRL &= ~OSC_RC2MEN_bm;
	_MemoryBarrier();
	SREG = temp;
}

void board_init(void)
{
	// set sleep mode (not using yet)
	//set_sleep_mode(SLEEP_MODE_PWR_SAVE);
	
	// disable all peripherals that can be disabled to save power (ATxmega384D3 not yet supported in avr-libc power.h)
#if !defined(__AVR_ATxmega384D3__)
	power_all_disable();
#endif
	
	(LED_PORT)->OUTCLR = LED_PIN;
	(LED_PORT)->DIRSET = LED_PIN;
	
	// enable interrupts (not using yet)
	//PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
	//PMIC.CTRL |= PMIC_RREN_bm;	// round-robin
	//sei();
}

void WDT_Disable(void)
{
	uint8_t temp = (WDT.CTRL & ~WDT_ENABLE_bm) | WDT_CEN_bm;
	
	CCP = CCP_IOREG_gc;
	WDT.CTRL = temp;
}

