#define buton 7
#define LED1 13
#define LED2 2
volatile bool durum;
//**************************************
void setup()
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2,OUTPUT);
	pinMode(buton, INPUT_PULLUP);
	PCICR=PCICR|B00000100;	// portd nin değişim int. aç
	PCMSK2=PCMSK2|B10000000;  // portd nin 7. pininin int. aç
}
//**************************************
void loop()
{
	digitalWrite(LED2, HIGH);
	delay(500);
	digitalWrite(LED2, LOW);
	delay(500);
}
//**************************************
ISR(PCINT2_vect)
{
	durum=!durum;
	digitalWrite(LED1,durum);
}