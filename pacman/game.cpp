#include "game.hpp"

sf::SoundBuffer dotBuffer;
sf::Sound dotSound;

sf::SoundBuffer boosterBuffer;
sf::Sound boosterSound;

sf::SoundBuffer deathBuffer;
sf::Sound deathSound;

// 100 is maximum



Game::Game()
    : window(sf::VideoMode(800, 650), "Pac-Man"), player(710.f, 555.f, 15.f), score(0), won(false) {
    font.loadFromFile("arial.ttf");

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(10, 610);
    scoreText.setFillColor(sf::Color::White);

    winText.setFont(font);
    winText.setCharacterSize(30);
    winText.setPosition(250, 300);
    winText.setFillColor(sf::Color::Green);
    winText.setString("You Win!");

    if (!dotBuffer.loadFromFile("sounds/pickup.wav")) {
        // error handling
    }
    dotSound.setBuffer(dotBuffer);
    
    if (!boosterBuffer.loadFromFile("sounds/booster.wav")) {
        // error handling
    }
    boosterSound.setBuffer(boosterBuffer);
    
    if (!deathBuffer.loadFromFile("sounds/death.wav")) {
        // error handling
    }
    deathSound.setBuffer(deathBuffer);

    

    

    
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(float deltaTime) {
    player.handleInput(deltaTime);

    if (checkWallCollision(player.getX(), player.getY())) {
        player.handleInput(-deltaTime); // Move back
    }

    player.update(deltaTime);

    if (map.activateBooster(player.getX(), player.getY())) {
        boosterSound.play();    // <<< Play booster sound only if activated
    }


    for (auto& dot : map.getDots()) {
        if (dot.checkCollision(player.getX(), player.getY(), player.getRadius())) {
            dotSound.play();
            score++;

        }
    }
    

    for (auto& ghost : map.getGhosts()) {
        map.updateGhosts(deltaTime, walls);


        if (ghost.checkCollision(player.getX(), player.getY(), player.getRadius())) {
            player.loseLife();
        }
    }
    

    won = true;
for (const auto& dot : map.getDots()) {
    if (!dot.isCollected()) {
        won = false;
        break;
    }
}


    scoreText.setString("Score: " + std::to_string(score));
}

void Game::render() {
    
    window.clear();
    map.render(window);
    for (auto& wall : walls) wall.draw(window);
    for (auto& dot : map.getDots()) dot.draw(window);
for (auto& ghost : map.getGhosts()) ghost.draw(window);

    player.draw(window);
    window.draw(scoreText);
    if (won) window.draw(winText);
    window.display();
}

bool Game::checkWallCollision(float x, float y) {
    return map.checkCollision(x, y, player.getRadius());
}

