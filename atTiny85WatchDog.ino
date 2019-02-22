#include <SimpleTimer.h>

const int wdPin = 4;
const int resetPin = 3;
const int ledPin = 1;

int wd_timer_id;
int currState = HIGH;
int prevState = LOW;

// Create timer instances
SimpleTimer timer;

void wdCallback() {
  resetHost(resetPin); 
}

void setup() {
  pinMode(resetPin, OUTPUT);
  digitalWrite(resetPin, HIGH);
  wd_timer_id = timer.setInterval(30000, wdCallback);
}

void loop() {
  timer.run();
  ledHeartbeat();
}

void ledHeartbeat(void) {
  digitalWrite(ledPin, currState = digitalRead(wdPin));
  if ( currState != prevState) { // State has changed
    prevState = currState; // Update
    timer.restartTimer(wd_timer_id);
  }
}

void resetHost(int resetPin) {
  digitalWrite(resetPin, LOW); 
  delay(5000); 
  digitalWrite(resetPin, HIGH);
}
