#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    std::string display;

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(400, 400);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::TextEntered){
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
            } 
        }
    
        //window.clear();
        //window.draw(text);
        window.display();
    }

    return 0;
}