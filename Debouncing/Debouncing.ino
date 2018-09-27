int switchPin=2;
int led=13;
boolean lastButton=LOW,currentButton=LOW,ledOn=false;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{

  currentButton=debounce(lastButton);
  if(currentButton==HIGH && lastButton==LOW)
    ledOn=!ledOn;
   
 lastButton=currentButton;
 digitalWrite(led,ledOn);
}

boolean debounce(boolean lastButton){

  boolean current=digitalRead(switchPin);
  if(lastButton!=current){delay(5);current = digitalRead(switchPin);}

  return current;

}
