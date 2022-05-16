#include "Player.h"

//constructor
Player::Player(int size, int x, int y, int health, float speed, sf::Color colour, float jumpheight, Gun* aGun) :Character( size,  x,  y,  health,  speed,  colour){
    this->jumpheight = jumpheight;
    this->canjump = true;
    this->faceright = true;
    this->gravity = 981.0f;//9.81 m/s^2 or 981 pixels/s^2
    this->smallgun = aGun;//pass gun from main game, this will allow character selection of gun from mainscreen
    this->shootdelayer = 0.0f; //stops continous bullets
}

//fall which moves the player if the error margin between the player and an object below is greater then 1.5 pixels
// this is to stop bouncing from continout collision due to gravity, needed for platforms
void Player::fall(float theta, float errormargin){
    if (errormargin > 1.5){
        movement.y += gravity*theta; //g*t^2
    }    
}
//destructor
Player::~Player(){
    delete smallgun;
}
//draw player as per the character draw function but redelacre draw to include drawgun
void Player::draw(sf::RenderWindow* win){
    Character::draw(win);
    smallgun->drawgun(win);

}
//update player movement
void Player::update(float theta, float time, float errormargin){
    // a delay timer so bullet stream isn't super fast
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
        
    //update gun
    smallgun->update(theta);

    //moves down unless your on the ground, ground currently set to starting y position
    fall(theta, errormargin);
    
    //multiplying by theta here rather then every euqation
    MoveBody(movement,theta);
}

//return direction of of collison and reset can jump if collision is with an object below;
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