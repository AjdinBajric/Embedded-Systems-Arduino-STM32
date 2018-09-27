void setup() {
  // put your setup code here, to run once:

}

void loop() {

  for(int i=0;i<255;i+=5){
    
  analogWrite(9,i);  
  delay(50);
  }

   for(int i=255;i>=0;i-=5){
    
  analogWrite(9,i);  
  delay(50);
  }
delay(300);
}
