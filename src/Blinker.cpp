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
  
  _pin = pin;       // Set the pin number for the LED
  _state = LOW;     // Initialize the LED state to LOW (off)

}


// Initialize the pin as an output
void Blinker::begin() {

  pinMode(_pin, OUTPUT);         // Set the pin as an output
  digitalWrite(_pin, _state);    // Set the initial state of the LED

}


// Turn the LED on
void Blinker::on() {

  _state = HIGH;                 // Set the state to HIGH (on)
  digitalWrite(_pin, _state);    // Apply the state to the LED pin

}


// Turn the LED off
void Blinker::off() {

  _state = LOW;                  // Set the state to LOW (off)
  digitalWrite(_pin, _state);    // Apply the state to the LED pin

}


// Toggles the LED state (on/off)
void Blinker::toggle() {

  _state = !_state;              // Flip the current state (on/off)
  digitalWrite(_pin, _state);     // Apply the new state to the LED pin

}


// Returns the current state of the LED (HIGH/LOW)
bool Blinker::get() {

  return _state;                 // Return the current state (HIGH or LOW)

}


// Blinks the LED with specified on/off times and a max time duration
bool Blinker::blink(int on_time, int off_time, unsigned long max_time) {

  unsigned long current_time = millis();  // Get the current time in milliseconds
  bool initialized;

  // Initialize the start time and set the off_time to on_time if not specified
  if (!initialized) {

    if (off_time == 0) {
      off_time = on_time; // If off_time is not specified, use on_time as off_time
    }

    _start_time = current_time;  // Record the start time for max_time
    initialized = true;         // Mark the initialization as done

  }


  // Check if the max_time has been reached
  if (current_time - _start_time >= max_time) {
    
    off();                        // Turn the LED off
    
    return false;                 // Indicate that the blinking has stopped
    return;

  }

  
  // Blink the LED based on on_time and off_time
  if (current_time - _delay >= (_state == HIGH ? on_time : off_time)) {

    toggle();                    // Toggle the LED state (on/off)
    _delay = current_time;       // Update the delay time

  }

  
  return true;                   // Return true while blinking

}



Blinker::fadeIn(int fade_time){
  
  unsigned long current_time = millis();
}



Blinker::fadeOut(int fade_time){

}



Blinker::lin(int fade_time){

}