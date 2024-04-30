#include "../include/game.hpp"
#include <string>
#include <iostream>
#include <cstdlib> 
#include <chrono>
#include <time.h>

using namespace std;


Game::Game(int size)
{

    score = 0;

    

    int row = rand() % size;
    int col = rand() % size;

    int row2 = rand() % size;
    int col2 = rand() % size;

    while(row == row2 && col == col2){
       
        row2 = rand() % size;
        col2 = rand() % size;
    }

    vector<int> tmp(size, 0);
    for (int i = 0; i < size; i++){
        board.push_back(tmp);
    }

    board[row][col] = 2;
    board[row2][col2] = 2;
    

    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++){

            cout << board[j][i] << " ";

        }
        cout << endl;
    }


}

