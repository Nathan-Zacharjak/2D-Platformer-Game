#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Leaderboard.h"

Leaderboard::Leaderboard(){
    scoreLimit = 3;
    lineNumber = 0;

    file.open("leaderboard.txt",std::ios::in);
    if(file.is_open()){
        while (std::getline(file,line)){
            lineNumber++;
            if (lineNumber % 2 == 0){
                scoreNumbers.push_back(std::stoi(line));
            } else {
                scoreNames.push_back(line);
            }
        }
    file.close();
    }

    // Sort both the score and name vectors by the highest scores
    tempScore = -1;
    tempName = "";
    for (int i = 0; i < scoreNumbers.size(); i++){
        for (int j = i; j < scoreNumbers.size(); j++){
            if (scoreNumbers[i] < scoreNumbers[j]){
                tempScore = scoreNumbers[i];
                scoreNumbers[i] = scoreNumbers[j];
                scoreNumbers[j] = tempScore;

                tempName = scoreNames[i];
                scoreNames[i] = scoreNames[j];
                scoreNames[j] = tempName;
            }
        }
    }
    
};

std::string Leaderboard::get_scores(){
    formattedScores = "";
    for (int i = 0; i < scoreNumbers.size(); i++){
        formattedScores = formattedScores + scoreNames[i] + ": " + std::to_string(scoreNumbers[i]) + "\n";
    }
    
    return formattedScores;
}

void Leaderboard::write_score(std::string Player, int Score){
    scoreNames.push_back(Player);
    scoreNumbers.push_back(Score);

    // Sort both the score and name vectors by the highest scores
    tempScore = -1;
    tempName = "";
    for (int i = 0; i < scoreNumbers.size(); i++){
        for (int j = i; j < scoreNumbers.size(); j++){
            if (scoreNumbers[i] < scoreNumbers[j]){
                tempScore = scoreNumbers[i];
                scoreNumbers[i] = scoreNumbers[j];
                scoreNumbers[j] = tempScore;

                tempName = scoreNames[i];
                scoreNames[i] = scoreNames[j];
                scoreNames[j] = tempName;
            }
        }
    }

    // Remove the lowest score from the scoreboard when the score limit is reached
    if (scoreNumbers.size() > scoreLimit){
        scoreNumbers.pop_back();
        scoreNames.pop_back();
    }
}

Leaderboard::~Leaderboard(){
    file.open("leaderboard.txt",std::ios::out);
    for (int i = 0; i < scoreNumbers.size(); i++){
        file << scoreNames[i] << "\n" << scoreNumbers[i] << "\n";
    }
    file.close();
}