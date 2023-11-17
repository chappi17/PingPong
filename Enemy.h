#include <raylib.h>
#include <bar.h>

class Enemy : public Bar
{
    public:
    void CpuMove(int ball_y);
};