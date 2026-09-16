#include "include/game.hpp"


static constexpr unsigned int FRAMERATE = 60;
static constexpr float MAX_FRAME_TIME = 0.25f;
static constexpr float FIXED_DT = 1.f / FRAMERATE;

void Game::pollEvent()
{
    while (const std::optional<sf::Event> event = m_window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_window->close();
            break;
        }

        m_sceneManager.handleEvent(*event);
    }
}

void Game::update(const float dt)
{
    m_sceneManager.update(dt);
}

void Game::draw()
{
    m_sceneManager.draw(*m_window);
}

Game::Game(const std::string& title, const sf::Vector2u& size)
{
    m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(size),
        title
    );
    m_window->setVerticalSyncEnabled(true);
    m_window->setFramerateLimit(FRAMERATE);
}

void Game::execute()
{
    float accumulator = 0.0f;

    while (m_window->isOpen())
    {
        pollEvent();
        const float dt = std::min(m_clock.restart().asSeconds(), MAX_FRAME_TIME);

        accumulator += dt;

        while (accumulator >= FIXED_DT)
        {
            update(FIXED_DT);
            accumulator -= FIXED_DT;
        }

        draw();
    }
}

sf::RenderWindow& Game::getWindow() const
{
    return *m_window;
}

SceneManager& Game::getSceneManager()
{
    return m_sceneManager;
}
