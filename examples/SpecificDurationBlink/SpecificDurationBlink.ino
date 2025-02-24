/*
    Example: Blinking LED for a Specific Duration
    This example blinks an LED for a specified amount of time using the blink function 
    with a blink duration.

    * Connect an LED to pin 2 on your Arduino (make sure you use a resistor to limit current).
*/

#include <Blinker.h>

Blinker led(2); // LED connected to pin 2

void setup() {
    // Initialize the pin as output and define the pin
    led.begin();
}

void loop() {
    // Blink for 5 seconds, on 500ms and off 500 ms  |  led.blink(on_time, off_time, max_time)
    if (led.blink(500, 500, 5000)) {  
        // Once the blinking is finished, turn the LED off
        led.off();
    }
}
