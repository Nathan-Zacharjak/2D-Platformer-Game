
#include "Bullet.h"
#include <SFML/Graphics.hpp>

Bullet::Bullet(){
    this->body = new sf::CircleShape();
    this->body->setFillColor(sf::Color::Red);
    this->body->setPosition(-1,-1);//setting bullet off screen
    this->fired = false;
    this->faceright = true;
}

void Bullet::SetBulletRadius(int radius){
    body->setRadius(radius);
}
    
void Bullet::drawbullet(sf::RenderWindow* win){
        win->draw(*body);
}

void Bullet::MoveBullet(sf::Vector2f Movement, float theta){
if (this->faceright)
{
    body->move(Movement*theta);
}else if(!this->faceright)
    body->move(-Movement*theta);
}

sf::Vector2f Bullet::getposition(){
    return body->getPosition();
}


bool Bullet::isFired(){return fired;}

void Bullet::use(sf::Vector2f position, bool faceright){
    body->setPosition(position);
    fired = true;
    this->faceright = faceright;
}

void Bullet::stop(){
    fired = false;
}

    
Bullet::~Bullet(){
    delete this->body;
}