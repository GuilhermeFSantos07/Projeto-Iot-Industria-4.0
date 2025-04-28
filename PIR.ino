int LED = 2;       
     
int PIR = 5;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  pinMode(PIR, INPUT);

  delay(1500);

  serial.println("Teste do sensor");
}

unsigned long currentTime;
const unsigned long motionCheckInterval = 150UL;
unsigned long previousMotionCheckTime = 0;

void loop() {
  int sensorvalue = digitalRead(SENSOR_OUTPUT_PIN);

  Serial.println(sensorvalue);
  
  if (sensorvalue == HIGH) {
   digitalWrite(LED, HIGH);
   delay(2000);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
