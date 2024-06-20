void setup()
{
  pinMode(1, OUTPUT);     // digital 1'i cikis yap
}
void loop()
{
  digitalWrite(1,HIGH);   // LED'i yak
  delay(500);             // 0.5 sn bekle
  digitalWrite(1,LOW);    // LED'i sondur
  delay(500);             // 0.5 sn bekle
}
