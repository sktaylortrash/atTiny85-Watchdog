// Class "timer" -- monitors a time instance and returns 1 if it is passed or 0 otherwise
// It requires a time interval in milliseconds

class timer
{
//Class variables initialized at startup
unsigned long timerDuration; // How long is this timer for?

// Runtime variables
unsigned long startMillis; // When did it start?

// Constructor
public:
timer(unsigned long timer) {
timerDuration = timer;
startMillis = millis();
}

int update(void) {
if (millis() - startMillis >= timerDuration) {
return 1;
} else {
return 0;
}
}

void reset(void) {
startMillis = millis();
}

};
