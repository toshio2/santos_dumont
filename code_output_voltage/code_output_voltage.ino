//const int Throttle = 67;
const int Throttle = 10;
String menuMsg = ("| Drone RC Interface | ");
String InString = "";

void setup() {
  //pinMode(throttle_voltage, OUTPUT);
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
    
    if (InVoltage > 176){
      InVoltage = 176;
    }
    
    //InVoltage = map(InVoltage, 0, 3.3, 0, 255);
    analogWrite(Throttle, InVoltage);
    Serial.print("String: ");
    Serial.println(InString);
    Serial.print("Throttle Voltage = ");
    Serial.println(InVoltage);
  }
  
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

