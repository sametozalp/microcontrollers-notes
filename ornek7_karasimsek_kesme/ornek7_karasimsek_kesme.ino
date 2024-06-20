const int LED_pinler[] = {4,5,6,7,8,9}; // 4,5,6,7,8,9 pinlere LED baglicaz
int bekleme=50;
volatile int temp_bekleme=50;
//***************************************************
void setup()
{
  pinMode(2, INPUT_PULLUP);          // 2. pini giris olarak ayarla dahili pull up aktif et
  pinMode(3, INPUT_PULLUP);          // 3. pini giris olarak ayarla dahili pull up aktif et   
  
  for (int i =0;i<6;i++)
    pinMode(LED_pinler[i], OUTPUT);   // led pinleri cikis yap
  
  attachInterrupt(0,arttir,FALLING);
  attachInterrupt(1,azalt,FALLING);
}
//***************************************************
void loop()
{
  for (int i =0;i<6;i++)
  {
   digitalWrite(LED_pinler[i], HIGH);
   bekleme=temp_bekleme;
   delay(bekleme);
   digitalWrite(LED_pinler[i], LOW);
  }
  for (int j =5;j>-1;j--)
  {
   digitalWrite(LED_pinler[j], HIGH);
   bekleme=temp_bekleme;
   delay(bekleme);
   digitalWrite(LED_pinler[j], LOW);
  }
}
//**************************************************
void arttir()
{
  temp_bekleme=bekleme;
  temp_bekleme=temp_bekleme+10;
  if(temp_bekleme>1000)
    temp_bekleme=1000;
}
//**************************************************
void azalt()
{
  temp_bekleme=bekleme;
  temp_bekleme=temp_bekleme-10;
  if(temp_bekleme<20)
    temp_bekleme=20;
}
