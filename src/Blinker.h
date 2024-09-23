/*
  Blinker.h - A simple library for controlling LED blinking patterns on an Arduino.
  
  This library allows easy manipulation of LEDs connected to Arduino pins, enabling the user
  to turn LEDs on, off, and blink them at specified intervals. It also includes functionality 
  to blink an LED for a limited duration and then stop. This can be useful for various projects 
  where visual feedback is needed.

  Version: 1.0
  Revision date: September 22, 2024
  Created by: Sirio Altilar Guy

  FEATURES:
  - Set a specific pin for LED control.
  - Turn the LED on or off.
  - Blink the LED indefinitely with customizable on/off times.
  - Blink the LED for a limited duration with customizable on/off times.
  - Check the current state of the LED (on or off).

  PARAMETERS:
  - pin: the Arduino pin to which the LED is connected.
  
  FUNCTIONS:
  - begin(): Initialize the LED pin as an output.
  - turnOn(): Turns the LED on by setting the pin HIGH.
  - turnOff(): Turns the LED off by setting the pin LOW.
  - askState(): Returns the current state of the LED (HIGH or LOW).
  - blink(on_time, off_time): Blinks the LED indefinitely based on the provided on and off times.
  - blink(on_time, off_time, blink_time): Blinks the LED for a limited duration (blink_time) with the specified on and off times.

  USAGE:
  - Suitable for controlling single or multiple LEDs in a time-based pattern.
  - Ideal for projects that require visual indicators with precise timing control, such as blinking lights or status indicators.
  - Control status indicators that require blinking for a short duration (e.g., notifications, alarms).
  - Implement long-term, repeated blinking patterns with adjustable on and off intervals.

*/

#ifndef Blinker_h
#define Blinker_h

#include "Arduino.h"

class Blinker {
  public:
    // Constructor to initialize the pin for the LED
    Blinker(byte pin);
    
    // Starts the LED by setting the pinMode
    void begin();
    
    // Turns the LED on
    void turnOn();
    
    // Turns the LED off
    void turnOff();
    
    // Asks the current state of the LED (on or off)
    bool askState();
    
    // Blinks the LED with specified on and off times
    bool blink(int on_time, int off_time);
    
    // Blinks the LED with specified on/off times and a total blink duration (blink_time)
    bool blink(int on_time, int off_time, unsigned long blink_time);

  private:
    byte _pin;                 // Stores the pin number for the LED
    bool _state;               // Stores the state of the LED (on/off)
    bool _time_reached;        // Used to check if the blink reach the maximum time
    unsigned long _delay;      // Used to track the last time the LED state changed
    unsigned long _blink_delay;// Used to track the time and check if it exceeded of maximum time
};

#endif
