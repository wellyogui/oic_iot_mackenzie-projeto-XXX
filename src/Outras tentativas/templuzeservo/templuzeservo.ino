/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>

  Rotate a servo using a slider!

  App project setup:
    Slider widget (0...180) on V3
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT SwSerial

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleStream.h>
#include <Servo.h>
#include <Thermistor.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8ccaf4e53a0e436e9a570b7c2df08b2b";

Thermistor temp(0);
Servo servo;
int ledPin = 7; //Led no pino 7
int ldrPin = 0; //LDR no pino analígico 0
int ldrValor = 0; //Valor lido do LDR
int nloop = 0;
WidgetTerminal terminal(V1);

void setup()
{
  // Debug console
  SwSerial.begin(9600);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  terminal.println("ldrValor:");
  terminal.println(ldrValor);
  terminal.flush();
  servo.attach(9);
  pinMode(ledPin,OUTPUT); //define a porta 7 como saída
}

BLYNK_WRITE(V1)
{
 terminal.println("ldrValor:" + ldrValor);
 terminal.flush();
}

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}


void loop()
{
  Blynk.run();
  //LED 
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 //se o valor lido for maior que 500, liga o led
 if (ldrValor>= 1000) digitalWrite(ledPin,HIGH);
 // senão, apaga o led
 else digitalWrite(ledPin,LOW);
 delay(1000);
}
