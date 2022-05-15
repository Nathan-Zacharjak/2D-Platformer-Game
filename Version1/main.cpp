#include <SFML/Graphics.hpp>
#include "Player.h"
//#include "Character.h"
#include <string>
#include <iostream>
#include "Platform.h"

//Global Game Parameters
    int GW_X = 1000;
    int GW_Y = 600;
    std::string GW_NAME = "I Can Jump!!!";
    int PLAYER_SIZE = 30;
    int PLAYER_X = GW_X/2;
    int PLAYER_Y = 500;
    float PLAYER_SPEED = 200.0f;
    float PLAYER_JUMP_HEIGHT = 200;
    int PLAYER_HEALTH = 3;

int main(){ 
    sf::Color colour(105,105,105);
    Character* Player1 = new Player(PLAYER_SIZE,PLAYER_X,PLAYER_Y,PLAYER_HEALTH, PLAYER_SPEED, sf::Color::Magenta, PLAYER_JUMP_HEIGHT);
    Platform* ground = new Platform(colour,sf::Vector2f((int)1000,(int)100),sf::Vector2f(500,563));
    Platform* platform1 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(500,200));
    Platform* platform2 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(750,350));
    Platform* platform3 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(250,350));
    sf::Vector2f* direction = new sf::Vector2f(0,0);
    float errormargin; //erorr margin for gravity to stop bouncing
    //sf::Vector2f* direction;
    sf::RenderWindow window(sf::VideoMode(GW_X, GW_Y), GW_NAME);
    //window.setKeyRepeatEnabled(false);
    float theta = 0.0f;
    float time = 0.0f;
    sf::Clock clock;

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
        Player1->update(theta, time, errormargin);
        //p1.update(theta);
        errormargin = abs(abs(Player1->getcollision()->getposition().y - ground->getcollider()->getposition().y) - abs(Player1->getcollision()->gethalfsize().y + ground->getcollider()->gethalfsize().y));
        std::cout<<errormargin<<std::endl;
        direction->x = 0;
        direction->y = 0;
        if( ground->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
            Player1->onCollision(direction);
        }
        if (platform1->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
            Player1->onCollision(direction);
        }
        if (platform2->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
            Player1->onCollision(direction);
        }
        if (platform3->getcollider()->checkcollision(Player1->getcollision(),direction,1.0f)){
            Player1->onCollision(direction);
        }
        //std::cout<<(*direction).y<<std::endl;
        window.clear();
        Player1->draw(&window);//pass window address so it can be altered
        platform1->drawplatform(&window);
        platform2->drawplatform(&window);
        platform3->drawplatform(&window);
        ground->drawplatform(&window);
        window.display();
        
    }
    
    delete Player1;
    delete ground;
    delete direction;
    return 0;
}