# LED Blinker for Arduino boards

Blinker.h is simple *non-blocking* LED controller Arduino library. It can handle multiple LED's blinking at different rythms maintaining a short code.

## Usage
- Suitable for controlling single or multiple LEDs in a *time-based* pattern.
- Ideal for projects that require visual indicators with precise timing control, such as blinking lights or status indicators.
- Control status indicators that require blinking for a short duration (e.g., notifications, alarms).
- Implement long-term, repeated blinking patterns with adjustable on and off intervals.

## Functions
Turns the LED ***on*** (HIGH)
```cpp
led.turnOn();
```

Turns the LED ***off*** (LOW)
```cpp
led.turnOff();
```

Blinks the LED with a custom ***on***/***off*** cycle for a specific duration (***blink_time***) before turning it ***off***. Returns ***true*** when reaches max duration(***off_time*** and ***blink_time*** are optional, see examples)
```cpp
led.blink(on_time, off_time, blink_time);
```

Returns whether the LED is currently ***on*** or ***off***
```cpp
led.askState();
```

Sets the LED pin, and as an ***output***
```cpp
led.begin(pin);
```

> [!NOTE]
> **All time values are in milliseconds.**

## Examples

### Basic On/Off Control
```cpp
#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin(2);
}

void loop() {
    // Turn the LED on, wait for 1 second, then turn it off
    led.turnOn();  
    delay(1000);   
    led.turnOff(); 
    delay(1000);   
}
```

### Blinking Led Indefinitely
```cpp
#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin(2);
}

void loop() {
    // Blink the LED: on for 500 ms, off for 500 ms
    led.blink(500, 500); 
}
```

### Blinking LED Indefinitely with different on/off time
``` cpp
#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin(2);
}

void loop() {
    // Turns the LED on 100ms every 500ms | led.blink(on_time, off_time)
    led.blink(100, 500); 
}
```


### Blinking LED for a Specific Duration
```cpp
#include <Blinker.h>

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize the pin as output
    led.begin(2);
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

Blinker led(); // LED connected to pin 2

void setup() {
    // Initialize serial communication and the LED pin
    Serial.begin(9600); 
    led.begin(2);
}

void loop() {
    // Turn the LED on, check and print the state
    led.turnOn();  

    if (led.getState()) {
        Serial.println("LED is ON");
        delay(1000);
    }

    // Turn the LED off, check and print the state
    led.turnOff();  

    if (!led.getState()) {
        Serial.println("LED is OFF");
        delay(1000);
    }
}
```

## Installing

[Check out the instructions](https://www.arduino.cc/en/Guide/Libraries) from Arduino.

## Notes
Currently only a LED controlling software. Any blocking code delaying it(e.g. ***delay()*** function) will prevent the LED from blink at specified time.

Any contribution would be helpfull, i'm starting to make libraries and i want to learn.