#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_SENSOR_PIN 4

// LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int buttonState1 = 0;
int buttonState2 = 0;

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

float temperature;
float humidity;

// Happy face
byte happy[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
};

// Angry face
byte angry[8] = {
  B00000,
  B10001,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
};

// Neutral face
byte neutral[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B11111,
  B00000,
  B00000,
};

void setup() {

  pinMode(5, INPUT);
  pinMode(6, INPUT);

  lcd.begin(16, 2);

  lcd.createChar(0, happy);
  lcd.createChar(1, angry);
  lcd.createChar(2, neutral);

  lcd.setCursor(0, 0);
  lcd.print("Robot");

  lcd.setCursor(0, 1);
  lcd.write(byte(2));
}

void loop() {

  buttonState1 = digitalRead(5);
  buttonState2 = digitalRead(6);

  // BUTTON 1 → Happy
  if (buttonState1 == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Happy");

    lcd.setCursor(0, 1);
    lcd.write(byte(0));
  }

  // BUTTON 2 → Angry
  else if (buttonState2 == HIGH) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Angry");

    lcd.setCursor(0, 1);
    lcd.write(byte(1));
  }

  // NO BUTTON → Temperature mode
  else {

    if (dht_sensor.measure(&temperature, &humidity)) {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("Temp:");
      lcd.print(temperature);
      lcd.print("C");

      lcd.setCursor(0, 1);

      if (temperature < 20) {

        lcd.print("Cold ");
        lcd.write(byte(1)); // angry/cold
      }
      else {

        lcd.print("Nice ");
        lcd.write(byte(0)); // happy
      }
    }
  }

  delay(500);
}
