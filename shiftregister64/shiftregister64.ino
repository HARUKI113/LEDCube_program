// https://hogehoge.tk/tool/number.html
// ※CUBEは1番上から1段目，1番下は8段目

const int g_SRCLK = A1;                           //74hc595 11
const int g_RCLK = A0;                            //74hc595 12
const int g_SER = A2;                             //74hc595 14
const int g_GND[8] = { 2, 9, 8, 7, 6, 5, 4, 3 };  //※ ボード左から左記順

byte patterns[8][8] = {  //※
  { 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

void setup() {
  pinMode(g_SRCLK, OUTPUT);
  pinMode(g_RCLK, OUTPUT);
  pinMode(g_SER, OUTPUT);
  pinMode(13, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(g_GND[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(13, HIGH);

    digitalWrite(g_GND[i], HIGH);
    digitalWrite(g_RCLK, LOW);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][0]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][1]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][2]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][3]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][4]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][5]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][6]);
    shiftOut(g_SER, g_SRCLK, MSBFIRST, patterns[i][7]);
    digitalWrite(g_RCLK, HIGH);
    digitalWrite(13, LOW);

    digitalWrite(g_GND[i], LOW);
  }
}