#pragma once
#include "include/scene.hpp"

class MenuScene : public Scene
{
public:
    explicit MenuScene(Game& game);
    ~MenuScene() override = default;

    void draw(sf::RenderWindow& window) override;
    void update(float dt) override;
    void handleEvent(const sf::Event& event) override;

    void onEnter() override;
    void onExit() override;
};