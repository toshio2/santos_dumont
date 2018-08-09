int incomingByte = 0;  // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(7, OUTPUT);
}

void loop() {

  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    digitalWrite(7, HIGH);
    digitalWrite(7, LOW);
  }
}
