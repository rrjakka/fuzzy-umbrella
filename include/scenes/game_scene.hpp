#pragma once
#include "include/scene.hpp"

class GameScene : public Scene
{
public:
    explicit GameScene(Game& game);
    ~GameScene() override = default;

    void draw(sf::RenderWindow& window) override;
    void update(float dt) override;
    void handleEvent(const sf::Event& event) override;

    void onEnter() override;
    void onExit() override;
};