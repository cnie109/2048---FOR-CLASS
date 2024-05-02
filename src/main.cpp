#include "../include/game.hpp"
#include "raylib.h"
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

    Game *game = new Game(15);

    const int width = 800;
    const int height = 800;
    const int frameRate = 100000;

    InitWindow(width, height, "2048");
    SetTargetFPS(frameRate);

    Texture2D texture = LoadTexture("Kitty.png");

    InitAudioDevice();
    Music music = LoadMusicStream("kurdsong.mp3");
    PlayMusicStream(music);

    Sound sound = LoadSound("taco-bell-bong-sfx.wav");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("FPS: %i", GetFPS()), 500, 40, 20, PURPLE);
        game->draw();
        if (game->state == 2)
        {

            DrawTexture(texture, width / 2 - texture.width / 2, height / 2 - texture.height / 2, WHITE);
            // DrawText("YOU WIN", 100, 550, 100, YELLOW);
            PlaySound(sound);
            EndDrawing();
            WaitTime(3);
            break;
        }
        EndDrawing();

        game->right();
        game->addNewBlock();

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
}
