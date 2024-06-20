#define trig_pin 3
#define echo_pin 4
#define LED_pin 13
//************************************************
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(LED_pin,OUTPUT);
  digitalWrite(trig_pin,LOW);
  Serial.println("Mesafe ölcümü basliyor...");
}
//************************************************
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin,HIGH);  // trig pini high yap
  delayMicroseconds(10);        // 10 micro saniye bekle
  digitalWrite(trig_pin,LOW);   // trig pini low yap

  unsigned long sure= pulseIn(echo_pin,HIGH);
  float mesafe=(sure*0.034)/2.0;  // 2 ye bölüyoruz çünkü ses dalgası engele gidip geliyor, 2 katı süre geçiyor
                                  // 0.034 cm/us ses hızı
  Serial.print("Olculen mesafe: ");
  Serial.println(mesafe);
  delay(300);
  if(mesafe<30)                 // mesafe 30cm den küçük ise LEDi yak
    digitalWrite(LED_pin,HIGH);
  else
   digitalWrite(LED_pin,LOW);

}
