#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "wall.hpp"
#include "booster.hpp"
#include "ghost.hpp"
#include "dot.hpp"

#define MAX_WALLS 100

class Map {
private:
    std::array<Wall, MAX_WALLS> walls;
    int wallCount;
    std::array<Booster, 3> boosters;
    std::vector<Dot> dots;
    std::vector<Ghost> ghosts;

public:
    Map();
    void loadMap(); // no mapId now
    void render(sf::RenderWindow& window);
    bool checkCollision(float playerX, float playerY, float playerRadius);
    void activateBooster(float playerX, float playerY);
    std::vector<Dot>& getDots() { return dots; }
    std::vector<Ghost>& getGhosts() { return ghosts; }
};
