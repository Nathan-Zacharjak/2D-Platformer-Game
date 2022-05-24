#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Leaderboard.h"
using namespace sf;
using namespace std;

Leaderboard::Leaderboard(){
    // file.open("leaderboard.txt",ios::in);
    // if(file.is_open()){                           
    //     while (std::getline(file,line)){
    //         scores.push_back(stoi(line));
    //     }
    // file.close();
    // }
};

std::vector<int> Leaderboard::get_scores(){
    return this->scores;
}

void Leaderboard::write_scores(std::string Player, int Score){
    file.open("leaderboard.txt",ios::out);
    file << Player<<","<< Score <<"\n";
    file.close();
}