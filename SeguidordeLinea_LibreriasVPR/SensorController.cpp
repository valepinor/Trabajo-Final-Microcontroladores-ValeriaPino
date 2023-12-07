// Incluye el archivo de declaración de la clase SensorController
#include "SensorController.h"

// Implementación del constructor que recibe los pines de los sensores
SensorController::SensorController(int pinSensor1, int pinSensor2) {
  // Asigna los pines recibidos a las variables de la clase
  PinSensor1 = pinSensor1;
  PinSensor2 = pinSensor2;
}

// Implementación del método para inicializar los pines de los sensores
void SensorController::setupSensors() {
  // Configura los pines de los sensores como entradas
  pinMode(PinSensor1, INPUT);
  pinMode(PinSensor2, INPUT);
}

// Implementación del método para leer el valor del sensor 1
int SensorController::readSensor1() {
  // Lee y devuelve el valor digital del sensor 1
  return digitalRead(PinSensor1);
}

// Implementación del método para leer el valor del sensor 2
int SensorController::readSensor2() {
  // Lee y devuelve el valor digital del sensor 2
  return digitalRead(PinSensor2);
}
