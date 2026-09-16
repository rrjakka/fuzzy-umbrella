#include "include/scenes/game_scene.hpp"
#include "include/game.hpp"
#include <iostream>

GameScene::GameScene(Game& game)
    : Scene(game)
{

}

void GameScene::onEnter()
{
    std::cout << "GameScene: Entering scene..." << std::endl;
}

void GameScene::onExit()
{
    std::cout << "GameScene: Exiting scene..." << std::endl;
}

void GameScene::update(float dt)
{

}

void GameScene::draw(sf::RenderWindow& window)
{
    window.clear();

    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);
    shape.setPosition({260, 140});

    window.draw(shape);
}

void GameScene::handleEvent(const sf::Event& event)
{
    if (const auto* keyEvent = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            m_game.getSceneManager().popScene();
        }
        if (keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Space pressed! You can change scene here." << std::endl;
        }
    }
}