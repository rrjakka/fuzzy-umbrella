#include "include/game.hpp"
#include "include/scenes/menu_scene.hpp"

#include <memory>

int main()
{
    auto game = Game("fuzzy umbrella", sf::Vector2u(720, 480));
    game.getSceneManager().pushScene(std::make_unique<MenuScene>(game));
    game.execute();
    return 0;
}
