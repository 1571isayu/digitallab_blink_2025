int ledPin = 9;
int analogPin = A0;
// potentiometer connected to analog
int val = 0;

void setup() {
  // 初始化串口通讯，波特率为 9600
  pinMode (ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {

val = analogRead(analogPin);  // 读取模拟口 A0 的值
analogWrite(ledPin, val / 4);
  delay(1);                          // 延迟 1 毫秒
}
