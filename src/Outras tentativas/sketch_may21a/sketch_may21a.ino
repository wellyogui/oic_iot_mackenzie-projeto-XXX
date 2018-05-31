
//Programa: Controle de Servo Motor com Potenciometro
//Autor: FILIPEFLOP
 
//Carrega a biblioteca Servo
#include "Servo.h"
 
// Criar um Objeto Servo
Servo servo1; 
 
int ledPin = 7; //Led no pino 7
int ldrPin = 1; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR

void setup()
{
  // Anexa o Servo ao Pin5
  servo1.attach(5); 
  pinMode(ledPin,OUTPUT); //define a porta 7 como saída
  Serial.begin(9600); //Inicia a comunicação serial
}
 
void loop()
{
  ledOn();
servoMotor();


}

void servoMotor()
{
    
  // Lê o valor do Potenciometro
  int angle = analogRead(0); 
  // Mapeia o valor de 0 a 180 graus
  angle=map(angle, 0, 1023, 0, 180);
  // Repassa o angulo ao ServoWrite
  servo1.write(angle);

  delay(15);
}

void ledOn()
{
       ///ler o valor do LDR
 ldrValor = analogRead(ldrPin);
 //O valor lido será entre 0 e 1023
 Serial.print("ldrValor: ");
 
 Serial.println(ldrValor);

  //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 600) digitalWrite(ledPin,HIGH);
 // senão, apaga o led
 else digitalWrite(ledPin,LOW);
 
 //imprime o valor lido do LDR no monitor serial
 delay(1000);
}

