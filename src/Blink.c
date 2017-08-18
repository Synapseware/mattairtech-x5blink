/** ***************************************************************************
 * Description       : Blink.c
 *************************************************************************** **/

#include "Blink.h"

void sysclk_init(void)
{
	// set prescalers (must use Xmega configuration change protection (CCP) mechanism)
	_PROTECTED_WRITE(CLK_PSCTRL, (CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc));

	// Configure the external crystal
	{
		// enable external crystal (16mhz range)
		OSC.XOSCCTRL = OSC_XOSCSEL_XTAL_16KCLK_gc | OSC_FRQRANGE_12TO16_gc;

		// enable ext osc
		OSC.CTRL |= OSC_XOSCEN_bm;

		// wait for crystal to be ready
		while (!(OSC.STATUS & OSC_XOSCEN_bm));
	}

	// Configure the PLL
	{
		// Set PLL to use ext osc with mult factor of 2 (16MHz * 2 = 32MHz)
		// PLL *MUST* be configured before it can be enabled
		OSC.PLLCTRL = OSC_PLLSRC_XOSC_gc | (2 << OSC_PLLFAC_gp);

		// enable the PLL
		OSC.CTRL |= OSC_PLLEN_bm;

		// wait for PLL to be ready
		while (!(OSC.STATUS & OSC_PLLEN_bm));
	}

	// select PLL as system clock
	_PROTECTED_WRITE(CLK_CTRL, CLK_SCLKSEL_PLL_gc);

	// disable int oscillators
	OSC.CTRL &= ~(OSC_RC32MEN_bm | OSC_RC8MEN_bm | OSC_RC2MEN_bm);
}

void timer_init(void)
{
	//set up for PWM out as well as program clock
	TCC4.CTRLB = 0;

	// configure timer/counter0 (clk/1024)
	TCC4.CTRLA = TC4_CLKSEL2_bm | TC4_CLKSEL1_bm | TC4_CLKSEL0_bm;  

	// configure the period
	TCC4.PER   = F_CPU / 1024 / 2; // 0.5s

	// enable overflow int
	TCC4.INTCTRLA = TC4_OVFINTLVL0_bm;   // Enabled: Overflow interrupt with LOW Priority on port C
}

void board_init(void)
{
	// disable all peripherals that can be disabled to save power (ATxmega384D3 not yet supported in avr-libc power.h)
	power_all_disable();
	power_tc4c_enable();
	power_tc5d_enable();
	
	(LED_PORT)->OUTCLR = LED_PIN;
	(LED_PORT)->DIRSET = LED_PIN;
	
	// enable interrupts (not using yet)
	PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
	PMIC.CTRL |= PMIC_RREN_bm;	// round-robin
	sei();
}

// Disable the WDT timer
void WDT_Disable(void)
{
	uint8_t temp = (WDT.CTRL & ~WDT_ENABLE_bm) | WDT_CEN_bm;
	
	CCP = CCP_IOREG_gc;
	WDT.CTRL = temp;
}

int main (void)
{
	WDT_Disable();
	sysclk_init();
	board_init();
	timer_init();

	PORTD.OUT = 0xFF;
	PORTD.DIRSET = LED_RED | LED_YLW;
	PORTD.OUTCLR = LED_YLW;

	while (1)
	{
		/*
		(LED_PORT)->OUTSET = LED_PIN;
		_delay_ms(500);
		(LED_PORT)->OUTCLR = LED_PIN;
		_delay_ms(500);
		*/
	}
}

ISR(TCC4_OVF_vect)
{
    // Clear interrupt flag
    TCC4.INTFLAGS = TC4_OVFIF_bm;
    // Toggle a pin to tell we were here
    (LED_PORT)->OUTTGL = LED_PIN;
}
