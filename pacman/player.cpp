#include "player.hpp"

Player::Player(float x, float y, float radius)
    : speed(150.f), normalSpeed(150.f), boosterActive(false), boosterTimer(0.f), lives(3) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x, y);
}

void Player::handleInput(float deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += speed;

    shape.move(movement * deltaTime);
}

void Player::update(float deltaTime) {
    if (boosterActive) {
        boosterTimer -= deltaTime;
        if (boosterTimer <= 0.f) {
            boosterActive = false;
            speed = normalSpeed;
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

float Player::getX() const {
    return shape.getPosition().x;
}

float Player::getY() const {
    return shape.getPosition().y;
}

float Player::getRadius() const {
    return shape.getRadius();
}

void Player::activateBooster() {
    boosterActive = true;
    boosterTimer = 5.f;
    speed = 300.f;
}

bool Player::isBoosterActive() const {
    return boosterActive;
}

void Player::loseLife() {
    if (lives > 0) lives--;
}

int Player::getLives() const {
    return lives;
}
