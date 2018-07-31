int en = 2;
int b = 4;
int a = 7;
int button = 8;

int state = LOW;
int reading;
int previous = LOW;

long time = 0;
long debounce = 200;


void setup() {
  pinMode(en, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(button, INPUT);
}


void loop() {
  state = digitalRead(button);
  if (state == HIGH){
    digitalWrite(en, LOW);
    digitalWrite(b, LOW);
    digitalWrite(a, HIGH);
  }
  else {
    digitalWrite(en, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(a, HIGH);
  }

}
