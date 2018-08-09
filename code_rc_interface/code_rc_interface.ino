//const int Throttle = 67;
const int Throttle = 3;
int buttonState = 0;

String menuMsg = ("| Drone RC Interface | ");
String InString = "";

void setup() {
  //pinMode(throttle_voltage, OUTPUT);
  pinMode(2, OUTPUT);
  //pinMode(4, INPUT);
  //analogWriteResolution(12);
  Serial.begin(9600);

  DashedLine(menuMsg.length());
  Serial.println(menuMsg);
  DashedLine(menuMsg.length());

  while(!Serial){
  }
}

void loop() {
  /*
  for (int value = 255; value > 1; value--) {
    analogWrite(throttle_voltage, value);
    delay(100);
  }
  */
  while(Serial.available()){
    InString = Serial.readString();
    int InVoltage = InString.toInt();
    
    if (InVoltage > 171){
      InVoltage = 171;
    }
    
    //InVoltage = map(InVoltage, 0, 3.3, 0, 255);
    analogWrite(Throttle, InVoltage);
    delay(500);
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(50);
    Serial.print("String: ");
    Serial.println(InString);
    Serial.print("Throttle Voltage = ");
    Serial.println(InVoltage);
  }
  /*
  buttonState = digitalRead(4);
  if (buttonState == HIGH){
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  */
}

void Menu(){
  Serial.println("menu_banner");
  for(;;){
    switch(Serial.read()){
      case '1':
        //DemuxConfig();
        Serial.println("Demultiplexer Configuration");
        break;
      case '2':
        //SetVoltage();
        Serial.println("Set Voltage");
        break;
      case '3':
        return;
      default:
        continue;
    }
  }
}

void DashedLine(int len){
  for(int i = 0; i < len; i++){
    Serial.print("-");
  }
  Serial.println();
}
