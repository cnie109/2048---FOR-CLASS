#include "../include/game.hpp"
#include <random>
#include <chrono>

int main()
{
    srand(time(0));

    Game *game = new Game(4);
    
    game->addNewBlock();
    game->print();

    /*game->up();
    game->print();*/

    game->down();
    game->print();
}
