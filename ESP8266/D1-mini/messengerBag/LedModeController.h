#include "LedRenderer.h"

class LedModeController
{
public:
  //LedWebServer();
  LedModeController(LedRenderer::Mode& renderMode);
  void handleClient();
  
private:  
  void handleRoot();
  void handleLogin();
  void handleNotFound();

  LedRenderer::Mode& _renderMode;
};
