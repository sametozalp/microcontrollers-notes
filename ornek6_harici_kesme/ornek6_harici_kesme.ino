#define buton 2               		// butonu 2.digital pine ata
#define LED1_pin 5             		// LEDi 5. pine bagla
#define LED2_pin 4             		// LEDi 4. pine bagla
volatile bool durum=false;
//************************************************************
void setup()
{
  pinMode(buton, INPUT_PULLUP);   	// 2. pini giris olarak ayarla dahili pull up direncini ac  
  pinMode(LED1_pin, OUTPUT);   		// led pinleri cikis yap
  pinMode(LED2_pin, OUTPUT);   		// led pinleri cikis yap
  
  attachInterrupt(0,kesme_fonk,FALLING);
  //attachInterrupt(digitalPinToInterrupt(buton),kesme_fonk,CHANGE);
}
//************************************************************
void loop()
{
  digitalWrite(LED2_pin, HIGH);		// LED2 yi yanıyor
  delay(500);                   	// 500 ms bekle
  digitalWrite(LED2_pin, LOW);		// LED2 yi söndür
  delay(500);                   	// 500 ms bekle
}
//************************************************************
void kesme_fonk()
{
  durum=!durum;
  digitalWrite(LED1_pin, durum);
}
