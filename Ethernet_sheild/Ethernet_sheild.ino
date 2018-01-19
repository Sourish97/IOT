# include <Ethernet.h>
# include <SPI.h>

byte mac[] = {0x21,0xFE,0xFF,0xAE,0x12,0x30};
byte ip[] = {192,168,1,6};
EthernetServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Ethernet.begin(mac,ip);
  server.begin();
  Serial.println(Ethernet.localIP());
  //pinMode(3,INPUT);
  //pinMode(5,INPUT);
} 

int flag = 0;
int val3 = 0, val5 = 0;

void loop() {
  // put your main code here, to run repeatedly:
  EthernetClient client=server.available();
  int a3 = analogRead(3);
  int a5 = analogRead(5);
//  
//  if (val3 != a3 || val5 != a5){
//          val3=a3;
//          val5=a5;
//    client.println("<!DOCTYPE HTML>");
//      client.print("<html><head>  <title>    Arduino   </title></head><body><p> LDR = " );
//      client.print( val );
//      client.print("</p><p>Potentiometer =");
//      client.print( val5 );
//      client.print("</p></body></html>");
//      client.();
  
          
  if(client){
    if(client.available()){
    char c=client.read();
    Serial.print(c);
    
    
    
    if ( c == '\n' && flag){
      
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println("Connection:close");
      client.println("Refresh:5");
      client.println();
      client.println("<!DOCTYPE HTML>");
      client.print("<html><head>  <title>    Arduino   </title></head><body><p> LDR = " );
      client.print( analogRead(A1) );
      client.print("</p><p>Potentiometer =");
      client.print( analogRead(A0));
      client.print("</p></body></html>");
      client.stop();
    }
    if( c == '\n')
      flag = 1;
    else if ( c != '\r')
      flag = 0;
         
    
    }
  }
}
