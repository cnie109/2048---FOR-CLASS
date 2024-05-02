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

    board[row][col] = 2;
    board[row2][col2] = 2;
}
<<<<<<< Updated upstream
=======

// add up and down
void Game::up() {
    int temp_index = 0;

    for (int col = 0; col < board.size(); col++) {
        int bottom = board.size() - 1;

        while (bottom != 0) {
            // remove zeroes and combines (row-based:)
            /*for (int i = 0; i < board.size(); i++) {
                if (board[i][col] != 0) {
                    if (i != temp_index) {
                        board[temp_index][col] = board[i][col];
                        board[i][col] = 0;
                    }
                    temp_index++;
                }
            }

            temp_index = 0;

            if (board[bottom - 1][col] == board[bottom][col]) {
                board[bottom - 1][col] = 2 * board[bottom][col];
                board[bottom][col] = 0;
            }
            bottom--;
            */
           
           // removes zeroes and combines (col-based:)
           for (int i = 0; i < board.size(); i++) {
                if (board[col][i] != 0) {
                    if (i != temp_index) {
                        board[col][temp_index] = board[col][i];
                        board[col][i] = 0;
                    }
                    temp_index++;
                }
            }

            temp_index = 0;

            if (board[col][bottom - 1] == board[col][bottom]) {
                board[col][bottom - 1] = 2 * board[col][bottom];
                board[col][bottom] = 0;
            }
            bottom--;
        }
    }
}

void Game::down() {
    int temp_index = board.size() - 1;

    for (int col = 0; col < board.size(); col++) {
        int top = 0;

        while (top != board.size() - 1) {
           // removes zeroes and combines (col-based:)
           for (int i = board.size() - 1; i >= 0; i--) {
                if (board[col][i] != 0) {
                    if (i != temp_index) {
                        board[col][temp_index] = board[col][i];
                        board[col][i] = 0;
                    }
                    temp_index--;
                }
            }

            temp_index = board.size() - 1;

            if (board[col][top + 1] == board[col][top]) {
                board[col][top + 1] = 2 * board[col][top];
                board[col][top] = 0;
            }

            top++;
        }
    }
}
>>>>>>> Stashed changes

void Game::print()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {

            cout << board[j][i] << " "; // why was this column-based?
        }
        cout << endl;
    }
}

void Game::addNewBlock()
{
<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes

    int randrow = rand() % (board.size() - 1);
    int randcol = rand() % (board.size() - 1);

    while (board[randrow][randcol] != 0)
    {
        randrow = rand() % (board.size() - 1);
        randcol = rand() % (board.size() - 1);
    }

    board[randrow][randcol] = 7;
}
