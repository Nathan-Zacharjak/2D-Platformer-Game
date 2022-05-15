#include "Player.h"

Player::Player(int size, int x, int y, int health, float speed, sf::Color colour, float jumpheight) :Character( size,  x,  y,  health,  speed,  colour){
    this->jumpheight = jumpheight;
    this->canjump = true;
    this->faceright = true;
    this->gravity = 981.0f;//9.81 m/s^2 or 981 pixels/s^2
    this->smallgun = new Gun(1,250, 5, 200);
    this->shootdelayer = 0.0f; //stops continous bullets
}


void Player::fall(float theta, float errormargin){//should be replaces with a ground collide!!!
    //if (getbodyPosition().y<500){
    if (errormargin > 1.5){
        movement.y += gravity*theta;
    }
    //     //std::cout<<getbodyPosition().y<<std::endl;
    // }else if (getbodyPosition().y>500) //set players y position manually as we have no collision/ground
    // {
    //     //std::cout<<getbodyPosition().y<<std::endl;
    //     //setbodyposition(sf::Vector2f(getbodyPosition().x,500));
    //    // movement.y = 0.0f; //stopping residual movements in movement.y
    //     canjump = true;
    // }
    
}

Player::~Player(){

}

void Player::draw(sf::RenderWindow* win){
    Character::draw(win);
    smallgun->drawgun(win);

}

void Player::update(float theta, float time, float errormargin){
    float delayshot = time - shootdelayer;
    movement.x = 0.0f;
    bulletmovement.x = 0.0f;
        //set to  movement.x *= 0.8f for deceleration 
    //move left -x
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= getspeed();
        faceright = false;
    }
    //move right +x
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += getspeed();
        faceright = true;
    }
    //move up -y *note SMFL y axis is reversed.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canjump){
        canjump = false;
        movement.y = -sqrtf(2.0f*gravity*jumpheight);//potential energy of gravity eqn.
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && delayshot > 0.25){//set delayshot > to whatever you want your minimum break between shots to be
        smallgun->shoot(getbodyPosition(),faceright);
        shootdelayer = time;
        //std::cout<<"q";
    }       
        
    
    
    smallgun->update(theta);

    //moves down unless your on the ground, ground currently set to starting y position
    fall(theta, errormargin);
    
    //multiplying by theta here rather then every euqation
    MoveBody(movement,theta);
}

void Player::onCollision(sf::Vector2f* Direction){
    if (Direction->x > 0 || Direction->x < 0)
    {
        movement.x = 0.0f;
    }
    if (Direction->y > 0){
        movement.y = 0.0f;
    }else if (Direction->y < 0){
        movement.y = 0.0f;
        canjump = true;
    }
    
    
}