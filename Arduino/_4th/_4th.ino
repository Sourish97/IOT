void setup() {
  // put your setup code here, to run once:
  for ( int i = 2 ; i < 8 ; i++)
    pinMode(i,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int arr[6] = {4, 2, 3, 7, 6, 5};
  for ( int  i = 0 ; i < 6 ; i ++)
  {
    digitalWrite(arr[i], HIGH);
    delay(500);
    digitalWrite(arr[i],LOW);
  }
}
