#include <DigiMouse.h>

#define MOVEMENT_AREA_X 500
#define MOVEMENT_AREA_Y 500

// save the current relative mouse position as middle (500 /2)
int XX = MOVEMENT_AREA_X / 2;
int YY = MOVEMENT_AREA_Y / 20;
// Static memory variables
int d, x, y, xx, yy;
int l = 0; // LED state
int dl = 1; // LED state direction
bool enabled = false;
bool down = false;

void setup() {
  pinMode(PB1, OUTPUT);
  pinMode(PB2, INPUT_PULLUP);
  
  DigiMouse.begin();
  DigiMouse.delay(500);
}

void loop() {
  // Toggle the enabled flag and wait for key up before toggling again
  if (digitalRead(PB2) == LOW) {
    if (!down) {
      down = true;
      enabled = !enabled;
    }
  } else {
    down = false;
  }
  
  d = 50;
  if (enabled) {
    // Get a random wait time between moves
    d = random(40, 60);
  
    // Calculate a random move distance on both axes without leaving the movement area:
    // 1. New relative coordinates
    xx = min(MOVEMENT_AREA_X, max(0, XX - 7 + random(0, 15)));
    yy = min(MOVEMENT_AREA_Y, max(0, YY - 7 + random(0, 15)));
    // 2. Moved distances
    x = xx - XX;
    y = yy - YY;
    // Store new coordinated
    XX = xx;
    YY = yy;
  
    DigiMouse.move(x, y, 0);
  }

  // Using DigiMouse.delay() instead of delay() to handle USB
  // interrupts in the meantime
  DigiMouse.delay(d);

  // Update the status LED
  // - Fading if not enabled
  // - Blinking if enabled
  l += dl;
  if (l > 50) { 
    l = 50;
    dl = -1;
  } else if (l < 0) {
    l = 0;
    dl = 1;
  }
  if (!enabled) {
    analogWrite(PB1, l >> 2);
  } else if (l > 44) {
    analogWrite(PB1, 2);
  } else if (l > 32) {
    analogWrite(PB1, 0);
  } else if (l > 20) {
    analogWrite(PB1, 2);
  } else if (l > 7) {
    analogWrite(PB 1, 0);
  } else {
    analogWrite(PB1, 2);
  }
}
