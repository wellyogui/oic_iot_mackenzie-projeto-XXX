/***************************
*
*               Calibrar sensor de luminosidade LDR
*                   http://squids.com.br/arduino
*
***************************/
const int LDR = 0;
int ValorLido = 0;
void setup() {
Serial.begin(9600);
}
void loop() {
ValorLido = analogRead(LDR);
Serial.print("Valor lido pelo LDR = ");
Serial.println(ValorLido);
delay(500);
}
