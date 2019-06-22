#include "Sensor.h"

Sensor::Sensor(/* args */)
{
    this->capteur = Adafruit_HDC1000();

    if (!this->capteur.begin()) {
       // Serial.println("Couldn't find sensor!");
        while (1);
    }
    // Serial.println("sensor INIT");
};
Sensor::~Sensor()
{

}
float Sensor::getTemperature()
{
    Serial.println("sensor get Temperature");
    return this->capteur.readTemperature() ;
}
float Sensor::getHumidity(){
   return this->capteur.readHumidity();
}
