#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <chrono>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Boss.h"

int main()
{


    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
 //   sf::CircleShape shape(100.f);
    sf::RectangleShape shape2(sf::Vector2f(1200.f,800.f));
  //  shape.setPosition(400, 400);
    //shape.setFillColor(sf::Color::Green);
    shape2.setPosition(0, 0);
    shape2.setFillColor(sf::Color::Cyan);

    Player player;
    Boss boss;

    std::string name = "image.png";


    sf::Texture texture;
    if (!texture.loadFromFile(name)) {
    }
    if (!texture.create(200, 200))
    {
        // error...
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

    float xPos = 0, yPos = 10;
    int frameTime = 0;
    texture.loadFromFile(name);

    int i = 0;

    std::vector<std::reference_wrapper<sf::Sprite>> listOfSprites;
    std::vector<Bullet> bullets;
    std::vector<std::reference_wrapper<sf::Sprite>> bulletSprites;

    player.init();
    boss.init(listOfSprites);

    listOfSprites.push_back(sprite);

    auto startTime = std::chrono::high_resolution_clock::now();
    auto endTime = std::chrono::high_resolution_clock::now();

    sf::Clock deltaClock;

    while (window.isOpen())
    {

        sf::Time dt = deltaClock.restart();
        sf::Event event;
        xPos += 100 * dt.asSeconds();
        sprite.setPosition(sf::Vector2f(player.getXpos(), player.getYpos()));

        // Movement and Behavior
        player.movement(dt);
        player.collisions(dt,bullets);
        boss.update(frameTime, player, bullets, dt);
        for (auto &bullet : bullets) {
            bullet.update(dt);
        }

        // Manage Exit
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render
        window.clear();

        // Draw
        window.draw(shape2);
        for (auto& k : listOfSprites) {
            window.draw(k);
        }
        for (auto& k : bullets) {
            window.draw(k.getSprite());
        }
      //  window.draw(shape);

        // Finalize
        window.display();
        frameTime += 1;


    }

    return 0;
}