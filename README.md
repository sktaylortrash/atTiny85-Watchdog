This sketch is for a DigiSpark Tiny85 or AdaFruit Trinket

Acts as a hardware watchdog on any host that has a reset pin which functions by being pulled LOW to ground.

Monitors hbPin, requiring a state change within hbTime.

Onboard LED mimics the state of the hbPin signal from the host, giving a visual heartbeat of both hosts with one LED.

If a state change is not detected, resetPin is pulled LOW to force a reset on the host.
ResetPin on the watchdog needs to be connected to the RST pin on the host and both devices need to be on a common ground.

On startup and after a reset, resetTime is invoked to insure the host has time to properly start up and start emitting the heartbeat signal.