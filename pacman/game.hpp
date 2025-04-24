#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.hpp"
#include "wall.hpp"
#include "dot.hpp"
#include "booster.hpp"
#include "ghost.hpp"
#include "map.hpp"

class Game {
private:
    sf::RenderWindow window;
    Player player;
    std::vector<Wall> walls;
    
    std::vector<Booster> boosters;
    
    sf::Font font;
    sf::Text scoreText;
    sf::Text winText;
    int score;
    bool won;
    Map map;
    int lives;
    


public:
    Game();
    void run();
    void processEvents();
    void update(float deltaTime);
    void render();
    bool checkWallCollision(float x, float y);
};
