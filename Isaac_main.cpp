#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>

//Global Game Parameters
    int GW_X = 1000;
    int GW_Y = 600;
    std::string GW_NAME = "I Can Jump!!!";
    int PLAYER_SIZE = 25;
    int PLAYER_X = GW_X/2;
    int PLAYER_Y = GW_Y*0.9;
    float PLAYER_SPEED = 200.0f;
    float PLAYER_JUMP_HEIGHT = 200;

int main(){   
    Player p1 = Player(PLAYER_SIZE,PLAYER_X,PLAYER_Y,PLAYER_SPEED, PLAYER_JUMP_HEIGHT);
    sf::RenderWindow window(sf::VideoMode(GW_X, GW_Y), GW_NAME);
    float theta = 0.0f;
    sf::Clock clock;
    //game loop
    while (window.isOpen())
    {
        //game time to be used as reference for all movements??
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


        p1.update(theta);

        window.clear();
        
        p1.draw(&window);//pass window address so it can be altered
        
        window.display();
        
    }
    

    return 0;
}