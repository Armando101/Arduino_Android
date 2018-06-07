int LDR1=0;
int LDR2=4;
int luz1=0;
int luz2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  luz1=analogRead(LDR1);
  luz2=analogRead(LDR2);

  Serial.print("Luz 1: ");
  Serial.println(luz1);

  Serial.print("Luz 2: ");
  Serial.println(luz2);

  delay(1000);
}
