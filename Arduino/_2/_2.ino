void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(5,INPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  val = map (val,0,1023,0,255);
  analogWrite(3,val);
}

//PWM potentiometer
