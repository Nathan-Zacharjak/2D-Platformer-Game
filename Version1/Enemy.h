#ifndef ENEMY_DEF
#define ENEMY_DEF

#include <SFML/Graphics.hpp>
#include "Character.h"
#include <random>


class Enemy :public Character{
private:
    int damage;
    bool alive;
    bool moveLeft;
    sf::Vector2f movement;
public:
    //constructor
    Enemy(int size, int x, int y, int health, float speed, sf::Color colour, int damage);
    void update(float theta, float time, float errormargin);
    void spawn(int x, int y);
    void SetAlive(bool Alive);
    ~Enemy();
};

#endif

