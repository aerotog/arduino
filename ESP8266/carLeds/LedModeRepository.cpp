#include "LedModeRepository.h"

#include <EEPROM.h>


const int INTERNAL_STARTUP = 0;
const int INTERNAL_RUNNING = 1;
const int EXTERNAL_STARTUP = 2;
const int EXTERNAL_RUNNING = 3;


LedModeRepository::LedModeRepository(/* args */)
{
}

// LedModeRepository::~LedModeRepository()
// {
// }

//void LedModeRepository::GetInternalStartup()
//{
//  return;
//}
//
//void LedModeRepository::SetInternalStartup(int mode)
//{
//  return;  
//}
