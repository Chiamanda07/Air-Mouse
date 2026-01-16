#include <BleMouse.h>
#include <Wire.h>
#include <MPU6050.h>

BleMouse bleMouse("ESP32 Air Mouse", "Student", 100);
MPU6050 mpu;

// Pins
const int buttonPin = 13;

// Motion tuning
int sensitivity = 15;
int scrollSensitivity = 40;
int deadzone = 3;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);

  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  bleMouse.begin();
  Serial.println("Air Mouse Ready");
}

void loop() {
  if (!bleMouse.isConnected()) {
    delay(100);
    return;
  }

  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert gyro to movement
  int xMove = gy / sensitivity;
  int yMove = -gx / sensitivity;  // invert for natural feel
  int scroll = ay / scrollSensitivity;

  // Deadzone
  if (abs(xMove) < deadzone) xMove = 0;
  if (abs(yMove) < deadzone) yMove = 0;
  if (abs(scroll) < 1) scroll = 0;

  // Move mouse
  if (xMove != 0 || yMove != 0) {
    bleMouse.move(xMove, yMove);
  }

  // Scroll
  if (scroll != 0) {
    bleMouse.move(0, 0, scroll);
  }

  // Button click
  if (digitalRead(buttonPin) == LOW) {
    bleMouse.click(MOUSE_LEFT);
    delay(200); // debounce
  }

  delay(20);
}
