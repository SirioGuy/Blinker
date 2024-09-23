/*
    Example: Basic On/Off Control
    This example demonstrates turning an LED on and off using the Blinker library.

    * Connect an LED to pin 2 on your Arduino (make sure you use a resistor to limit current).
*/

#include <Blinker.h>

Blinker led(2); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin();
}

void loop() {
    // Turn the LED on, wait for 1 second, then turn it off
    led.turnOn();  
    delay(1000);   
    led.turnOff(); 
    delay(1000);   
}
