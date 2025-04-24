#include "map.hpp"

Map::Map() : wallCount(0) {
    loadMap();
}

void Map::loadMap() {
    
        wallCount = 0;
    
        // --- Outer boundary ---
        walls[wallCount++] = Wall(20, 20, 720, 20);   // Top  //done
        walls[wallCount++] = Wall(20, 580, 720, 20);  // Bottom  //done
        walls[wallCount++] = Wall(20, 20, 20, 580);   // Left  //done
        walls[wallCount++] = Wall(740, 20, 20, 580);  // Right //done
    
        // --- Top horizontal segments ---
        //walls[wallCount++] = Wall(180, 85, 80, 20);
        //walls[wallCount++] = Wall(130, 85, 60, 20);
        walls[wallCount++] = Wall(295, 80, 80, 20);
        walls[wallCount++] = Wall(480, 85, 80, 20);
        walls[wallCount++] = Wall(540, 85, 80, 20);
    
        // --- Top vertical tunnels ---
        walls[wallCount++] = Wall(85, 80, 20, 80);
        walls[wallCount++] = Wall(665, 80, 20, 80);
    
        // --- Vertical T connectors near top center ---
        walls[wallCount++] = Wall(280, 80, 20, 100);
        walls[wallCount++] = Wall(360, 80, 20, 100);
    
        // --- Center box ---
        walls[wallCount++] = Wall(220, 230, 100, 20);  // Top
        walls[wallCount++] = Wall(220, 240, 20, 140);  // Left
        walls[wallCount++] = Wall(220,380,300,20);
        walls[wallCount++] = Wall(500,230,20,150);
        walls[wallCount++] = Wall(400,230,120,20);
        walls[wallCount++] = Wall(380,230,20,80);
        walls[wallCount++] = Wall(380,300,50,20);
        walls[wallCount++] = Wall(85,160,80,20);
        walls[wallCount++] = Wall(150,160,20,180);
        walls[wallCount++] = Wall(40,340,130,20);
        walls[wallCount++] = Wall(40,250,40,20);
        walls[wallCount++] = Wall(190, 440, 20, 80);  
        walls[wallCount++] = Wall(200, 500, 120, 20);  
        walls[wallCount++] = Wall(300, 450, 70, 20);  
        walls[wallCount++] = Wall(380,160,100,20);
        walls[wallCount++] = Wall(480,100,20,80);
        walls[wallCount++] = Wall(580,150,105,20);
        walls[wallCount++] = Wall(580,150,20,290);
        walls[wallCount++] = Wall(580,300,80,20);
        walls[wallCount++] = Wall(670,220,80,20);
        walls[wallCount++] = Wall(670,380,80,20);
        walls[wallCount++] = Wall(500,500,160,20);
    
        // --- Bottom L rooms ---
        walls[wallCount++] = Wall(90, 440, 100, 20);   // Left hor
        walls[wallCount++] = Wall(90, 460, 20, 120);    // Left vert
        walls[wallCount++] = Wall(580, 440, 100, 20);  // Right hor
        walls[wallCount++] = Wall(660, 460, 20, 60);   // Right vert
    
        // --- Bottom center pillars ---
        walls[wallCount++] = Wall(300, 450, 20, 60);
        walls[wallCount++] = Wall(360, 450, 20, 70);
    
        // --- Bottom horizontal bars ---
        walls[wallCount++] = Wall(260, 580, 80, 20);
        walls[wallCount++] = Wall(420, 580, 80, 20);

        // --- Boosters (place based on image) ---
        boosters[0] = Booster(645.f, 480.f);      // Top-left corner
        boosters[1] = Booster(55.f, 230.f);    // Top-right
        boosters[2] = Booster(340.f, 490.f);    // Near center-bottom
    
    

    // Clear existing before populating
dots.clear();
ghosts.clear();

// Clear old dots
dots.clear();

for (int y = 40; y <= 560; y += 40) {
    for (int x = 40; x <= 760; x += 40) {
        // Skip dots if inside central box (roughly)
        if ((x >= 220 && x <= 500) && (y >= 220 && y <= 380)) continue;

        // Skip dots on outer wall edges (with buffer)
        if (x <= 40 || x >= 730 || y <= 40 || y >= 580) continue;

        // Optional: skip near bottom L rooms if you want to fine-tune more

        dots.emplace_back(x, y);
    }
}


// Add ghosts
ghosts.emplace_back(400.f, 300.f);
ghosts.emplace_back(300.f,400.f);

}


void Map::render(sf::RenderWindow& window) {
    for (int i = 0; i < wallCount; ++i) {
        walls[i].draw(window);
    }

    for (auto& booster : boosters) {
        booster.draw(window);
    }
}

bool Map::checkCollision(float playerX, float playerY, float playerRadius) {
    for (int i = 0; i < wallCount; ++i) {
        if (walls[i].checkCollision(playerX, playerY, playerRadius)) {
            return true;
        }
    }
    return false;
}

void Map::activateBooster(float playerX, float playerY) {
    for (auto& booster : boosters) {
        if (booster.checkCollision(playerX, playerY, 16.f)) {
            booster.activate();
        }
    }
}



