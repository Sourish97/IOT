# include <SoftwareSerial.h>

SoftwareSerial s1(10,11);
// 10 IS RX 11 IS TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (s1.available()> 0){
    String val= s1.readString();
    if ( val == "1")
      Serial.println("HELLO");
    else if( val == "ON" )
      digitalWrite(3,HIGH);
    else if (val == "OFF")
      digitalWrite(3,LOW);
    else if (val == "LDR")
      {
        int abc = analogRead(A5);
        s1.println(abc) ;
      }
  }
  
}

// mobile bluetooth module arduino



