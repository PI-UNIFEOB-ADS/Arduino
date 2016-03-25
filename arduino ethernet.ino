#include "etherShield.h"
 #include "ETHER_28J60.h"
int outputPin = 6;
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   
static uint8_t ip[4] = {192, 168, 0, 177};                      
static uint16_t port = 80;                                      // Use port 80 - the standard for HTTP
ETHER_28J60 e;
void setup()
 {  
   e.setup(mac, ip, port);
   pinMode(outputPin, OUTPUT);
}
void loop() {
   char* params;
  if (params = e.serviceRequest())
  {   
  e.print("<H1>Web Remote</H1>");   
  if (strcmp(params, "?cmd=on") == 0)   
  {     
  digitalWrite(outputPin, HIGH);    
   e.print("<A HREF='?cmd=off'>Turn off</A>");  
   }     else     {     
  digitalWrite(outputPin, LOW);   
    e.print("<A HREF='?cmd=on'>Turn on</A>");   
  }    
 e.respond();  
}
}