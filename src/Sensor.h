
#ifndef _SENSOR_H_
#define _SENSOR_H_
#include <Adafruit_HDC1000.h>


class Sensor
{
private:
    /* data */
    Adafruit_HDC1000 capteur;
public:
    Sensor(/* args */);
    ~Sensor();
    float getTemperature();
    float getHumidity();
   
};
#endif //_SENSOR_H_