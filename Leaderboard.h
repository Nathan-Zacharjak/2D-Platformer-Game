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
        std::vector<std::string> scoreNames;
        std::vector<int> scoreNumbers;
        std::string line;//The temp line of text being read from leaderboard.txt, used in reading the file
        std::string formattedScores;
        int scoreLimit;//The max number of high scores stored
        int tempScore;
        std::string tempName;
        int lineNumber;
    public:
        Leaderboard();//Reads the leaderboard.txt file and adds any existing scores to the leaderboard
        std::string get_scores();//Returns all scores in the leaderboard as a formatted string for display
        void write_score(std::string Player, int Score);//Adds a score to the leaderboard
        ~Leaderboard();//On close the leaderboard is written to leaderboard.txt
};

#endif