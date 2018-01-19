# include <Ethernet.h>
# include <SPI.h>

byte mac[] = {0x21,0xFE,0xFF,0xAE,0x12,0x30};
byte ip[] = {192,168,1,6};
EthernetServer server(80);
String http_req = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Ethernet.begin(mac,ip);
  server.begin();
  Serial.println(Ethernet.localIP());
  pinMode(2,OUTPUT);
  //pinMode(5,INPUT);
} 

int flag = 0;
int state = 0;

void loop() {
  // put your main code here, to run repeatedly:
  EthernetClient client=server.available();
  int a3 = analogRead(3);
  int a5 = analogRead(5);
  
          
  if(client){
    if(client.available()){
    char c=client.read();
    //Serial.print(c);
    http_req += c;
    
    
    if ( c == '\n' && flag){
      Serial.println(http_req);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");

      client.println("Connection:keep-alive");
      //client.println("Refresh:5");
      client.println();
      client.println("<!DOCTYPE HTML>");
      client.println("<html><head>  <title>    LED   </title></head><body><p><h1> change led state </h1></p><form method = \"get\">");
      ProcessCheckbox (client);
      client.println("</form></body></html>");
      http_req ="";
      //client.stop();
    }
    if( c == '\n')
      flag = 1;
    else if ( c != '\r')
      flag = 0;
         
   
    }
  }
}

void ProcessCheckbox (EthernetClient client){
  if ( http_req.indexOf("LED2=2"))
    state = !state;
  if (state!=1){
    digitalWrite(2,LOW);
    client.println("<input type = \"checkbox\" name = \"LED2\" value = \"2\" onclick =\"submit();\" > LED " );
  
  }
  else
  {
    digitalWrite(2,HIGH);
    client.println("<input type = \"checkbox\" name = \"LED2\" value = \"2\" onclick =\"submit();\" checked> LED " );
  }
  
   
}

