#include "include/game.hpp"

void Game::pollEvent()
{
    while (const std::optional<sf::Event> event = m_window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            m_window->close();
    }
}

void Game::update(float dt)
{

}

void Game::draw()
{

}

Game::Game(const std::string& title, const sf::Vector2u& size)
{
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(size),
        title
    );
}

Game::~Game()
{

}

void Game::execute()
{
    while (m_window->isOpen())
    {
        pollEvent();
        update(1.f);
        draw();
    }
}