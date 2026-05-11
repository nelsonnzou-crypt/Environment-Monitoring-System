#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT11

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  lcd.begin(16, 2);

  // --- Personalized startup message ---
  lcd.setCursor(0, 0);
  lcd.print("Saint Nelson");
  lcd.setCursor(0, 1);
  lcd.print("System Online...");
  
  Serial.begin(9600); // TX0=1, RX0=0
  delay(1000);        // shorter greeting delay
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // --- LCD Display ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity, 1);
  lcd.print(" %");

  // --- Virtual Terminal Output ---
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000); // faster refresh
}
