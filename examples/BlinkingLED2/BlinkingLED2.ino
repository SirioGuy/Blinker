/*
    Example: Blinking LED Indefinitely with a different off delay
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
    // Turns the LED on 100ms every 500ms | led.blink(on_time, off_time)
    led.blink(100, 500); 
}
