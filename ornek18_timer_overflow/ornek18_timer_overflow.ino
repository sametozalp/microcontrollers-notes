//   16000000/256=62500 Hz    Timer1=65536   Kesme aralıgı=65536*(1/62500)=1,05sn
#define LED_pin 2             // LEDi 2. pine bagla
bool durum=false;

void setup()
{
  pinMode(LED_pin, OUTPUT);   // led pinleri cikis yap
  cli(); 		// tüm interruptları durdur
  
  TCCR1A=0;				
  TCCR1B=0;
  
  TCCR1B |= B00000100;	// prescaler degeri ayarla,256
  TIMSK1 |= B00000001; // overflow interruptını enable et      
 
  sei();		//Tüm interruptları çalıştır.
}

void loop()
{
  delay(300);                   // buton arkının sönmesini bekle
}

ISR(TIMER1_OVF_vect)
{
  durum=!durum;
  digitalWrite(LED_pin, durum);
}
