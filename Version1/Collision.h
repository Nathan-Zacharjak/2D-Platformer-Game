#ifndef COLLISION_DEF
#define COLLISION_DEF


#include <SFML/Graphics.hpp>

class Collision
{
private:
    sf::RectangleShape* body;
public:
    Collision(sf::RectangleShape* );
    bool checkcollision(Collision* , sf::Vector2f*, float );
    sf::Vector2f getposition();
    sf::Vector2f gethalfsize();
    void move(float , float );
    ~Collision();
};

#endif