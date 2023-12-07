#include <NewPing.h> //Para el sensor ultrasonico
#include <Servo.h> //Para el servo

#define TRIG_PIN A0 // Numero del pin para TRIG (transmisor)
#define ECHO_PIN A1 // Numero del pin para ECHO (receptor)
#define MAX_DISTANCE 200

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
boolean goesForward = false; // Saber si el robot avanza o no
int distancia = 100; // Variable distancia se inicializa en 100
int speedSet = 0; 

//pines motores
const int MotorA1 = 8; //Motor A
const int MotorA2 = 9;
const int MotorB1 = 10; //Motor B
const int MotorB2 = 11;

void setup(){
  
  myservo.attach(7); // Servo al pin 7
  myservo.write(115); // Posicion inicial del servo
  distancia = readPing(); // Lee distancia del sensor
  delay(100);
  distancia = readPing();
  delay(100);
  distancia = readPing();
  delay(100);
}

void loop(){

  int distanciaD = 0; // Distancia derecha
  int distanciaI = 0; // Distancia izquierda
  delay(40);

  if(distancia<=30) {

      detenerse(); // Detener
      delay(200);
      moveratras(); // Retroceder
      delay(800);

      detenerse();
      delay(200);
      distanciaD = lookD(); //Girar derecha y medir distancia
      delay(200);
      distanciaI = lookI(); //Girar izquierda y medir distancia
      delay(200);

      if(distanciaD>=distanciaI) {
        girarDerecha(); // Girar derecha
        detenerse(); // Detener
      }

      else {
        girarIzquierda(); // Girar izquierda
        detenerse(); // Detener
      }
  }

  else{
      avanzar(); // Avanzar
  }

distancia = readPing(); // Leer distancia actual
}

int lookD() {
  myservo.write(50); // Girar el servo a la derecha
  delay(500);
  int distancia = readPing(); // Medir distancia
  delay(100);
  myservo.write(115); // Volver a la posicion frontal
  return distancia;
}

int lookI() {
  myservo.write(50); // Girar el servo a la izquierda
  delay(500);
  int distancia = readPing(); // Medir distancia
  delay(100);
  myservo.write(115); // Volver a la posicion frontal
  return distancia;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm(); // Lectura sensor en cm
  if(cm==0)
  {
    cm=300; // Si es cero, establecer una distancia max
  }
  return cm;
}

void detenerse(){
  analogWrite (MotorA1, 0); // Detener todos los motores
  analogWrite (MotorA2, 0);
  analogWrite (MotorB1, 0);
  analogWrite (MotorB2, 0);
}

void avanzar(){
  analogWrite (MotorA1, 180); // Ruedas hacia adelante
  analogWrite (MotorA2, 0);
  analogWrite (MotorB1, 180);
  analogWrite (MotorB2, 0);
}

void moveratras(){
  analogWrite (MotorA1, 0); // Ruedas hacia atras
  analogWrite (MotorA2, 180);
  analogWrite (MotorB1, 0);
  analogWrite (MotorB2, 180);
}

void girarDerecha(){
  analogWrite (MotorA1, 180); // Gira a la derecha
  analogWrite (MotorA2, 0);
  analogWrite (MotorB1, 0);
  analogWrite (MotorB2, 180);
  delay(300);
  avanzar(); //avanzar
}

void girarIzquierda(){
  analogWrite (MotorA1, 0); // Gira a la izquierda
  analogWrite (MotorA2, 180);
  analogWrite (MotorB1, 180);
  analogWrite (MotorB2, 0); 
  delay(300);
  avanzar(); // avanzar
}