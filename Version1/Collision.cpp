#include "Collision.h"
    
sf::Vector2f Collision::getposition(){
    return body->getPosition();
}
sf::Vector2f Collision::gethalfsize(){
    return sf::Vector2f(body->getSize().x/2, body->getSize().y/2);
}
void Collision::move(float dx, float dy){
    body->move(dx,dy);
}

Collision::Collision(sf::RectangleShape* body) :body(body)
{
    

}


bool Collision::checkcollision(Collision* other, sf::Vector2f* direction, float pushback){
    sf::Vector2f otherposition = other->getposition();
    sf::Vector2f otherhalfsize = other->gethalfsize();
    sf::Vector2f thisposition = getposition();
    sf::Vector2f thishalfsize = gethalfsize();

    float deltax = otherposition.x - thisposition.x;
    float deltay = otherposition.y - thisposition.y;

    float intersectx = abs(deltax) - abs(otherhalfsize.x + thishalfsize.x);
    float intersecty = abs(deltay) - abs(otherhalfsize.y + thishalfsize.y);

    if(intersectx < 0.0f && intersecty < 0.0f){
        pushback = std::min(std::max(pushback,0.0f),1.0f);
        if (intersectx > intersecty){
            if (deltax > 0.0f){
                move(intersectx*(1.0f - pushback),0.0f);
                other->move(-intersectx*pushback,0.0f);
                //direction of collision to use as reference elsewhere
                direction->x = 1.0f;
                direction->y = 0.0f;
            }else{
                move(-intersectx*(1.0f - pushback),0.0f);
                other->move(intersectx*pushback,0.0f);
                //direction of collision to use as reference elsewhere
                direction->x = -1.0f;
                direction->y = 0.0f;
            }
            }else{
                if (deltay > 0.0f){
                move(0.0f,intersecty*(1.0f - pushback));
                other->move(0.0f,-intersecty*pushback);
                //direction of collision to use as reference elsewhere
                direction->x = 0.0f;
                direction->y = 1.0f; 
            }else{
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

Collision::~Collision(){
    delete body;
}