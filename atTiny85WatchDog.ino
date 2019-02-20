#include "timer.h"

// constants won't change -- used to set pin numbers and define delays
const int hbPin = 3; // Use the signal from the host to set the
// heartbeat status
const int resetPin = 4; // use this pin to reset the host
const int ledPin = 1; // built-in LED on Trinket
const unsigned long resetTime = (1000 * 60 *3); // give the host 3 minutes to boot
const unsigned long hbTime = (1000 * 30); // 30 second heartbeat cycle before reset

// global variables
int currState = HIGH;
int prevState = LOW;

// Create timer instances
timer resetTimer = timer(resetTime); // reset delay timer
timer hbTimer = timer(hbTime); // heartbeat timer

/* --------------------------------------------------------------------------------- */

void setup() {

// Set pin modes
pinMode(resetPin, OUTPUT);
// Make sure we are turned on to start!
digitalWrite(resetPin, HIGH);

// Start with a zeroed out timers
resetTimer.reset();
hbTimer.reset();

}

/* --------------------------------------------------------------------------- */

void loop() {

ledHeartbeat();
if ((hbTimer.update() == 1) && (resetTimer.update() == 1)) {
resetHost(resetPin); 
}

}

/* --------------------------------------------------------------------------------- */

void ledHeartbeat(void) {

// Pulse the LED to show WE are alive!
// Use the host's heartbeat signal to drive the LED
// This way we have visibility on both controllers with 1 indicator

digitalWrite(ledPin, currState = digitalRead(hbPin));
if ( currState != prevState) { // State has changed
prevState = currState; // Update
hbTimer.reset(); // Reset the timer
}

}

/* -------------------------------------------------------------------------------- */

void resetHost(int resetPin) {

digitalWrite(resetPin, LOW); // Turn the power relay (transistor) off
delay(5000); // 5 seconds so we don't cycle any bulbs too fast
digitalWrite(resetPin, HIGH); // Turn it back on so the host can boot!
resetTimer.reset(); // Zero out the timer

}
