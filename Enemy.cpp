#include "Enemy.h"

   //constructor
Enemy::Enemy(int size, int x, int y, int health, float speed, sf::Color colour, int damage) :Character( size,  x,  y,  health,  speed,  colour){
        this->damage = damage;
        alive = false;
    }
void Enemy::update(float theta, float time, float errormargin){
        // a 5 second delay before the emenies start apearing
        movement.x = 0.0;
        if (time > 5.0f){
            //if enemy is alive set movement and move
            //dependent on spawn;
            if (this->alive && moveLeft){   
                movement.x -= getspeed();//*sqrt(time)/100;
            }
            else if(this->alive && !moveLeft){
                movement.x += getspeed();//*sqrt(time)/100;
            }
            //respawns if is out of bounds or dead
            if (this->getbodyPosition().x < 0 ||this->getbodyPosition().x > 1010 || !alive){
                this->spawn(1000+10,400);
            }

            MoveBody(movement,theta);
        }
    }

    void Enemy::spawn(int x, int y){
        // a random number between 100 and screen size
        int rand_y = rand() % y + 50; 
        //an if statement which checks if (float)rand()/RAND_MAX  a number randomly between
        // between 0 and 1 is greater then 0.5 and then assigns which side of the screen to start on
        if((float)rand()/RAND_MAX > 0.5){
            setbodyposition(sf::Vector2f(x,rand_y));
            moveLeft = true;
        }
        else{
            setbodyposition(sf::Vector2f(10,rand_y));
            moveLeft = false;
        }
        //Enemy is now alive
        this->alive = true;
    }

    //set current status function
    void Enemy::SetAlive(bool Alive){this->alive = Alive;}
    

    Enemy::~Enemy(){
    };