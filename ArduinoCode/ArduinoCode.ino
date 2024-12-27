#include <Servo.h>

// Pin definitions
const int mq5Pin = A0;      // Analog pin for MQ-5 sensor
const int buzzerPin = 3;    // Digital pin for buzzer
const int relayPin = 4;     // Digital pin for relay module
const int servoPin = 5;     // Digital pin for servo motor

Servo myservo;              // Create servo object
const int gasThreshold = 150; // Threshold for gas detection

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  myservo.attach(servoPin); // Attaching the servo motor
  Serial.begin(9600);       // Initialize serial communication for debugging
}

void loop() {
  // Read the analog value from MQ-5 sensor
  int gasValue = analogRead(mq5Pin);
  Serial.println(gasValue); // Print the sensor value for debugging
  // If gas concentration exceeds the threshold
  if (gasValue > gasThreshold) {
    activateAlarm();      // Activate alarm
    activateRelay();      // Activate relay module
    turnOnServo();        // Turn on servo motor
  } else {
    deactivateAlarm();    // Deactivate alarm
    deactivateRelay();    // Deactivate relay module
    turnOffServo();       // Turn off servo motor
  }

  delay(500); // Small delay for stability
}

void activateAlarm() {
  digitalWrite(buzzerPin, HIGH); // Turn on buzzer
}

void deactivateAlarm() {
  digitalWrite(buzzerPin, LOW);  // Turn off buzzer
}

void activateRelay() {
  digitalWrite(relayPin, LOW);   // Activate relay module
}

void deactivateRelay() {
  digitalWrite(relayPin, HIGH);  // Deactivate relay module
}

void turnOnServo() {
  myservo.write(90);             // Rotate servo motor to 90 degrees
}

void turnOffServo() {
  myservo.write(0);              // Rotate servo motor to 0 degrees
}
