#pragma once
#include <SFML/Graphics.hpp>

class Ghost {
private:
    sf::CircleShape shape;
    sf::Vector2f direction;
    float speed;

public:
    Ghost(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool checkCollision(float playerX, float playerY, float radius);
};
