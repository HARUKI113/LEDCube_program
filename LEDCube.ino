const int PIN_SER   =  8;
const int PIN_RCLK  =  9;
const int PIN_SRCLK = 10;

const int PIN_G1 = 1; //D1
const int PIN_G2 = 2; //D2
const int PIN_G3 = 3; //D3
const int PIN_G4 = 4; //D4
const int PIN_G5 = 5; //D5
const int PIN_G6 = 6; //D6
const int PIN_G7 = 7; //D7
const int PIN_G8 = 8; //D8

void setup() {
  pinMode( PIN_SER, OUTPUT );
  pinMode( PIN_RCLK, OUTPUT );
  pinMode( PIN_SRCLK, OUTPUT );

  pinMode( PIN_G1, OUTPUT );
  pinMode( PIN_G2, OUTPUT );
  pinMode( PIN_G3, OUTPUT );
  pinMode( PIN_G4, OUTPUT );
  pinMode( PIN_G5, OUTPUT );
  pinMode( PIN_G6, OUTPUT );
  pinMode( PIN_G7, OUTPUT );
  pinMode( PIN_G8, OUTPUT );
}

byte b1 = B11010001;
byte b2 = B00110011;

void loop() {
  digitalWrite(PIN_RCLK, LOW);
  shiftOut(PIN_SER, PIN_SRCLK, LSBFIRST, b2);
  shiftOut(PIN_SER, PIN_SRCLK, LSBFIRST, b1);
  digitalWrite(PIN_RCLK, HIGH);
}
