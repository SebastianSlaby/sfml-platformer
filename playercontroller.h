#include <SFML/Graphics.hpp>
#include <vector>
class playercontroller: public sf::RectangleShape{
public:
bool grounded;
playercontroller(sf::Vector2f position, sf::Vector2f size, sf::Color color);
void updatepos(std::vector<sf::FloatRect> colliders);
void jump();
void accelright();
void accelleft();
private:
sf::Vector2f velocity;
sf::RectangleShape playercollider;

}; 