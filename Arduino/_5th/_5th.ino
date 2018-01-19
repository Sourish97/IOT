void setup() {
  // put your setup code here, to run once:
  pinMode (13,INPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(13);
  Serial.println(val);
  digitalWrite(5,val);
  
}
