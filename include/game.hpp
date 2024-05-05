#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include <map>

using namespace std;

class Game
{
public:
    vector<vector<int> > board;
    vector<vector<int>> previousBoard;
    map<int, int> colorSpace;
    int score;
    char state; // 0 = normal, 1 = lost, 2 = won

    Game(int);

    void left();
    void right();
    void up();
    void down();
    void addNewBlock();
    bool isFull();
    bool hasChanged();

    void draw();
    void print();
};
#endif