// I2C haberleşme master programı
#include<Wire.h>                            //I2C için kütüphane ekle
//*********************************************
void setup() 
{ 
  Serial.begin(9600);                        // 9600 baud ratede seri portu başlat
  Wire.begin();                              // I2C haberleşmesini master olarak başlat
}
//*********************************************
void loop()
{
  Wire.requestFrom(13,1);                   // slaveden 1 byte veri iste
  Serial.println( Wire.read());         // veriyi oku, seri porttan yazdır
  delay(1000);
}     
