#include <Bar.h>

void Bar::SettingBar(float Cordinate_x, float Cordinate_y, float SettingWidth, float SettingHeight, float SettingSpeed)
{
    x = Cordinate_x;
    y = Cordinate_y;
    width = SettingWidth;
    height = SettingHeight;
    Speed = SettingSpeed;
}

void Bar::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Bar::Limit()
{
    if (y + 120 >= GetScreenHeight())
    {
        y = GetScreenHeight() - 120;
    }
    if (y <= 0)
    {
        y = 0;
    }
}

void Bar::Update()
{
    if (IsKeyDown(KEY_DOWN))
    {
        y += Speed;
    }
    if (IsKeyDown(KEY_UP))
    {

        y -= Speed;
    }
    Limit();
}
