#include <Servo.h>
Servo sg90;

int initial_position = 90;
int LDR1 = A0;
int LDR2 = A1;
int error = 5;
int servopin = 9;

void setup() {
  sg90.attach(servopin);
  sg90.write(initial_position);
  delay(200); // Wait for the servo to settle
}

void loop() {
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);
  Serial.println(R1);
  Serial.println("LDR1");
  Serial.println(R2);
  Serial.println("LDR2");
  delay(300);

  int diff = abs(R1 - R2);
 
  if (diff > error) {
    if (R1 > R2) {
      initial_position--; // Move servo to the left
    }
    if (R1 < R2) {
      initial_position++; // Move servo to the right
    }
    
    // Ensure the position stays within valid range (0° to 180°)
    if (initial_position < 0) {
      initial_position = 0;
    } else if (initial_position > 180) {
      initial_position = 180;
    }

    sg90.write(initial_position);
  }
  delay(100);
}