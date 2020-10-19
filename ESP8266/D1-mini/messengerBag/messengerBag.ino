
#include "LedRenderer.h"
#include "LedModeController.h"

LedRenderer ledRenderer;
LedModeController* ledModeController;

LedRenderer::Mode renderMode;

void setup()
{
  Serial.begin(115200);

  renderMode = LedRenderer::Mode::RAINBOW;

  ledModeController = new LedModeController(renderMode);
}

void loop()
{
  ledRenderer.Render(renderMode);
  
  ledModeController->handleClient();
}
