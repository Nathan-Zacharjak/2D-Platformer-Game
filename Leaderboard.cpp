#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Leaderboard.h"
using namespace sf;
using namespace std;

Leaderboard::Leaderboard(){
    file.open("leaderboard.txt",ios::in);
    if(file.is_open()){                           
        while (std::getline(file,line)){
            scores.push_back(stoi(line));
        }
    file.close();
    }
};