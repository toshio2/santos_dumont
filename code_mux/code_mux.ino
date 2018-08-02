int en = 2;
int b = 4;
int a = 7;
int button = 8;
int pwmOut = 10;

int state = LOW;
int a_state = LOW;
int b_state = LOW;
int option = 0;
int reading;
int previous = LOW;

long time = 0;
long debounce = 200;


void setup() {
  Serial.begin(9600);
  pinMode(en, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  reading = digitalRead(button);
  int sensorValue = analogRead(A0);
  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(pwmOut,sensorValue);
  Serial.println(sensorValue);
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch(inByte){
      case 'e':
        digitalWrite(en, LOW);
        break;
      case 'd':
        digitalWrite(en, HIGH);
        break;
      case '0':
        digitalWrite(b, LOW);
        digitalWrite(a, LOW);
        break;
      case '1':
        digitalWrite(b, LOW);
        digitalWrite(a, HIGH);
        break;
      case '2':
        digitalWrite(b, HIGH);
        digitalWrite(a, LOW);
        break;
      case '3':
        digitalWrite(b, HIGH);
        digitalWrite(a, HIGH);
        break;
      default:
        digitalWrite(en, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(a, LOW);
        break;
    }
  }
  
  delay(1);

  /*
  if (reading == HIGH && previous == LOW && millis() - time > debounce){
    if (state == HIGH) {
      state = LOW;
    }
    else {
      state = HIGH;
    }

    time = millis();
  }
  */
  //digitalWrite(en, state);
  previous = reading;
}
