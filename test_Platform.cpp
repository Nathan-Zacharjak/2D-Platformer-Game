#include <SFML/Graphics.hpp>

//#include "Character.h"
#include <string>
#include <iostream>
#include "Platform.h"


int main(){ 
    sf::Color colour(105,105,105);
    Platform* ground = new Platform(colour,sf::Vector2f(1000,100),sf::Vector2f(500,564));
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Test Platforms");
  

    //game loop
    while (window.isOpen())
    {
        
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
        
        
        //p1.update(theta);

        window.clear();
        ground->drawplatform(&window);
        window.display();
        
    }
    
   
delete ground;
    return 0;
}