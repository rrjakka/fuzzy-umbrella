#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "scene_manager.hpp"

class Game
{
private:
    std::unique_ptr<sf::RenderWindow> m_window;
    sf::Clock m_clock;
    SceneManager m_sceneManager;

    void pollEvent();
    void update(float dt);
    void draw();

public:
    explicit Game(const std::string& title, const sf::Vector2u& size);
    ~Game()=default;

    void execute();

    [[nodiscard]] sf::RenderWindow& getWindow() const;
    SceneManager& getSceneManager();
};