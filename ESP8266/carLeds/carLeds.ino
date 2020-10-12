
#include "Logger.h"
#include "LedModeRepository.h"

Logger logger;

void setup() {
  // TODO Load internal LED mode from EEPROM
  // TODO Load external LED mode from EEPROM

  Serial.begin(115200);  

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // TODO Render inside
  // TODO Render outside

  // TODO Cycle web service?
  // TODO If LED modes changed, update EEPROM
  
  logger.Info("Here is an info msg");
  logger.Debug("Here is a debug msg");


  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000); 
}
