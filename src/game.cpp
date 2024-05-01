#include "../include/game.hpp"
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

    // board[1][1] = 0;

    board[row][col] = 2;
    board[row2][col2] = 2;
}

void Game::print()
{

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {

            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}

void Game::addNewBlock()
{

    vector<vector<int>> empy;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][i] == 0)
            {
                // empy.push_back(i);
                // empy.push_back(j);
            }
        }
    }

    int randrow = rand() % (board.size() - 1);
    int randcol = rand() % (board.size() - 1);

    while (board[randrow][randcol] != 0)
    {
        randrow = rand() % (board.size() - 1);
        randcol = rand() % (board.size() - 1);
    }

    board[randrow][randcol] = 7;
}
