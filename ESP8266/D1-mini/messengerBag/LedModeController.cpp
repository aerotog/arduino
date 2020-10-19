#include "LedModeController.h"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

LedModeController::LedModeController(LedRenderer::Mode& renderMode):
  _renderMode(renderMode)
{    
    wifiMulti.addAP("SSID_CHANGE_ME", "PASSWORD_CHANGE_ME");

    Serial.println("Connecting ...");
    int i = 0;
    
    // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    while (wifiMulti.run() != WL_CONNECTED)
    { 
        delay(250);
        Serial.print('.');
    }

    Serial.println('\n');
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("bag"))
    {              
        Serial.println("mDNS responder started");
    }
    else
    {
        Serial.println("Error setting up MDNS responder!");
    }

    server.on("/", HTTP_GET, std::bind(&LedModeController::handleRoot, this));
    server.on("/", HTTP_POST, std::bind(&LedModeController::handleRoot, this));
    server.onNotFound(std::bind(&LedModeController::handleNotFound, this));

    server.begin();
    Serial.println("HTTP server started");

    MDNS.addService("http", "tcp", 80);
}

void LedModeController::handleClient(){
  MDNS.update();
  server.handleClient();
}

void LedModeController::handleRoot()
{
  //server.send(200, "text/html", "<form method=\"POST\"><input type=\"text\" name=\"username\" placeholder=\"Username\"></br><input type=\"password\" name=\"password\" placeholder=\"Password\"></br><input type=\"submit\" value=\"Login\"></form><p>Try 'John Doe' and 'password123' ...</p>");
  String pageContent = 
  "<form method=\"POST\">"
  "<label for=\"modes\">Choose a mode:</label>"
  "<select name=\"modes\" id=\"modes\">"
  "<option value=\"0\">Off</option>"
  "<option value=\"1\">Caution</option>"
  "<option value=\"2\">Cylon</option>"
  "<option value=\"3\">Rainbow</option>"
  "</select>"
  "<input type=\"submit\" value=\"Submit\">"
  "</form>";
  
  server.send(200, "text/html", pageContent);

  Serial.println(server.args());

  for(int i = 0; i < server.args(); i++)
  {
    Serial.println(server.arg(i));
  }

  if(server.args() > 0)
  {
    LedRenderer::Mode newMode = (LedRenderer::Mode)(server.arg(0).toInt());
    this->_renderMode = newMode;
  }
}

void LedModeController::handleNotFound()
{
  server.send(404, "text/plain", "404: Not found");
}
