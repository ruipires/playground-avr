#include <avr/io.h>
#include <util/delay.h>

#define shift_light_up(port) port << 1   					// shifts the bits of port left
#define shift_light_down(port) port >> 1  					// shifts the bits of port right

#define register_set_output(register) register = 0b11111111  // sets to output
#define enable_first_light(port) port = 0b00000001  		// sets first pin to high

bool is_last_pin(volatile uint8_t const *port){   	// Checks if pin 5 is lit up
	return (*port & 0b00010000) != 0;
}

bool is_first_pin(volatile uint8_t const *port){  	// Checks if pin 1 is lit up
	return (*port & 0b00000001) != 0;
}

int main (){
	register_set_output(DDRB);			// Set it all to output
	enable_first_light(PORTB);			// Set the first light to on
	bool up = true;
	while(true){
		_delay_ms(200);					// Dependent on the chip's clock speed, speed must be set

		if(is_first_pin(&PORTB))		// check if it is at the start
			up = true;
		if(is_last_pin(&PORTB))			// check if it is at the end
			up = false;
		if(up)
			PORTB = shift_light_up(PORTB);			// Shift our light up
		else
			PORTB = shift_light_down(PORTB);		// Shift our light down
	}
}
