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
    const int frameRate = 480;

    InitWindow(width, height, "2048");
    SetTargetFPS(frameRate);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("FPS: %i", GetFPS()), 500, 40, 20, GREEN);
        game->draw();
        EndDrawing();

        // if (game->isFull())
        // {
        //     lost = true;
        //     break;
        // }
        if (IsKeyPressed(KEY_RIGHT))
        {
            game->right();
            if (!game->isFull())
            {
                game->addNewBlock();
            }
        }
        else if (IsKeyPressed(KEY_LEFT))
        {
            game->left();
            if (!game->isFull())
            {
                game->addNewBlock();
            }
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            game->down();
            if (!game->isFull())
            {
                game->addNewBlock();
            }
        }
        else if (IsKeyPressed(KEY_UP))
        {
            game->up();
            if (!game->isFull())
            {
                game->addNewBlock();
            }
        }
    }

    CloseWindow();

    // game->down();
    // cout << "-------" << endl;
    // game->print();
}
