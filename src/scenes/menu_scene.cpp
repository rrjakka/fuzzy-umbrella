#include "include/scenes/menu_scene.hpp"
#include "include/game.hpp"
#include <iostream>

#include "include/scenes/game_scene.hpp"

MenuScene::MenuScene(Game& game)
    : Scene(game)
{

}

void MenuScene::onEnter()
{
    std::cout << "MenuScene: Entering scene..." << std::endl;
}

void MenuScene::onExit()
{
    std::cout << "MenuScene: Exiting scene..." << std::endl;
}

void MenuScene::update(float dt)
{

}

void MenuScene::draw(sf::RenderWindow& window)
{
    window.clear();

    sf::RectangleShape shape(sf::Vector2f(200.f, 100.f));

    shape.setFillColor(sf::Color::Red);
    shape.setPosition({260.f, 190.f});

    window.draw(shape);
}

void MenuScene::handleEvent(const sf::Event& event)
{
    if (const auto* keyEvent = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            m_game.getWindow().close();
        }
        if (keyEvent->code == sf::Keyboard::Key::Space)
        {
            m_game.getSceneManager().pushScene(std::make_unique<GameScene>(m_game));
        }
    }
}