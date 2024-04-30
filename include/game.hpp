#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include <map>

using namespace std;

class Game
{
public:
    vector<vector<int>> board;
    map<int, int> colorSpace;
    int score;

    Game(int);

    void left();
    void right();
    void up();
    void down();

    void initScreen();
    void draw();
};
#endif