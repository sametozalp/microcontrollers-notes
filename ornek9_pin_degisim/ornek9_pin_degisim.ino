#define buton1 2			// butonu 2.digital pine ata
#define buton2 7			// butonu 7.digital pine ata
#define LED1_pin 11         // LEDi 11. pine bagla
#define LED2_pin 13         // LEDi 13. pine bagla
#define LED3_pin 12         // LEDi 12. pine bagla

volatile bool durum1 = false;
volatile bool durum2 = false;
//***************************************************
void setup() {

  pinMode(LED1_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED2_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED3_pin, OUTPUT);   		// led pinleri cikis yap

  pinMode(buton1, INPUT_PULLUP);	// 2. pini giris olarak ayarla dahili pull up direncini ac  
  pinMode(buton2, INPUT_PULLUP);	// 7. pini giris olarak ayarla dahili pull up direncini ac  

  PCICR = PCICR | B00000100;		//portd nin interruptını aç
  PCMSK2 = PCMSK2 | B10000100;		// portd nin 2. ve 7.pinini kullanacağız
}
//***************************************************
void loop() {
  digitalWrite(LED3_pin, HIGH);		// LED3 ü yanıyor
  delay(500);                   	// 500 ms bekle
  digitalWrite(LED3_pin, LOW);		// LED3 ü söndür
  delay(500);                   	// 500 ms bekle
}
//***************************************************
ISR (PCINT2_vect)					// interrupt oldu
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
