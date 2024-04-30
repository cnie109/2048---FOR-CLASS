#include "../include/game.hpp"
#include "raylib.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <time.h>
#include <cmath>

using namespace std;

Game::Game(int size)
{

    score = 0;

    int row = rand() % size;
    int col = rand() % size;

    int row2 = rand() % size;
    int col2 = rand() % size;

    while (row == row2 && col == col2)
    {

        row2 = rand() % size;
        col2 = rand() % size;
    }

    vector<int> tmp(size, 0);
    for (int i = 0; i < size; i++)
    {
        board.push_back(tmp);
    }

    board[row][col] = 2;
    board[row2][col2] = 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            cout << board[j][i] << " ";
        }
        cout << endl;
    }

    // setup the colorSpace
    colorSpace.insert(*(new pair<int, int>(2, 0xff0000ff)));
    colorSpace.insert(*(new pair<int, int>(4, 0xfa8405ff)));
    colorSpace.insert(*(new pair<int, int>(8, 0xffff00ff)));
    colorSpace.insert(*(new pair<int, int>(16, 0xa8fa05ff)));
    colorSpace.insert(*(new pair<int, int>(32, 0x00ff00ff)));
    colorSpace.insert(*(new pair<int, int>(64, 0x05fab0ff)));
    colorSpace.insert(*(new pair<int, int>(128, 0x05b5faff)));
    colorSpace.insert(*(new pair<int, int>(256, 0x0000ffff)));
    colorSpace.insert(*(new pair<int, int>(512, 0x9005faff)));
    colorSpace.insert(*(new pair<int, int>(1024, 0xea05faff)));
    colorSpace.insert(*(new pair<int, int>(2048, 0xfa0567ff)));
}

void Game::draw()
{
    int squareSize = 100;
    int margin = squareSize / 30;
    int fontSize;
    int squareOffset;
    int fontOffsetX;
    int fontOffsetY;

    unsigned int colorValue = 0;
    // draw the score
    DrawText(TextFormat("Score: %i", score), 200, 10, 40, WHITE);
    // draw the board
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            colorValue = colorSpace[board[j][i]];
            DrawRectangle(200 + i * (squareSize + margin), 100 + j * (squareSize + margin), squareSize, squareSize, GetColor(colorValue));

            // draw the numbers on each square
            if (board[j][i] != 0)
            {
                squareOffset = squareSize / 2;
                fontSize = squareSize / 2.5 - log10(board[j][i]) * 3;
                fontOffsetX = fontSize / 3 * log10(board[j][i]);
                fontOffsetY = fontSize / 2;
                DrawText(to_string(board[j][i]).c_str(),
                         200 + squareOffset - fontOffsetX + i * (squareSize + margin),
                         100 + squareOffset - fontOffsetY + j * (squareSize + margin),
                         fontSize,
                         WHITE);
            }
        }
    }
}
