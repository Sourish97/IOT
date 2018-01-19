# include <SoftwareSerial.h>

SoftwareSerial s1(10,11);
// 10 IS RX 11 IS TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (s1.available()> 0){
    char val= s1.read();
    Serial.print(val);
  }
}



