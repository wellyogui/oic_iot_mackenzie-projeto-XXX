#include <Thermistor.h>

Thermistor temp(0);
int tempPin= 0;
int tempValor = 0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  tempValor = analogRead(tempPin);
  int temperature = temp.getTemp();
  Serial.print("Temperaturaensor eh: ");
  Serial.print(temperature);
  Serial.println("*C");

  Serial.print("TempValor: ");
  Serial.print(tempValor);
  Serial.println("*C");
  
  delay(1000);
}
