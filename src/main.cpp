#include <Arduino.h>
#include "Serre.h"
#include "RestServer.h"

//function declaration
void toSerial(String myString );

RestServ  restservr = RestServ();

void setup() {
  Serial.begin(9600);
  delay(10);

  Serre mySerre;
  mySerre = Serre();
  if (mySerre.needAeration()) {
    toSerial("NEED"); 
  } else {
    toSerial("NO");
  }

  restservr.init();
}

void loop() {
  // serve Web clients...
  restservr.handleWebRequests();
}

void toSerial(String myString ) {
  Serial.println(myString); 
 }