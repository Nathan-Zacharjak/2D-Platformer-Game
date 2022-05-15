#ifndef PLAYER_DEF
#define PLAYER_DEF

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Character.h"
#include "Gun.h"

class Player :public Character{
private:
    Gun* smallgun;
    bool faceright;
    bool canjump;
    float jumpheight;
    sf::Vector2f movement;
    sf::Vector2f bulletmovement;
    float gravity;
    float shootdelayer;
public:
    Player(int, int, int, int, float, sf::Color, float);
    void update(float,float, float );
    void fall(float, float);
    void draw(sf::RenderWindow*);
    void onCollision(sf::Vector2f*);
    ~Player();
};

#endif
