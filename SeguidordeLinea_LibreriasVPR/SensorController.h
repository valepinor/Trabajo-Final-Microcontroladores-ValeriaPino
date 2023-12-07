// SensorController.h

// Evita problemas de inclusión múltiple
#ifndef SENSOR_CONTROLLER_H
#define SENSOR_CONTROLLER_H

// Incluye la librería principal de Arduino
#include <Arduino.h>

// Declaración de la clase SensorController
class SensorController {
public:
  // Constructor que recibe los pines de los sensores como parámetros
  SensorController(int pinSensor1, int pinSensor2);

  // Método para inicializar los pines de los sensores
  void setupSensors();

  // Métodos para leer los valores de los sensores
  int readSensor1();
  int readSensor2();

private:
  // Variables para almacenar los pines de los sensores
  int PinSensor1;
  int PinSensor2;
};

// Fin de la directiva para evitar problemas de inclusión múltiple
#endif
