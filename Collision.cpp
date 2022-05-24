#include "Collision.h"

//get players current position    
sf::Vector2f Collision::getposition(){
    return body->getPosition();
}
//get half size, needed for calculation on if objects are touching
sf::Vector2f Collision::gethalfsize(){
    return sf::Vector2f(body->getSize().x/2, body->getSize().y/2);
}
//move bosy by the small intersection on the y or x axis
void Collision::move(float dx, float dy){
    body->move(dx,dy);
}
//pass the body address of the rectangle passes to this body
Collision::Collision(sf::RectangleShape* body) :body(body)
{}

//check if a collisoin has occured between the "Other" object and push back the objects which collide
bool Collision::checkcollision(Collision* other, sf::Vector2f* direction, float pushback){
        //getting this position and half size for an equation on if the objects are touching
        sf::Vector2f otherposition = other->getposition();
        sf::Vector2f otherhalfsize = other->gethalfsize();
        sf::Vector2f thisposition = getposition();
        sf::Vector2f thishalfsize = gethalfsize();
        //difference between origins of position
        float deltax = otherposition.x - thisposition.x;
        float deltay = otherposition.y - thisposition.y;
        //difference between origins accoutning for half size of each object, creating a "collision square"
        float intersectx = abs(deltax) - abs(otherhalfsize.x + thishalfsize.x);
        float intersecty = abs(deltay) - abs(otherhalfsize.y + thishalfsize.y);
        //if interect variables are less then 0.0f an intersection has occured
        if(intersectx < 0.0f && intersecty < 0.0f){
            //pushback is between 1 and 0, where 0 means this object gets moved and 1 means the other object gets moved
            // and for values in between there is resistance between the two objects, i.e. a slower objet movement rate
            pushback = std::min(std::max(pushback,0.0f),1.0f);
            //if the x intersection was larger, move in the x direction (looks better)
            if (intersectx > intersecty)
            {   //positive x value intersection between this object and the other object
                //intersection from right to left (from other object)
                if (deltax > 0.0f)
                {   //if pushback 1 move the other object back by the intersection value
                    //if pushback 0 move this object by the intersection caused by the other object
                    move(intersectx*(1.0f - pushback),0.0f);
                    other->move(-intersectx*pushback,0.0f);
                    //direction of collision to use as reference elsewhere
                    direction->x = 1.0f;
                    direction->y = 0.0f;
                }
                else 
                {   //intersection from left to right (from other object)
                    move(-intersectx*(1.0f - pushback),0.0f);
                    other->move(intersectx*pushback,0.0f);
                    //direction of collision to use as reference elsewhere
                    direction->x = -1.0f;
                    direction->y = 0.0f;

                }
                
            }
            else
            {   //intersection from above by other object
                if (deltay > 0.0f)
                {
                    
                    move(0.0f,intersecty*(1.0f - pushback));
                    other->move(0.0f,-intersecty*pushback);
                    //direction of collision to use as reference elsewhere
                    direction->x = 0.0f;
                    direction->y = 1.0f; 
                }
                else
                {//intersection from below by other object
                    move(0.0f,-intersecty*(1.0f - pushback));
                    other->move(0.0f,intersecty*pushback);
                    //direction of collision to use as reference elsewhere
                    direction->x = 0.0f;
                    direction->y = -1.0f; 

                }
            } 
            
            return true;
        }
        return false;
    }
    //destructor
    Collision::~Collision(){
       delete body;
    }

    