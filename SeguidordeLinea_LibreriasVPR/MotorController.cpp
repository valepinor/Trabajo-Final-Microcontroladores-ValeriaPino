// MotorController.cpp

// Incluye el archivo de declaración de la clase MotorController
#include "MotorController.h"
// Incluye la librería principal de Arduino
#include <Arduino.h>

// Implementación del constructor que recibe los pines de los motores
MotorController::MotorController(int MotorA1, int MotorA2, int motorB1, int motorB2) {
  // Asigna los pines recibidos a las variables de la clase
  MotorA1 = motorA1;
  MotorA2 = motorA2;
  MotorB1 = motorB1;
  MotorB2 = motorB2;
}

// Implementación del método para mover el motor hacia la izquierda
void MotorController::MotorIzquierda() {
  // Configura los pines para mover el motor hacia la izquierda
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);
}

// Implementación del método para mover el motor hacia la derecha
void MotorController::MotorDerecha() {
  // Configura los pines para mover el motor hacia la derecha
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);
}

// Implementación del método para mover el motor hacia adelante
void MotorController::MotorAdelante() {
  // Configura los pines para mover el motor hacia adelante
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);
  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);
}

// Implementación del método para detener el motor
void MotorController::MotorStop() {
  // Configura todos los pines en modo bajo para detener el motor
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, LOW);
}

// Implementación del método para inicializar los pines de los motores
void MotorController::setupMotors() {
  // Configura los pines de los motores como salidas
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
}

