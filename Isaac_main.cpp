#include <SFML/Graphics.hpp>
#include "IsaacPlayer.h"
#include <string>
#include <iostream>

//Global Game Parameters
    int GW_X = 1000;
    int GW_Y = 600;
    std::string GW_NAME = "I Can Jump!!!";
    int PLAYER_SIZE = 26;
    int PLAYER_X = GW_X/2;
    int PLAYER_Y = 500;
    float PLAYER_SPEED = 200.0f;
    float PLAYER_JUMP_HEIGHT = 200;

int main(){   
    Player p1 = Player(PLAYER_SIZE,PLAYER_X,PLAYER_Y,PLAYER_SPEED, PLAYER_JUMP_HEIGHT, sf::Color::Magenta);
    sf::RenderWindow window(sf::VideoMode(GW_X, GW_Y), GW_NAME);
    float theta = 0.0f;
    float time = 0.0f;
    sf::Clock clock;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFont(font);

    //game loop
    while (window.isOpen())
    {
        //game time to be used as reference for all movements??
        time = time + theta;
        theta = clock.restart().asSeconds();
        //close event
        sf::Event clsevent;
        while (window.pollEvent(clsevent))
        {
            if (clsevent.type == clsevent.Closed)
            {
                window.close();
            }
            
        }

       //std::cout<<time<<std::endl;
        
        p1.update(theta);

        window.clear();
        text.setString(std::to_string(time));
        text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0f,0));
        text.setPosition(sf::Vector2f(GW_X/2,0));
        window.draw(text);
        p1.draw(&window);//pass window address so it can be altered
        
        window.display();
        
    }
    

    return 0;
}