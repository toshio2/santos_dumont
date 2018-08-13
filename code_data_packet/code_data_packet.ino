//zoomkat 6-29-14 Simple serial echo test
//type or paste text in serial monitor and send

const uint8_t throttlePin = 5;
const uint8_t yawPin = 6;
const uint8_t pitchPin = 10;
const uint8_t rollPin = 11;

String readString;

void setup() {
  Serial.begin(9600);
  Serial.println("Simple serial echo test"); // so I can keep track of what is loaded
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
    Serial.println(readString);  //so you can see the captured String
    
    int throttleValue = readString.substring(0,3).toInt();
    int yawValue = readString.substring(4,7).toInt();
    int pitchValue = readString.substring(8,11).toInt();
    int rollValue = readString.substring(12).toInt();
    
    analogWrite(throttlePin, throttleValue);
    analogWrite(yawPin, yawValue);
    analogWrite(pitchPin, pitchValue);
    analogWrite(rollPin, rollValue);
    
    //Serial.println(throttleValue);
    //Serial.println(yawValue);
    //Serial.println(pitchValue);
    //Serial.println(rollValue);
    readString="";
  }
}
