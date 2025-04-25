
int ledpin2 = 12;
void setup() {
  // put your setup code here, to run once:
  
pinMode(LED_BUILTIN, OUTPUT);
pinMode(LED_ledpin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_BUILTIN,  HIGH);
digitalWrite(LED_ledpin2,  LOW);
delay(500);
digitalWrite(LED_ledpin2,  HIGH);
delay(500);
digitalWrite(LED_BUILTIN,  LOW);
digitalWrite(LED_ledpin2,  LOW);
delay(500);
digitalWrite(LED_BUILTIN,  HIGH);
delay(500);

}
