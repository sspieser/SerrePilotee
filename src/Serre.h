#ifndef _SERRE_H_
#define _SERRE_H_
#include "Sensor.h"

class Serre
{
private:
    Sensor sensor1;
    float SeuilTemperature;

public:
    Serre(/* args */);
    ~Serre();
    bool needAeration();
    void open();
    float getHumidity();
    float getTemperature();
    String coucou();
    void setSeuilTemperature(float newSeuil);
    float getSeuilTemperature();

};



#endif //_SERRE_H_