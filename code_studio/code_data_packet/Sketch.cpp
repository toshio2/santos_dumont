#include <Arduino.h>

//zoomkat 6-29-14 Simple serial echo test
//type or paste text in serial monitor and send


// Analog ports
const uint8_t throttlePin = 5;
const uint8_t yawPin = 6;
const uint8_t pitchPin = 10;
const uint8_t rollPin = 11;

// Digital ports
const uint8_t shThrottle = 3;
const uint8_t shYaw = 4;
const uint8_t shPitch = 8;
const uint8_t shRoll = 9;

String readString;

void setup() {
  Serial.begin(9600);
  Serial.println("Simple serial echo test"); // so I can keep track of what is loaded
  pinMode(shThrottle, OUTPUT);
  pinMode(shYaw, OUTPUT);
  pinMode(shPitch, OUTPUT);
  pinMode(shRoll, OUTPUT);
}

void loop() {

  while (Serial.available())
  {
	char c = Serial.read();  //gets one byte from serial buffer
	readString += c; //makes the String readString
	delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() > 0) {
    Serial.println(readString);  //so you can see the captured String

    int throttleValue = readString.substring(0,3).toInt();
	if ((throttleValue > 171) || (throttleValue < 0))
	{
		throttleValue = 171;
	}

	int yawValue = readString.substring(4,7).toInt();
	if ((yawValue > 171) || (yawValue < 0))
	{
		yawValue = 171;
	}

    int pitchValue = readString.substring(8,11).toInt();
	if ((pitchValue > 171) || (pitchValue < 0))
	{
		yawValue = 171;
	}

	int rollValue = readString.substring(12).toInt();
	if ((rollValue > 171) || (rollValue < 0))
	{
		rollValue = 171;
	}

    analogWrite(throttlePin, throttleValue);
	analogWrite(yawPin, yawValue);
    analogWrite(pitchPin, pitchValue);
    analogWrite(rollPin, rollValue);

	digitalWrite(shThrottle, HIGH);
	digitalWrite(shYaw, HIGH);
	digitalWrite(shPitch, HIGH);
	digitalWrite(shRoll, HIGH);
	_delay_ms(2);
	digitalWrite(shThrottle, LOW);
	digitalWrite(shYaw, LOW);
	digitalWrite(shPitch, LOW);
	digitalWrite(shRoll, LOW);



	//Serial.println(throttleValue);
    //Serial.println(yawValue);
    //Serial.println(pitchValue);
    //Serial.println(rollValue);
    readString="";
  }
}
