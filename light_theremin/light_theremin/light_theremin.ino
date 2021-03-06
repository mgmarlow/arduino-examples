int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int LED_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    
    if (sensorValue > sensorHigh)
      sensorHigh = sensorValue;

    if (sensorValue < sensorLow)
      sensorLow = sensorValue;    
  }
  
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.print("\tPitch: ");
  Serial.println(pitch);
  tone(8, pitch, 20);
  delay(10);
}
