# LED Controller for Arduino boards

Blinker.h is an Arduino library made it to work with multiple LED's at the same time.

It can handle multiple LED's blinking at different rythms maintaining a short code.

## Features:
- Easy to use
- Shortens the code
- Supports multiple LED's 

## Functions:

```
led.turnOn();   // Turns the LED on (HIGH).
```

```
led.turnOff();   // Turns the LED off (LOW).
```

```
led.blink(on_time, off_time); // Blinks the LED with a custom on/off cycle.
```

```
led.blink(on_time, off_time, blink_time);   // Blinks the LED for a specific duration (blink_time) before turning it off.
```

```
led.askState();   // Returns whether the LED is currently on or off
```

```
led.begin();   // Sets the LED pin as an output.
```

> [!NOTE]
> All time values are in milliseconds.

##