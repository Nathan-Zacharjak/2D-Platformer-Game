#include <SFML/Graphics.hpp>
#include "Player.h"
//#include "Character.h"
#include <string>
#include <iostream>
#include "Platform.h"
#include "Enemy.h"
#include "Gun.h"
#include "Parameters.h"


int main(){ 
    Parameters Global;
    sf::Color colour(105,105,105);
    int score = 0;
    Gun* SmallGun = new Gun(1,250, 5, 20);
    Player* Player1 = new Player(Global.PLAYER_SIZE,Global.PLAYER_X,Global.PLAYER_Y,Global.PLAYER_HEALTH, Global.PLAYER_SPEED, sf::Color::Magenta,Global. PLAYER_JUMP_HEIGHT,SmallGun);
    Enemy* enemy[Global.NUMBER_OF_ENEMIES];
    for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++)
    {
        enemy[i] = new Enemy(Global.ENEMY_SIZE,Global.PLAYER_X,Global.ENEMY_X,Global.ENEMY_Y, Global.ENEMY_SPEED, sf::Color::Red, Global.ENEMY_HEALTH);
    }
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    Platform* ground = new Platform(colour,sf::Vector2f((int)1000,(int)100),sf::Vector2f(500,563));
    Platform* platform1 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(500,200));
    Platform* platform2 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(750,350));
    Platform* platform3 = new Platform(colour,sf::Vector2f((int)200,(int)4),sf::Vector2f(250,350));
    sf::Vector2f* direction = new sf::Vector2f(0,0);
    sf::Vector2f* direction2 = new sf::Vector2f(0,0);
    float errormargin; //erorr margin for gravity to stop bouncing on ground
    //sf::Vector2f* direction;
    sf::RenderWindow window(sf::VideoMode(Global.GW_X,Global.GW_Y), Global.GW_NAME);
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
        for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
            enemy[i]->update(theta, time, errormargin);
        }

        //bullet and enemy collision
        for (int i = 0; i < 20; i++){
            for (int j = 0; j < Global.NUMBER_OF_ENEMIES; j++)
            {
               if( SmallGun->getammo()[i].getcollision()->checkcollision( enemy[j]->getcollision(),direction2,1.0f)){
                    //std::cout<<"hit"<<std::endl;
                    enemy[j]->SetAlive(false);
                    score += 1;
               }
            }
        }

        for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
               if( Player1->getcollision()->checkcollision( enemy[i]->getcollision(),direction2,1.0f)){
                    //std::cout<<"hit"<<std::endl;
                    enemy[i]->SetAlive(false);
                    Player1->sethealth(Player1->gethealth()-1);//should be minus enemy damage in future
               }
        }

        if (Player1->gethealth() <= 0)
        {
             window.close();
        }
        

        //p1.update(theta);
        errormargin = abs(abs(Player1->getcollision()->getposition().y - ground->getcollider()->getposition().y) - abs(Player1->getcollision()->gethalfsize().y + ground->getcollider()->gethalfsize().y));
        //std::cout<<errormargin<<std::endl;
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
        text.setString("Score: " + std::to_string(score) + "    " + "Health: " + std::to_string(Player1->gethealth()));
        text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0f,0));
        text.setPosition(sf::Vector2f(Global.GW_X/2,0));
        window.draw(text);
        for (int i = 0; i < Global.NUMBER_OF_ENEMIES; i++){
            enemy[i]->draw(&window);
        }
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
    delete SmallGun;
    return 0;
}