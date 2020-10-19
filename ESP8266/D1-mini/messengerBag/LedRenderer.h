#ifndef LED_RENDERER
#define LED_RENDERER

class LedRenderer
{
public:
    enum Mode { OFF, CAUTION, CYLON, RAINBOW };
    
    LedRenderer();
    void Render(Mode mode);
    
private:
    float GetDelayTime(float num, float den);
    int modeCounter;
};

#endif
