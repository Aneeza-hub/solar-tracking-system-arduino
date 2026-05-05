#include <Servo.h>

int photopin = A0;      // LDR input pin
int Servopin = 9;       // Servo output pin
int photoVal = 0;       // Light intensity value
int ServoPos = 0;       // Servo angle

Servo Myservo;          // Create servo object

void setup() {
  Serial.begin(9600);         // Start serial monitor
  pinMode(photopin, INPUT);   // Set LDR as input
  Myservo.attach(Servopin);   // Attach servo to pin 9
}

void loop() {
  photoVal = analogRead(photopin);              // Read LDR value
  ServoPos = map(photoVal, 250, 630, 180, 0);    // Map light to angle
  Myservo.write(ServoPos);                       // Move servo

  // Debug output
  Serial.print("Light Value: ");
  Serial.print(photoVal);
  Serial.print(" | Servo Angle: ");
  Serial.println(ServoPos);

  delay(100);
}
