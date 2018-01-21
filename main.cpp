#include <SFML/Graphics.hpp>
#include "playercontroller.h"
#include <vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ball");
        window.setFramerateLimit(30);
    playercontroller player(sf::Vector2f(400,100),sf::Vector2f(60,150),sf::Color::White);
    std::vector<sf::FloatRect> colliders;
    sf::RectangleShape obstacle;
    obstacle.setSize(sf::Vector2f(1000,50));
    obstacle.setPosition(0,500);
    obstacle.setFillColor(sf::Color::Green);
        sf::RectangleShape obstacle2;
    obstacle2.setSize(sf::Vector2f(200,50));
    obstacle2.setPosition(400,300);
    obstacle2.setFillColor(sf::Color::Green);
    colliders.push_back(obstacle.getGlobalBounds());
    colliders.push_back(obstacle2.getGlobalBounds());
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(window.hasFocus()){
        player.updatepos(colliders);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.grounded){
            player.jump();
        }
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.accelright();

        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player.accelleft();

        }
        }
        window.clear();
        window.draw(obstacle);
          window.draw(obstacle2);
        window.draw(player);

        window.display();
    }
    return 0;
}
