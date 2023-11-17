#include <iostream>
#include <raylib.h>
#include <Ball.h>
#include <Bar.h>
#include <Enemy.h>

using namespace std;

const int Screen_Width = 1280;
const int Screen_Height = 800;
const int Screen_Width_Half = Screen_Width / 2;
const int Screen_Heigt_Half = Screen_Height / 2;

Ball ball;
Bar player;
Enemy cpu;

int main()
{

    InitWindow(Screen_Width, Screen_Height, "PingPong");
    SetTargetFPS(60);    

    // define Object
    ball.SettingBall(Screen_Width_Half, Screen_Heigt_Half, 6.0f, 6.0f, 25.0f);
    player.SettingBar(10, Screen_Heigt_Half - 60, 25, 120, 6);
    cpu.SettingBar(Screen_Width - 35, Screen_Heigt_Half - 60, 25, 120, 6);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Setting game
        DrawLine(Screen_Width_Half, 0, Screen_Width_Half, Screen_Height, WHITE);
        ball.Update();
        player.Update();
        cpu.CpuMove(ball.GetY());
        ball.Draw();
        player.Draw();
        cpu.Draw();

        // Check Collision
        if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), Rectangle{player.GetX(), player.GetY(), player.GetWidth(), player.GetHeigth()}))
        {
            ball.SetSpeed_X(-1);
        }
        if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), Rectangle{cpu.GetX(), cpu.GetY(), cpu.GetWidth(), cpu.GetHeigth()}))
        {
            ball.SetSpeed_X(-1);
        }

        // Draw Text
        DrawText("Player", Screen_Width / 4, 50, 20, WHITE);
        DrawText(TextFormat("%i", ball.player_Score), Screen_Width / 4, 80, 20, WHITE);
        DrawText("Cpu", 3 * (Screen_Width / 4), 50, 20, WHITE);
        DrawText(TextFormat("%i", ball.cpu_Score), 3 * (Screen_Width / 4), 80, 20, WHITE);
        DrawFPS(10,10);

        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}