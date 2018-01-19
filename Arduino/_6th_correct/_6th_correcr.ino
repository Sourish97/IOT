void setup() {
  // put your setup code here, to run once:
  pinMode (5,OUTPUT);
  pinMode( 13, INPUT);
}
int state = LOW;
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13)){
    state = !state;
    while (digitalRead(13) );
  }
  digitalWrite(5,state);
}
