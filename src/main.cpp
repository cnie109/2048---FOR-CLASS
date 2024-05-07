#include "../include/game.hpp"
#include "raylib.h"
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

void postMove(Game *game, Sound sound)
{
    if (game->hasChanged())
    {
        game->addNewBlock();
        game->addNewBlock();
    }
    PlaySound(sound);
}

int main()
{
    srand(time(0));

    // it is recommended that you do not do a game larger than 100
    // however, it will still work
    // realistically you shouldn't go over 11 otherwise winning becomes trivial (spam one direction and you win eventually)
    // setting it to 15 will make it run and win automatically with our very advanced high tech AI
    Game *game = new Game(15);

    const int width = 800;
    const int height = 800;

    InitWindow(width, height, "2048");

    Texture2D texture = LoadTexture("Kitty.png");
    Texture2D lossTexture = LoadTexture("loss.png");

    InitAudioDevice();
    Music backgroundMusic = LoadMusicStream("kurdsong.mp3");
    PlayMusicStream(backgroundMusic);

    Sound winSound = LoadSound("taco-bell-bong-sfx.wav");
    Sound loseSound = LoadSound("spongebob-fail.mp3");
    Sound moveSound = LoadSound("vine-boom.wav");

    while (!WindowShouldClose())
    {
        UpdateMusicStream(backgroundMusic);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("FPS: %i", GetFPS()), 500, 40, 20, PURPLE);
        game->draw();
        // game-state == 2 = win
        if (game->state == 2)
        {
            DrawTexture(texture, width / 2 - texture.width / 2, height / 2 - texture.height / 2, WHITE);
            DrawText("YOU WIN", 100, 550, 100, YELLOW);
            PlaySound(winSound);
            EndDrawing();
            WaitTime(3);
            break;
        }
        // game-state == 1 = lose
        else if (game->state == 1)
        {
            DrawTexture(lossTexture, width / 2 - lossTexture.width / 2, height / 2 - lossTexture.height / 2, WHITE);
            DrawText("YOU LOSE", 100, 550, 100, RED);
            PlaySound(loseSound);
            EndDrawing();
            WaitTime(3);
            break;
        }
        EndDrawing();

        // autoplay if the board size is 15
        if (game->board.size() == 15)
        {
            PlaySound(moveSound);
            game->right();
            game->addNewBlock();
        }

        // get if the arrow keys are pressed and do the appropriate action
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
        {
            game->right();
            postMove(game, moveSound);
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_D))
        {
            game->left();
            postMove(game, moveSound);
        }
        else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_D))
        {
            game->down();
            postMove(game, moveSound);
        }
        else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_D))
        {
            game->up();
            postMove(game, moveSound);
        }
    }

    UnloadMusicStream(backgroundMusic);
    UnloadSound(moveSound);
    UnloadSound(winSound);
    CloseAudioDevice();
    CloseWindow();
}
