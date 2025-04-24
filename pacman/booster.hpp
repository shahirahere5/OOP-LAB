#pragma once
#include <SFML/Graphics.hpp>

class Booster {
private:
    sf::CircleShape shape;
    bool active;

public:
Booster();
    Booster(float x, float y);
    void draw(sf::RenderWindow& window);
    bool checkCollision(float playerX, float playerY, float radius);
    bool isActive() const;
    void activate();
};
