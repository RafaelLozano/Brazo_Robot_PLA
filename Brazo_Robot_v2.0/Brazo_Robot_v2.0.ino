#include <Servo.h>
#include <SoftwareSerial.h>
#include "robocon-blt-protocol.cpp"

SoftwareSerial Bluetooth(9, 8); // RX, TX

Servo Servo_1;
Servo Servo_2;
Servo Servo_3;
Servo Servo_4;
Servo Servo_5;
Servo Servo_6;

int Angulo = 0;
int Angulo_1 = 90;
int Angulo_2 = 90;
int Angulo_3 = 90;
int Angulo_4 = 90;
int Angulo_5 = 90;
int Angulo_6 = 90;

String Estado;
int Velocidad = 25;
int Avance = 10;

byte Mover_Servo(Servo Servo_1, int Angulo_Actual, int Angulo, int Velocidad);

void setup()
{
  Serial.begin(9600);
  Bluetooth.begin(9600);

  Servo_1.attach(2);
  Servo_2.attach(3);
  Servo_3.attach(4);
  Servo_4.attach(5);
  Servo_5.attach(6);
  Servo_6.attach(7);

  Home();
  delay(2000);
  Serial.println(SERVO_1_DERECHA);
}

void loop()
{
  if (Bluetooth.available() > 0)
  {
    char _command = Bluetooth.read();

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

    Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 - Avance, Velocidad);
  }
  else if (Angulo_1 < 180 && Estado == SERVO_1_IZQUIERDA)
  {
    Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 + Avance, Velocidad);
  }
  else if (Angulo_2 > 0 && Estado == SERVO_2_DERECHA)
  {
    Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 - Avance, Velocidad);
  }
  else if (Angulo_2 < 180 && Estado == SERVO_2_IZQUIERDA)
  {
    Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 + Avance, Velocidad);
  }
  else if (Angulo_3 < 180 && Estado == SERVO_3_DERECHA)
  {
    Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 - Avance, Velocidad);
  }
  else if (Angulo_3 > 0 && Estado == SERVO_3_IZQUIERDA)
  {
    Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 + Avance, Velocidad);
  }
  else if (Angulo_4 < 180 && Estado == SERVO_4_DERECHA)
  {
    Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 - Avance, Velocidad);
  }
  else if (Angulo_4 > 0 && Estado == SERVO_4_IZQUIERDA)
  {
    Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 + Avance, Velocidad);
  }
  else if (Angulo_5 < 180 && Estado == SERVO_5_DERECHA)
  {
    Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 - Avance, Velocidad);
  }
  else if (Angulo_5 > 0 && Estado == SERVO_5_IZQUIERDA)
  {
    Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 + Avance, Velocidad);
  }
  else if (Angulo_6 < 180 && Estado == SERVO_6_DERECHA)
  {
    Angulo_6 = Mover_Servo(Servo_6, Angulo_6, Angulo_6 - Avance, Velocidad);
  }
}

void Home()
{
  Angulo_1 = Mover_Servo(Servo_1, Angulo_1, 90, 25);
  Angulo_2 = Mover_Servo(Servo_2, Angulo_2, 90, 25);
  Angulo_3 = Mover_Servo(Servo_3, Angulo_3, 90, 25);
  Angulo_4 = Mover_Servo(Servo_4, Angulo_4, 90, 10);
  Angulo_5 = Mover_Servo(Servo_5, Angulo_5, 90, 10);
  Angulo_6 = Mover_Servo(Servo_6, Angulo_6, 90, 10);
}
byte Mover_Servo(Servo Servo_1, int Angulo_Actual, int Angulo, int Velocidad)
{
  while (Angulo_Actual != Angulo)
  {
    if (Angulo_Actual < Angulo)
    {
      Angulo_Actual++;
      Servo_1.write(Angulo_Actual);
      delay(Velocidad);
    }
    else
    {
      Angulo_Actual--;
      Servo_1.write(Angulo_Actual);
      delay(Velocidad);
    }
  }
  return (Angulo_Actual);
}
