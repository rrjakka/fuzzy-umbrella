#include "include/game.hpp"

int main()
{
    auto game = Game("fuzzy umbrella", sf::Vector2u(720, 480));
    game.execute();
    return 0;
}