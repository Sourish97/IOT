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
    String val = Serial.readString();
    if ( val == "ON")
      digitalWrite(3,HIGH);
    else if (val == "OFF")
      digitalWrite(3,LOW); 
  }
}

//PC to arduino project
