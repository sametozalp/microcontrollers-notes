int VRx_deger=0;      // joystick X eksenindeki potansiyometre digital değeri
int VRy_deger=0;      // joystick y eksenindeki potansiyometre digital değeri

float gerilim_vrx=0.0;  // joystick X eksenindeki potansiyometre gerilim değeri
float gerilim_vry=0.0;  // joystick y eksenindeki potansiyometre gerilim değeri
//*************************************************
void setup() {
  Serial.begin(9600);   // seri portu 9600 baud rate de başlat
}
//**************************************************
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("ADC Okumasi");    
  
  VRx_deger=analogRead(A0);               // analog 0 portunu oku
  gerilim_vrx=(VRx_deger*5.0)/1024.0;     // okunan değeri gerilime çevir

  
  VRy_deger=analogRead(A1);               // analog 1 portunu oku
  gerilim_vry=(VRy_deger*5.0)/1024.0;     // okunan değeri gerilime çevir
  
  Serial.print("Okunan VRx degeri: ");
  Serial.println(VRx_deger);
  Serial.print("Okunan VRx gerilimi: ");
  Serial.println(gerilim_vrx);

  Serial.println("-------------------------");

  Serial.print("Okunan VRy degeri: ");
  Serial.println(VRy_deger);
  Serial.print("Okunan VRy gerilimi: ");
  Serial.println(gerilim_vry);
  delay(500);
}
