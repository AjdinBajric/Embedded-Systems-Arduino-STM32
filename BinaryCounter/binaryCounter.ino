
int bits[8];

void setup() {

for(int i=2;i<=9;i++){
  
pinMode(i,OUTPUT);  

}

}

void loop() {


int mask = 1, count = 0,n=19;

    for (int i = 0; i < 32; i++) {
      if ((n & mask) == 1)
        bits[count]=1;
      count++;
      n >>= 1;
    }

    for(int i=0;i<8;i++){

    if(bits[i]==1)digitalWrite(i+2,HIGH);
  
      
    }

}
