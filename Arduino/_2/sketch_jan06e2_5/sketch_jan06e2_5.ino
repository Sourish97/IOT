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
     char val = Serial.read();
    if ( val == 'O')
    {
      char ch =Serial.read();
      if ( ch == 'N')
         digitalWrite(3,HIGH); 
   
    else if ( ch == 'F')
      {
        if (Serial.read() == 'F')
          digitalWrite(3,LOW);
      }
   
    }
  }
}

//PC to arduino project
