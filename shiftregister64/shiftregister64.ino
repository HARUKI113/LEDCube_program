// https://hogehoge.tk/tool/number.html
// CUBEは1番上から1段目，1番下は8段目

const int g_SRCLK = A1;                           //74hc595 11
const int g_RCLK = A0;                            //74hc595 12
const int g_SER = A2;                             //74hc595 14
const int g_GND[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };  //1,2,3,4,5,6,7,8段目

byte patterns[8][8] = {
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //1段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //2段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //3段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //4段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //5段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //6段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },  //7段目
  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }   //8段目
};

void setup() {
  pinMode(g_SRCLK, OUTPUT);
  pinMode(g_RCLK, OUTPUT);
  pinMode(g_SER, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(g_GND[i], OUTPUT);
  }
}

void loop() {
  // digitalWrite(g_RCLK,  LOW);
  // shiftOut(g_SER, g_SRCLK, MSBFIRST, 0b11111111);
  // digitalWrite(g_RCLK,  HIGH);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == 0) {
        digitalWrite(g_GND[8], LOW);
      } else {
        digitalWrite(g_GND[i - 1], LOW);
      }
      digitalWrite(g_RCLK, LOW);
      shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][j]);
      digitalWrite(g_GND[i], HIGH);
      digitalWrite(g_RCLK, HIGH);
    }
  }
}