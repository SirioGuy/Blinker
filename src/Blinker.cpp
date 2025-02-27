/*
  Blinker.cpp - A simple library implementation for controlling LED blinking patterns on an Arduino.
  
  This source file implements the functions declared in Blinker.h. It controls the state of an LED connected 
  to an Arduino pin, allowing it to be turned on, off, and blinked in a repeated pattern, either indefinitely 
  or for a specified period.

  Version: 1.1
  Last revision: February 17, 2025
  Created by: Sirio Altilar Guy

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

#include "Blinker.h"

#include "Arduino.h"


// Constructor to initialize the pin and default values

Blinker::Blinker(byte pin) {

  _pin = pin;
  _state = LOW;  // Initialize the LED state as off

}





// Initialize the pin as an output

void Blinker::begin() {

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _state);

}





// Turn the LED on

void Blinker::on() {

  _state = HIGH;
  digitalWrite(_pin, _state);  // Write HIGH to the LED pin to turn it on

}





// Turn the LED off

void Blinker::off() {

  _state = LOW;
  digitalWrite(_pin, _state);  // Write LOW to the LED pin to turn it off

}





// Return the current state of the LED (HIGH/LOW)

bool Blinker::get() {

  return _state;

}





// Blink the LED for a limited duration (blink_max_time) with specified on and off delays

bool Blinker::blink(int on_time, int off_time, unsigned long max_time) {
  if (off_time == 0) {
      off_time = on_time;
  }

  unsigned long current_time = millis();

  // If max_time is set and reached, stop blinking and turn LED off
  if (current_time - max_time >= max_time) {
      _time_reached = true;
      return false;  // Indicate blinking has stopped
  }

  // Normal blinking logic
  if (current_time - _delay >= (_state == HIGH ? on_time : off_time)  &&  _time_reached == false) {
      _state = !_state;
      digitalWrite(_pin, _state);
      _delay = current_time;
      return true;  // Indicate it's still blinking
  }
}

