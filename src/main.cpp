#include "../include/game.hpp"
#include "raylib.h"

int main()
{
    Game *game = new Game(4);

    const int width = 800;
    const int height = 800;
    const int frameRate = 100000;

    InitWindow(width, height, "2048");
    SetTargetFPS(frameRate);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        game->draw();
        DrawText(TextFormat("FPS: %i", GetFPS()), 500, 20, 40, GREEN);
        EndDrawing();
    }
    CloseWindow();
}