#include <raylib.h>

class Ball
{
    private:
    float x;
    float y;
    float Speed_x;
    float Speed_y;
    float radius = 25;


    public:
    void SettingBall(float Cordinate_x , float Cordinate_y, float x_Speed, float y_Speed, float Settingradius);
    void Draw();
    int player_Score =0;
    int cpu_Score= 0;
    
    float GetX() {return x;}
    float GetY() {return y;}
    float GetRadius() {return radius;}
    float SetSpeed_X(float speed);   

    void Update();
    
    void ReSetBall();

    void GetScore();



};