#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_SENSOR_PIN 4

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

float temperature;
float humidity;

unsigned long lastMeasurement = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (millis() - lastMeasurement > 2000) {

    if (dht_sensor.measure(&temperature, &humidity)) {

      Serial.print("Temp: ");
      Serial.print(temperature);
      Serial.print(" C | Hum: ");
      Serial.print(humidity);
      Serial.println(" %");

    } else {
      Serial.println("Sensor failed reading!");
    }

    lastMeasurement = millis();
  }
}
