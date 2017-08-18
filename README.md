MattairTech xmega32e5 Breakout Board
====================================
Product Page: https://www.mattairtech.com/index.php/development-boards/mt-db-x5.html

# Introduction

The MT-DB-X5 is a development board for the 32-pin Atmel AVR XMEGA E microcontroller. It can be powered from USB or from the Vin pin. Two schottky diodes facilitate simple switching (and reverse-polarity protection) between the two power sources. This voltage is regulated to 3.3V by the onboard 250mA, extremely low quiescent current (2uA) LDO regulator that supports up to 16V DC input voltage. Overcurrent protection is provided by a 180mA hold (400mA trip) PTC resettable fuse. Also mounted is a mini USB connector (power only), green LED, 16MHz crystal, 32.768KHz RTC crystal, reset/user button, and a user jumper. The board has 40 main dual inline header pins with 100 mil pin spacing and 700 mil row spacing which allows for mounting on a breadboard or perfboard. The PDI/SPI header can be used with an external programmer, or be reconfigured to be used as a SPI master or slave. There are 2 3mm mounting holes. The PCB measures approx. 2.1” x 0.9” x 0.062” (52mm x 33mm x 1.6mm).

# Features

* Atmel AVR XMEGA E 32-pin microcontroller
    ATxmega32E5, ATxmega16E5, or ATxmega8E5
    Features the XMEGA Custom Logic Module
* Onboard 3.3V, 250mA LDO regulator
   up to 16V DC input
   extremely low quiescent current (2.0uA typical)
   low dropout (525mV typical @ 250mA, 725mV max. @ 250mA)
   0.4% output tolerance typical
   Over-current and over-temperature protection
* Simple power source switching
   2 schottky diodes (Vbus and Vin)
   Low voltage drop (250mV @ 50mA, 375mV @ 500mA)
   Reverse-polarity protection
   Vbus can be disconnected (solder jumper)
   Vin schottky can be shorted (solder jumper) to eliminate voltage drop (battery use)
   Either Vin or Vbus can be routed through a resistor divider to pin A1 (ADC)
* PTC resettable fuse (180mA hold / 400mA trip) (SEE TROUBLESHOOTING / FAQ)
* PDI/SPI header (PDI by default)
   As a PDI header, it is used to program the AVR with an external programmer
   Header can be converted to a SPI (master or slave) header
   Can mount the MT-SD MicroSD card slot directly to this header
* 16MHz crystal for main clock
* 32.768KHz crystal for real-time counter
* Green Status LED (can be disconnected)
* Button configurable for reset or general use (pin C1) with optional debouncing
* User jumper
* Mini USB connector (power only)
* USB pins routed to header pins (for panel-mount USB connector)
* Powered by USB or external power source (up to 16V) on Vin
* Ferrite bead and 2 capacitors on analog supply
* 21 solder jumpers for configuration flexibility
* All PORT pins routed to headers
* 2 main headers are on 0.1” spacing (breadboard/perfboard mounting)
* Two 3mm mounting holes (~5mm pad)
* High-quality PCB with gold-plated finish
* Measures approx. 2.1” x 0.9” (52mm x 33mm) and 0.062” (1.6mm) thick.

