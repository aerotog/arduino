#include "Logger.h"

enum LogLevel { TRACE, DEBUG, INFO, WARN };
LogLevel logLevelLimit = INFO;

Logger::Logger(/* args */)
{
//  logLevelLimit = TRACE;
  Serial.println(logLevel);
}


//void Logger:SetLogLevel(int level)
//{
//  
//}

  // TOOD Add circular buffer
  
void Logger::Info(String message)
{
  if(LogLevel::INFO >= logLevelLimit)
  {
    Log(message, "INFO");
  }
}

void Logger::Debug(String message)
{
  if(LogLevel::DEBUG >= logLevelLimit)
  {
    Log(message, "DEBUG");
  }
}

void Logger::Log(String message, String level)
{
  String formattedMessage = level + ": " + message;
  Serial.println(formattedMessage);
}

// TODO Write circular buffer of logs to /logs web request
