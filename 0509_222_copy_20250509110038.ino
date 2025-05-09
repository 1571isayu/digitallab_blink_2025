#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0

#define BUTTON 2

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

char incomingByte = 0;

int circle[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}
};

int H[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}
};

int A[8][8] = {
  {1,1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,1,1,1}
};

void setup() {
  Serial.begin(9600);

  for (byte i = 0; i < sizeof(row) / sizeof(row[0]); i++) {
    pinMode(row[i], OUTPUT);
  }

  for (byte i = 0; i < sizeof(col) / sizeof(col[0]); i++) {
    pinMode(col[i], OUTPUT);
  }

  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }

  if (incomingByte == 'c') showPattern(circle);
  else if (incomingByte == 'H') showPattern(H);
  else if (incomingByte == 'A') showPattern(A);
}

void showPattern(int matrix[8][8]) {
  for (int t = 0; t < 100; t++) {  // 顯示穩定幾次，避免閃爍
    lightup(matrix);
  }
}

void lightup(int matrix[8][8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(col[i], HIGH);
    for (int j = 0; j < 8; j++) {
      digitalWrite(row[j], matrix[j][i]);
    }
    delay(1);
    for (int j = 0; j < 8; j++) {
      digitalWrite(row[j], HIGH);
    }
    digitalWrite(col[i], LOW);
  }
}
