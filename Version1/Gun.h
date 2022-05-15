#ifndef GUN_DEF
#define GUN_DEF

#include "Bullet.h"
#include <SFML/Graphics.hpp>

class Gun
{
private:
    Bullet* ammo;
    int speed;
    int damage;
    int bulletsize;
    int numberofbullets;
public:
    Gun(int,int, int, int);
    void shoot(sf::Vector2f, bool);
    void update(float);
    void drawgun(sf::RenderWindow*);
    ~Gun();
};

#endif
