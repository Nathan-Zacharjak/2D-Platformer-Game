#include "Gun.h"
#include <iostream>

Gun::Gun(int damage, int speed, int bulletsize, int numberofbullets){
    this->numberofbullets = numberofbullets;
    this->ammo = new Bullet[numberofbullets];
    this->damage = damage;
    this->speed = speed;

    for (int i = 0; i < this->numberofbullets; i++)
    {
        ammo[i].SetBulletRadius(bulletsize);
    }
    
}

void Gun::shoot(sf::Vector2f PlayerPosition, bool faceright){
    for (int i = 0; i < this->numberofbullets; i++){
        if (!ammo[i].isFired())
        {
            ammo[i].use(PlayerPosition, faceright);
            //std::cout<<"1"<<std::endl;
            break;
        }  
    }    
}

void Gun::update( float theta){
    for (int i = 0; i < this->numberofbullets; i++){
        if (ammo[i].isFired()){  
                ammo[i].MoveBullet(sf::Vector2f(speed,0),theta);
             }

        if (ammo[i].getposition().x >= 1100 || ammo[i].getposition().x <= -10  )
            {
                ammo[i].stop();
            }
    }
}

void Gun::drawgun(sf::RenderWindow* win){
    for (int i = 0; i < this->numberofbullets; i++){
        if (ammo[i].isFired()){ 
            ammo[i].drawbullet(win);
        }
    }
}

Gun::~Gun(){
    delete[] ammo;
}