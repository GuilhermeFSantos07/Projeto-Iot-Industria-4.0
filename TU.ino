#include "DHT.h"
#define DHTPIN 5 //
#define DHTTYPE DHT11
#define LED 2

DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  dht.begin();
}

void loop() {
  digitalWrite(LED, HIGH);

  float u = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan (u) || isnan (t)){
    Serial.println("Falha na leitura");
    return;
  }
  
  Serial.print("Umidade: ");
  Serial.print(u);
  Serial.println("%");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("°");

  digitalWrite(LED, LOW);
  delay(3000);
  
}
