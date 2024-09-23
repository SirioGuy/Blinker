# LED Controller for Arduino boards

Blinker.h is an Arduino library made it to work with multiple LED's at the same time.

It can handle multiple LED's blinking at different rythms maintaining a short code.

## Features:
- Easy to use
- Shortens the code
- Supports multiple LED's 

## Functions:

```
// Turns the LED on (HIGH).
led.turnOn();   

// Turns the LED off (LOW).
led.turnOff();   

// Blinks the LED with a custom on/off cycle.
led.blink(on_time, off_time); 

// Blinks the LED for a specific duration (blink_time) before turning it off.
led.blink(on_time, off_time, blink_time);

// Returns whether the LED is currently on or off
led.askState();   

// Sets the LED pin as an output.
led.begin();   
```

> [!NOTE]
> All time values are in milliseconds.

##
