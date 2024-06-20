void setup()
{
  pinMode(1, INPUT);    // 1. pini giris olarak ayarla  
  pinMode(2, OUTPUT);     // 2. pini cikis olarak ayarla 
}
void loop()
{
  if (digitalRead(1) == 0)    // Pull up baglantida, butona basıldı mı?
	digitalWrite(2,HIGH);         // evet basildi LED'i yak
  else
	digitalWrite(2,LOW);          // hayır basılmadı LED'i sondur
  delay(250); 						// butona basıldığında arkları söndürmek için
}
