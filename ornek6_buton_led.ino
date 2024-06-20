#define buton 1		// buton 1. pine bağlı
#define LED1 2		// LED1 2. pine bağlı
#define LED2 3		// LED2 3. pine bağlı
//-------------------------------------------------
void setup()
{
  pinMode(buton, INPUT);    // 1. pini giris olarak ayarla  
  pinMode(LED1, OUTPUT);     // 2. pini cikis olarak ayarla
  pinMode(LED2, OUTPUT);     // 2. pini cikis olarak ayarla
}
//-------------------------------------------------
void loop()
{
  if (digitalRead(1) == 0)    // Pull up baglantida, butona basıldı mı?
	digitalWrite(2,HIGH);         // evet basildi LED'i yak
  else
	digitalWrite(2,LOW);          // hayır basılmadı LED'i sondur
  delay(250); 						// butona basıldığında arkları söndürmek için
}
