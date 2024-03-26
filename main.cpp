#include "raylib.h"
#include "player.h"

int main(void)
{
    float windowWidth = 256.f;
    float windowHeight = 240.f;
    float scale = 2.5f;

    InitWindow(windowWidth * scale, windowHeight * scale, "Zelda");
    SetTargetFPS(60);

    Player player{scale};

    while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(BLACK);
      float dT = GetFrameTime();

      player.tick(dT);

      EndDrawing();
    }
}
