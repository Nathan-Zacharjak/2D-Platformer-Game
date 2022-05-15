#include "Platform.h"
#include <iostream>

Platform::Platform(sf::Color colour, sf::Vector2f size, sf::Vector2f position){
    body = new sf::RectangleShape;
    body->setSize(size);
    body->setPosition(position);
    body->setOrigin(size.x/2,size.y/2);
    std::cout<<body->getOrigin().y<<std::endl;
    body->setFillColor(colour);
}
void Platform::drawplatform(sf::RenderWindow* win){
    win->draw(*body);
}

Collision* Platform::getcollider() {
    Collision* bodycolision = new Collision(this->body);
    return bodycolision;
    }

Platform::~Platform(){
    delete body;
};