//I2C haberleşme Slave programı
#include<Wire.h>                          //I2C için kütüphane ekle

byte sayac=0;
//*****************************************
void setup() 
{
  Serial.begin(9600);                    // 9600 baud ratede seri portu başlat
  Wire.begin(13);                        // I2C haberleşmesini Slave adresi 13 olarak başlat
  Wire.onRequest(veri_istendi);          // Veri talebi geldiğinde veri_istendi fonksiyonuna git
} 
//*****************************************
void loop(void) 
{
  sayac++;
  delay(500);
 
}
//*****************************************
void veri_istendi()                     // veri talep edildi
{
  Wire.write(sayac);					// sayac verisini gönder
}