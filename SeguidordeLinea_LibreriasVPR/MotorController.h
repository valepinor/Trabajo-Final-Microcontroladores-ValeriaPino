// MotorController.h

// Evita problemas de inclusión múltiple
#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

// Declaración de la clase MotorController
class MotorController {
public:
  // Constructor de la clase que recibe los pines de los motores
  MotorController(int motorA1, int motorA2, int motorB1, int motorB2);

  // Métodos para controlar los movimientos de los motores
  void MotorIzquierda();
  void MotorDerecha();
  void MotorAdelante();
  void MotorStop();

  // Método para inicializar los pines de los motores
  void setupMotors();  // Agregado para la inicialización de los motores

private:
  // Variables para almacenar los pines de los motores
  int MotorA1;
  int MotorA2;
  int MotorB1;
  int MotorB2;
};

// Fin de la directiva para evitar problemas de inclusión múltiple
#endif
