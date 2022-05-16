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
    public:
        Enemy(int size, int x, int y, int health, float speed, sf::Color colour);   
        void spawn(int x, int y);        
        void draw(sf::RenderWindow* win);
        bool IsDead(int target_x, int target_y);
};

#endif