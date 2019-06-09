#include "RestServer.h"

WebServer server(80);

//Enter your WiFi SSID and PASSWORD
const char* ssid = "SERREWIFI";
const char* password = "12345678";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
  char html[1000];

  snprintf (html, 1000, "<html><body>\
      <h1>Gestionnaire de la serre</h1>\
      <div><h2>Etat</h2>\
      <div>Temp. : </div>\
      <div>Etat : </div>\
      </div>\
      <div><h2>Actions</h2>\
      <div><button>Ouvrir</button></div>\
      <div><button>Fermer</button></div>\
      </div>\
      </body></html>");

  server.send(200, "text/html", html);
}

//===============================================================
// constructor
//===============================================================
RestServ::RestServ(void) {
    WiFi.enableAP(true);
    delay(100);
}

void RestServ::init() {
  // ESP32 As access point IP, default: 192.168.4.1
    WiFi.mode(WIFI_AP); //Access Point mode
    IPAddress apIP(192, 168, 0, 1);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssid, password);    // Password length minimum 8 char
    Serial.println("");
    Serial.print("WiFi hotspot ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());
    //----------------------------------------------------------------
  
    server.on("/", handleRoot);      
  
    server.begin();                  
    Serial.println("HTTP server started");
}
void RestServ::handleWebRequests() {
  server.handleClient();
  delay(100);
}

RestServ::~RestServ() {}
