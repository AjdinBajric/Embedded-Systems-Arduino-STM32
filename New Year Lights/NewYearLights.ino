void setup()  
{
  pinMode (2,OUTPUT) ;
  pinMode (3,OUTPUT) ;
  pinMode (4,OUTPUT) ;
  pinMode (5,OUTPUT) ;
  pinMode (6,OUTPUT) ;
  pinMode (7,OUTPUT) ;
  pinMode (8,OUTPUT) ;
  pinMode (9,OUTPUT);
}
int vrijeme=800;
void loop() {
firsec(vrijeme-=250);
onoff(vrijeme-=250);
lasteff(vrijeme-=250);
if(vrijeme<=50)vrijeme=800;
lasteff(vrijeme-=250);
onoff(vrijeme-=250);
firsec(vrijeme-=250);
if(vrijeme<=50)vrijeme=800;
}

void firsec(int vrijeme)
{
  for(int i=2;i<=9;i++)
  {
    digitalWrite(i,HIGH);
    delay (vrijeme);
  }
  vrijeme=100;
  for(int i=9;i>=2;i--)
{
  digitalWrite(i,LOW);
  delay(vrijeme);
}

}
void onoff(int vrijeme)
{
 for(int i=2;i<=9;i++)
{
  digitalWrite(i,HIGH);
  delay(vrijeme);
  digitalWrite(i,LOW);
}
vrijeme=100;
for(int i=9;i>=2;i--)
{

  digitalWrite(i,HIGH);
  delay(vrijeme);
  digitalWrite(i,LOW);
  
} 
}
void lasteff(int vrijeme)
{
  for(int i=6, j=5;i<=9,j>=2;i++,j--){

  digitalWrite(i,HIGH);
  digitalWrite(j,HIGH);
  delay (vrijeme);
}
vrijeme=100;
for(int i=9, j=2;i<=6,j<=6;i--,j++){
  digitalWrite(i,LOW);
  digitalWrite(j,LOW);
  delay(vrijeme); 
}
}
