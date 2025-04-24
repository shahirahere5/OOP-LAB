#include "ghost.hpp"
#include <cmath>

Ghost::Ghost(float x, float y) : speed(80.f) {
    shape.setRadius(12.f);
    shape.setOrigin(12.f, 12.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);
    direction = sf::Vector2f(1.f, 0.f); // Initially move right
}

void Ghost::update(float deltaTime) {
    shape.move(direction * speed * deltaTime);

    sf::Vector2f pos = shape.getPosition();
    if (pos.x < 0 || pos.x > 800) direction.x *= -1;
    if (pos.y < 0 || pos.y > 600) direction.y *= -1;
}

void Ghost::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Ghost::checkCollision(float playerX, float playerY, float radius) {
    float dx = shape.getPosition().x - playerX;
    float dy = shape.getPosition().y - playerY;
    float distance = sqrt(dx * dx + dy * dy);
    return distance < (radius + shape.getRadius());
}
