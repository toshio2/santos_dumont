// PWM channels
const int Throttle = 3;
const int Yaw = 5;
const int Pitch = 9;
const int Roll = 10;

String menuMsg = ("| Drone RC Interface | ");
String InString = "";

void setup() {
  Serial.begin(9600);
  Serial.println(menuMsg);
  while(!Serial){
  }
}

void loop() {
  analogWrite(Throttle, 170);
  analogWrite(Yaw, 50);
  analogWrite(Pitch, 100);
  analogWrite(Roll, 127);
}

