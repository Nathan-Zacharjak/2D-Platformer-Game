#include <SFML/Graphics.hpp>
#include <math.h>

class Player
{
private:
    sf::RectangleShape* body;
    float speed;
    bool faceright;
    bool canjump;
    float jumpheight;
    sf::Vector2f movement;
    float gravity;
public:
    //constructor
    Player(int h, int x, int y, float speed, float jumpheight){
        this->body = new sf::RectangleShape();
        this->body->setSize(sf::Vector2f(h,h));
        this->body->setPosition(x,y);
        this->body->setFillColor(sf::Color::Magenta);
        this->body->setOrigin(h/2,h/2);
        this->speed = speed;
        this->jumpheight = jumpheight;
        this->canjump = true;
        this->gravity = 981.0f;
    }
    //pass as pointer so we make modifications to the actual window and not a copy of the window
    void draw(sf::RenderWindow* win){
        win->draw(*body);
    
    }
    void fall(float theta){
        if (body->getPosition().y<500){
            movement.y += gravity*theta;
        }else if (body->getPosition().y>500) //set players y position manually as we have no collision/ground
        {
            body->setPosition(body->getPosition().x,500);
            canjump = true;
        }
        
    }
    void update(float theta){
        
        movement.x = 0.0f; //set to  movement.x *= 0.0f for no deceleration 
        //move left -x
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            
            movement.x -= speed;
            faceright = true;
        }
        //move right +x
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            movement.x += speed;
            faceright = false;
        }
        //move up -y *note SMFL y axis is reversed.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canjump){
            canjump = false;
            movement.y = -sqrtf(2.0f*gravity*jumpheight);//potential energy of gravity.
        }

        //moves down unless your on the ground, ground currently set to starting y position
        fall(theta);
        
        //multiplying by theta here rather then every euqation
        body->move(movement*theta);
    }
        
    //destructor
    ~Player(){ 
        delete this->body;
    } 
};


