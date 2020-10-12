#ifndef LOGGER
#define LOGGER

#include <Arduino.h>

class Logger
{
private:
    /* data */
    int logLevel;
    void Log(String message, String level);
    
public:
    Logger(/* args */);
    // ~Logger();
    void Info(String message);
    void Debug(String message);
    
};



#endif
