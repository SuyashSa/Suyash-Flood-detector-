
  lcd.init(); // Use lcd.init() instead of lcd.begin() if required by your library
  lcd.backlight();

  // Initialize pins
  pinMode(WATER_LEVEL_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Display initialization message
  lcd.setCursor(0, 0);
  lcd.print("Flood Control Sys");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read water level sensor value
  waterLevel = analogRead(WATER_LEVEL_PIN);

  // Display water level on LCD
  lcd.setCursor(0, 0);
  lcd.print("Water Level: ");
  lcd.print(waterLevel);
  lcd.print("    "); // Clear extra characters

  // Check if water level exceeds threshold
  if (waterLevel > WATER_LEVEL_THRESHOLD) {
    // Activate alert
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    // Display alert on LCD
    lcd.setCursor(0, 2);
    lcd.print("Status: Flood Alert!");
  } else {
    // Deactivate alert
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    // Display safe status
    lcd.setCursor(0, 2);
    lcd.print("Status: Safe       ");
  }
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Constants
#define WATER_LEVEL_PIN A0 // Water level sensor analog input
#define BUZZER_PIN 6       // Buzzer output
#define LED_PIN 7          // LED output
#define WATER_LEVEL_THRESHOLD 600 // Water level threshold (adjust after calibration)

// LCD object (check I2C address with scanner)
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Variables
int waterLevel = 0;

void setup() {
  // Initialize LCD
  delay(1000); // Update every second
}
