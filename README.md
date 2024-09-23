# LED Controller for Arduino boards

Blinker.h is an Arduino library made it to work with multiple LED's at the same time. It can handle multiple LED's blinking at different rythms maintaining a short code.

## Usage:
- Suitable for controlling single or multiple LEDs in a time-based pattern.
- Ideal for projects that require visual indicators with precise timing control, such as blinking lights or status indicators.
- Control status indicators that require blinking for a short duration (e.g., notifications, alarms).
- Implement long-term, repeated blinking patterns with adjustable on and off intervals.

## Functions:
```cpp
// Turns the LED on (HIGH).
led.turnOn();

// Turns the LED off (LOW).
led.turnOff();

// Blinks the LED with a custom on/off cycle. Returns true
led.blink(on_time, off_time);

// Blinks the LED for a specific duration (blink_time) before turning it off. Returns false, and true after turning it off
led.blink(on_time, off_time, blink_time);

// Returns whether the LED is currently on or off
led.askState();

// Sets the LED pin as an output.
led.begin();
```

> [!NOTE]
> All time values are in milliseconds.

## Examples:

### Basic On/Off Control
```cpp
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
```

### Blinking LED for a Specific Duration
```cpp
#include <Blinker.h>

Blinker led(2); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin();
}

void loop() {
    // Blink for 5 seconds, on for 500 ms, off for 500 ms
    if (led.blink(500, 500, 5000)) {  
        // Once the blinking is finished, execute any code that you want
        delay(1000); // Optional delay before repeating or doing something else
    }
}
```

### Checking LED state with askState
```cpp
#include <Blinker.h>

Blinker led(2); // LED connected to pin 2

void setup() {
    // Initialize serial communication and the LED pin
    Serial.begin(9600); 
    led.begin();
}

void loop() {
    // Turn the LED on, check and print the state
    led.turnOn();  

    if (led.askState()) {
        Serial.println("LED is ON");
        delay(1000);
    }

    // Turn the LED off, check and print the state
    led.turnOff();  

    if (!led.askState()) {
        Serial.println("LED is OFF");
        delay(1000);
    }
}
```