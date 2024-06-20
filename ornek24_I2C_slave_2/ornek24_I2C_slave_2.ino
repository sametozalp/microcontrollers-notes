//I2C haberleşme slave programı
#include<Wire.h>
volatile bool durum = false;
volatile byte gelen_veri[2];
//******************************************
void setup()
{
  Serial.begin(9600);
  Wire.begin(54);           // slave adresi 54 olarak başlat
  Wire.onReceive(veri_geldi);
}
//******************************************
void loop()
{
  if (durum)
  {
    int okunan = (gelen_veri[0]<<8)|gelen_veri[1];
    Serial.println(okunan);    
    durum = false;
  }
}
//******************************************
void veri_geldi(int kac_byte)
{
  for(int i=0; i<kac_byte; i++)
    gelen_veri[i] = Wire.read();
  durum = true;
}
