#ifndef LEADERBOARD_DEF
#define LEADERBOARD_DEF

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include "Game.h"
using namespace sf;

class Leaderboard{
    private:
        int highest_score;
    public:
        Leaderboard(int);
        void store();
        void highestscore();
};

#endif