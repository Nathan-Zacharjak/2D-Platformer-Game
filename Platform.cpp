#include "Platform.h"
#include <iostream>
//constructor which sets platform positon
Platform::Platform(sf::Color colour, sf::Vector2f size, sf::Vector2f position){
    body = new sf::RectangleShape;
    body->setSize(size);
    body->setPosition(position);
    body->setOrigin(size.x/2,size.y/2);
    body->setFillColor(colour);
}
//draw platform
void Platform::drawplatform(sf::RenderWindow* win){
    win->draw(*body);
}
//A collision detecor for platform
Collision* Platform::getcollider() {
    Collision* bodycolision = new Collision(this->body);
    return bodycolision;
}
//destructor
Platform::~Platform(){
    delete body;
};