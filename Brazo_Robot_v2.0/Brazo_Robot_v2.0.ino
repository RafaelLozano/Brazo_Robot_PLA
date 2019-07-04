#include <Servo.h>

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

char Estado;
int Velocidad = 25;
int Avance = 10;


byte Mover_Servo(Servo Servo_1, int Angulo_Actual, int Angulo, int Velocidad);

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
    Estado = Serial.read();
  }
  switch (Estado)
  {
    case 'e':
      if (Angulo_1 > 0)
      {
        Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 - Avance, Velocidad);
      }
      break;

    case 'd':
      if (Angulo_1 < 180)
      {
        Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 + Avance, Velocidad);
      }
      break;

    case 'g':
      if (Angulo_2 > 0)
      {
        Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 - Avance, Velocidad);
      }
      break;

    case 'f':
      if (Angulo_2 < 180)
      {
        Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 + Avance, Velocidad);
      }
      break;

    case 'h':
      if (Angulo_3 < 180)
      {
        Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 - Avance, Velocidad);
      }

      break;

    case 'i':
      if (Angulo_3 > 0)
      {
        Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 + Avance, Velocidad);
      }
      break;

    case 'j':
      if (Angulo_4 < 180)
      {
        Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 - Avance, Velocidad);
      }

      break;

    case 'k':
      if (Angulo_4 > 0)
      {
        Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 + Avance, Velocidad);
      }
      break;

    case 'l':
      if (Angulo_5 < 180)
      {
        Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 - Avance, Velocidad);
      }

      break;

    case 'm':
      if (Angulo_5 > 0)
      {
        Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 + Avance, Velocidad);
      }
      break;

    case 'n':
      if (Angulo_6 < 180)
      {
        Angulo_6 = Mover_Servo(Servo_6, Angulo_6, Angulo_6 - Avance, Velocidad);
      }

      break;

    case 'o':
      if (Angulo_6 > 0)
      {
        Angulo_6 = Mover_Servo(Servo_6, Angulo_6, Angulo_6 + Avance, Velocidad);
      }
      break;


    case 'p':
      //Funcion 1
      Home();
      break;
    case 'q':
      //Funcion 1
      break;

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
