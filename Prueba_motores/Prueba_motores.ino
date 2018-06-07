int enM11=10;
int enM12=9;
int enM21=6;
int enM22=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(enM11, OUTPUT);
  pinMode(enM12, OUTPUT);
  pinMode(enM21, OUTPUT);
  pinMode(enM22, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(enM11, HIGH);
  digitalWrite(enM12, LOW);
  digitalWrite(enM21, HIGH);
  digitalWrite(enM22, LOW);
  
  delay(1000);

  digitalWrite(enM11, LOW);
  digitalWrite(enM12, HIGH);
  digitalWrite(enM21, LOW);
  digitalWrite(enM22, LOW);

  delay(1000);

  digitalWrite(enM21, HIGH);
  digitalWrite(enM22, LOW);
  digitalWrite(enM11, HIGH);
  digitalWrite(enM12, HIGH);

  delay(1000);

  digitalWrite(enM11, LOW);
  digitalWrite(enM12, HIGH);
  digitalWrite(enM21, LOW);
  digitalWrite(enM22, HIGH);
  
}

