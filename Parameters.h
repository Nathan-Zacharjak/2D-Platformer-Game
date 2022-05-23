#ifndef PARA_DEF
#define PARA_DEF

#include <string>

class Parameters
{
public:
//Global Game Parameters
    //game window
    const int GW_X = 1000;
    const int GW_Y = 600;
    const std::string GW_NAME = "2D Shooter";
    //player parameters
    const int PLAYER_SIZE = 30;
    const int PLAYER_X = GW_X/2;
    const int PLAYER_Y = 500;
    const float PLAYER_SPEED = 200.0f;
    const float PLAYER_JUMP_HEIGHT = 200;
    const int PLAYER_HEALTH = 3;
    //Enemy parameters
    const int ENEMY_SIZE = 40;
    const int ENEMY_X = -20;
    const int ENEMY_Y = -20;
    const float ENEMY_SPEED = 100.0f;
    const int ENEMY_DAMAGE = 1;
    const int ENEMY_HEALTH = 3;
    const int NUMBER_OF_ENEMIES = 2;
    //Extra
    Parameters(){};
    ~Parameters(){};
};

#endif
