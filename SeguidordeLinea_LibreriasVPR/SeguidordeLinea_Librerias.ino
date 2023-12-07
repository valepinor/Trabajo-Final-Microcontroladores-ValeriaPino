#include <Arduino.h>
#include "MotorController.h"
#include "SensorController.h"

// Definición de pines para motores y sensores
int MotorA1 = 8;
int MotorA2 = 9;
int MotorB1 = 10;
int MotorB2 = 11;
int PinSensor1 = 40;
int PinSensor2 = 42;

// Creación de instancias de las clases MotorController y SensorController
MotorController motorController(MotorA1, MotorA2, MotorB1, MotorB2);
SensorController sensorController(PinSensor1, PinSensor2);

void setup() {
  // Inicia la comunicación serial
  Serial.begin(9600);

  // Configura los pines de los motores
  motorController.setupMotors();

  // Configura los pines de los sensores
  sensorController.setupSensors();
}

void loop() {
  // Lee los valores de los sensores
  int value1 = sensorController.readSensor1();
  int value2 = sensorController.readSensor2();

  // Realiza acciones en función de las lecturas de los sensores
  if (value1 == HIGH && value2 == HIGH) {
    Serial.println("adelante");
    motorController.MotorAdelante();
  } else if (value1 == LOW && value2 == LOW) {
    Serial.println("detenido");
    motorController.MotorStop();
  } else if (value1 == HIGH && value2 == LOW) {
    Serial.println("izquierda");
    motorController.MotorIzquierda();
  } else if (value2 == HIGH && value1 == LOW) {
    Serial.println("derecha");
    motorController.MotorDerecha();
  }

  // Breve pausa antes de repetir el bucle
  delay(20);
}
