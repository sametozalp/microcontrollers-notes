//   16000000/8=2000000 Hz    Timer2=256   Kesme aralıgı=256*(1/2000000)=128 us de bir overflow oluyor
//   2sn=2000000us/128us=15625 kere overflow oluşursa 2 sn dolar

#define LED_pin 2             // LEDi 2. pine bagla
bool durum=false;
volatile int sayac=15625;

void setup()
{
  pinMode(LED_pin, OUTPUT);   // led pinleri cikis yap
  cli(); 		// tüm interruptları durdur
  
  TCCR2A=0;				
  TCCR2B=0;
  
  TCCR2B |= B00000010;	// prescaler degeri 8 ayarla	
  TIMSK2 |= B00000001; // overflow interruptını enable et      
 
  sei();		//Tüm interruptları çalıştır.
}

void loop()
{
	if(sayac==0)		 
	{
		sayac=15625;
		durum=!durum;
		digitalWrite(LED_pin, durum);
	}
}

ISR(TIMER2_OVF_vect)
{
  sayac--;
}
