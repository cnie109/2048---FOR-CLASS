#include "../include/game.hpp"
#include "raylib.h"
#include <iostream>
#include <cmath>
#include <vector>

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
    previousBoard = board;

    print();

    // setup the colorSpace
    colorSpace.insert(*(new pair<int, int>(0, 0x777777ff)));
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

void Game::addNewBlock()
{
    if (isFull())
    {
        return;
    }
    int randrow = rand() % (board.size());
    int randcol = rand() % (board.size());

    while (board[randrow][randcol] != 0)
    {
        randrow = rand() % (board.size());
        randcol = rand() % (board.size());
    }

    board[randrow][randcol] = rand() > 0.1 ? 2 : 4;
}

bool Game::isFull()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Game::hasChanged()
{
    // cout << "=======" << endl;
    // for (int i = 0; i < board.size(); i++)
    // {
    //     for (int j = 0; j < board.size(); j++)
    //     {
    //         cout << previousBoard[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-------" << endl;
    // for (int i = 0; i < board.size(); i++)
    // {
    //     for (int j = 0; j < board.size(); j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            // cout << "board: " << board[i][j] << " previous: " << previousBoard[i][j] << endl;
            if (board[i][j] != previousBoard[i][j])
            {
                // cout << "changed" << endl;
                previousBoard = board;
                return true;
            }
        }
    }
    previousBoard = board;
    return false;
}

bool Game::loss() {
    if (isFull()) {
        previousBoard = board;
        left(); right(); up(); down();
        if (board == previousBoard) {
            state = 1;
            return true;
        }
        board = previousBoard;
    }
    return false;
}


// move every block left
void Game::left()
{
    int currentX = 0;
    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][i] == 0)
            {
                continue;
            }
            // move the block over until there is a block in the way
            currentX = i;
            while (currentX > 0 && board[j][currentX - 1] == 0)
            {
                board[j][currentX - 1] = board[j][currentX];
                board[j][currentX] = 0;
                currentX--;
            }
            // combine the blocks if possible
            if (board[j][currentX] == board[j][currentX - 1])
            {
                board[j][currentX - 1] = board[j][currentX - 1] * 2;
                board[j][currentX] = 0;
                state = board[j][currentX - 1] == 2048 ? 2 : 0;
                score += board[j][currentX - 1];
            }
        }
    }
}

// move every block right
void Game::right()
{
    int currentX = 0;
    for (int i = board.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][i] == 0)
            {
                continue;
            }
            // move the block over until there is a block in the way
            currentX = i;
            while (currentX < board.size() - 1 && board[j][currentX + 1] == 0)
            {
                board[j][currentX + 1] = board[j][currentX];
                board[j][currentX] = 0;
                currentX++;
            }
            // combine the blocks if possible
            if (board[j][currentX] == board[j][currentX + 1])
            {
                board[j][currentX + 1] = board[j][currentX + 1] * 2;
                board[j][currentX] = 0;
                state = board[j][currentX + 1] == 2048 ? 2 : 0;
                score += board[j][currentX + 1];
            }
        }
    }
}

vector<vector<int>> transpose(vector<vector<int>> &input)
{
    vector<vector<int>> result(input.size(), *(new vector<int>(input.size(), 0)));
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            result[j][i] = input[i][j];
        }
    }
    return result;
}

void Game::up()
{
    board = transpose(board);
    left();
    board = transpose(board);
}

void Game::down()
{
    board = transpose(board);
    right();
    board = transpose(board);
}

void Game::draw()
{
    
    int squareSize = 100 / (board.size() / 4 == 0 ? 1 : board.size() / 4);
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
            if (board.size() < 20)
            {
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
    loss();
}

void Game::print()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}