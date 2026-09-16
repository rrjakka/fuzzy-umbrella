#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Scene
{
public:
    explicit Scene(Game& game);
    virtual ~Scene() = default;

    virtual void handleEvent(const sf::Event& event)=0;
    virtual void update(float dt)=0;
    virtual void draw(sf::RenderWindow& window)=0;

    virtual void onEnter()=0;
    virtual void onExit()=0;

protected:
    Game& m_game;
};