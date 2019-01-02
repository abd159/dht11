//DHT11 Sensor:
#include "DHT.h"
#define DHTPIN 8     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);


//I2C LCD:
#include <Wire.h> // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Test Humidité et Temperature par Mr Abdellatif M 2019");
  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Capteur DHT11");
  lcd.setCursor(1, 1);
  lcd.print("Humidite/temperature");
  delay(2000);//Wait 5 seconds before accessing sensor again.
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  lcd.clear();
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:

  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.print("C");

  // set the cursor to (16,1):
  lcd.setCursor(0, 1);
  lcd.print("Humidite: ");
  lcd.print(h);
  lcd.print(" % ");

  Serial.print("Température: ");
  Serial.print(t);
  Serial.print("C, Humidité: ");
  Serial.print(h);
  Serial.println(" %  ");
  delay(2000);//Wait 5 seconds before accessing sensor again.
}
