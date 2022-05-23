#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include "Leaderboard.h"
using namespace sf;
using namespace std;

Leaderboard::Leaderboard(int highest_score){
    Game g;
    highest_score = 0;
};

void Leaderboard::store(){
    if (highest_score < g.score){
        highest_score = g.score;
    }
}

void Leaderboard::highestscore(){
    FILE *fp = NULL;
    fp = fopen("Highestscore.txt", "r");
    if (fp == NULL){
        fp = fopen("Highestscore", "w");
    }
    else{
        fscanf(fp, "%10d", highest_score);
    }
    fclose(fp);
}