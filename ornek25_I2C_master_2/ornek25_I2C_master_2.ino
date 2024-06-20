// master programı
#include<Wire.h>
int giden_veri = 1234;
byte iletisim=1;
//****************************************************
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}
//****************************************************
void loop()
{
  while(iletisim!=0)
    slave_kontrol_et();
  
  Wire.beginTransmission(54);        // slave adresi 54 olan cihaz ile haberleşmeyi başlat
  Wire.write(highByte(giden_veri));  // 1234 sayısının üst bytenı gönder
  Wire.write(lowByte(giden_veri));   // 1234 sayısının alt bytenı gönder
  Wire.endTransmission();            // iletişimi bitir
  Serial.println("Slave cihaza veri gonderildi");
  delay(1000);       
}
//****************************************************
void slave_kontrol_et()
{
  Wire.beginTransmission(54);         // slave adresi 54 olan cihaz ile haberleşmeyi başlat
  iletisim = Wire.endTransmission();  // iletişimi bitir
  if (iletisim != 0)
    Serial.println("Belirtilen adresten cevap alinamadi");
  else
    Serial.println("Slave cihaz ile iletisim saglandi");
}
