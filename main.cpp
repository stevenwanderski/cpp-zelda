#include "raylib.h"

int main(void)
{
    float windowWidth = 256.f;
    float windowHeight = 240.f;
    float scale = 2.5f;

    InitWindow(windowWidth * scale, windowHeight * scale, "Zelda");
    SetTargetFPS(60);

    float playerPosX = 100.f;
    float playerPosY = 100.f;
    float playerSpeed = 5.f;

    while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(BLACK);

      if (IsKeyDown(KEY_D))
      {
        playerPosX += playerSpeed;
      }
      else if (IsKeyDown(KEY_A))
      {
        playerPosX -= playerSpeed;
      }
      else if (IsKeyDown(KEY_W))
      {
        playerPosY -= playerSpeed;
      }
      else if (IsKeyDown(KEY_S))
      {
        playerPosY += playerSpeed;
      }

      Texture2D playerTex = LoadTexture("assets/player_walk.png");
      Rectangle playerSource = Rectangle{0, 0, 16, 16};
      Rectangle playerDest = Rectangle{playerPosX, playerPosY, 16 * scale, 16 * scale};

      DrawTexturePro(playerTex, playerSource, playerDest, Vector2{}, 0, WHITE);

      EndDrawing();
    }
}
