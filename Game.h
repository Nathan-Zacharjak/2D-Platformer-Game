#ifndef GAME_DEF
#define GAME_DEF

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>
#include <iostream>
#include "Platform.h"
#include "Enemy.h"
#include "Gun.h"
#include "Parameters.h"

class Game
{
private:
    Parameters Global;
    sf::Color* grey;
    int score;
    Gun* SmallGun; 
    Player* Player1; 
    Enemy* enemy[2];//should not be static 2
    sf::Font font;
    sf::Text text;
    sf::Text beginGameButtonText;
    Platform* ground;
    Platform* platform1;
    Platform* platform2;
    Platform* platform3;
    Platform* leftWall;
    Platform* rightWall;
    Platform* ceiling;
    sf::Vector2f* direction;
    sf::Vector2f* direction2;
    float errormargin;
    sf::RenderWindow* window;
    float theta;
    float time;
    sf::Clock clock;
    bool gameActive;
    sf::Vector2i mousePosition;
public:
    Game();
    void run();
    void runMainGame();
    void runMainMenu();
    ~Game();
};

#endif

