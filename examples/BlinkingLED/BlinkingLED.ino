/*
    Example 2: Blinking LED Indefinitely
    This example blinks an LED with a custom on/off cycle indefinitely using the blink function.

    * Connect an LED to pin 2 on your Arduino (make sure you use a resistor to limit current).
*/

#include <Blinker.h>

Blinker led(2); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin();
}

void loop() {
    // Blink the LED: on for 500 ms, off for 500 ms
    led.blink(500, 500); 
}
