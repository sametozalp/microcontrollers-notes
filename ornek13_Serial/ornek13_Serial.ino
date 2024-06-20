#define L_LEDi 13
byte gelen_veri=0;
//*************************************************
void setup()
{
  Serial.begin(9600);         // Seri portu 9600 baud rate de başlat
  pinMode(L_LEDi, OUTPUT);    // digital 13'i cikis yap
}
//*************************************************
void loop()
{
  if(Serial.available() > 0)  // seri porttan veri gelmiş mi?
  {
    gelen_veri=Serial.read(); // gelen veriyi oku
    if(gelen_veri==51)        // gelen veri 3 sayısı mı? ascii karşılığı 51
      digitalWrite(L_LEDi,HIGH);    // evet LED'i yak
    
    if(gelen_veri==53)        // gelen veri 5 sayısı mı? ascii karşılığı 53
      digitalWrite(L_LEDi,LOW);     // evet LED'i sondur
  }
}