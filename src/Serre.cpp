#include "Serre.h"

Serre::Serre(/* args */)
{
this->sensor1 =Sensor();
this->SeuilTemperature =0;
}

Serre::~Serre()
{
}

bool Serre::needAeration() {
    return bool (this->getTemperature() > this->getSeuilTemperature()) ;
}
float  Serre::getHumidity(){
    return this->sensor1.getHumidity();
 }
float  Serre::getTemperature(){
    return this->sensor1.getTemperature();
 }
String Serre::coucou() {
    return "coucou from Serre";
}
void Serre::setSeuilTemperature(float newSeuil) {
    this->SeuilTemperature = newSeuil;
}
float Serre::getSeuilTemperature(){
    return this->SeuilTemperature;
}
