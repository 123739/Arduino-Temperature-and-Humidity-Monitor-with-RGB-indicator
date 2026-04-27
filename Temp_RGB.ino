#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin Definitions
#define DHTPIN 2        
#define DHTTYPE DHT11   
const int redPin = 8;    // Digital pin for Red
const int greenPin = 9;  // PWM pin for Green
const int bluePin = 10;  // PWM pin for Blue

// Initialize objects
LiquidCrystal_I2C lcd(0x27, 16, 2); 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // 1. Configure baud rate for communication [3]
  
  lcd.begin(); 
  lcd.backlight();
  
  // Initial stage reading as shown in the hardware results [4, 5]
  lcd.setCursor(0, 0);
  lcd.print("!!EV-State!!"); 
  delay(2000);
  lcd.clear();
  
  dht.begin();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }
  
  // --- Updated RGB LED Logic based on your request ---
  if (temperature > 30) {
    // Red for temperatures above 30°C (High Temp Alert)
    setColor(255, 0, 0); 
  } 
  else if (temperature < 0) {
    // Blue for temperatures below 0°C (Freezing Alert)
    setColor(0, 0, 255); 
  } 
  else {
    // Green for temperatures between 0°C and 30°C (Optimal Window)
    setColor(0, 255, 0); 
  }
  
  // Displaying data on the 16x2 LCD [5, 6]
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print("%");
  
  // Transmitting data via Serial for IoT Gateway role [1, 2]
  Serial.print("T:"); Serial.print(temperature);
  Serial.print("|H:"); Serial.println(humidity);
  
  delay(2000); 
}

// Function to handle the RGB LED state using Pin 8, 9, 10 configuration
void setColor(int redValue, int greenValue, int blueValue) {
  // Pin 8 is digital-only on the Uno
  digitalWrite(redPin, redValue > 127 ? HIGH : LOW);
  // Pins 9 and 10 support PWM
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}