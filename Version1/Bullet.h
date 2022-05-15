#ifndef BULLET_DEF
#define BULLET_DEF

#include <SFML/Graphics.hpp>

class Bullet{
private:
    sf::CircleShape* body;
    bool fired;
    bool faceright;
public:
    Bullet();
    void drawbullet(sf::RenderWindow* );
    void MoveBullet(sf::Vector2f, float);
    sf::Vector2f getposition();
    bool isFired();
    void use(sf::Vector2f, bool);
    void stop();
    void SetBulletRadius(int);
    ~Bullet();
};

#endif