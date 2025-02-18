/*
    Example: Checking LED State
    This example shows how to check whether the LED is on or off using the askState function.

    * Connect an LED to pin 2 on your Arduino (make sure you use a resistor to limit current).
*/

#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize serial communication and the LED pin
    Serial.begin(9600); 
    led.begin(2);
}

void loop() {
    // Turn the LED on, check and print the state
    led.on();  

    if (led.get()) {
        Serial.println("LED is ON");
        delay(1000);
    }

    // Turn the LED off, check and print the state
    led.off();  

    if (!led.get()) {
        Serial.println("LED is OFF");
        delay(1000);
    }
}
