#pragma once

#include <SFML/Graphics.hpp>
#include <memory>


class Game
{
private:
    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<sf::Sprite> m_sprite;
    std::unique_ptr<sf::Texture> m_texture;

    void pollEvent();
    void update(float dt);
    void draw();

public:
    explicit Game(const std::string& title, const sf::Vector2u& size);
    ~Game();

    void execute();
};