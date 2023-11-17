#include <Ball.h>

void Ball::SettingBall(float Cordinate_x, float Cordinate_y, float x_Speed, float y_Speed, float Settingradius)
{
    x = Cordinate_x;
    y = Cordinate_y;
    Speed_x = x_Speed;
    Speed_y = y_Speed;
    radius = Settingradius;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

float Ball::SetSpeed_X(float speed)
{
    return Speed_x *= speed;
}

void Ball::Update()
{
    x += Speed_x;
    y += Speed_y;

    GetScore();
    if (y - radius <= 0 || y + radius >= GetScreenHeight())
    {
        Speed_y *= -1;
    }
}

void Ball::ReSetBall()
{

    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
}

void Ball::GetScore()
{
    // GetScore
    if (x - radius <= 0)
    {
        Speed_x *= -1;
        cpu_Score++;
        ReSetBall();
    }
    if (x + radius >= GetScreenWidth())
    {
        Speed_x *= -1;
        player_Score++;
        ReSetBall();
    }
}
