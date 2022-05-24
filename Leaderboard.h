#ifndef LEADERBOARD_DEF
#define LEADERBOARD_DEF

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
using namespace sf;

class Leaderboard{
    private:
        std::fstream file;
        std::vector<int> scores; //Stores the highest game scores
        std::string line;
    public:
        Leaderboard();
        std::vector<int> get_scores();
        void write_scores(std::string Player, int Score);
};

#endif