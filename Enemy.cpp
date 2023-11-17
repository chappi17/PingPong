#include <Enemy.h>

void Enemy::CpuMove(int ball_y)
{
    if (y + height / 2 > ball_y)
    {
        y -= Speed/2;
    }
    if (y + height / 2 < ball_y)
    {
        y += Speed/2;
    }
    Limit();
}
