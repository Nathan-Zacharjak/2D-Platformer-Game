#include "Enemy.h" 

Enemy::Enemy(int size, int x, int y, int health, float speed, sf::Color colour, int damage):Character(size, x, y, health, speed, colour){
    this->_IsDead = false;
    this->_damage = damage;
};

void Enemy::spawn(Vector2f position){
    this->setbodyposition(position);
};

bool Enemy::IsDead(){
    return this->_IsDead;
}

int Enemy::GetDamage(){
    return this->_damage;
}

void Enemy::Update(){
    
}