#include "include/game.hpp"

void Game::pollEvent()
{
    while (const std::optional<sf::Event> event = m_window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            m_window->close();
    }
}

void Game::update(const float dt)
{
    m_sprite->move({ 1 * dt, 1 * dt });
}

void Game::draw()
{
    m_window->clear();

    m_window->draw(*m_sprite);

    m_window->display();
}

Game::Game(const std::string& title, const sf::Vector2u& size)
{
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(size),
        title
    );

    m_window->setFramerateLimit(60);

    m_texture = std::make_unique<sf::Texture>("../assets/textures/flowery.jpg");

    const sf::Vector2u texture_size = m_texture->getSize();

    m_sprite = std::make_unique<sf::Sprite>(*m_texture);

    const auto scale = sf::Vector2f(
         static_cast<float>(size.x) / static_cast<float>(texture_size.x),
         static_cast<float>(size.y) / static_cast<float>(texture_size.y)
    );

    m_sprite->setScale(scale);
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