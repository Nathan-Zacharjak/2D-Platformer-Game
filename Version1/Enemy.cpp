#include "Enemy.h"

Enemy::Enemy(){
    Enemy::IsDead = false;
};
        
void Enemy::spawn(Vector2f position){
    body->setPosition(position);
    Enemy::IsDead = false;
};
        
void Enemy::draw(sf::RenderWindow* win){
    Character::draw(win);
}