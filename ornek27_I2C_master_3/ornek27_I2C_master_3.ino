// master programı
#include<Wire.h>       
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32,16,2);  // set the LCD address to 32 for a 16 chars and 2 line display


byte iletisim=1;  // hatta slave olup olmadıgını kontrol icin kullanılacak
volatile byte gelen_veri[2];
//*******************************************
void setup() 
{ 
  Serial.begin(9600);           // seri portu başlat       
  Wire.begin();
  do
  {
    iletisim=slave_kontrol_et();
    Serial.println("I2C hatti kontrol ediliyor");
  }while(iletisim!=0);
  lcd_yaz();
}
//*******************************************
void loop()
{
  Wire.requestFrom(13,1);   //I2C adresi 13 olan cihazdan 1 byte iste
  Serial.print("Slave1: ");
  Serial.println( Wire.read()); // oku ve seri porta yaz
  delay(100);
  
  Serial.print("Slave2: ");
  Wire.requestFrom(53,2);   //I2C adresi 13 olan cihazdan 1 byte iste
  gelen_veri[0]=Wire.read();  // oku ve seri porta yaz
  gelen_veri[1]=Wire.read();  // oku ve seri porta yaz
  int okunan = (gelen_veri[0]<<8)|gelen_veri[1];
  Serial.println(okunan);
  delay(100);
  
  Wire.requestFrom(120,1);    //I2C adresi 13 olan cihazdan 1 byte iste
  Serial.print("Slave3: ");
  Serial.println( Wire.read()); // oku ve seri porta yaz
  Serial.println("-------------------------");
  delay(800);
}
//*******************************************
byte slave_kontrol_et()
{
  byte sonuc=0;
  
  byte sonuc1=0;
  Wire.beginTransmission(13);
  sonuc1=Wire.endTransmission();
  delay(300);
  
  byte sonuc2=0;
  Wire.beginTransmission(53);
  sonuc2=Wire.endTransmission();
  delay(300);
  
  byte sonuc3=0;
  Wire.beginTransmission(120);
  sonuc3=Wire.endTransmission();
  delay(300);
  
  sonuc=sonuc1+sonuc2+sonuc3;
  return sonuc;
}
//*******************************************
void lcd_yaz()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("Merhaba");
  lcd.setCursor(0,1);
  lcd.print("Mikrodenetleyici");
}
