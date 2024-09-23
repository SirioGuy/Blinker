/*
  Blinker.cpp - A simple library implementation for controlling LED blinking patterns on an Arduino.
  
  This source file implements the functions declared in Blinker.h. It controls the state of an LED connected 
  to an Arduino pin, allowing it to be turned on, off, and blinked in a repeated pattern, either indefinitely 
  or for a specified period.

  Version: 1.0
  Last revision: September 22, 2024
  Created by: Sirio Altilar Guy

  FUNCTIONALITY:
  - begin(): Sets the LED pin as an output, preparing it for use.
  - turnOn(): Turns the LED on (HIGH).
  - turnOff(): Turns the LED off (LOW).
  - askState(): Returns whether the LED is currently on (HIGH) or off (LOW).
  - blink(int on_time, int off_time): Blinks the LED repeatedly with a custom on/off cycle.
  - blink(int on_time, int off_time, unsigned long blink_time): Blinks the LED for a specific duration 
    (defined by blink_time) before turning it off.

  INTERNAL LOGIC:
  - The class uses the `millis()` function to manage time-based blinking. This allows non-blocking delays, 
    so the program can continue running while LEDs are blinking.
  - The second `blink()` function stops blinking after a total duration (blink_time) and then turns the LED off.

  USAGE EXAMPLES:
  - Suitable for controlling single or multiple LEDs in a time-based pattern.
  - Ideal for projects that require visual indicators with precise timing control, such as blinking lights or status indicators.
  - Control status indicators that require blinking for a short duration (e.g., notifications, alarms).
  - Implement long-term, repeated blinking patterns with adjustable on and off intervals.
*/

#include "Arduino.h"
#include "Blinker.h"

// Constructor to initialize the pin and default values
Blinker::Blinker(byte pin) {
  _pin = pin;
  _state = LOW;  // Initialize the LED state as off
  _delay = 0;
}

// Initialize the pin as an output
void Blinker::begin() {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _state);
}

// Turn the LED on
void Blinker::turnOn() {
  _state = HIGH;
  digitalWrite(_pin, _state);  // Write HIGH to the LED pin to turn it on
}

// Turn the LED off
void Blinker::turnOff() {
  _state = LOW;
  digitalWrite(_pin, _state);  // Write LOW to the LED pin to turn it off
}

// Return the current state of the LED (HIGH/LOW)
bool Blinker::askState() {
  return _state;
}

// Blink the LED indefinitely with specified on and off times
bool Blinker::blink(int on_time, int off_time) {
  unsigned long current_time = millis();  // Get the current time in milliseconds
  
  // If enough time has passed, change the state
  if (current_time - _delay >= (_state == HIGH ? on_time : off_time)) {
    _state = !_state;  // Toggle the LED state (on/off)
    digitalWrite(_pin, _state);  // Apply the state to the LED
    _delay = current_time;  // Update the delay timer
  }
  return true;
}

// Blink the LED for a limited duration (blink_time) with specified on and off times
bool Blinker::blink(int on_time, int off_time, unsigned long blink_time) {
  unsigned long current_time = millis(); // Get the current time in milliseconds

  // Check if the blink time has been reached
  if(current_time - _blink_delay >= blink_time && _time_reached == 0) {
    _time_reached = 1; // Set the flag to indicate time has been reached
  }

  // Blink the LED if the blink time has not been reached
  if (current_time - _delay >= (_state == HIGH ? on_time : off_time) && _time_reached == 0) {
    _state = !_state; // Toggle the LED state (on/off)
    digitalWrite(_pin, _state); // Apply the state to the LED
    _delay = current_time; // Update the delay timer
  } else if(_time_reached == 1) {
    turnOff(); // Turn off the LED after blink time is reached
    return true; // Blinking finished
  }
  return false; // Still blinking
}
