// https://hogehoge.tk/tool/number.html

const int SRCLK = A1; //74hc595 11
const int RCLK =  A0; //74hc595 12
const int SER =   A2; //74hc595 14

const int GND[8] = {2, 3, 4, 5, 6, 7, 8, 9}; //上から順に

byte patterns[][8] = {
  {0xFF},
  {0xFF},
  {0xFF},
  {0xFF},
  {0xFF},
  {0xFF},
  {0xFF},
  {0xFF}
};

void setup() {
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK,  OUTPUT);
  pinMode(SER,   OUTPUT);

  for (int i = 0; i > 8; i++) {
    pinMode(GND[i], OUTPUT);
  }
}

void loop() {
  // digitalWrite(RCLK,  LOW);
  // shiftOut(SER, SRCLK, MSBFIRST, 0b11111111);
  // digitalWrite(RCLK,  HIGH);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(RCLK,  LOW);
      shiftOut(SER, SRCLK, MSBFIRST, patterns[i][j]);
      digitalWrite(RCLK, HIGH );
    }
  }

}