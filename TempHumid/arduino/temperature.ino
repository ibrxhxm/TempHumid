#include <DHT.h>

#define DHT11_PIN 6
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

struct TempHumid {
  float tempCelcius;
  float tempFarenheit;
  float humidity; 
};

void setup(){
  Serial.begin(9600);

  dht.begin();
}

void loop() {
  TempHumid payload;
  
  payload.tempCelcius = dht.readTemperature();
  payload.tempFarenheit = dht.readTemperature(true);
  payload.humidity = dht.readHumidity();

  if (isnan(payload.tempCelcius) || isnan(payload.tempFarenheit) || isnan(payload.humidity)) {
    Serial.println("Failed to read from DHT11 sensor!");

    return;
  }

  String payloadString = "";

  payloadString.concat(payload.tempCelcius);
  payloadString.concat("-");
  payloadString.concat(payload.tempFarenheit);
  payloadString.concat("-");
  payloadString.concat(payload.humidity);

  Serial.println(payloadString);

  delay(5000);
}
