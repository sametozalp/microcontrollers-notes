#define buton 7               		// butonu 7.digital pine ata
#define LED1_pin 13             	// LEDi 13. pine bagla
#define LED2_pin 4             		// LEDi 4. pine bagla
volatile bool durum=false;
//***************************************************
void setup() {
  pinMode(LED1_pin, OUTPUT);		  // led pinleri cikis yap
  pinMode(LED2_pin, OUTPUT);		  // led pinleri cikis yap
  pinMode(buton, INPUT_PULLUP);		// 7. pini giris olarak ayarla dahili pull up direncini ac  
  
  PCICR = PCICR | B00000100;		  // portd nin interruptını aç
  PCMSK2 = PCMSK2 | B10000000;		// portd nin 7.pinini kullanacağız
}
//*************************************************** 
void loop() {
  digitalWrite(LED2_pin, HIGH);		// LED2 yi yanıyor
  delay(500);                   	// 500 ms bekle
  digitalWrite(LED2_pin, LOW);		// LED2 yi söndür
  delay(500);                   	// 500 ms bekle
}
//***************************************************
ISR (PCINT2_vect)					        // interrupt oldu
{
  durum = !durum;
  digitalWrite(LED1_pin, durum);
}