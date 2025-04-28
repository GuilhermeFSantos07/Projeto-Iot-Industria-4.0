#define PIR_PIN 4

unsigned long lastPIRTrigger = 0;  // Armazena o último momento de detecção
const unsigned long PIRInterval = 5000; // Intervalo entre detecções em milissegundos (5 segundos)

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  Serial.println("Iniciando teste do sensor PIR com temporizador...");
}

void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(PIR_PIN) == HIGH && currentMillis - lastPIRTrigger >= PIRInterval) {
    Serial.println("Movimento detectado!");
    lastPIRTrigger = currentMillis;
    delay(500);  // Curta espera para evitar detecções múltiplas muito próximas
  }
}
