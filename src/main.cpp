#include "../include/game.hpp"
#include "raylib.h"
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

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
        DrawText(TextFormat("FPS: %i", GetFPS()), 500, 40, 20, GREEN);
        game->draw();
        if (game->state == 2)
        {
            DrawText("YOU WIN", 100, 10, 100, GRAY);
            EndDrawing();
            WaitTime(3);
            break;
        }
        EndDrawing();

        if (IsKeyPressed(KEY_RIGHT))
        {
            game->right();
            game->addNewBlock();
            game->addNewBlock();
        }
        else if (IsKeyPressed(KEY_LEFT))
        {
            game->left();
            game->addNewBlock();
            game->addNewBlock();
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            game->down();
            game->addNewBlock();
            game->addNewBlock();
        }
        else if (IsKeyPressed(KEY_UP))
        {
            game->up();
            game->addNewBlock();
            game->addNewBlock();
        }
    }

    CloseWindow();

    // game->down();
    // cout << "-------" << endl;
    // game->print();
}
