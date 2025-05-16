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
Serial.println(val);
if(val < 100) val = 100;
if(val < 800) val = 800;
int ledDimming = map(val, 100, 800, 0, 255);
analogWrite(ledPin, ledDimming);
  delay(1);                          // 延迟 1 毫秒
}
