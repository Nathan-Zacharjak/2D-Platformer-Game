#ifndef CHARACTER_DEF
#define CHARACTER_DEF

#include <SFML/Graphics.hpp>
//#include <math.h>
#include <iostream>
#include "Collision.h"

class Character{
private:
    int health;
    float speed;
    sf::RectangleShape* body;
public:
    Character(int, int, int, int, float, sf::Color);
    Collision* getcollision();
    void sethealth(int);
    int gethealth();
    void setbodycolor(sf::Color);
    float getspeed();
    virtual void draw(sf::RenderWindow* );
    sf::Vector2f getbodyPosition();
    void setbodyposition(sf::Vector2f);
    void MoveBody(sf::Vector2f , float );
    virtual void update(float, float, float) = 0;
    virtual void onCollision(sf::Vector2f*);
    virtual ~Character();
};

#endif