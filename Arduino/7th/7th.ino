void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
 
}
int state = LOW;

int pressed=0;

void loop() {
  // put your main code here, to run repeatedly:
    int val = digitalRead(13);
    if ( val == 0)
      pressed = 0;
    if(val==1 && pressed == 0){
      state = !state;
      pressed = 1;
    }
    digitalWrite(5,state);
   
    
}
