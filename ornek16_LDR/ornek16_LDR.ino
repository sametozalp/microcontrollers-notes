#define LED_pin 3
int okunan_ADC=0;
//*********************************************
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  okunan_ADC=analogRead(A0);
  Serial.print("okunan ADC degeri:");
  Serial.println(okunan_ADC);
  int x=map(okunan_ADC,200,0,0,255);
  if(x<0)
    x=0;
  Serial.print("Donusum degeri:");
  Serial.println(x);
  analogWrite(LED_pin,x);
  delay(500);

}
