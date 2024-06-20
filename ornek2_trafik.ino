void setup() 
{
  pinMode(1, OUTPUT);        // 1. pini cikis yap
  pinMode(2, OUTPUT);        // 2. pini cikis yap
  pinMode(3, OUTPUT);        // 3. pini cikis yap
}

void loop() 
{
  digitalWrite(1, HIGH);        // öncelikle kırmızı ledi yak
  delay(1000);          		// uzun bekleme
  digitalWrite(2, HIGH);        // sarı ledi yak
  delay(300);                   // kisa bekleme
  
  // şimdi yeşil ledi yakarak kırmızı ve sarı ledi söndürüyoruz
  digitalWrite(3, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  delay(1000);                   // uzun bekleme
  
  // sarı ledi yakıp yeşil ledi söndürüyoruz
  digitalWrite( 2, HIGH);
  digitalWrite(3, LOW);
  delay(300);                    // kisa bekleme
  digitalWrite(2, LOW);          // sarı led söner ve döngü baştan başlar
}
