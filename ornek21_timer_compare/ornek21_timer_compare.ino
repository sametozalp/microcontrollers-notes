// 1,75 sn de bir interrupt oluşması için OCR1A=(1,75*16000000)/1024=27343 olmalı

#define LED_pin 2             // LEDi 2. pine bagla
bool durum=false;
//**************************************************************************
void setup()
{
  pinMode(LED_pin, OUTPUT);   // led pinleri cikis yap
  cli();                      // tüm interruptları durdur
  
  TCCR1A=0;       
  TCCR1B=0;
  TCNT1  = 0;                 // timer1 sayıcısını sıfırla
  TCCR1B |= B00000101;        // prescaler degeri 1024 ayarla  
  TIMSK1 |= B00000010;        // compare 1A interruptını enable et      
  OCR1A= 27343;
  
  sei();                      //Tüm interruptları çalıştır.
}
//**************************************************************************
void loop()
{
  delay(300);                 // buton arkının sönmesini bekle
}
//**************************************************************************
ISR(TIMER1_COMPA_vect)        // timer compare kesme alt rutini
{
  TCNT1  = 0;
  durum=!durum;
  digitalWrite(LED_pin, durum);
}
