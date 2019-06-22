#include <Arduino.h>
#include "Serre.h"
#include "Sensor.h"


//function declaration
void toSerial(String myString );

//glocal declaration
int seuilTemp=0;
Serre *mySerre;
//RestServ  restservr = RestServ();

void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.println("Hello Computer");

  mySerre = &Serre();
  Serial.println("Hello Computer 1.1");
  if (mySerre->needAeration()) {
    toSerial("NEED"); 
  } else {
    toSerial("NO");
  }
Serial.println("Hello Computer 2");
  toSerial(mySerre->coucou());
   Serial.print("Temp: "); Serial.print(mySerre->getTemperature());
   Serial.print("\t\tHum: "); Serial.println(mySerre->getHumidity());
Serial.println("Hello Computer3");
  //restservr.init();
}

void loop() {
  //Serre mySerre;
 // mySerre = Serre();
  seuilTemp+=1;
  Serial.print("\t Seuil :"); Serial.print(seuilTemp);
  mySerre->setSeuilTemperature(seuilTemp);
  bool need = mySerre->needAeration();
  if (need ){
    toSerial(" NEED ");
  } else {
    toSerial(" NO NEED ");
  }
  
  // serve Web clients...
 // restservr.handleWebRequests();

  delay(100);
 
}

void toSerial(String myString ) {
  Serial.println(myString); 
 }