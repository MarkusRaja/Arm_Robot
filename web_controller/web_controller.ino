#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>Servo management</h1><br>
Tekan untuk <a href="manual" target="myIframe">Manual</a><br>
Tekan untuk <a href="matic" target="myIframe">Matic</a><br>
Servo dalam keadaan :<iframe name="myIframe" width="100" height="25"\ frameBorder="0"><br>

</center>

</body>
</html>
)=====";
//---------------------------------------------------------------

#define PC 5
const char* ssid = "pro updated"; 
const char* password = "markustian2345"; 
//const char* ssid = "ASUS_X00TD"; 
//const char* password = "33334441"; 
ESP8266WebServer server(80);

void handleRoot() {
 Serial.println("You called root page");
 String s = MAIN_page;
 server.send(200, "text/html", s);
}

void manual() { 
  digitalWrite(PC,LOW);
  server.send(200, "text/html", "Manual status");
 
}
void matic() { 
 digitalWrite(PC,HIGH);
 server.send(200, "text/html", "Matic status");
}

void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);      
  Serial.println("");

  pinMode(PC,OUTPUT); 
  digitalWrite(PC,LOW );
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(70);
    Serial.print(".");
    digitalWrite(2, HIGH);
    delay(70);
    digitalWrite(2, LOW);
    
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  server.on("/", handleRoot);    
  server.on("/manual", manual);
  server.on("/matic", matic);

  server.begin();
  Serial.println("HTTP server started");
}
void loop(void){
  
  server.handleClient();
}
