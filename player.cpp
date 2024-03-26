#include "raylib.h"
#include "player.h"

Player::Player(float scale)
{
    this->scale = scale;
};

void Player::tick(float dT)
{
    bool moving = false;

    if (IsKeyDown(KEY_D))
    {
      posX += speed;
      spriteX = 16 * 2;
      moving = true;
    }
    else if (IsKeyDown(KEY_A))
    {
      posX -= speed;
      spriteX = 16 * 3;
      moving = true;
    }
    else if (IsKeyDown(KEY_W))
    {
      posY -= speed;
      spriteX = 16 * 1;
      moving = true;
    }
    else if (IsKeyDown(KEY_S))
    {
      posY += speed;
      spriteX = 16 * 0;
      moving = true;
    }

    if (moving)
    {
      runningTime += dT;

      if (runningTime > spriteTime)
      {
        runningTime = 0.f;
        frame += 1;

        if (frame > 1) frame = 0;
      }
    }
    else
    {
      frame = 0;
    }

    Texture2D playerTex = LoadTexture("assets/player_walk.png");
    Rectangle playerDest = Rectangle{posX, posY, 16 * scale, 16 * scale};
    Rectangle playerSource = Rectangle{spriteX, 16 * frame, 16, 16};

    DrawTexturePro(playerTex, playerSource, playerDest, Vector2{}, 0, WHITE);
};