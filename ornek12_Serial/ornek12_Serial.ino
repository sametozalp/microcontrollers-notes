int sayac=0;
//*************************************************
void setup()
{
  Serial.begin(9600);			// Seri portu 9600 baud rate de başlat
  pinMode(L_LEDi, OUTPUT);      // digital 13'i cikis yap
}
//*************************************************
void loop()
{
  Serial.print("Sayac Degeri: ");	// Seri porttan metni gönder, alt satıra geç
  Serial.println(sayac);
  sayac++;
  
  digitalWrite(L_LEDi, HIGH);		// LED'i yak
  delay(500);						// 500 ms bekle
  digitalWrite(L_LEDi, LOW);		// LED'i sondür
  delay(500);						// 500 ms bekle
}