//slave programı
#include<Wire.h>                          

int pot_okunan=0;
//***************************************************************
void setup() 
{
  Serial.begin(9600);    // seri portu başlat                
  Wire.begin(53);         // 13 adresini kullan                 
  Wire.onRequest(veri_istendi); // veri isteme olursa veri_istendi fonksiyonuna git         
} 
//***************************************************************
void loop(void) 
{  
  pot_okunan=analogRead(A0);
  delay(500);
}
//***************************************************************
void veri_istendi()                              
{
  Wire.write(highByte(pot_okunan));  // adc degeri ust byte
  Wire.write(lowByte(pot_okunan));   // adc degeri alt byte
}
