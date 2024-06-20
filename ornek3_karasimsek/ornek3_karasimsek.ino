void setup () {     
  for(int i=1; i<9 ;i++)    
    pinMode(i, OUTPUT);     // tüm pinleri cikis yap
}

void loop() {                                              
  for(int i=1; i<9; i++){               // sagdan sola dogru yakma
    digitalWrite(i,HIGH);      
    delay(100);                           
    digitalWrite(i,LOW);       
  }
 
  for(int i=8;i>0; i--)                // soldan saga dogru yakma
  { 
    digitalWrite(i,HIGH);     
    delay(100);
    digitalWrite(i, LOW);
  }
}
