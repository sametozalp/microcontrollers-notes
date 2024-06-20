#define buton1 7
#define buton2 2
#define buton3 8

#define LED1 13
#define LED2 11
#define LED3 3
#define LED4 12
volatile bool durum1,durum2,durum3;
//**************************************
void setup()
{
	pinMode(LED1,OUTPUT);
	pinMode(LED2,OUTPUT);
	pinMode(LED3,OUTPUT);
	pinMode(LED4,OUTPUT);
	
	pinMode(buton1, INPUT_PULLUP);
	pinMode(buton2, INPUT_PULLUP);
	pinMode(buton3, INPUT_PULLUP);
	
	PCICR=PCICR|B00000101;	// portd ve b nin değişim int. aç
	PCMSK2=PCMSK2|B10000100;  // portd 7.,2. pininin int. aç
	PCMSK0=B00000001;	// portb 0. pini int. aç
}
//**************************************
void loop()
{
	digitalWrite(LED3, HIGH);
	delay(500);
	digitalWrite(LED3, LOW);
	delay(500);
}
//**************************************
ISR(PCINT2_vect)
{
	if(digitalRead(buton1)==LOW)
	{
		durum1=!durum1;
		digitalWrite(LED1,durum1);
	}
	if(digitalRead(buton2)==LOW)
	{
		durum2=!durum2;
		digitalWrite(LED2,durum2);
	}
}
//*************************************
ISR(PCINT0_vect)
{
	durum3=!durum3;
	digitalWrite(LED4,durum3);
}