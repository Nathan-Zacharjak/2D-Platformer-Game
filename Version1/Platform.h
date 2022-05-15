#ifndef PLATFORM_DEF
#define PLATFORM_DEF

#include <SFML/Graphics.hpp>
#include "Collision.h"
class Platform
{
private:
    
public:
    sf::RectangleShape* body;
    Platform(sf::Color , sf::Vector2f , sf::Vector2f );
    void drawplatform(sf::RenderWindow*);
    Collision* getcollider();
    ~Platform();
};

#endif

