#define buton1 2			// butonu 2.digital pine ata
#define buton2 7			// butonu 7.digital pine ata
#define buton3 8			// butonu 8.digital pine ata
#define LED1_pin 11         // LEDi 11. pine bagla
#define LED2_pin 13         // LEDi 13. pine bagla
#define LED3_pin 12         // LEDi 12. pine bagla
#define LED4_pin 10         // LEDi 10. pine bagla

volatile bool durum1=false;
volatile bool durum2=false;
volatile bool durum3=false;
//***************************************************
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED2_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED3_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED4_pin, OUTPUT);		// led pinleri cikis yap

  pinMode(buton1, INPUT_PULLUP);	// 2. pini giris olarak ayarla dahili pull up direncini ac  
  pinMode(buton2, INPUT_PULLUP);	// 7. pini giris olarak ayarla dahili pull up direncini ac  
  pinMode(buton3, INPUT_PULLUP);	// 8. pini giris olarak ayarla dahili pull up direncini ac

  PCICR=PCICR|B00000101;  //Port D ve B nin interruptını aç

  PCMSK2=PCMSK2|B10000100; // portd nin 7 ve 2. pinlerini kullanacagiz
  PCMSK0=PCMSK0|B00000001;  // portb nin PB0. pini yani 8.digital pini kullanacagiz

}
//***************************************************
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED4_pin, HIGH);		// LED4 ü yanıyor
  delay(500);                   	// 500 ms bekle
  digitalWrite(LED4_pin, LOW);		// LED4 ü söndür
  delay(500);                   	// 500 ms bekle
}
//***************************************************
ISR(PCINT2_vect)					// interrupt oldu, PORTD kaynaklı
{
	// hangi butona basıldığı için interrupt oluştu onu kontrol et
  if (digitalRead(buton1) == LOW)	// buton1 e mi basıldı?
  {
    durum1 = !durum1;
    digitalWrite(LED1_pin, durum1);
  }

  if (digitalRead(buton2) == LOW)	// buton2 ye mi basıldı?
  {
    durum2 = !durum2;
    digitalWrite(LED2_pin, durum2);
  }
}
//***************************************************
ISR(PCINT0_vect)					// interrupt oldu, PORTb kaynaklı
{
  durum3=!durum3;
  digitalWrite(LED3_pin,durum3);
}