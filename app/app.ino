int izqA=5;
int izqB=6;
int derA=9;
int derB=10;
int vel=254;
int estado='g'; //Detenido
int echo=2;
int trig=3;
int duracion;
int distancia;

int LDR1=0;   //Seguidor de luz
int LDR2=4;
int luz1=0;
int luz2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0) {
    estado=Serial.read();
  }
  if(estado=='a') {         //Enfrente
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, vel);
  } 
  if(estado=='b') {     //Izquierda
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, 0);
    analogWrite(izqA, vel);
  }
  if(estado=='c') {       //Seguir Luz
    luz1=analogRead(LDR1);
    luz2=analogRead(LDR2);

    if(luz1>luz2) {         //Ve a la derecha
    
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, 0);
    
    }else {   //Si Luz2 es mayor a luz1   Ve a la izquierda
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, vel);
    }
    
  }
  if(estado=='d') {         //Derecha
    analogWrite(derB, 0);
    analogWrite(izqB, 0);
    analogWrite(derA, vel);
    analogWrite(izqA, 0);
  }
  if(estado=='e') {         //Reversa
    analogWrite(derB, vel);
    analogWrite(izqB, vel);
    analogWrite(derA, 0);
    analogWrite(izqA, 0);
  }

  if(estado=='f') {   //Si hay un obstaculo
    digitalWrite(trig, HIGH);   //Pone en funcionamiento el sensor ultrasonico
    delay(0.1);
    digitalWrite(trig, LOW);
    duracion = pulseIn(echo, HIGH);
    distancia=(duracion/2)/29;
    delay(10);
    
    if(distancia <= 15 && distancia >=2) {   //Si hay un obstaculo a una distancia menor a 15 cm
      digitalWrite(13, HIGH);   //Enciende un led

      analogWrite(derB, 0); //Se detiene
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, 0);
      delay(200);

      analogWrite(derB, vel);   //Reversa
      analogWrite(derB, vel);
      delay(500);

      analogWrite(derB, 0);   //Gira hacia la derecha
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, vel);
      delay(1100);

      digitalWrite(13, LOW);
      
    } else {            //Si no hay obstaculo avanza hacia el frente
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, vel);
      analogWrite(izqA, vel);
    }
  }
  if(estado=='g') {   //Boton off --> Detiene los motores
      analogWrite(derB, 0);
      analogWrite(izqB, 0);
      analogWrite(derA, 0);
      analogWrite(izqA, 0);
  }
}
