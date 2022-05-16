
#include "Bullet.h"
#include <SFML/Graphics.hpp>

//constructor
Bullet::Bullet(){
    this->body = new sf::RectangleShape();
    this->body->setFillColor(sf::Color::Red);
    this->body->setPosition(-1,-1);//setting bullet off screen
    this->fired = false;
    this->faceright = true;
}

//setting bulletsize outside the constructor so no
//arguments are needed for constructor
void Bullet::SetBulletsize(int size){
    body->setSize(sf::Vector2f(size*2,size));
    this->body->setOrigin(sf::Vector2f(size,size/2));
}
    
//draw bullet to window
void Bullet::drawbullet(sf::RenderWindow* win){
        win->draw(*body);
}

//movement of bullet, requires change in time and movement vector
void Bullet::MoveBullet(sf::Vector2f Movement, float theta){
//if faceright is true we want to shoot from left to right
if (this->faceright)
{
    body->move(Movement*theta);
//else if it doesnt face right move from right to left
}else if(!this->faceright)
    body->move(-Movement*theta);
}

//getting vector position of bullet
sf::Vector2f Bullet::getposition(){
    return body->getPosition();
}

//if the bullet has been fired false, else true
bool Bullet::isFired(){return fired;}

//use bullet spawns a bullet from the players origin
//set fired to true so its know this bullet cannot 
//be used until fired is false and pass players direction at the time
void Bullet::use(sf::Vector2f position, bool faceright){
    body->setPosition(position);
    fired = true;
    this->faceright = faceright;
}

//set bullet to false
void Bullet::stop(){
    fired = false;
}

//destructor    
Bullet::~Bullet(){
    delete this->body;
}

//collsion function, to be used for checking if a collisoin has occured with another object
Collision* Bullet::getcollision(){
    Collision* bodycolision = new Collision(this->body);
    return bodycolision;//we must copy this not pass the address, as it won't be accesssible and cause segmentation fault
}