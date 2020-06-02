#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <DHT.h>
#define sensorPin 8
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
dht DHT;
void setup() {
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
}
void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /+ 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp in F:");
  lcd.setCursor(11,0);
  lcd.print(temperatureF);

  lcd.setCursor(0,1);
  lcd.print("Temp in C:");
  lcd.setCursor(11, 1);
  lcd.print(temperatureC);
  
  delay(2000);
}
