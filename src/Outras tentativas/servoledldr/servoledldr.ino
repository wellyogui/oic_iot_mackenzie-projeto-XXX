//incluindo biblioteca para controle do servomotor
#include "Servo.h"
  
//Criando um objeto da classe Servo
Servo servoMotorObj;  
  
///variáveis Servo
int const potenciometroPin = 0;  //pino analógico onde o potenciômetro está conectado
int const servoMotorPin    = 3; //pino digital associado ao controle do servomotor 
int valPotenciometro;  //variável usada para armazenar o valor lido no potenciômetro   
///variáveis LED
int ledPin = 7; //Led no pino 7
int ldrPin = 0; //LDR no pino analígico 0
int ldrValor = 0; //Valor lido do LDR       
  
void setup() { 
  ///setup Servo
  servoMotorObj.attach(servoMotorPin); //associando o pino digital ao objeto da classe Servo
  
  ///setup LED
  pinMode(ledPin,OUTPUT); //define a porta 7 como saída
 Serial.begin(9600); //Inicia a comunicação serial
} 
  
void loop() 
{ 
///LOOP Servo
  //lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  valPotenciometro = analogRead(potenciometroPin); 
 
  //mapeando o valor para a escala do servo (entre 0 e 180)
  valPotenciometro = map(valPotenciometro, 0, 1023, 0, 180); 
 
  //definindo o valor/posição do servomotor
  servoMotorObj.write(valPotenciometro); 
  delay(15);  

///LOOP ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 600, liga o led
 if (ldrValor>= 600) digitalWrite(ledPin,HIGH);
 // senão, apaga o led
 else digitalWrite(ledPin,LOW);
 
 //imprime o valor lido do LDR no monitor serial
 Serial.println(ldrValor);
 delay(100);  
}

