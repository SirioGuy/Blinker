/*
    Example: Blinking LED Indefinitely
    This example blinks an LED with a custom on/off cycle indefinitely using the blink function.

    * Connect an LED to pin 2 on your Arduino (make sure you use a resistor to limit current).
*/

#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize the pin as output and define the pin
    led.begin(2);
}

void loop() {
    // Blink the LED every 500 ms
    led.blink(500); 
}
