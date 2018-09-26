short led=13, flag=0;
String code[26]={"*-","-***","-*-*","-**","*", "**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-","*--","-**-","-*--","--**"};
String sentence="MY NAME IS AJDIN BAJRIC";

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {

if(!flag){

for(int i=0;i<sentence.length();i++){

  if(sentence[i]!=' '){
    
  int letter=int(sentence[i])-65;
  String output=code[letter];
  
  for(int j=0;j<output.length();j++){

    if(output[j]=='*'){

      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      delay(1000);  
      }

      else if(output[j]=='-'){

      digitalWrite(led, HIGH);
      delay(3000);
      digitalWrite(led,LOW);
      delay(1000);

        }
    }
    delay(3000);
    }

    else delay(7000);
  
    }
 }

flag=1;

}
