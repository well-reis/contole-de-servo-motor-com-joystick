#include <Servo.h>

//define os servos - Neste exemplo, um joystick controla 2 servos - *ligar fonte externa para alimentar mais de 2 servos
Servo servo1;
Servo servo2;

//define joystick pin (Analog)
int joyX = A0;   // eixo X - para frente e para trás, conectado na porta analógica A0
int joyY = A1;   // eixo Y - para direita e para esquerda, conectado na porta analógica A1

//variavel para ler os valores dos pinos analogicos
int joyVal;

void setup()
{ //anexa os servos aos pinos digitais - OS PINOS DIGITAIS DEVEM SER DO TIPO PWM PARA FUNCIONAR
  servo1.attach(5); //Servo 1 conectado ao pino 5 do arduino
  servo2.attach(9); //Servo 2 conectado ao pino 9 do arduino
}

void loop()
{
  //lê o valor do joystick (de 0 a 1023, 0 a 180º)  eixo X controla o servo 1
  joyVal = analogRead(joyX);
  joyVal = map (joyVal, 0, 1023, 0, 180); //
  servo1.write(joyVal); //Posiciona o servo de acordo com o movimento do joystick
 
  joyVal = analogRead(joyY);  //eixo Y controla o servo 2
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(15);
}
