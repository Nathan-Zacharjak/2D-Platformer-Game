#include "Character.h"

//abstract classes constructor
Character::Character(int size, int x, int y, int health, float speed, sf::Color colour){
    this->body = new sf::RectangleShape(sf::Vector2f(size,size));
    this->body->setPosition(x,y);
    this->body->setFillColor(colour);
    this->body->setOrigin(size/2,size/2);
    this->speed = speed;
}
//abstract classes destructor
Character::~Character(){ 
    delete this->body;
} 

//functions which allow for health to be changed upon taking damage
void Character::sethealth(int health){
    this->health = health;
}
int Character::gethealth(){
    return this->health;
}

//return colour, this can be used for changing a characters color once health gets lower
void Character::setbodycolor(sf::Color Colour){
    this->body->setFillColor(Colour);
}

//return speed, as speed is a private member we can use this function to access in sub classes.
float Character::getspeed(){
    return this->speed;
}

//pass as pointer so we make modifications to the actual window and not a copy of the window
//draws characters body
void Character::draw(sf::RenderWindow* win){
    win->draw(*body);

}

//body related function which will be needed in subclasses
sf::Vector2f Character::getbodyPosition(){
    return body->getPosition();
}

void Character::setbodyposition(sf::Vector2f position){
    body->setPosition(position.x,position.y);
}

void Character::MoveBody(sf::Vector2f movement, float theta){
    body->move(movement*theta);
}

Collision* Character::getcollision(){
    Collision* bodycolision = new Collision(this->body);
    return bodycolision;//we must copy this not pass the address, as it won't be accesssible and cause segmentation fault
}

