/*
  Blinker.h - A simple library for controlling LED blinking patterns on an Arduino.
  
  This library allows easy manipulation of LEDs connected to Arduino pins, enabling the user
  to turn LEDs on, off, and blink them at specified intervals. It also includes functionality 
  to blink an LED for a limited duration and then stop. This can be useful for various projects 
  where visual feedback is needed.

  Version: 1.1
  Last revision: February 17, 2025
  Created by: Sirio Altilar Guy

  FEATURES:
  - Set a specific pin for LED control.
  - Turn the LED on or off.
  - Blink the LED indefinitely with customizable on/off times.
  - Blink the LED for a limited duration with customizable on/off times.
  - Check the current state of the LED (on or off).

  FUNCTIONALITY:
  - begin(): Sets the LED pin as an output, preparing it for use.
  - on(): Turns the LED on (HIGH).
  - off(): Turns the LED off (LOW).
  - get(): Returns whether the LED is currently on (HIGH) or off (LOW).
  - blink(int on_time, int off_time): Blinks the LED repeatedly with a custom on/off cycle.
  - blink(int on_time, int off_time, unsigned long blink_time): Blinks the LED for a specific duration (defined by blink_time) before turning it off.

  INTERNAL LOGIC:
  - The class uses the `millis()` function to manage time-based blinking. This allows non-blocking delays, so the program can continue running while LEDs are blinking.
  - The second `blink()` function stops blinking after a total duration (blink_time) and then turns the LED off.

  USAGE EXAMPLES:
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
    void on();



    // Turns the LED off
    void off();


    
    // Asks the current state of the LED (on or off)
    bool get();



    // Blinks the LED with specified on/off times and a total blink duration (blink_time)
    bool blink(int on_time, int off_time = 0, unsigned long blink_max_time = -1);



  private:

    byte _pin;                 // Stores the pin number for the LED


    bool _state;               // Stores the state of the LED (on/off)


    bool _time_reached;        // Used to check if the blink reach the maximum time


    unsigned long _delay;      // Used to track the last time the LED state changed


    unsigned long _blink_max_time;// Used to track the time and check if it exceeded of maximum time

};

#endif