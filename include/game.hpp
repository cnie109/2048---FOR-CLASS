#ifdef GAME_HPP
#define GAME_HPP

#include <vector>

class 2048
{
public:
    vector<vector<int>> board;
    void up();
    void down();
    void left();
    void right();

private:
    void addnum();
    void merge();
};

#endif