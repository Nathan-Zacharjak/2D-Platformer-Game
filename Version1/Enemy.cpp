#include "Enemy.h" 

Enemy::Enemy(int size, int x, int y, int health, float speed, sf::Color colour):Character(size, x, y, health, speed, colour){
    this->_IsDead = false;
};

void Enemy::spawn(Vector2f position){
    this->setbodyposition(position);
};

bool Enemy::IsDead(){
    return this->_IsDead;
}