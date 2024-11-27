#include <Wire.h> // I2C library
#include "rgb_lcd.h" // LCD library
#include <avr/io.h> // I/O library
#include <avr/interrupt.h> // Interrupt library

rgb_lcd lcd; // LCD object

const int lightSensorPin = A0; // Light sensor pin
const int buttonPin = 4; // Button pin         
const int buzzerPin = 2; // Buzzer pin           

// Interrupt service routine for INT0
ISR(INT0_vect)
{
  if (digitalRead(buttonPin)== HIGH){ // If button is pressed
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(2000); // Wait for 2 seconds
  }
  else{
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
  }
}

// Initialize INT0
void initInterrupt0(void)
{
  EIMSK |= (1 << INT0); // Enable INT0 
  EICRA |= (1 << ISC00); // Trigger when button changes 
  sei(); // Set (global) interrupt enable bit 
}

void setup() {
  Serial.begin(9600); // Start serial communication

  initInterrupt0(); // Initialize INT0

  lcd.begin(16, 2); // Start LCD with 16 columns and 2 rows
  lcd.setCursor(0, 0); // Set cursor to first row, first column
  lcd.print("Light Sensor: "); // Print message on LCD

  pinMode(buttonPin, INPUT); // Set button pin as input
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
  int lightValue = analogRead(lightSensorPin); // Read light sensor value

  lcd.setCursor(0, 1); // Set cursor to second row, first column
  lcd.print("Value: "); // Print message on LCD
  lcd.print(lightValue); // Print light sensor value on LCD
}