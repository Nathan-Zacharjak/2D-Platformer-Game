#include "Gun.h"
#include <iostream>
//constructor
Gun::Gun(int damage, int speed, int bulletsize, int numberofbullets){
    this->numberofbullets = numberofbullets;
    this->ammo = new Bullet[numberofbullets];
    this->damage = damage;
    this->speed = speed;
    //setting each bullets bullet size
    //was easier then have a bullet with a constructor then making that an 
    //array of size "number of bullets"
    for (int i = 0; i < this->numberofbullets; i++)
    {
        ammo[i].SetBulletsize(bulletsize);
    }
    
}
//shoot bullets
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
//update gun to check if bullets are shot
//if they are move accordingly
void Gun::update( float theta){
    for (int i = 0; i < this->numberofbullets; i++){
        if (ammo[i].isFired()){  
                ammo[i].MoveBullet(sf::Vector2f(speed,0),theta);
             }
        //if bullet goes off screen then reset
        if (ammo[i].getposition().x >= 1100 || ammo[i].getposition().x <= -10  )
            {
                ammo[i].stop();
            }
    }
}
//draw each bullet which has been shot
void Gun::drawgun(sf::RenderWindow* win){
    for (int i = 0; i < this->numberofbullets; i++){
        if (ammo[i].isFired()){ 
            ammo[i].drawbullet(win);
        }
    }
}
//return ammo for use in collision checking
Bullet* Gun::getammo(){
    return ammo;
}
//destructor
Gun::~Gun(){
    delete[] ammo;
}