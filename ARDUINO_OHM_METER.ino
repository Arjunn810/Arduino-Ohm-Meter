#include <LiquidCrystal.h>

// Initialize LCD for parallel mode (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int analogPin = A0;  // Analog input pin
int raw = 0;
const float Vin = 5.0;  // Arduino 5V
float Vout = 0;
const float R1 = 1000.0; // Fixed 1KΩ reference resistor
float R2 = 0;
float buffer = 0;

void setup() {
    lcd.begin(16, 2); // Start LCD
    lcd.setCursor(0, 0);
    lcd.print("Resistance Meter");
    delay(2000);
    lcd.clear();
}

void loop() {
    raw = analogRead(analogPin);  // Read voltage at A0

    if (raw == 0) {
        lcd.setCursor(0, 1);
        lcd.print(" Open Circuit   "); // If no resistor is detected
    } else {
        Vout = (raw * Vin) / 1023.0;  // Convert ADC value to voltage
        buffer = (Vout / (Vin - Vout));  // Corrected equation
        R2 = R1 * buffer;  // Solve for R2

        lcd.setCursor(0, 1);
        lcd.print("                "); // Clear previous values

        if (R2 >= 1000.0) {
            lcd.setCursor(0, 1);
            lcd.print(R2 / 1000.0, 2); // Display resistance in KΩ
            lcd.print(" KOhm");
        } else {
            lcd.setCursor(0, 1);
            lcd.print(R2, 2);
            lcd.print(" Ohm  ");
        }
    }

    delay(1000);
}
