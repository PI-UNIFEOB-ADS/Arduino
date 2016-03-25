#include "etherShield.h"
 #include "ETHER_28J60.h"
int outputPin = 6;
int porta_rele1 = 7;
int porta_rele2 = 8;
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   
static uint8_t ip[4] = {192, 168, 0, 177};                      
static uint16_t port = 80;                                      // Use port 80 - the standard for HTTP
ETHER_28J60 e;
void setup()
 {  
   e.setup(mac, ip, port);
   pinMode(outputPin, OUTPUT);
   pinMode(porta_rele1, OUTPUT); 
   pinMode(porta_rele2, OUTPUT);
}
void loop() {
   char* params;
  if (params = e.serviceRequest())
  {   
  e.print("<H1>Choque Nelas!!!</H1>"); 
    
  if (strcmp(params, "?cmd=on") == 0){
     digitalWrite(porta_rele1, HIGH);  //Liga rele 1
     digitalWrite(porta_rele2, HIGH);     
     e.print("<A HREF='?cmd=off'>Turn off</A>");  
   }     
   else if(strcmp(params, "?cmd=off") == 0){         
    digitalWrite(porta_rele1, LOW); //Desliga rele 1
    digitalWrite(porta_rele2, LOW);  //Liga rele 2
    e.print("<A HREF='?cmd=on'>Turn on</A>"); 
  }    
 e.respond()