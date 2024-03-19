/*
  Kit Brazo Robot PLA
  compatible con App robocon

*/
#include <Servo.h>
#include "robocon-blt-protocol.cpp"

Servo Servo_1;
Servo Servo_2;
Servo Servo_3;
Servo Servo_4;
Servo Servo_5;
Servo Servo_6;

volatile int Angulo = 0;
volatile int Angulo_1 = 90;
volatile int Angulo_2 = 90;
volatile int Angulo_3 = 90;
volatile int Angulo_4 = 90;
volatile int Angulo_5 = 90;
volatile int Angulo_6 = 90;

String Estado;
int Velocidad = 25;
int Avance = 10;

void Mover_Servo(Servo Servo_1, int Angulo_Actual, int Velocidad);

void setup()
{
  Serial.begin(9600);

  Servo_1.attach(2);
  Servo_2.attach(3);
  Servo_3.attach(4);
  Servo_4.attach(5);
  Servo_5.attach(6);
  Servo_6.attach(7);

  Home();
  delay(2000);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char _command = Serial.read();

    if (_command != '#' && _command != '!' && _command != '\n' && _command != '\r' && _command != ' ' && _command != '\t' && _command != '\0' && _command != '\b' && _command != '\f' && _command != '\v' && _command != '\a' && _command != '\e')
    {
      Estado += _command;
    }

    else if (_command == '#')
    {

      Estado = "";
    }
  }

  if (Angulo_1 > 0 && Estado == SERVO_1_DERECHA)
  {
    Angulo_1--;
    Mover_Servo(Servo_1, Angulo_1, Velocidad);
  }
  else if (Angulo_1 < 180 && Estado == SERVO_1_IZQUIERDA)
  {
    Angulo_1++;
    Mover_Servo(Servo_1, Angulo_1, Velocidad);
  }
  else if (Angulo_2 > 0 && Estado == SERVO_2_DERECHA)
  {
    Angulo_2--;
    Mover_Servo(Servo_2, Angulo_2, Velocidad);
  }
  else if (Angulo_2 < 180 && Estado == SERVO_2_IZQUIERDA)
  {
    Angulo_2++;
    Mover_Servo(Servo_2, Angulo_2, Velocidad);
  }
  else if (Angulo_3 > 0 && Estado == SERVO_3_IZQUIERDA)
  {
    Angulo_3--;
    Mover_Servo(Servo_3, Angulo_3, Velocidad);
  }
  else if (Angulo_3 < 180 && Estado == SERVO_3_DERECHA)
  {
    Angulo_3++;
    Mover_Servo(Servo_3, Angulo_3, Velocidad);
  }
  else if (Angulo_4 > 0 && Estado == SERVO_4_IZQUIERDA)
  {
    Angulo_4--;
    Mover_Servo(Servo_4, Angulo_4, Velocidad);
  }
  else if (Angulo_4 < 180 && Estado == SERVO_4_DERECHA)
  {
    Angulo_4++;
    Mover_Servo(Servo_4, Angulo_4, Velocidad);
  }
  else if (Angulo_5 > 0 && Estado == SERVO_5_IZQUIERDA)
  {
    Angulo_5--;
    Mover_Servo(Servo_5, Angulo_5, Velocidad);
  }

  else if (Angulo_5 < 180 && Estado == SERVO_5_DERECHA)
  {
    Angulo_5++;

    Mover_Servo(Servo_5, Angulo_5, Velocidad);
  }
  else if (Angulo_6 > 0 && Estado == SERVO_6_IZQUIERDA)
  {
    Angulo_6--;
    Mover_Servo(Servo_6, Angulo_6, Velocidad);
  }

  else if (Angulo_6 < 180 && Estado == SERVO_6_DERECHA)
  {
    Angulo_6++;
    Mover_Servo(Servo_6, Angulo_6, Velocidad);
  }
}

void Home()
{
  Mover_Servo(Servo_1, Angulo_1, 25);
  Mover_Servo(Servo_2, Angulo_2, 25);
  Mover_Servo(Servo_3, Angulo_3, 25);
  Mover_Servo(Servo_4, Angulo_4, 10);
  Mover_Servo(Servo_5, Angulo_5, 10);
  Mover_Servo(Servo_6, Angulo_6, 10);
}
void Mover_Servo(Servo Servo_1, int Angulo_Actual, int Velocidad)
{
  Servo_1.write(Angulo_Actual);
  delay(Velocidad);
}
