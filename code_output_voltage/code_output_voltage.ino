const int throttle_voltage = 67;

void setup() {
  pinMode(throttle_voltage, OUTPUT);
  analogWriteResolution(8);

}

void loop() {
  for (int value = 255; value > 1; value--) {
    analogWrite(throttle_voltage, value);
    delay(100);
  }
}
