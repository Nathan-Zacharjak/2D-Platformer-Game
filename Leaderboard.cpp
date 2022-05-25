#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Leaderboard.h"

Leaderboard::Leaderboard(){
    file.open("leaderboard.txt",std::ios::in);
    if(file.is_open()){
        while (std::getline(file,line)){
            scores.push_back(line);
        }
    file.close();
    }
};

std::string Leaderboard::get_scores(){
    formattedScores = "";
    for (int i = 0; i < scores.size(); i++){
        formattedScores = formattedScores + scores[i] + "\n";
    }
    
    return formattedScores;
}

void Leaderboard::write_score(std::string Player, int Score){
    scores.push_back(Player + ": " + std::to_string(Score));
}

Leaderboard::~Leaderboard(){
    file.open("leaderboard.txt",std::ios::out);
    for (int i = 0; i < scores.size(); i++){
        file << scores[i] << "\n";
    }
    file.close();
}