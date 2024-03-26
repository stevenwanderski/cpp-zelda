#pragma once

class Player
{
public:
    Player(float scale);
    void tick(float dT);

private:
    float posX = 100.f;
    float posY = 100.f;
    float speed = 4.f;
    float frame = 0.f;
    float runningTime = 0.f;
    float spriteTime = 1.f / 12.f;
    float spriteX = 0.f;
    float scale = 0.f;
};