#ifndef LEADERBOARD_DEF
#define LEADERBOARD_DEF

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Leaderboard{
    private:
        int* scores; //Stores the highest game scores
    public:
        Leaderboard();
        int* get_scores();
        void set_scores();
        int get_highest_score();
};

#endif