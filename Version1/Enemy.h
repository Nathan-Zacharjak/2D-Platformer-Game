#ifndef ENEMY_DEF
#define ENEMY_DEF

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include "Character.h"
using namespace sf;

class Enemy: public Character{
    private:
        Vector2f movement;
        bool _IsDead;
        int _damage;
    public:
        Enemy(int size, int x, int y, int health, float speed, sf::Color colour, int damage);   
        void spawn(Vector2f position);        
        void Update();
        bool IsDead();
        int GetDamage();
};

#endif