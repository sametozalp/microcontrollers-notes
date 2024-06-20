byte sayac=0;                 // sayac değişkenini tanımla

void setup()
{
  pinMode(5, INPUT);          // 5. pini giris olarak ayarla  
  for (int i =0;i<4;i++)
    pinMode(i, OUTPUT);   		// led pinleri cikis yap
}

void loop()
{
  if (digitalRead(5) == 0)    	  // Pull up baglantida, butona basıldı mı?
  {
    sayac++;                      // sayac'ı bir arttır
    goster(sayac);                // sayac'ı LED'lerde goster
    delay(300);                   // buton arkının sönmesini bekle
  }
}

void goster(byte sayi)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(sayi, i)==1)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}
