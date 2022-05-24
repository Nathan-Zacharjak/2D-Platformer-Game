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
#include "Leaderboard.h"

class Game
{
private:
    Leaderboard leaderboard;
    Parameters Global;
    sf::Color* grey;
    int score;
    Gun* SmallGun; 
    Gun* slowgun;
    Gun* fastgun;
    Player* Player1; 
    Enemy** enemy;
    sf::Font font;
    sf::Text text;
    sf::Text beginGameButtonText;
    sf::Text exitGameButtonText;
    sf::String playerInput;
    sf::Text playerText;
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
    std::string gameScreen;
    sf::Vector2i mousePosition;
public:
    Game();
    void run();
    void runMainMenu();
    void runMainGame();
    void runGunMenu();
    void runLeaderboardInput();
    void runGameOver();
    ~Game();
};

#endif

