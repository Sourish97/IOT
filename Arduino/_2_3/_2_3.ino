void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

int state = LOW;
int abc = 0;
void loop() {
  // put your main code here, to run repeatedly:
 
  if(Serial.available() > 0 ){
    int val = Serial.read();
    if ( val == 49)
      Serial.println("Hello");
    else if (val == 50){
      state = !state ;
      digitalWrite(3,state);
    }
    else if (val == 51 || abc ){
      abc = !abc ;
      while (1){
        Serial.println(analogRead(A5));

          if ( Serial.read() == 51)
            break ;
        
      }
      
    }
  }
  
}

//PC to arduino project
