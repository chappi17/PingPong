
#include <raylib.h>
#pragma once

class Bar
{
    protected:
        float x;
        float y;
        float width;
        float height;
        float Speed;

    public:
    void SettingBar(float Cordinate_x, float Cordinate_y, float SettingWidth, float SettingHeight, float SettingSpeed);

    float GetX() {return x;}
    float GetY() {return y;}
    float GetWidth() {return width;}
    float GetHeigth() {return height;}

    void Draw();
    void Limit();
    void Update();    
};