void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = LOW;
  while (1){ 
    int val = digitalRead(13);
    delay(500);
    //Serial.println(val);
    
    if (val){
      state = (state == LOW) ? HIGH : LOW;
      digitalWrite(5,state);
    }
  }
    
}
