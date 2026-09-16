#include "include/scene_manager.hpp"

SceneManager::~SceneManager()
{
    while (!m_scenes.empty())
    {
        m_scenes.top()->onExit();
        m_scenes.pop();
    }
}

void SceneManager::handleEvent(const sf::Event& event)
{
    if (!m_scenes.empty())
    {
        m_scenes.top()->handleEvent(event);
    }
}

void SceneManager::update(const float dt)
{
    if (!m_scenes.empty())
        m_scenes.top()->update(dt);
}

void SceneManager::draw(sf::RenderWindow& window)
{
    if (!m_scenes.empty())
    {
        m_scenes.top()->draw(window);
        window.display();
    }
}

void SceneManager::pushScene(std::unique_ptr<Scene> scene)
{
    if (!m_scenes.empty())
        m_scenes.top()->onExit();

    m_scenes.push(std::move(scene));
    m_scenes.top()->onEnter();
}

void SceneManager::popScene()
{
    if (!m_scenes.empty())
    {
        m_scenes.top()->onExit();
        m_scenes.pop();
        if (!m_scenes.empty())
            m_scenes.top()->onEnter();
    }
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene)
{
    if (!m_scenes.empty())
    {
        m_scenes.top()->onExit();
        m_scenes.pop();
    }
    m_scenes.push(std::move(scene));
    m_scenes.top()->onEnter();
}

bool SceneManager::isEmpty() const
{
    return m_scenes.empty();
}
