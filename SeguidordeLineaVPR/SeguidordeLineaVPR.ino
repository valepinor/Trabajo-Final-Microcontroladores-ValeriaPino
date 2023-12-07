static int MotorA1 = 8; //Motor A
static int MotorA2 = 9;
static int MotorB1 = 10; //Motor B
static int MotorB2 = 11;
static int Pin_sensor1 = 40;   // Recoge las señales del sensor
static int Pin_sensor2 = 42;   // Recoge las señales del sensor

void setup() {
  Serial.begin(9600); // Comunicaciones con el puerto serie para monitorear
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
  pinMode(Pin_sensor1, INPUT);       
  pinMode(Pin_sensor2, INPUT);       
}

void loop() {
  
  int value1 =0; // Recoge la señal del sensor izquierdo
  int value2 =0; // Recoge la señal del sensor derecho
  value1 = digitalRead(Pin_sensor1); // lectura digital de pin del sensor1
  value2 = digitalRead(Pin_sensor2); // lectura digital de pin del sensor2
   
  if (value1 == HIGH && value2 == HIGH) {
    Serial.println("adelante");
    MotorAdelante();    
  }
  
  if (value1 == LOW && value2 == LOW) {
    Serial.println("detenido");
    MotorStop();    
  }
 
   if (value1 == HIGH && value2 == LOW) // Si el sensor izquierdo detecta una zona oscura    
    {
     Serial.println("izquierda");
     MotorIzquierda();
    } 
    
   if (value2 == HIGH && value1 == LOW) // Si el sensor derecho detecta una zona oscura  
    { 
     Serial.println("derecha"); 
     MotorDerecha();
    }
 
  delay(20);	// Pausa en milisegundos
}
  
  void MotorIzquierda()
  {
  digitalWrite (MotorA1, HIGH); // Motor Izquierdo atrás
  digitalWrite (MotorA2, LOW);  
  digitalWrite (MotorB1, HIGH); // Motor Derecho adelante
  digitalWrite (MotorB2, LOW); 
  }

  void MotorDerecha(){
  digitalWrite (MotorA1, LOW); // Motor Izquierdo adelante
  digitalWrite (MotorA2, HIGH);  
  digitalWrite (MotorB1, LOW); // Motor Derecho atrás
  digitalWrite (MotorB2, HIGH);
  }

  void MotorAdelante(){
  digitalWrite (MotorA1, LOW); // Motor Izquierdo adelante
  digitalWrite (MotorA2, HIGH); 
  digitalWrite (MotorB1, HIGH); // Motor Derecho adelante
  digitalWrite (MotorB2, LOW); 
  }

  void MotorStop(){
  digitalWrite (MotorA1, LOW); // Motor Izquierdo detenido
  digitalWrite (MotorA2, LOW);
  digitalWrite (MotorB1, LOW); // Motor Derecho detenido 
  digitalWrite (MotorB2, LOW);
  }