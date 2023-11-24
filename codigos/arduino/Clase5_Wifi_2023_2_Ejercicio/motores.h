// Nombramos los pines:
//  Motor A: Derecho
//  Motor B: Izquierdo
//  Pin 1: Retroceder (Polaridad)
//  Pin 2: Avanzar    (Polaridad)
// Esto es importante para que el bot funcione bien

int motor_A1 = 14; // pin motor A1
int motor_A2 = 12; // pin motor A2
int pin_vel_A = 15; // pin control de velocidad motor A

int motor_B1 = 5; // pin motor B1
int motor_B2 = 4; // pin motor B2
int pin_vel_B = 13; // pin control de velocidad motor A

int SPEED_A = 170; //velocidades
int SPEED_B = 255;

int arma = 0;
	
/** motors setup
 * @brief Función que configura inificalmente los motores
 */
void motors_setup()
{
	// configuramos el motor A como salida (OUTPUT)
	pinMode(motor_A1, OUTPUT); // motor A1
	pinMode(motor_A2, OUTPUT); // motor A2
	pinMode(pin_vel_A, OUTPUT); // control velocidad A
	
	// configuramos el motor B como salida (OUTPUT)
	pinMode(motor_B1, OUTPUT); // motor B1
	pinMode(motor_B2, OUTPUT); // motor B2
	pinMode(pin_vel_B, OUTPUT); // control velocidad B

  pinMode(arma, OUTPUT);
	
	// partimos con el motor A apagado (LOW)
	digitalWrite(motor_A1, LOW); // motor A1
	digitalWrite(motor_A2, LOW); // motor A2

	// partimos con el motor B apagado (LOW)
	digitalWrite(motor_B1, LOW); // motor A1
	digitalWrite(motor_B2, LOW); // motor A2

  digitalWrite(arma, HIGH);
}

/** motor Foward Backward
 * @brief Función controla el movimiento hacia adelante o hacia atrás de los motores.
 * @param dir1 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_FWBW(bool dir1)
{ 
	
	if (dir1) {
	digitalWrite(motor_A1, LOW);
	digitalWrite(motor_A2, HIGH);
	analogWrite(pin_vel_A, SPEED_A);
	digitalWrite(motor_B1, LOW);
	digitalWrite(motor_B2, HIGH);
	analogWrite(pin_vel_B, SPEED_B);
	}
	else {
	digitalWrite(motor_A1, !LOW);
	digitalWrite(motor_A2, !HIGH);
	analogWrite(pin_vel_A, SPEED_A);
	digitalWrite(motor_B1, !LOW);
	digitalWrite(motor_B2, !HIGH);
	analogWrite(pin_vel_B, SPEED_B);
	}

}
/** motor Left Right 
 * @brief Función controla el giro hacia la derecha o izquierda de los motores.
 * @param dir2 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_LR(bool dir2) {
	if (dir2) { // Gira a la derecha
	digitalWrite(motor_A1, !LOW);
	digitalWrite(motor_A2, !HIGH);
	analogWrite(pin_vel_A, SPEED_A);
  // Motor A Retrocede

	digitalWrite(motor_B1, LOW);
	digitalWrite(motor_B2, HIGH);
  analogWrite(pin_vel_B, SPEED_B);
	// Motor B Avanza

	}
	else { // Gira a la izquierda
	digitalWrite(motor_A1, LOW);
	digitalWrite(motor_A2, HIGH);
	analogWrite(pin_vel_A, SPEED_A);
  // Motor A Avanza

	digitalWrite(motor_B1, !LOW);
	digitalWrite(motor_B2, !HIGH);
  analogWrite(pin_vel_B, SPEED_B);
	// Motor B Retrocede

	}
}


/** Motor Stop
 * @brief Función que detiene los motores
 */
void motor_stop(void)
{
	digitalWrite(motor_A1, LOW);
	digitalWrite(motor_A2, LOW);
	analogWrite(pin_vel_A, 0);
	digitalWrite(motor_B1, LOW);
	digitalWrite(motor_B2, LOW);
	analogWrite(pin_vel_B, 0);
}

void motor_vel(bool doble)
{
  if (doble) {
    SPEED_A = SPEED_A*2;
    SPEED_B = SPEED_B*2;
  } else {
    SPEED_A = SPEED_A/2;
    SPEED_B = SPEED_B/2;
  }
} 

void motor_arma(bool prendido)
{
  if (prendido) {
    digitalWrite(arma, LOW);  
  } else {
    digitalWrite(arma, HIGH);
  }
}

