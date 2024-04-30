#include "../include/game.hpp"
#include "raylib.h"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

Game::Game(int size)
{
    score = 0;
    vector<int> tmp(size, 2);
    for (int i = 0; i < size; i++)
    {
        board.push_back(tmp);
    }
    board[0][1] = 4;
    board[0][2] = 8;
    board[0][3] = 16;
    board[1][0] = 32;
    board[1][1] = 64;
    board[1][2] = 128;
    board[1][3] = 256;
    board[2][0] = 512;
    board[2][1] = 1024;
    board[2][2] = 2048;

    // setup the colorSpace
    colorSpace.insert(*(new pair<int, int>(2, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(4, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(8, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(16, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(32, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(64, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(128, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(256, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(512, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(2, 0x777777ff)));
    colorSpace.insert(*(new pair<int, int>(2, 0x777777ff)));
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
            colorValue = 0x777777ff;
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