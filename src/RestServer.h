
#ifndef _RESTSERVER_H_
#define _RESTSERVER_H_

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
class RestServ
{
private:
    /* data */

public:
    RestServ();
    ~RestServ();
    void init();
    void handleWebRequests();
};

#endif //_RESTSERVER_H_
