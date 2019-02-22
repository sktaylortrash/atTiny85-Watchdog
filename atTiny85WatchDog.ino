#include <SimpleTimer.h>

// constants won't change -- used to set pin numbers and define delays
const int hbPin = 4; // Use the signal from the host to set the heartbeat status
const int resetPin = 3; // use this pin to reset the host
const int ledPin = 1; // built-in LED on atTiny85
int wd_timer_id;

// global variables
int count = 0;
int currState = HIGH;
int prevState = LOW;

// Create timer instances
SimpleTimer timer;

void wdCallback() {
resetHost(resetPin); 
}


/* --------------------------------------------------------------------------------- */

void setup() {
  // Set pin modes
  pinMode(resetPin, OUTPUT);
  // Make sure we are turned on to start!
  digitalWrite(resetPin, HIGH);
  wd_timer_id = timer.setInterval(30000, wdCallback);
}

/* --------------------------------------------------------------------------- */

void loop() {
timer.run();
ledHeartbeat();
}

/* --------------------------------------------------------------------------------- */

void ledHeartbeat(void) {

// Pulse the LED to show WE are alive!
// Use the host's heartbeat signal to drive the LED
// This way we have visibility on both controllers with 1 indicator

digitalWrite(ledPin, currState = digitalRead(hbPin));
if ( currState != prevState) { // State has changed
prevState = currState; // Update
timer.restartTimer(wd_timer_id);
}


}

/* -------------------------------------------------------------------------------- */

void resetHost(int resetPin) {

digitalWrite(resetPin, LOW); // Turn the power relay (transistor) off
delay(5000); // 5 seconds so we don't cycle any bulbs too fast
digitalWrite(resetPin, HIGH); // Turn it back on so the host can boot!


}
