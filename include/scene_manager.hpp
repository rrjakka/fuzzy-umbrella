#pragma once
#include <memory>
#include <stack>
#include "include/scene.hpp"

class SceneManager
{
private:
    std::stack<std::unique_ptr<Scene>> m_scenes;

public:
    SceneManager() = default;
    ~SceneManager();

    SceneManager(const SceneManager&) = delete;
    SceneManager& operator=(const SceneManager&) = delete;

    void handleEvent(const sf::Event& event);
    void update(float dt);
    void draw(sf::RenderWindow& window);

    void pushScene(std::unique_ptr<Scene> scene);
    void popScene();
    void changeScene(std::unique_ptr<Scene> scene);

    [[nodiscard]] bool isEmpty() const;
};