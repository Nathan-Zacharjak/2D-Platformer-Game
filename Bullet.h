#ifndef BULLET_DEF
#define BULLET_DEF

#include <SFML/Graphics.hpp>
#include "Collision.h"

class Bullet{
private:
    sf::RectangleShape* body;
    bool fired;
    bool faceright;
public:
    Bullet();
    Collision* getcollision();
    void drawbullet(sf::RenderWindow* );
    void MoveBullet(sf::Vector2f, float);
    sf::Vector2f getposition();
    bool isFired();
    void use(sf::Vector2f, bool);
    void stop();
    void SetBulletsize(int);
    ~Bullet();
};

#endif