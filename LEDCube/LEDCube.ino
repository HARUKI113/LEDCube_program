// const int PIN_SER   = A2;
// const int PIN_RCLK  = A0;
// const int PIN_SRCLK = A1;
#define DATAPIN		(A2)		// 74HC595のDSへ
#define LATCHPIN	(A1)	// 74HC595のST_CPへ
#define CLOCKPIN	(A2)	// 74HC595のSH_CPへ

void MyShiftOut( int dataPin, int clockPin, int bit, uint64_t val )
{
	for( int i = 0; i < bit; i++ )
	{
		digitalWrite(dataPin, !!(val & ((uint64_t)1 << i)));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
	}
}

void setup()
{
  pinMode(13, OUTPUT);
	pinMode(DATAPIN, OUTPUT);
	pinMode(LATCHPIN, OUTPUT);
	pinMode(CLOCKPIN, OUTPUT);
}

void loop()
{
	for( int i = 0; i < 64; i++ )
	{
    digitalWrite(13, LOW);
		digitalWrite(LATCHPIN, LOW);		// 送信中はLATCHPINをLOWに

		// シフト演算を使って点灯するLEDを選択しています
		MyShiftOut( DATAPIN, CLOCKPIN, 64, (uint64_t)1 << i );

		digitalWrite(LATCHPIN, HIGH);		// 送信後はLATCHPINをHIGHに戻す

		delay(10);
    digitalWrite(13, HIGH);
	}

}

