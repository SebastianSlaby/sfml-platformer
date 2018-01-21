#include "playercontroller.h"

playercontroller::playercontroller(sf::Vector2f position, sf::Vector2f size, sf::Color color){
setPosition(position);
setSize(size);
setFillColor(color);
velocity=sf::Vector2f(0,5);
setOrigin(30.f,75.f);
playercollider.setOrigin(30.f,75.f);
    playercollider.setSize(getSize());

}
void playercontroller::updatepos(std::vector<sf::FloatRect> colliders){
    grounded=false;
    velocity.y+=0.4;
    playercollider.setPosition(getPosition().x,getPosition().y+velocity.y);
    for(int i=0;i<colliders.size();i++  ){ // sprawdza kolizje w dół, brak kolizji w górę
        if(playercollider.getGlobalBounds().intersects(colliders[i]) && playercollider.getPosition().y+75 < colliders[i].top+colliders[i].height && velocity.y>0){
            velocity.y=0;
            setPosition(getPosition().x,colliders[i].top-75);
            grounded=true;
        }
    }
    velocity.x*=0.90;
    move(velocity);
}
void playercontroller::jump(){
        velocity.y=-20;
}
void playercontroller::accelleft(){
    velocity.x-=1;
}
void playercontroller::accelright(){
    velocity.x+=1;
}