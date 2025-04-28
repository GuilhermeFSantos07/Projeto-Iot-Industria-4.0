int LED = 2;         
int PIR = 4;
void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  pinMode(PIR, INPUT);

  delay(2000);
}

int contador = 0;

void loop() {
  int isMotionDetected = digitalRead(PIR);

  if(isMotionDetected == 0){
    Serial.println("Sem movimento");
    digitalWrite(LED, HIGH);
  } else{
    Serial.println("Movimento detectado");
    digitalWrite(LED, LOW);
    isMotionDetected = 0;
    contador++;
    delay(3000);
  }
  Serial.println(isMotionDetected);
  Serial.println(contador);
  delay(500);
}