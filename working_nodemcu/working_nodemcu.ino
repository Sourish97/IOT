#include<ESP8266WiFi.h>
const char* ssid="Vaghulade";
const char* pass="Smira@97";
int state=0;
String http_req="";
WiFiServer server(80);
void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(115200);
    WiFi.begin(ssid,pass);

while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print("."); 
  delay(200);
  }
  server.begin();
  Serial.println(WiFi.localIP());


  }
void loop()
{
  WiFiClient client=server.available();
  if(-1)
  {
    Serial.print(".");
  }
  if(!client)
  {
    return;
  }
String s="";
  if(client.available())
  {
     s=client.readStringUntil('\r');
     client.flush();
    Serial.print(s);
    if(s.indexOf("/gpio/0")!=-1)
  {
    Serial.print("OFF");
    digitalWrite(2,LOW);
    }  
     else if(s.indexOf("/gpio/1")!=-1)
  {
    Serial.print("ON");
    digitalWrite(2,HIGH);
    }
  }
    


  }

